
#ifndef GREGORIAN_H_
#define GREGORIAN_H_

#include "simple.h"

namespace calendar {
  class Gregorian : public Simple
  {
  public:
    Gregorian () : Simple (RD) { }
    Gregorian (double year, double month, 
               double day) : Simple (RD, year, month, day) { }   
    Gregorian (double year, util::CommonMonth month, 
               double day) : Simple (RD, year, 
                                     static_cast<double> (month), 
                                     day) { }

    virtual double to_fixed_date () const;
    virtual Calendar* create_from_fixed (double date);
    virtual Calendar* update_from_fixed (double date, Calendar* c);
    virtual void destroy (Calendar* c);
    virtual double nth_kday (double n, double k) const;
    virtual bool is_leap_year () const;
    double new_year () const;
    double year_end () const;
    util::DoubleRange year_range () const;
    double year_from_fixed (double date) const;
    double difference (const Gregorian& g) const;
    double day_light_saving_start () const;
    double day_light_saving_end () const;

  private:
    static const int RD;    
  };  
}

#endif // GREGORIAN_H_
