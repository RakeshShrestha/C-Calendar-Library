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

#ifndef ISO_H_
#define ISO_H_

#include "simple.h"

namespace calendar {
  class ISO : public Simple
  {
  public:
    ISO () : Simple (RD), week_ (1) { }
    ISO (double year, double week, double day) : Simple (RD, year, 0, day), 
                                                 week_ (week) { }
    ISO (double year, double month, 
         double week, double day) : Simple (RD, year, month, day), 
                                    week_ (week) { }
    ISO (double year, util::CommonMonth month, double week,
         double day) : Simple (RD, year, 
                               static_cast<double> (month), 
                               day), week_ (week) { }
    ISO (const Calendar& c) : Simple (RD) 
    { 
      ISO *e = dynamic_cast<ISO*> (create_from_fixed (c.to_fixed_date ()));
      *this = *e;
      destroy (e);
    }
    
    virtual double to_fixed_date () const;
    virtual Calendar* create_from_fixed (double date);
    virtual Calendar* update_from_fixed (double date, Calendar* c);
    virtual void destroy (Calendar* c);
    virtual double nth_kday (double n, double k) const;
    virtual bool is_leap_year () const;
    virtual bool operator== (const Calendar& c) const
    {
      const ISO& ca = dynamic_cast<const ISO&> (c);
      return (rep_ == ca.rep_ && week_ == ca.week_);
    }

    virtual void print (std::ostream& out) const
    {
      rep_.print (out);
      out << ' ' << week_;
    }

    double week () const { return week_; }
    bool is_long_year () const;

  private:
    static const int RD;    
    double week_;
  };  
}

#endif // ISO_H_
