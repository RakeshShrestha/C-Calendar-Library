# Copyright Rakesh Shrestha (rakesh.shrestha@gmail.com)
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# Redistributions must retain the above copyright notice.

#include <cmath>
#include "util.h"

namespace calendar {
namespace util {

  static const double jd_epoch = -1721424.5;
  static const double mjd_epoch = 678576;

  double moment_from_jd (double jd) { return (jd + jd_epoch); }
  double jd_from_moment (double t) { return (t - jd_epoch); }
  double fixed_from_mjd (double mjd) { return (mjd + mjd_epoch); }
  double mjd_from_fixed (double date) { return (date - mjd_epoch); }
  double fixed_from_moment (double t) { return std::floor (t); }
  double fixed_from_jd (double jd) 
  { 
    return std::floor (moment_from_jd (jd)); 
  }
  double jd_from_fixed (double date) { jd_from_moment (date); }
  double mod (double x, double y) { return (x - y * std::floor (x/y)); }
  double amod (double x, double y)
  {
    if (mod (x, y) == 0) return y;
    return mod (x, y);
  }
  double gcd (double x, double y) 
  {
    if (y == 0) return x;
    return gcd (y, mod (x, y));
  }
  double lcm (double x, double y) { return (x * y / gcd (x, y)); }
  double time_from_moment (double t) { return (mod (t, 1)); }
  double time_from_clock (const Clock& clock)
  {
    int m = clock.minute + clock.second / 60;
    int h = clock.hour + m / 60;
    return ((1 / 24) * h);
  }
  Clock clock_from_moment (double t)
  {
    t = time_from_moment (t);
    Clock clock;
    clock.hour = static_cast<int> (std::floor (t * 24));
    clock.minute = static_cast<int> (std::floor (mod ((t * 24 * 60), 60)));
    clock.second = static_cast<int> (mod ((t * 24 * (60 * 60)), 60));
    return clock;
  }

  Angle angle_from_degrees (double d)
  {
    Angle angle;
    angle.degrees = std::floor (d);
    angle.minutes = std::floor (60 * mod (d, 1));
    angle.seconds = mod ((d * (60 * 60)), 60);
    return angle;
  }

  double hr (double x)
  {
    return (x/24.0f);
  }
}
}


