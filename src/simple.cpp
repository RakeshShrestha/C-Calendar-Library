
#include <cmath>
#include "util.h"
#include "calendar.h"
#include "simple.h"

namespace calendar {

  static bool is_simple (Calendar* c)
  {
    return (dynamic_cast<Simple*> (c) != 0);
  }

  double Simple::to_fixed_date () const
  {
    return (rep_.d_epoch () + 365 * (rep_.d_year () - 1) + 30 
            * (rep_.d_month () - 1) + rep_.d_day() - 1);
  }

  Calendar* Simple::create_from_fixed (double date)
  {   
    return update_from_fixed (date, new Simple (rep_.d_epoch ()));
  }

  Calendar* Simple::update_from_fixed (double date, Calendar* c)
  {
    double days = date - rep_.d_epoch ();
    double year = std::floor (days/365 + 1);
    double month = std::floor ((1.0f/30.0f) * util::mod (days, 365)) + 1;
    double day = days - 365 * (year - 1) - 30 * (month - 1) + 1;
    Simple* ca = dynamic_cast<Simple*> (c);
    ThreePartRepresentation tp (rep_.d_epoch (), year, month, day);
    ca->rep_ = tp;
    return c;
  }

  void Simple::destroy (Calendar* c)
  {   
    if (is_simple (c)) delete c;
  }
}
