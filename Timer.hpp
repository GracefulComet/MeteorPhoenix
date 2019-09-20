
#pragma once
#include <SDL2/SDL.h>

class TimerF {
public:
  TimerF() {
    m_ready = false;
    m_prevTime = 0.0f;
    m_currTime = 0.0f;
    m_deltaTime = 0.0f;
  }
  bool cooldown(float duration);
  void reset();
  float getDelta();

private:
  bool m_ready;
  float m_prevTime;
  float m_currTime;
  float m_deltaTime;
};
