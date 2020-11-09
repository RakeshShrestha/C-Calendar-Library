# Copyright Rakesh Shrestha (rakesh.shrestha@gmail.com)
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# Redistributions must retain the above copyright notice.

#ifndef THREE_PART_REP_H
#define THREE_PART_REP_H

#include <iostream>

namespace calendar {

  class ThreePartRepresentation
  {
  public:
    ThreePartRepresentation () : epoch_ (0.0), year_ (0.0), 
      month_ (0.0), day_ (0.0) { }
    ThreePartRepresentation (double e) : epoch_ (e), year_ (0.0), 
      month_ (0.0), day_ (0.0) 
    { }

    ThreePartRepresentation (double e, double year, 
                             double month, double day) : epoch_ (e), year_ (year),
      month_ (month), day_ (day)
    { }

    ThreePartRepresentation (const ThreePartRepresentation& tpr)
    {
      init_from (tpr);
    }

    double d_year () const { return year_; }
    double d_month () const { return month_; }
    double d_day () const { return day_; }
    double d_epoch () const { return epoch_; }

    ThreePartRepresentation& operator= (const ThreePartRepresentation& tpr)
    {
      if (this == &tpr)
        return *this;
      init_from (tpr);
      return *this;
    }

    bool operator== (const ThreePartRepresentation& tpr) const
    {
      return (year_ == tpr.year_ && month_ == tpr.month_ && day_ == tpr.day_);
    }

    void print (std::ostream& out) const
    {
      out << year_ << ' ' << month_ << ' ' << day_;
    }

    double sub_year (double n) const
    {
      return (year_ - n);
    }

    double sub_month (double n) const
    {
      return (month_ - n);
    }

    double add_day (double n) const
    {
      return (day_ + n);
    }

  private:
    void init_from (const ThreePartRepresentation& tpr)
    {
      epoch_ = tpr.epoch_;
      year_ = tpr.year_;
      month_ = tpr.month_;
      day_ = tpr.day_;
    }

    double epoch_;
    double year_;
    double month_;
    double day_;
  };
}

#endif // THREE_PART_REP_H
