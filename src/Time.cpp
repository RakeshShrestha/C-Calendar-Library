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

#include "Time.h"
#include "ProtoDate.h"

namespace calendar
{

	Time::Time()
	{
	}

	Time::Time(double const moment)
	{
		this->fromMoment(moment);
	}

	Time::Time(int const hour, int const minute, double const second)
	{
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}

	double Time::toMoment(int const hour, int const minute, double const second)
	{
		return hour / 24.0 + minute / 1440.0 + second / 86400.0;
	}

	double Time::toMoment()
	{
		return toMoment(this->hour, this->minute, this->second);
	}

	void Time::fromMoment(double const tee)
	{
		this->hour = static_cast<int>(std::floor(ProtoDate::mod(tee * 24.0, 24.0)));
		this->minute = static_cast<int>(std::floor(ProtoDate::mod(tee * 24.0 * 60.0, 60.0)));
		this->second = ProtoDate::mod(tee * 24.0 * 60.0 * 60.0, 60.0);
	}

	std::wstring Time::toString()
	{
		return std::wstring::valueOf(this->getClass().getName()) + L"[hour=" + std::to_wstring(this->hour) + L",minute=" + std::to_wstring(this->minute) + L",second=" + std::to_wstring(this->second) + L"]";
	}

	std::wstring Time::format()
	{
		constexpr int modHour = ProtoDate::mod(this->hour, 12);
		constexpr int aHour = (modHour == 0) ? 12 : modHour;
		return MessageFormat::format(L"{0,number,00}:{1,number,00}:{2,number,00} {3}", std::optional<int>(aHour), std::optional<int>(this->minute), std::optional<int>(static_cast<int>(this->second)), (ProtoDate::mod(this->hour, 24) < 12) ? L"A.M." : L"P.M.");
	}

	bool Time::equals(std::any const obj)
	{
		if (this == obj)
		{
			return true;
		}
		if (!(obj.type() == typeid(Time)))
		{
			return false;
		}
		Time * const o = std::any_cast<Time*>(obj);
		return o->hour == this->hour && o->minute == this->minute && o->second == this->second;
	}
}
