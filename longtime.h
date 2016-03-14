/*
  LongTimer - common mid-resolution timer library
  Copyright (c) 2012 Max Klimenko.  All right reserved.
  Copyright (c) 2012 dePhonica software. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
*/

#ifndef LongTimer_h
#define LongTimer_h

#include <Arduino.h>

class CLongTimer
{
private:
  bool enabled_, elapsed_;
  long period_;
  long long next_timer_tick_;
  
  unsigned long last_ms_;
  long long offset_;

  void (*p_event_)(long long elapsed);
  void (*v_event_)();

  // overflow-safe version of millis()
  inline long long get_millis()
  {
    unsigned long ms = millis();
    
    if (last_ms_ > ms) offset_ += (unsigned long)0xffffffff;
    
    last_ms_ = ms;
    
    return offset_ + ms;
  }
  
public:
  CLongTimer(long period) : 
    period_(period), enabled_(false), elapsed_(false),
    last_ms_(0), offset_(0),
    p_event_(0), v_event_(0)
  {
  }
  
  void start()
  {
    next_timer_tick_ = get_millis() + period_;
    enabled_ = true;
    elapsed_ = false;
  }
  
  void stop()
  {
    enabled_ = false;
  }
    
  inline void tick()
  {
    if (!enabled_) return;
    
    if (get_millis() >= next_timer_tick_)
    {
      if (p_event_) p_event_(next_timer_tick_);
      if (v_event_) v_event_();
      
      next_timer_tick_ += period_;
      elapsed_ = true;
    }
  }

  inline void set(long period)
  {
    period_ = period;
  }
  
  inline bool elapsed()
  {
    if (elapsed_)
    {
      elapsed_ = false;
      return true;
    }
    
    return false;
  }
  
  inline bool enabled()
  {
    return enabled_;
  }
  
  void event(void (*p_event)(long long elapsed))
  {
    p_event_ = p_event;
    v_event_ = 0;
  }
  
  void event(void (*v_event)())
  {
    v_event_ = v_event;
    p_event_ = 0;
  }
};

#endif LongTimer_h
