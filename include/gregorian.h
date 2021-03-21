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
#include <any>
#include <optional>

namespace calendar { class Date; }

namespace calendar
{

	class Gregorian : public StandardDate
	{
	public:
		static constexpr long long EPOCH = 1LL;
		static const std::vector<std::wstring> dayOfWeekNames;
		static const std::vector<std::wstring> monthNames;

		private:
			class StaticConstructor
			{
			public:
				StaticConstructor();
			};

		private:
			static Gregorian::StaticConstructor staticConstructor;


	public:
		Gregorian();

		Gregorian(long long const date);

		Gregorian(Date const date);

		Gregorian(long long const year, int const month, int const day);

		static long long toFixed(long long const year, int const month, int const day);

		long long toFixed() override;

		void fromFixed(long long const date) override;

		static long long altFixedFromGregorian(long long const year, int const month, int const day);

		virtual void altGregorianFromFixed(long long const date);

		static bool isLeapYear(long long const gYear);

		static long long yearFromFixed(long long const date);

		static long long altGregorianYearFromFixed(long long const date);

		virtual int lastDayOfMonth();

		virtual long long dayNumber();

		virtual long long daysRemaining();

		static long long independenceDay(long long const gYear);

		static long long laborDay(long long const gYear);

		static long long memorialDay(long long const gYear);

		static long long electionDay(long long const gYear);

		static long long daylightSavingStart(long long const gYear);

		static long long daylightSavingEnd(long long const gYear);

		static long long christmas(long long const gYear);

		static long long advent(long long const gYear);

		static long long epiphany(long long const gYear);

		std::wstring format() override;

		virtual bool equals(std::any const obj);
	};

}
