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
#include <any>
#include <optional>

namespace calendar { class Date; }

namespace calendar
{

	class ISO : public Date
	{
	public:
		long long year = 0;
		int week = 0;
		int day = 0;

		ISO();

		ISO(long long const date);

		ISO(Date const date);

		ISO(long long const year, int const week, int const day);

		static long long toFixed(long long const year, int const week, int const day);

		long long toFixed() override;

		void fromFixed(long long const date) override;

		void fromArray(std::vector<int> &a) override;

	protected:
		std::wstring toStringFields() override;

	public:
		std::wstring format() override;

		virtual bool equals(std::any const obj);
	};

}
