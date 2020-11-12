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

#include "util.h"
#include "calendar.h"

namespace calendar {

  util::CommonDayOfWeek Calendar::day_of_week_from_fixed (double date) const
  {
    double d = util::mod (date - 0.0f - static_cast<double> (util::SUN), 7.0f);
    int i = static_cast<int> (d);
    return static_cast<util::CommonDayOfWeek> (i);
  }

}
