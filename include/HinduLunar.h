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

#include "Date.h"
#include <string>
#include <vector>
#include <cmath>
#include <any>
#include <optional>
#include "stringhelper.h"

namespace calendar { class Date; }
namespace calendar { class FixedVector; }

namespace calendar
{

	class HinduLunar : public Date
	{
	public:
		long long year = 0;
		int month = 0;
		bool leapMonth = false;
		int day = 0;
		bool leapDay = false;
		static constexpr int LUNAR_ERA = 3044;
		static constexpr double SYNODIC_MONTH = 29.53058794607172;
		static constexpr double SIDEREAL_MONTH = 27.321674162683866;
		static constexpr double ANOMALISTIC_MONTH = 27.554597974680476;

		HinduLunar();

		HinduLunar(long long const date);

		HinduLunar(Date const date);

		HinduLunar(long long const year, int const month, bool const leapMonth, int const day, bool const leapDay);

		static long long toFixed(long long const year, int const month, bool const leapMonth, int const day, bool const leapDay);

		long long toFixed() override;

		void fromFixed(long long const date) override;

		void fromArray(std::vector<int> &a) override;

		static double newMoonBefore(double const tee);

		static bool onOrBefore(HinduLunar *const d1, HinduLunar *const d2);

		static double lunarDayAfter(double const tee, double const k);

		static double lunarLongitude(double const tee);

		static double lunarPhase(double const tee);

		static int lunarDay(double const tee);

		static int lunarStation(long long const date);

		static long long newYear(long long const gYear);

		static int karana(int const n);

		static int yoga(long long const date);

		static FixedVector *sacredWednesdaysInGregorian(long long const gYear);

		static FixedVector *sacredWednesdays(long long const start, long long const end);

	protected:
		std::wstring toStringFields() override;

	public:
		std::wstring format() override;

		virtual bool equals(std::any const obj);
	};

}
