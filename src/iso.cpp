/**
# Copyright Rakesh Shrestha (rakesh.shrestha@gmail.com)
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# Redistributions must retain the above copyright notice.
*/

#include <cmath>
#include "calendar.h"
#include "gregorian.h"
#include "iso.h"

using namespace std;

namespace calendar {

  const int ISO::RD = 1;

  bool ISO::is_leap_year () const
  {
    Gregorian g (rep_.d_year (), rep_.d_month (), rep_.d_day ());
    return g.is_leap_year ();
  }

  double ISO::nth_kday (double n, double k) const
  {
    Gregorian g (rep_.d_year (), rep_.d_month (), rep_.d_day ());
    return g.nth_kday (n, k);
  }

  double ISO::to_fixed_date () const
  {
    Gregorian g (rep_.d_year () - 1, util::DEC, 28);
    return (g.nth_kday (week_, static_cast<double> (util::SUN)) + rep_.d_day ());
  }

  Calendar* ISO::create_from_fixed (double date)
  {   
    return update_from_fixed (date, new ISO ());
  }

  Calendar* ISO::update_from_fixed (double date, Calendar* c)
  {    
    Gregorian g;
    double approx = g.year_from_fixed (date - 3);
    ISO iso (approx + 1, 1, 1);
    double year = 0.0f;
    if (date >= iso.to_fixed_date ())
      year = approx + 1;
    else
      year = approx;
    ISO iso2 (year, 1, 1);
    double week = 1.0f + floor (1.0f / 7.0f * (date - iso2.to_fixed_date ()));
    double day = util::amod (date - 0.0f, 7);
    ISO* ret = dynamic_cast<ISO*> (c);
    ret->rep_ = ThreePartRepresentation (rep_.d_epoch (), year, rep_.d_month (), day);
    ret->week_ = week;
    return c;
  }

  static bool is_iso (Calendar* c)
  {
    return (dynamic_cast<ISO*> (c) != 0);
  }

  void ISO::destroy (Calendar* c)
  {   
    if (is_iso (c)) delete c;
  }

  bool ISO::is_long_year () const
  {
    Gregorian g (rep_.d_year (), 1, 1);
    util::CommonDayOfWeek jan1 = day_of_week_from_fixed (g.new_year ());
    util::CommonDayOfWeek dec31 = day_of_week_from_fixed (g.year_end ());
    return (jan1 == util::THU || dec31 == util::THU);
  }
  
}
