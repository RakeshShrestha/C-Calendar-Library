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

#ifndef SIMPLE_H_
#define SIMPLE_H_

#include "three_part_rep.h"

namespace calendar {
  class Simple : public Calendar
  {
  public:
    Simple (double e) : rep_ (e) { }
    Simple (double e, double year, 
            double month, double day) : rep_(e, year, month, day) { }
    Simple (const Calendar& c, double e) : rep_ (e)
    {
      update_from_fixed (c.to_fixed_date (), this);
    }
    virtual double to_fixed_date () const;
    virtual Calendar* create_from_fixed (double date);
    virtual Calendar* update_from_fixed (double date, Calendar* c);
    virtual void destroy (Calendar* c);

    virtual bool operator== (const Calendar& c) const
    {
      const Simple& ca = dynamic_cast<const Simple&> (c);
      return (rep_ == ca.rep_);
    }

    virtual void print (std::ostream& out) const
    {
      rep_.print (out);
    }

    virtual double nth_kday (double n, double k) const
    {
      throw "Not implemented.";
    }
    virtual bool is_leap_year () const
    {
      throw "Not implemented.";
    }

    const ThreePartRepresentation& rep () const { return rep_; }

  protected:
    ThreePartRepresentation rep_;
  };  
}

#endif // SIMPLE_H_
