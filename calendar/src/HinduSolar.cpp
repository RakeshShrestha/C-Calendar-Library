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

#include "HinduSolar.h"
#include "Location.h"
#include "OldHinduSolar.h"
#include "ProtoDate.h"
#include "Date.h"
#include "TimeException.h"
#include "Gregorian.h"
#include "OldHinduLunar.h"

namespace calendar
{

	const double HinduSolar::CREATION = 0;
	Location *const HinduSolar::UJJAIN;
	Location *const HinduSolar::HINDU_LOCALE;
	const std::vector<double> HinduSolar::rs;

	HinduSolar::StaticConstructor::StaticConstructor()
	{
		CREATION = OldHinduSolar::EPOCH - 7.14402296627E11;
		UJJAIN = new Location(L"Ujjain, India", ProtoDate::angle(23.0, 9.0, 0.0), ProtoDate::angle(75.0, 46.0, 0.0), ProtoDate::mt(0.0), 5.051222222222222);
		HINDU_LOCALE = HinduSolar::UJJAIN;
		rs = std::vector<double> {0.9277777777777778, 0.9972222222222222, 1.075, 1.075, 0.9972222222222222, 0.9277777777777778};
	}

	HinduSolar::StaticConstructor HinduSolar::staticConstructor;

	HinduSolar::HinduSolar()
	{
	}

	HinduSolar::HinduSolar(long long const date) : StandardDate(date)
	{
	}

	HinduSolar::HinduSolar(Date const date) : StandardDate(date)
	{
	}

	HinduSolar::HinduSolar(long long const year, int const month, int const day) : StandardDate(year, month, day)
	{
	}

	long long HinduSolar::toFixed(long long const year, int const month, int const day)
	{
		HinduSolar tempVar(year, month, day);
		return (&tempVar)->toFixed();
	}

	long long HinduSolar::toFixed()
	{
		constexpr long long approx = static_cast<long long>(std::floor((this->year + 3179LL + (this->month - 1) / 12.0) * 365.2587564814815)) + OldHinduSolar::EPOCH + this->day - 1LL;
		constexpr double rate = ProtoDate::deg(360.0) / 365.2587564814815;
		constexpr double phi = (this->month - 1) * ProtoDate::deg(30.0) + (this->day - 1) * rate;
		constexpr double capDelta = ProtoDate::mod(solarLongitude(approx + 0.25) - phi + ProtoDate::deg(180.0), 360.0) - ProtoDate::deg(180.0);
		constexpr long long tau = approx - static_cast<long long>(std::ceil(capDelta / rate));
		long long date;
		for (date = tau - 2LL; !onOrBefore(this, new HinduSolar(date)); ++date)
		{
		}
		return date;
	}

	void HinduSolar::fromFixed(long long const date)
	{
		constexpr double critical = sunrise(date + 1LL);
		this->month = zodiac(critical);
		this->year = calendarYear(critical) - 3179LL;
		long long begin;
		for (long long approx = begin = date - 3LL - static_cast<long long>(ProtoDate::mod(std::floor(solarLongitude(critical)), ProtoDate::deg(30.0))); zodiac(sunrise(1LL + begin)) != this->month; ++begin)
		{
		}
		this->day = static_cast<int>(date - begin + 1LL);
	}

	double HinduSolar::hinduSineTable(int const entry)
	{
		constexpr double exact = 3438.0 * ProtoDate::sinDegrees(entry * 225.0 / 60.0);
		constexpr double error = 0.215 * ProtoDate::signum(exact) * ProtoDate::signum(std::abs(exact) - 1716.0);
		return static_cast<long long>(std::round(exact + error)) / 3438.0;
	}

	double HinduSolar::hinduSine(double const theta)
	{
		constexpr double entry = theta * 60.0 / 225.0;
		constexpr double fraction = ProtoDate::mod(entry, 1.0);
		return fraction * hinduSineTable(static_cast<int>(std::ceil(entry))) + (1.0 - fraction) * hinduSineTable(static_cast<int>(std::floor(entry)));
	}

	double HinduSolar::hinduArcsin(double amp)
	{
		constexpr bool neg = amp < 0.0;
		if (neg)
		{
			amp = -amp;
		}
		int pos;
		for (pos = 0; amp > hinduSineTable(pos); ++pos)
		{
		}
		constexpr double below = hinduSineTable(pos - 1);
		double result = 3.75 * (pos - 1 + (amp - below) / (hinduSineTable(pos) - below));
		if (neg)
		{
			result = -result;
		}
		return result;
	}

	double HinduSolar::meanPosition(double const tee, double const period)
	{
		return ProtoDate::deg(360.0) * ProtoDate::mod((tee - HinduSolar::CREATION) / period, 1.0);
	}

	double HinduSolar::truePosition(double const tee, double const period, double const size, double const anomalistic, double const change)
	{
		constexpr double aLong = meanPosition(tee, period);
		constexpr double offset = hinduSine(meanPosition(tee, anomalistic));
		constexpr double contraction = std::abs(offset) * change * size;
		constexpr double equation = hinduArcsin(offset * (size - contraction));
		return ProtoDate::mod(aLong - equation, 360.0);
	}

	double HinduSolar::solarLongitude(double const tee)
	{
		return truePosition(tee, 365.2587564814815, 0.03888888888888889, 365.25878920258134, 0.023809523809523808);
	}

	int HinduSolar::zodiac(double const tee)
	{
		return static_cast<int>(ProtoDate::quotient(solarLongitude(tee), ProtoDate::deg(30.0))) + 1;
	}

	bool HinduSolar::onOrBefore(HinduSolar *const d1, HinduSolar *const d2)
	{
		return d1->year < d2->year || (d1->year == d2->year && (d1->month < d2->month || (d1->month == d2->month && d1->day <= d2->day)));
	}

	long long HinduSolar::calendarYear(double const tee)
	{
		return static_cast<long long>(std::round((tee - OldHinduSolar::EPOCH) / 365.2587564814815 - solarLongitude(tee) / ProtoDate::deg(360.0)));
	}

	double HinduSolar::equationOfTime(long long const date)
	{
		constexpr double offset = hinduSine(meanPosition(static_cast<double>(date), 365.25878920258134));
		constexpr double equationSun = offset * 3438.0 / 60.0 * (std::abs(offset) / 1080.0 - 0.03888888888888889);
		return dailyMotion(date) * 1.0 / 360.0 * equationSun * 1.0 / 360.0 * 365.2587564814815;
	}

	double HinduSolar::ascensionalDifference(long long const date, Location *const locale)
	{
		constexpr double sinDecl = 0.4063408958696917 * hinduSine(tropicalLongitude(date));
		constexpr double lat = locale->latitude;
		constexpr double diurnalRadius = hinduSine(ProtoDate::deg(90.0) + hinduArcsin(sinDecl));
		constexpr double tanLat = hinduSine(lat) / hinduSine(ProtoDate::deg(90.0) + lat);
		constexpr double earthSine = sinDecl * tanLat;
		return hinduArcsin(-(earthSine / diurnalRadius));
	}

	double HinduSolar::tropicalLongitude(long long const date)
	{
		constexpr long long days = static_cast<long long>(std::floor(static_cast<double>(date - OldHinduSolar::EPOCH)));
		constexpr double precession = ProtoDate::deg(27.0) - std::abs(ProtoDate::deg(54.0) - ProtoDate::mod(ProtoDate::deg(27.0) + ProtoDate::deg(108.0) * 3.80247937727211E-7 * days, 108.0));
		return ProtoDate::mod(solarLongitude(static_cast<double>(date)) - precession, 360.0);
	}

	double HinduSolar::risingSign(long long const date)
	{
		constexpr int index = static_cast<int>(ProtoDate::mod(ProtoDate::quotient(tropicalLongitude(date), ProtoDate::deg(30.0)), 6LL));
		return HinduSolar::rs[index];
	}

	double HinduSolar::dailyMotion(long long const date)
	{
		constexpr double meanMotion = ProtoDate::deg(360.0) / 365.2587564814815;
		constexpr double anomaly = meanPosition(static_cast<double>(date), 365.25878920258134);
		constexpr double epicycle = 0.03888888888888889 - std::abs(hinduSine(anomaly)) / 1080.0;
		constexpr int entry = static_cast<int>(ProtoDate::quotient(anomaly, ProtoDate::deg(225.0) / 60.0));
		constexpr double sineTableStep = hinduSineTable(entry + 1) - hinduSineTable(entry);
		constexpr double factor = sineTableStep * -15.0 * epicycle;
		return meanMotion * (factor + 1.0);
	}

	double HinduSolar::solarSiderealDifference(long long const date)
	{
		return dailyMotion(date) * risingSign(date);
	}

	double HinduSolar::sunrise(long long const date)
	{
		return date + 0.25 + (HinduSolar::UJJAIN->longitude - HinduSolar::HINDU_LOCALE->longitude) / ProtoDate::deg(360.0) + equationOfTime(date) + 0.9972696898509495 / ProtoDate::deg(360.0) * (ascensionalDifference(date, HinduSolar::HINDU_LOCALE) + 0.25 * solarSiderealDifference(date));
	}

	double HinduSolar::altSunrise(long long const date)
	{
		try
		{
			constexpr double rise = ProtoDate::sunrise(date, HinduSolar::UJJAIN);
			return 6.944444444444444E-4 * static_cast<long long>(std::round(rise * 24.0 * 60.0));
		}
		catch (const TimeException &ex)
		{
			return 0.0;
		}
	}

	double HinduSolar::solarLongitudeAfter(double const tee, double const phi)
	{
		constexpr double varepsilon = 1.0E-6;
		constexpr double tau = tee + 1.0146076568930043 * ProtoDate::mod(phi - solarLongitude(tee), ProtoDate::deg(360.0));
		constexpr double l = std::max(tee, tau - 5.0);
		constexpr double u = tau + 5.0;
		double lo = l;
		double hi = u;
		double x = (hi + lo) / 2.0;
		while (hi - lo >= varepsilon)
		{
			if (ProtoDate::mod(solarLongitude(x) - phi, 360.0) < ProtoDate::deg(180.0))
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

	double HinduSolar::meshaSamkranti(long long const gYear)
	{
		constexpr long long jan1 = Gregorian::toFixed(gYear, 1, 1);
		return solarLongitudeAfter(static_cast<double>(jan1), ProtoDate::deg(0.0));
	}

	std::wstring HinduSolar::format()
	{
		return MessageFormat::format(L"{0}, {1} {2} {3,number,#} S.E.", ProtoDate::nameFromDayOfWeek(this->toFixed(), OldHinduSolar::dayOfWeekNames), std::optional<int>(this->day), ProtoDate::nameFromMonth(ProtoDate::adjustedMod(this->month + 1, 12), OldHinduLunar::monthNames), std::optional<long long>(this->year));
	}

	bool HinduSolar::equals(std::any const obj)
	{
		return obj.type() == typeid(HinduSolar) && this->internalEquals(obj);
	}
}
