# Copyright Rakesh Shrestha (rakesh.shrestha@gmail.com)
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# Redistributions must retain the above copyright notice.

namespace calendar {
  class Mayan : public Calendar
  {
  public:
    Mayan () : baktun_ (BAKTUN),
               katun_ (KATUN), tun_ (TUN),
               uinal_ (UINAL), kin_ (KIN) { }
    Mayan (double baktun, double katun,
           double tun, double uinal,
           double kin) : baktun_ (baktun),
                         katun_ (katun), tun_ (tun),
                         uinal_ (uinal), kin_ (kin) { }
    Mayan (const Calendar& c) : baktun_ (BAKTUN),
                                katun_ (KATUN), tun_ (TUN),
                                uinal_ (UINAL), kin_ (KIN)
    {
      Mayan *e = dynamic_cast<Mayan*> (create_from_fixed (c.to_fixed_date ()));
      *this = *e;
      destroy (e);
    }


    virtual double to_fixed_date () const;
    virtual Calendar* create_from_fixed (double date);
    virtual Calendar* update_from_fixed (double date, Calendar* c);
    virtual void destroy (Calendar* c);

    virtual bool operator== (const Calendar& c) const
    {
      const Mayan& ca = dynamic_cast<const Mayan&> (c);
      return (baktun_ == ca.baktun_ && katun_ == ca.katun_
              && tun_ == ca.tun_ && uinal_ == ca.uinal_
              && kin_ == ca.kin_);
    }

    virtual void print (std::ostream& out) const
    {
      out << baktun_ << ' ' << katun_ << ' '
          << tun_ << ' ' << uinal_ << ' '
          << kin_;
    }

    virtual double nth_kday (double n, double k) const
    {
      throw "Not implemented.";
    }

    virtual bool is_leap_year () const
    {
      throw "Not implemented.";
    }

    double baktun () const { return baktun_; }
    double katun () const { return katun_; }
    double tun () const { return tun_; }
    double uinal () const { return uinal_; }
    double kin () const { return kin_; }

    static const double KIN;
    static const double UINAL;
    static const double TUN;
    static const double KATUN;
    static const double BAKTUN;
  private:
    static const int RD;    
    double baktun_;
    double katun_;
    double tun_;
    double uinal_;
    double kin_;
  };  
}

#endif // MAYAN_H_
