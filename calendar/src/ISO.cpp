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

#include "ISO.h"
#include "Gregorian.h"
#include "ProtoDate.h"

namespace calendar
{

	ISO::ISO()
	{
	}

	ISO::ISO(long long const date) : Date(date)
	{
	}

	ISO::ISO(Date const date) : Date(date)
	{
	}

	ISO::ISO(long long const year, int const week, int const day)
	{
		this->year = year;
		this->week = week;
		this->day = day;
	}

	long long ISO::toFixed(long long const year, int const week, int const day)
	{
		return ProtoDate::nthKDay(week, 0, Gregorian::toFixed(year - 1LL, 12, 28)) + day;
	}

	long long ISO::toFixed()
	{
		return toFixed(this->year, this->week, this->day);
	}

	void ISO::fromFixed(long long const date)
	{
		constexpr long long approx = Gregorian::yearFromFixed(date - 3LL);
		this->year = ((date >= toFixed(approx + 1LL, 1, 1)) ? (approx + 1LL) : approx);
		this->week = static_cast<int>(ProtoDate::quotient(static_cast<double>(date - toFixed(this->year, 1, 1)), 7.0)) + 1;
		this->day = static_cast<int>(ProtoDate::adjustedMod(date, 7LL));
	}

	void ISO::fromArray(std::vector<int> &a)
	{
		this->year = a[0];
		this->week = a[1];
		this->day = a[2];
	}

	std::wstring ISO::toStringFields()
	{
		return L"year=" + std::to_wstring(this->year) + L",week=" + std::to_wstring(this->week) + L",day=" + std::to_wstring(this->day);
	}

	std::wstring ISO::format()
	{
		return MessageFormat::format(L"{0}, Week {1}, {2,number,#}", ProtoDate::nameFromDayOfWeek(this->toFixed(), Gregorian::dayOfWeekNames), std::optional<int>(this->week), std::optional<long long>(this->year));
	}

	bool ISO::equals(std::any const obj)
	{
		if (this == obj)
		{
			return true;
		}
		if (!(obj.type() == typeid(ISO)))
		{
			return false;
		}
		ISO * const o = std::any_cast<ISO*>(obj);
		return o->year == this->year && o->week == this->week && o->day == this->day;
	}
}
