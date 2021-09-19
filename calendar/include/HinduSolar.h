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

#pragma once

#include "StandardDate.h"
#include <string>
#include <vector>
#include <cmath>
#include <any>
#include <optional>

namespace calendar { class Location; }
namespace calendar { class Date; }

namespace calendar
{

	class HinduSolar : public StandardDate
	{
	public:
		static constexpr double SIDEREAL_YEAR = 365.2587564814815;
		static const double CREATION;
		static constexpr double ANOMALISTIC_YEAR = 365.25878920258134;
		static constexpr int SOLAR_ERA = 3179;
		static Location *const UJJAIN;
		static Location *const HINDU_LOCALE;
	private:
		static const std::vector<double> rs;

		private:
			class StaticConstructor
			{
			public:
				StaticConstructor();
			};

		private:
			static HinduSolar::StaticConstructor staticConstructor;


	public:
		HinduSolar();

		HinduSolar(long long const date);

		HinduSolar(Date const date);

		HinduSolar(long long const year, int const month, int const day);

		static long long toFixed(long long const year, int const month, int const day);

		long long toFixed() override;

		void fromFixed(long long const date) override;

		static double hinduSineTable(int const entry);

		static double hinduSine(double const theta);

		static double hinduArcsin(double amp);

		static double meanPosition(double const tee, double const period);

		static double truePosition(double const tee, double const period, double const size, double const anomalistic, double const change);

		static double solarLongitude(double const tee);

		static int zodiac(double const tee);

		static bool onOrBefore(HinduSolar *const d1, HinduSolar *const d2);

		static long long calendarYear(double const tee);

		static double equationOfTime(long long const date);

		static double ascensionalDifference(long long const date, Location *const locale);

		static double tropicalLongitude(long long const date);

		static double risingSign(long long const date);

		static double dailyMotion(long long const date);

		static double solarSiderealDifference(long long const date);

		static double sunrise(long long const date);

		static double altSunrise(long long const date);

		static double solarLongitudeAfter(double const tee, double const phi);

		static double meshaSamkranti(long long const gYear);

		std::wstring format() override;

		virtual bool equals(std::any const obj);
	};

}
