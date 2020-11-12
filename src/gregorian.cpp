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

using namespace std;

namespace calendar {

  const int Gregorian::RD = 1;

  double Gregorian::to_fixed_date () const
  {
    double year = rep_.d_year ();
    double month = rep_.d_month ();
    double day = rep_.d_day ();
    double p = 0;
    if (month <= 2) p = 0;
    else if (is_leap_year ()) p = -1;
    else p = -2;
    return (RD - 1.0f + 365.0f * (year - 1) + floor ((year - 1) / 4.0f)
            - floor ((year - 1) / 100.0f) + floor ((year - 1) / 400.0f)
            + floor (1.0f/12.0f * (367.0f * month - 362.0f)) + p + day);
  }

  Calendar* Gregorian::create_from_fixed (double date)
  {   
    return update_from_fixed (date, new Gregorian ());
  }

  Calendar* Gregorian::update_from_fixed (double date, Calendar* c)
  {    
    double year = year_from_fixed (date);
    Gregorian g (year, util::MAR, 1);
    double prior_days = date - g.new_year ();
    double correction = 0.0f;
    if (date < g.to_fixed_date ())
      correction = 0.0f;
    else if (g.is_leap_year ())
      correction = 1.0f;
    else
      correction = 2.0f;
    double month = floor (1.0f/367.0f * (12.0f * (prior_days + correction) + 373.0f));
    Gregorian g2 (year, month, 1);
    double day = 1 + date - g2.to_fixed_date ();
    Gregorian* ret = dynamic_cast<Gregorian*> (c);
    ret->rep_ = ThreePartRepresentation (rep_.d_epoch (), year, month, day);
    return c;
  }

  static bool is_greg (Calendar* c)
  {
    return (dynamic_cast<Gregorian*> (c) != 0);
  }
  
  void Gregorian::destroy (Calendar* c)
  {   
    if (is_greg (c)) delete c;
  }

  bool Gregorian::is_leap_year () const
  {
    if (util::mod (rep_.d_year (), 4) == 0)
      {
        double r = util::mod (rep_.d_year (), 400);
        return (r != 100 && r != 200 && r != 300);
      }
    return false;
  }

  double Gregorian::new_year () const
  {
    Gregorian g (rep_.d_year (), util::JAN, 1);
    return g.to_fixed_date ();
  }

  double Gregorian::year_end () const
  {
    Gregorian g (rep_.d_year (), util::DEC, 31);
    return g.to_fixed_date ();
  }

  util::DoubleRange Gregorian::year_range () const
  {
    return util::DoubleRange (new_year (), year_end ());
  }

  double Gregorian::year_from_fixed (double date) const
  {
    double d0 = date - rep_.d_epoch ();
    double n400 = std::floor (d0 / 146097.0f);
    double d1 = util::mod (d0, 146097.0f);
    double n100 = std::floor (d1 / 36524.0f);
    double d2 = util::mod (d1, 36524.0f);
    double n4 = std::floor (d2 / 1461.0f);
    double d3 = util::mod (d2, 1461.0f);
    double n1 = std::floor (d3 / 365.0f);
    double year = 400.0f * n400 + 100.0f * n100 + 4.0f * n4 + n1;
    if (n100 == 4.0f || n1 == 4.0f)
      return year;
    else
      return (year + 1.0f);
  }

  double Gregorian::difference (const Gregorian& g) const
  {
    return (g.to_fixed_date () - to_fixed_date ());
  }

  double Gregorian::nth_kday (double n, double k) const
  {
    int i = static_cast<int> (k);
    if (n > 0)
      return 7 * n + Calendar::kth_day_before (i, to_fixed_date ());
    else
      return 7 * n + Calendar::kth_day_after (i, to_fixed_date ());
  }

  double Gregorian::day_light_saving_start () const
  {
    Gregorian g (rep_.d_year (), util::MAR, 1);
    return g.nth_kday (2, util::SUN);
  }
  
  double Gregorian::day_light_saving_end () const
  {
    Gregorian g (rep_.d_year (), util::NOV, 1);
    return g.first_kday (util::SUN);
  }

}

