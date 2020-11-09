# Copyright Rakesh Shrestha (rakesh.shrestha@gmail.com)
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# Redistributions must retain the above copyright notice.

#include <cmath>
#include "calendar.h"
#include "gregorian.h"
#include "julian.h"
using namespace std;

namespace calendar {

  static int julian_epoch () 
  {
    Gregorian g (0, util::DEC, 30);
    return g.to_fixed_date ();
  }

  const int Julian::RD = julian_epoch ();

  bool Julian::is_leap_year () const
  {
    double year = rep_.d_year ();
    double d = util::mod (year, 4.0f);
    if (year > 0)
      return (d == 0);
    else
      return (d == 3);
  }

  double Julian::to_fixed_date () const
  {
    double epoch = rep_.d_epoch ();
    double year = rep_.d_year ();
    double month = rep_.d_month ();
    double day = rep_.d_day ();
    double y = (year < 0) ? year + 1.0f : year;
    double p = 0.0f;
    if (month <= 2)
      p = 0.0f;
    else if (is_leap_year ())
      p = -1.0f;
    else
      p = -2.0f;
    return (epoch - 1 + 365.0f * (y - 1) + floor ((y - 1)/4.0f) 
            + floor (1.0f/12.0f * (367.0f * month - 362.0f))
            + p + day);
  }

  Calendar* Julian::create_from_fixed (double date)
  {   
    return update_from_fixed (date, new Julian ());
  }

  Calendar* Julian::update_from_fixed (double date, Calendar* c)
  {    
    double approx = floor (1.0f/1461.0f * (4 * (date - rep_.d_epoch ()) + 1464.0f));
    double year = (approx <= 0) ? approx - 1 : approx;
    Julian j1 (year, util::JAN, 1);
    double prior_days = date - j1.to_fixed_date ();
    double correction = 0.0f;    
    Julian j2 (year, util::MAR, 1);
    if (date < j2.to_fixed_date ())
      correction = 0.0f;      
    else if (j2.is_leap_year ())
      correction = 1.0f;
    else
      correction = 2.0f;
    double month = floor (1.0f/367.0f * (12 * (prior_days + correction) + 373.0f));
    Julian j3 (year, month, 1);
    double day = date - j3.to_fixed_date () + 1;
    Julian* ret = dynamic_cast<Julian*> (c);
    ret->rep_ = ThreePartRepresentation (rep_.d_epoch (), year, month, day);
    return c;
  }

  static bool is_julian (Calendar* c)
  {
    return (dynamic_cast<Julian*> (c) != 0);
  }

  void Julian::destroy (Calendar* c)
  {   
    if (is_julian (c)) delete c;
  }

  bool Julian::operator== (const Calendar& c) const
  {
    const Julian& ca = dynamic_cast<const Julian&> (c);
    return (rep_ == ca.rep_);
  }

  void Julian::print (std::ostream& out) const
  {
    rep_.print (out);
  }

  int Julian::ides () const
  {
    util::CommonMonth month = static_cast<util::CommonMonth> (rep_.d_month ());
    if (month == util::MAR || month == util::MAY 
        || month == util::JUL || month == util::OCT)
      return 15;
    else
      return 13;
  }

  int Julian::nones () const
  {
    return (ides () - 8);
  }
  
}
