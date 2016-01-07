/*
* Author: Erickson Alves
*/

#ifndef BLINK_TASK_3_H
#define BLINK_TASK_3_H

#include "ITask.h"

class BlinkTask3 : public ITask {
public:

  void prepare();

  void execute();

  BlinkTask3();

  ~BlinkTask3();

  int get_interrupt_port();

private:

  int m_pin;

  int m_current_state;

  int m_interrupt_port;

  void interruptable_delay(long delay_time);
};

BlinkTask3::BlinkTask3() {
  set_priority(1);
  set_periodic(false);
  m_pin = 11;
  m_interrupt_port = 2;
  m_current_state = LOW;
}

BlinkTask3::~BlinkTask3() {
}

void BlinkTask3::prepare() {
  Serial.println("BlinkTask3 running prepare()");
  pinMode(m_pin, OUTPUT);
}

void BlinkTask3::execute() {
  Serial.println("BlinkTask3 running execute()");
  m_current_state = (m_current_state == LOW ? HIGH : LOW);
  digitalWrite(m_pin, m_current_state);
  interruptable_delay(5000UL);
  m_current_state = (m_current_state == LOW ? HIGH : LOW);
  digitalWrite(m_pin, m_current_state);
  interruptable_delay(5000UL);
}

int BlinkTask3::get_interrupt_port() {
  return m_interrupt_port;
}

void BlinkTask3::interruptable_delay(long delay_time) {
  long current_time = millis();
  while (millis() - current_time <= delay_time);
}

#endif
