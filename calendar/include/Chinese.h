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
namespace calendar { class ChineseName; }
namespace calendar { class Location; }

namespace calendar
{

	class Chinese : public Date
	{
	public:
		long long cycle = 0;
		int year = 0;
		int month = 0;
		bool leapMonth = false;
		int day = 0;
		static const long long EPOCH = 0;
		static constexpr int DAY_NAME_EPOCH = 15;
		static constexpr int MONTH_NAME_EPOCH = 3;
		static const std::vector<std::wstring> yearStemNames;
		static const std::vector<std::wstring> yearBranchNames;

		private:
			class StaticConstructor
			{
			public:
				StaticConstructor();
			};

		private:
			static Chinese::StaticConstructor staticConstructor;


	public:
		Chinese();

		Chinese(long long const date);

		Chinese(Date const date);

		Chinese(long long const cycle, int const year, int const month, bool const leapMonth, int const day);

		static long long toFixed(long long const cycle, int const year, int const month, bool const leapMonth, int const day);

		long long toFixed() override;

		void fromFixed(long long const date) override;

		void fromArray(std::vector<int> &a) override;

		static double solarLongitudeOnOrAfter(long long const date, double const theta);

		static double midnightInChina(long long const date);

		static long long winterSolsticeOnOrBefore(long long const date);

		static long long newYearInSui(long long const date);

		static long long newYearOnOrBefore(long long const date);

		static int nameDifference(ChineseName *const name1, ChineseName *const name2);

		static long long dayNameOnOrBefore(ChineseName *const name, long long const date);

		static int currentMajorSolarTerm(long long const date);

		static double majorSolarTermOnOrAfter(long long const date);

		static int currentMinorSolarTerm(long long const date);

		static double minorSolarTermOnOrAfter(long long const date);

		static long long newMoonBefore(long long const date);

		static long long newMoonOnOrAfter(long long const date);

		static bool hasNoMajorSolarTerm(long long const date);

		static bool hasPriorLeapMonth(long long const mPrime, long long const m);

		static ChineseName *sexagesimalName(long long const n);

		static ChineseName *nameOfYear(int const year);

		static ChineseName *nameOfMonth(int const year, int const month);

		static ChineseName *nameOfDay(long long const fixed);

		static Location *beijing(double const tee) final;

		static Location *chineseLocation(double const tee) final;

		static Location *tokyo(double const date) final;

		static Location *japaneseLocation(double const date) final;

		static long long newYear(long long const gYear);

		static long long dragonFestival(long long const gYear);

		static long long qingMing(long long const gYear);

		static long long age(Chinese *const birthdate, long long const date);

	protected:
		std::wstring toStringFields() override;

	public:
		std::wstring format() override;

		virtual bool equals(std::any const obj);
	};

}
