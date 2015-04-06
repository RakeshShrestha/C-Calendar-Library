
#ifndef CAL_UTIL_H_
#define CAL_UTIL_H_

#include <string>
#include <vector>
#include <utility>

namespace calendar {
namespace util {
  typedef std::pair<double, double> DoubleRange;
  double moment_from_jd (double jd);
  double jd_from_moment (double t);
  double fixed_from_mjd (double mjd);
  double mjd_from_fixed (double date);
  double fixed_from_moment (double t);
  double fixed_from_jd (double jd); 
  double jd_from_fixed (double date);
  double mod (double x, double y);
  double amod (double x, double y);
  double gcd (double x, double y);
  double lcm (double x, double y);
  double time_from_moment (double t);
  double hr (double x);
  
  struct Clock
  {
    int hour;
    int minute;
    int second;
    
    Clock () : hour (0), minute (0), second (0) { }
  };

  struct Angle
  {
    double degrees;
    double minutes;
    double seconds;
    
    Angle () : degrees (0.0), minutes (0.0), seconds (0.0) { }
  };
  
  double time_from_clock (const Clock& clock);
  Clock clock_from_moment (double t);
  Angle angle_from_degrees (double d);

  enum CommonDayOfWeek { SUN, MON, TUE, WED, THU, FRI, SAT };
  
  enum CommonMonth { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL,
                     AUG, SEPT, OCT, NOV, DEC };

}
}

#endif // CAL_UTIL_H_

