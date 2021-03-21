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

#include <string>
#include <cmath>
#include <any>
#include <optional>

namespace calendar
{

	class Time
	{
	public:
		int hour = 0;
		int minute = 0;
		double second = 0;

		Time();

		Time(double const moment);

		Time(int const hour, int const minute, double const second);

		static double toMoment(int const hour, int const minute, double const second);

		virtual double toMoment();

		virtual void fromMoment(double const tee);

		virtual std::wstring toString();

		virtual std::wstring format();

		virtual bool equals(std::any const obj);
	};

}
