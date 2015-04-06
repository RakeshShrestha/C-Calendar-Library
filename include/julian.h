/* NOT TESTED. */

#ifndef JULIAN_H_
#define JULIAN_H_

#include "three_part_rep.h"

namespace calendar {
  class Julian : public Calendar
  {
  public:
    Julian () : rep_ (RD) { }
    Julian (double year, double month, 
            double day) : rep_ (RD, year, month, day) { }
    Julian (double year, util::CommonMonth month, 
            double day) : rep_ (RD, year, 
                                static_cast<double> (month), 
                                day) { }

    virtual double to_fixed_date () const;
    virtual Calendar* create_from_fixed (double date);
    virtual Calendar* update_from_fixed (double date, Calendar* c);
    virtual void destroy (Calendar* c);
    virtual bool operator== (const Calendar& c) const;
    virtual void print (std::ostream& out) const;
    virtual bool is_leap_year () const;

    enum MonthlyEvent { KALENDS = 1, NONES, IDES };
    int ides () const;
    int nones () const;

  private:
    static const int RD;    
    ThreePartRepresentation rep_;
  };  
}

#endif // JULIAN_H_
