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
#include <any>
#include <optional>

namespace calendar { class Date; }
namespace calendar { class FixedVector; }

namespace calendar
{

	class Julian : public StandardDate
	{
	public:
		static const long long EPOCH = 0;

		private:
			class StaticConstructor
			{
			public:
				StaticConstructor();
			};

		private:
			static Julian::StaticConstructor staticConstructor;


	public:
		Julian();

		Julian(long long const date);

		Julian(Date const date);

		Julian(long long const year, int const month, int const day);

		static long long toFixed(long long const year, int const month, int const day);

		long long toFixed() override;

		void fromFixed(long long const date) override;

		static long long BCE(long long const n);

		static long long CE(long long const n);

		static bool isLeapYear(long long const jYear);

		static FixedVector *inGregorian(int const jMonth, int const jDay, long long const gYear);

		static FixedVector *easternOrthodoxChristmas(long long const gYear);

		std::wstring format() override;

		virtual bool equals(std::any const obj);
	};

}
