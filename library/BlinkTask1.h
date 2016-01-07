/*
* Author: Erickson Alves
*/

#ifndef BLINK_TASK_1_H
#define BLINK_TASK_1_H

#include "ITask.h"

class BlinkTask1 : public ITask {
public:

  void prepare();

  void execute();

  BlinkTask1();

  ~BlinkTask1();

private:

  int m_pin;

  int m_current_state;
};

BlinkTask1::BlinkTask1() {
  set_priority(2);
  set_periodic(true);
  m_pin = 9;
  m_current_state = LOW;
}

BlinkTask1::~BlinkTask1() {
}

void BlinkTask1::prepare() {
  Serial.println("BlinkTask1 running prepare()");
  pinMode(m_pin, OUTPUT);
}

void BlinkTask1::execute() {
  Serial.println("BlinkTask1 running execute()");
  m_current_state = (m_current_state == LOW ? HIGH : LOW);
  digitalWrite(m_pin, m_current_state);
  interruptable_delay(5000UL);
  m_current_state = (m_current_state == LOW ? HIGH : LOW);
  digitalWrite(m_pin, m_current_state);
  interruptable_delay(5000UL);
}

#endif
