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

namespace calendar { class Date; }

namespace calendar
{

	class OldHinduSolar : public StandardDate
	{
	public:
		static const long long EPOCH = 0;
		static constexpr double ARYA_SOLAR_YEAR = 365.25868055555554;
		static constexpr double ARYA_SOLAR_MONTH = 30.43822337962963;
		static constexpr double ARYA_JOVIAN_PERIOD = 4332.27217316816;
		static const std::vector<std::wstring> dayOfWeekNames;
		static const std::vector<std::wstring> monthNames;

		private:
			class StaticConstructor
			{
			public:
				StaticConstructor();
			};

		private:
			static OldHinduSolar::StaticConstructor staticConstructor;


	public:
		OldHinduSolar();

		OldHinduSolar(long long const date);

		OldHinduSolar(Date const date);

		OldHinduSolar(long long const year, int const month, int const day);

		static long long toFixed(long long const year, int const month, int const day);

		long long toFixed() override;

		void fromFixed(long long const date) override;

		static long long dayCount(long long const date);

		static double dayCount(double const date);

		static int jovianYear(long long const date);

		std::wstring format() override;

		virtual bool equals(std::any const obj);
	};

}
