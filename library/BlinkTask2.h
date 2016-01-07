/*
* Author: Erickson Alves
*/

#ifndef BLINK_TASK_2_H
#define BLINK_TASK_2_H

#include "ITask.h"

class BlinkTask2 : public ITask {
public:

  void prepare();

  void execute();

  BlinkTask2();

  ~BlinkTask2();

private:

  int m_pin;

  int m_current_state;

};

BlinkTask2::BlinkTask2() {
  set_priority(3);
  set_periodic(true);
  m_pin = 10;
  m_current_state = LOW;
}

BlinkTask2::~BlinkTask2() {
}

void BlinkTask2::prepare() {
  Serial.println("BlinkTask2 running prepare()");
  pinMode(m_pin, OUTPUT);
}

void BlinkTask2::execute() {
  Serial.println("BlinkTask2 running execute()");
  m_current_state = (m_current_state == LOW ? HIGH : LOW);
  digitalWrite(m_pin, m_current_state);
  interruptable_delay(5000UL);
  m_current_state = (m_current_state == LOW ? HIGH : LOW);
  digitalWrite(m_pin, m_current_state);
  interruptable_delay(5000UL);
}

#endif
