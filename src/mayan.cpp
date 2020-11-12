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

#include <cmath>
#include "calendar.h"
#include "mayan.h"

using namespace std;

namespace calendar {

  const double Mayan::KIN = 1.0f;
  const double Mayan::UINAL = 20 * KIN;
  const double Mayan::TUN = 18 * UINAL;
  const double Mayan::KATUN = 20 * TUN;
  const double Mayan::BAKTUN = 20 * KATUN;
  const int Mayan::RD = -1137142;

  double Mayan::to_fixed_date () const
  {
    return (RD + baktun_ * 144000 + katun_ * 7200
            + tun_ * 360 + uinal_ * 20 + kin_);
  }

  Calendar* Mayan::create_from_fixed (double date)
  {   
    return update_from_fixed (date, new Mayan ());
  }

  Calendar* Mayan::update_from_fixed (double date, Calendar* c)
  {    
    Mayan* ret = dynamic_cast<Mayan*> (c);
    double long_count = date - RD;
    ret->baktun_ = floor (long_count/144000);
    double day_of_baktun = util::mod (long_count, 144000);
    ret->katun_ = floor (day_of_baktun/7200);
    double day_of_katun = util::mod (day_of_baktun, 7200);
    ret->tun_ = floor (day_of_katun/360);
    double day_of_tun = util::mod (day_of_katun, 360);
    ret->uinal_ = floor (day_of_tun/20);
    ret->kin_ = util::mod (day_of_tun, 20);   
    return c;
  }

  static bool is_mayan (Calendar* c)
  {
    return (dynamic_cast<Mayan*> (c) != 0);
  }

  void Mayan::destroy (Calendar* c)
  {   
    if (is_mayan (c)) delete c;
  }

}
