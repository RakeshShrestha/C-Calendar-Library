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

#include "HinduLunar.h"
#include "OldHinduSolar.h"
#include "HinduSolar.h"
#include "ProtoDate.h"
#include "Gregorian.h"
#include "FixedVector.h"
#include "OldHinduLunar.h"

namespace calendar
{

	HinduLunar::HinduLunar()
	{
	}

	HinduLunar::HinduLunar(long long const date) : Date(date)
	{
	}

	HinduLunar::HinduLunar(Date const date) : Date(date)
	{
	}

	HinduLunar::HinduLunar(long long const year, int const month, bool const leapMonth, int const day, bool const leapDay)
	{
		this->year = year;
		this->month = month;
		this->leapMonth = leapMonth;
		this->day = day;
		this->leapDay = leapDay;
	}

	long long HinduLunar::toFixed(long long const year, int const month, bool const leapMonth, int const day, bool const leapDay)
	{
		HinduLunar tempVar(year, month, leapMonth, day, leapDay);
		return (&tempVar)->toFixed();
	}

	long long HinduLunar::toFixed()
	{
		constexpr double approx = OldHinduSolar::EPOCH + 365.2587564814815 * (this->year + 3044LL + (this->month - 1) / 12.0);
		constexpr long long s = static_cast<long long>(std::floor(approx - 1.0 / ProtoDate::deg(360.0) * 365.2587564814815 * (ProtoDate::mod(HinduSolar::solarLongitude(approx) - (this->month - 1) * ProtoDate::deg(30.0) + ProtoDate::deg(180.0), ProtoDate::deg(360.0)) - 180.0)));
		constexpr int k = lunarDay(s + 0.25);
		long long x;
		if (3 < k && k < 27)
		{
			x = k;
		}
		else
		{
			HinduLunar * const mid = new HinduLunar(s - 15LL);
			if (mid->month < this->month || (mid->leapMonth && !this->leapMonth))
			{
				x = ProtoDate::mod(k + 15, 30) - 15;
			}
			else
			{
				x = ProtoDate::mod(k - 15, 30) + 15;
			}
		}
		constexpr long long est = s + this->day - x;
		constexpr long long tau = est - ProtoDate::mod(lunarDay(est + 0.25) - this->day + 15, 30) + 15LL;
		long long date;
		for (date = tau - 1LL; !onOrBefore(this, new HinduLunar(date)); ++date)
		{
		}
		return date;
	}

	void HinduLunar::fromFixed(long long const date)
	{
		constexpr double critical = HinduSolar::sunrise(date);
		this->day = lunarDay(critical);
		this->leapDay = (this->day == lunarDay(HinduSolar::sunrise(date - 1LL)));
		constexpr double lastNewMoon = newMoonBefore(critical);
		constexpr double nextNewMoon = newMoonBefore(std::floor(lastNewMoon) + 35.0);
		constexpr int solarMonth = HinduSolar::zodiac(lastNewMoon);
		this->leapMonth = (solarMonth == HinduSolar::zodiac(nextNewMoon));
		this->month = ProtoDate::adjustedMod(solarMonth + 1, 12);
		this->year = HinduSolar::calendarYear(nextNewMoon) - 3044LL - ((this->leapMonth && this->month == 1) ? -1 : 0);
	}

	void HinduLunar::fromArray(std::vector<int> &a)
	{
		this->year = a[0];
		this->month = a[1];
		this->leapMonth = (a[2] != 0);
		this->day = a[3];
		this->leapDay = (a[4] != 0);
	}

	double HinduLunar::newMoonBefore(double const tee)
	{
		constexpr double varepsilon = std::pow(2.0, -34.0);
		constexpr double tau = tee - 1.0 / ProtoDate::deg(360.0) * lunarPhase(tee) * 29.53058794607172;
		constexpr double l = tau - 1.0;
		constexpr double u = std::min(tee, tau + 1.0);
		double lo = l;
		double hi = u;
		double x = (hi + lo) / 2.0;
		while (HinduSolar::zodiac(lo) != HinduSolar::zodiac(hi) && hi - lo >= varepsilon)
		{
			if (lunarPhase(x) < ProtoDate::deg(180.0))
			{
				hi = x;
			}
			else
			{
				lo = x;
			}
			x = (hi + lo) / 2.0;
		}
		return x;
	}

	bool HinduLunar::onOrBefore(HinduLunar *const d1, HinduLunar *const d2)
	{
		return d1->year < d2->year || (d1->year == d2->year && (d1->month < d2->month || (d1->month == d2->month && ((d1->leapMonth && !d2->leapMonth) || (d1->leapMonth == d2->leapMonth && (d1->day < d2->day || (d1->day == d2->day && (!d1->leapDay || d2->leapDay))))))));
	}

	double HinduLunar::lunarDayAfter(double const tee, double const k)
	{
		constexpr double varepsilon = std::pow(2.0, -17.0);
		constexpr double phase = (k - 1.0) * 12.0;
		constexpr double tau = tee + 0.002777777777777778 * ProtoDate::mod(phase - lunarPhase(tee), ProtoDate::deg(360.0)) * 29.53058794607172;
		constexpr double l = std::max(tee, tau - 2.0);
		constexpr double u = tau + 2.0;
		double lo = l;
		double hi = u;
		double x = (hi + lo) / 2.0;
		while (hi - lo >= varepsilon)
		{
			if (ProtoDate::mod(lunarPhase(x) - phase, 360.0) < ProtoDate::deg(180.0))
			{
				hi = x;
			}
			else
			{
				lo = x;
			}
			x = (hi + lo) / 2.0;
		}
		return x;
	}

	double HinduLunar::lunarLongitude(double const tee)
	{
		return HinduSolar::truePosition(tee, 27.321674162683866, 0.08888888888888889, 27.554597974680476, 0.010416666666666666);
	}

	double HinduLunar::lunarPhase(double const tee)
	{
		return ProtoDate::mod(lunarLongitude(tee) - HinduSolar::solarLongitude(tee), 360.0);
	}

	int HinduLunar::lunarDay(double const tee)
	{
		return static_cast<int>(ProtoDate::quotient(lunarPhase(tee), ProtoDate::deg(12.0))) + 1;
	}

	int HinduLunar::lunarStation(long long const date)
	{
		constexpr double critical = HinduSolar::sunrise(date);
		return static_cast<int>(ProtoDate::quotient(lunarLongitude(critical), ProtoDate::deg(800.0) / 60.0)) + 1;
	}

	long long HinduLunar::newYear(long long const gYear)
	{
		constexpr long long jan1 = Gregorian::toFixed(gYear, 1, 1);
		constexpr double mina = HinduSolar::solarLongitudeAfter(static_cast<double>(jan1), ProtoDate::deg(330.0));
		constexpr double newMoon = lunarDayAfter(mina, 1.0);
		constexpr long long hDay = static_cast<long long>(std::floor(newMoon));
		constexpr double critical = HinduSolar::sunrise(hDay);
		return hDay + ((newMoon >= critical && lunarDay(HinduSolar::sunrise(hDay + 1LL)) != 2) ? 1 : 0);
	}

	int HinduLunar::karana(int const n)
	{
		if (n == 1)
		{
			return 0;
		}
		if (n > 57)
		{
			return n - 50;
		}
		return ProtoDate::adjustedMod(n - 1, 7);
	}

	int HinduLunar::yoga(long long const date)
	{
		return static_cast<int>(std::floor(ProtoDate::mod((HinduSolar::solarLongitude(static_cast<double>(date)) + lunarLongitude(static_cast<double>(date))) * 60.0 / 800.0, ProtoDate::deg(27.0)))) + 1;
	}

	FixedVector *HinduLunar::sacredWednesdaysInGregorian(long long const gYear)
	{
		return sacredWednesdays(Gregorian::toFixed(gYear, 1, 1), Gregorian::toFixed(gYear, 12, 31));
	}

	FixedVector *HinduLunar::sacredWednesdays(long long const start, long long const end)
	{
		long long wed = ProtoDate::kDayOnOrAfter(start, 3);
		FixedVector * const result = new FixedVector();
		while (wed <= end)
		{
			HinduLunar * const hDate = new HinduLunar(wed);
			if (hDate->day == 8)
			{
				result->addFixed(wed);
			}
			wed += 7LL;
		}
		return result;
	}

	std::wstring HinduLunar::toStringFields()
	{
		return L"year=" + std::to_wstring(this->year) + L",month=" + std::to_wstring(this->month) + L",leapMonth=" + StringHelper::toString(this->leapMonth) + L",day=" + std::to_wstring(this->day) + L",leapDay=" + StringHelper::toString(this->leapDay);
	}

	std::wstring HinduLunar::format()
	{
		return MessageFormat::format(L"{0}, {1}{2} {3}{4} {5,number,#} V.E.", ProtoDate::nameFromDayOfWeek(this->toFixed(), OldHinduLunar::dayOfWeekNames), std::optional<int>(this->day), this->leapDay ? L" II" : L"", ProtoDate::nameFromMonth(this->month, OldHinduLunar::monthNames), this->leapMonth ? L" II" : L"", std::optional<long long>(this->year));
	}

	bool HinduLunar::equals(std::any const obj)
	{
		if (this == obj)
		{
			return true;
		}
		if (!(obj.type() == typeid(HinduLunar)))
		{
			return false;
		}
		HinduLunar * const o = std::any_cast<HinduLunar*>(obj);
		return o->year == this->year && o->month == this->month && o->leapMonth == this->leapMonth && o->day == this->day && o->leapDay == this->leapDay;
	}
}
