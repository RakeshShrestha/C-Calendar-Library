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
#include "hebrew.h"
using namespace std;

namespace calendar {

  const int Hebrew::RD = -1373427;

  bool Hebrew::is_leap_year () const
  {
    return is_leap_year (rep_.d_year ());
  }

  bool Hebrew::is_sabbatical_year () const
  {
    return is_sabbatical_year (rep_.d_year ());
  }

  Hebrew::Month Hebrew::last_month_of_year () const
  {
    return last_month_of_year (rep_.d_year ());
  }

  double Hebrew::molad () const
  {
    double month = rep_.d_month ();
    double year = rep_.d_year ();
    double tishri = static_cast<double> (TISHRI);
    double y = month < tishri ? (year + 1) : year;
    double months_elapsed = month - tishri + floor (1.0f/9.0f * (235 * y - 234));
    double e = rep_.d_epoch ();
    return (e - 876.0f/25920.0f + months_elapsed 
            * (29.0f + util::hr (12) + 793.0f/25920.0f));
  }

  double Hebrew::new_year () const
  {
    return new_year (rep_.d_year ());
  }

  int Hebrew::last_day_of_month () const
  {
    return last_day_of_month (static_cast<Month> (rep_.d_month ()), rep_.d_year ());
  }

  double Hebrew::days_in_year () const
  {
    return days_in_year (rep_.d_year ());
  }

  bool Hebrew::is_long_marheshvan () const
  {
    return is_long_marheshvan (rep_.d_year ());
  }

  bool Hebrew::is_short_kislev () const
  {
    return is_short_kislev (rep_.d_year ());
  }
  
  double Hebrew::nth_kday (double n, double k) const
  {
    Gregorian g (rep_.d_year (), rep_.d_month (), rep_.d_day ());
    return g.nth_kday (n, k);
  }

  bool Hebrew::to_fixed_date_helper (Hebrew::Month m, double year)
  {
    return (m <= last_month_of_year (year));
  }

  double Hebrew::to_fixed_date () const
  {
    double year = rep_.d_year ();
    double month = rep_.d_month ();
    double c = 0.0f;
    if (month < TISHRI)
      {
        double a = 0.0f;
        Month m = TISHRI;
        while (to_fixed_date_helper (m, year))
          {
            a += last_day_of_month (m, year);
            int t = m + 1;
            m = static_cast<Month> (t);
          }
        double b = 0.0f;
        m = NISAN;
        while (m < month)
          {
            b += last_day_of_month (m, year);
            int t = m + 1;
            m = static_cast<Month> (t);
          }
        c = a + b;
      }
    else
      {
        Month m = TISHRI;
        while (m < month)
          {
            c += last_day_of_month (m, year);
            int t = m + 1;
            m = static_cast<Month> (t);
          }
      }
    return (new_year (year) + rep_.d_day () - 1 + c);
  }

  Calendar* Hebrew::create_from_fixed (double date)
  {   
    return update_from_fixed (date, new Hebrew ());
  }

  Calendar* Hebrew::update_from_fixed (double date, Calendar* c)
  {    
    double approx = floor (98496.0f/35975351.0f * (date - rep_.d_epoch ())) + 1.0f;
    double y = approx - 1.0f;
    double mx = y;
    while (new_year (y) <= date)
      {
        y += 1.0f;
        if (y > mx)
          mx = y;
      }
    double year = mx;
    Hebrew h1 (year, NISAN, 1);
    Month start = date < h1.to_fixed_date () ? TISHRI : NISAN;
    double m = static_cast<double> (start);
    double mn = m;
    while (true)
      {
        Hebrew h2 (year, m, last_day_of_month (static_cast<Month> (m), year));               
        bool b = (date <= h2.to_fixed_date());
        if (m < mn) mn = m;
        if (b)
          break;
        m += 1.0f;        
      }
    double month = mn;
    Hebrew h3 (year, month, 1);
    double day = 1 + date - h3.to_fixed_date ();
    Hebrew* ret = dynamic_cast<Hebrew*> (c);
    ret->rep_ = ThreePartRepresentation (rep_.d_epoch (), year, month, day);
    return c;
  }

  static bool is_hebrew (Calendar* c)
  {
    return (dynamic_cast<Hebrew*> (c) != 0);
  }

  void Hebrew::destroy (Calendar* c)
  {   
    if (is_hebrew (c)) delete c;
  }

  double Hebrew::elapsed_days (double h_year)
  {
    double months_elapsed = floor (1.0f/19.0f * (235.0f * h_year - 234.0f));
    double parts_elapsed = 12084.0f + 13753.0f * months_elapsed;
    Hebrew h (h_year, TISHRI, 1);
    double days = floor (h.molad () - RD + util::hr (12));
    if (util::mod ((3 * (days + 2)), 7) < 3)
      return days + 1;
    else
      return days;
  }

  double Hebrew::year_length_correction (double h_year)
  {
    double ny0 = elapsed_days (h_year - 1);
    double ny1 = elapsed_days (h_year);
    double ny2 = elapsed_days (h_year + 1);
    if ((ny2 - ny1) == 356.0f)
      return 2.0f;
    else if ((ny1 - ny0) == 382.0f)
      return 1.0f;
    else
      return 0.0f;
  }

  double Hebrew::new_year (double h_year)
  {
    return (RD + elapsed_days (h_year) + year_length_correction (h_year));
  }

  bool Hebrew::is_leap_year (double h_year)
  {
    return (util::mod ((7.0f * h_year + 1.0f), 19.0f) < 7.0f);
  }

  bool Hebrew::is_sabbatical_year (double h_year)
  {
    return (util::mod (h_year, 7.0f) == 0.0f);
  }

  Hebrew::Month Hebrew::last_month_of_year (double h_year)
  {
    return (is_leap_year (h_year) ? ADARII : ADAR);
  }

  int Hebrew::last_day_of_month (Hebrew::Month month, double h_year)
  {
    if ((month == IYYAR || month == TAMMUZ || month == ELUL
         || month == TEVET || month == ADARII)
        || (month == ADAR && !is_leap_year (h_year))
        || (month == MARHESHVAN && !is_long_marheshvan (h_year))
        || (month == KISLEV && is_short_kislev (h_year)))
      return 29;
    else
      return 30;
  }  

  double Hebrew::days_in_year (double h_year)
  {
    return (new_year (h_year + 1) - new_year (h_year));
  }

  bool Hebrew::is_long_marheshvan (double h_year)
  {
    double d = days_in_year (h_year);
    return (d == 355.0f || d == 385.0f);
  }

  bool Hebrew::is_short_kislev (double h_year)
  {
    double d = days_in_year (h_year);
    return (d == 353.0f || d == 383.0f);
  }
}
