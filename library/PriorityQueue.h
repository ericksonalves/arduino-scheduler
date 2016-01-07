/*
* Author: Erickson Alves
*/

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <Arduino.h>
#include "ITask.h"

class PriorityQueue {

public:

  PriorityQueue();

  ~PriorityQueue();

  void push(ITask* item);

  ITask* pop();

  bool is_empty() const;

  int count() const;

private:

  typedef struct node {
    ITask* item;
    node* next;
  } node;

  typedef node* pointer;

  int size;

  pointer head;

};

PriorityQueue::PriorityQueue() {
  size = 0;
  head = NULL;
}

PriorityQueue::~PriorityQueue() {
  for (pointer t = head; t != NULL; head = t) {
    t = head->next;
    delete head;
  }

  size = 0;
  head = NULL;
}

void PriorityQueue::push(ITask* item) {
  pointer previous = NULL;
  pointer current = head;
  pointer element = NULL;

  element = new node;
  element->item = item;

  while (current != NULL && item->get_priority() > current->item->get_priority()) {
    previous = current;
    current = current->next;
  }

  if (previous == NULL) {
    element->next = head;
    head = element;
  } else {
    previous->next = element;
    element->next = current;
  }

  size++;
}

ITask* PriorityQueue::pop() {
  ITask* item;

  if (!is_empty()) {
    item = head->item;
    pointer t = head->next;
    delete head;
    head = t;

    size--;
  }

  return item;
}

bool PriorityQueue::is_empty() const {
  return head == NULL;
}

int PriorityQueue::count() const {
  return size;
}

#endif
