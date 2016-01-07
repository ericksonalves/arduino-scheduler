/*
* Author: Erickson Alves
*/

#ifndef ITASK_H
#define ITASK_H

#include <Arduino.h>

class ITask {
public:
  virtual void prepare() = 0;

  virtual void execute() = 0;

  int get_priority() const;

  void set_priority(int priority);

  bool is_periodic() const;

  void set_periodic(bool is_periodic);

  void interruptable_delay(long delay_time);

private:

  int m_priority;

  bool m_is_periodic;

};

int ITask::get_priority() const {
  return m_priority;
}

void ITask::set_priority(int priority) {
  m_priority = priority;
}

bool ITask::is_periodic() const {
  return m_is_periodic;
}

void ITask::set_periodic(bool is_periodic) {
  m_is_periodic = is_periodic;
}

void ITask::interruptable_delay(long delay_time) {
  long current_time = millis();
  while (millis() - current_time <= delay_time);
}

#endif
