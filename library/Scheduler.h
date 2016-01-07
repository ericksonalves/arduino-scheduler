/*
* Author: Erickson Alves
*/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "ITask.h"
#include "PriorityQueue.h"

class Scheduler {
public:

  void add(ITask *task);

  void loop();

  void setup();

  Scheduler();

  ~Scheduler();

private:

  PriorityQueue m_queue;

  PriorityQueue m_backup_queue;

  void move_queue(const int size);

};

Scheduler::Scheduler() {
}

Scheduler::~Scheduler() {
}

void Scheduler::add(ITask *task) {
  m_queue.push(task);
}

void Scheduler::move_queue(const int size) {
  int i;

  for (i = 0; i < size; i++) {
    m_queue.push(m_backup_queue.pop());
  }
}

void Scheduler::loop() {
  int i, size, new_size;

  size = m_queue.count();
  new_size = 0;

  for (i = 0; i < size; i++) {
    ITask *task = m_queue.pop();
    task->execute();
    if (task->is_periodic()) {
      m_backup_queue.push(task);
      new_size++;
    }
  }

  move_queue(new_size);
}

void Scheduler::setup() {
  int i, size;

  size = m_queue.count();

  for (i = 0; i < size; i++) {
    ITask *task = m_queue.pop();
    task->prepare();
    m_backup_queue.push(task);
  }

  move_queue(size);
}

#endif
