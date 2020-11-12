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

#ifndef CALENDAR_H_
#define CALENDAR_H_

#include <iostream>
#include "util.h"

namespace calendar {
  class Calendar
  {
  public:
    virtual ~Calendar () { }
    virtual double to_fixed_date () const = 0;
    virtual Calendar* create_from_fixed (double date) = 0;
    virtual Calendar* update_from_fixed (double date, Calendar* c) = 0;
    virtual void destroy (Calendar* c) = 0;
    virtual void print (std::ostream& out) const = 0;
    virtual bool operator== (const Calendar& c) const = 0;
    virtual double nth_kday (double n, double k) const = 0;
    virtual bool is_leap_year () const = 0;    
   
    util::CommonDayOfWeek day_of_week_from_fixed (double date) const;

    int kth_day_on_or_before (int k, double date) const
    {
      return static_cast<int> (date - day_of_week_from_fixed (date - k));
    }

    int kth_day_on_or_after (int k, double date) const
    {
      return kth_day_on_or_before (k, date + 6);
    }

    int kth_day_nearest (int k, double date) const
    {
      return kth_day_on_or_before (k, date + 3);
    }

    int kth_day_before (int k, double date) const
    {
      return kth_day_on_or_before (k, date - 1);
    }

    int kth_day_after (int k, double date) const
    {
      return kth_day_on_or_before (k, date + 7);
    }

    bool is_valid (double date) const
    {
      throw "Not implemented.";
    }

    double first_kday (double k) const
    {
      return nth_kday (1, k);
    }

    double last_kday (double k) const
    {
      return nth_kday (-1, k);
    }

    friend std::ostream& operator<< (std::ostream& out, Calendar& c)
    {
      c.print (out);
      return out;
    }
  };
}

#endif // CALENDAR_H_
