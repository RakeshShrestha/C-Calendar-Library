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

namespace calendar
{

	class OldHinduLunar : public Date
	{
	public:
		long long year = 0;
		int month = 0;
		bool leapMonth = false;
		int day = 0;
		static constexpr double ARYA_LUNAR_MONTH = 29.530581807581694;
		static constexpr double ARYA_LUNAR_DAY = 0.9843527269193898;
		static const std::vector<std::wstring> dayOfWeekNames;
		static const std::vector<std::wstring> monthNames;

		private:
			class StaticConstructor
			{
			public:
				StaticConstructor();
			};

		private:
			static OldHinduLunar::StaticConstructor staticConstructor;


	public:
		OldHinduLunar();

		OldHinduLunar(long long const date);

		OldHinduLunar(Date const date);

		OldHinduLunar(long long const year, int const month, bool const leapMonth, int const day);

		static long long toFixed(long long const year, int const month, bool const leapMonth, int const day);

		long long toFixed() override;

		void fromFixed(long long const date) override;

		void fromArray(std::vector<int> &a) override;

		static bool isLeapYear(long long const lYear);

	protected:
		std::wstring toStringFields() override;

	public:
		std::wstring format() override;

		virtual bool equals(std::any const obj);
	};

}
