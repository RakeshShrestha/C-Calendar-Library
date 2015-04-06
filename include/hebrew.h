// UNTESTED.


#ifndef HEBREW_H_
#define HEBREW_H_

#include "simple.h"

namespace calendar {
  class Hebrew : public Simple
  {
  public:
    Hebrew () : Simple (RD) { }
    Hebrew (double year, double month, 
            double day) : Simple (RD, year, month, day) { }

    enum Month { NISAN = 1, IYYAR, SIVAN, TAMMUZ, AV, ELUL,
                 TISHRI, MARHESHVAN, KISLEV, TEVET, SHEVAT, 
                 ADAR, ADARII };

    Hebrew (double year, Month month, 
            double day) : Simple (RD, year, 
                                  static_cast<double> (month), 
                                  day) { }
    
    virtual double to_fixed_date () const;
    virtual Calendar* create_from_fixed (double date);
    virtual Calendar* update_from_fixed (double date, Calendar* c);
    virtual void destroy (Calendar* c);
    virtual bool is_leap_year () const;
    virtual double nth_kday (double n, double k) const;

    bool is_sabbatical_year () const;
    Month last_month_of_year () const;
    double molad () const;
    double new_year () const;
    int last_day_of_month () const;
    double days_in_year () const;
    bool is_long_marheshvan () const;
    bool is_short_kislev () const;
  private:
    static double elapsed_days (double h_year);
    static double year_length_correction (double h_year);
    static double new_year (double h_year);
    static bool is_leap_year (double h_year);
    static bool is_sabbatical_year (double h_year);
    static Month last_month_of_year (double h_year);
    static int last_day_of_month (Month month, double h_year);
    static bool to_fixed_date_helper (Month m, double year);
    static double days_in_year (double h_year);
    static bool is_long_marheshvan (double h_year);
    static bool is_short_kislev (double h_year);

    static const int RD;    
  };  
}

#endif // HEBREW_H_
