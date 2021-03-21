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

#include "Julian.h"
#include "Gregorian.h"
#include "Date.h"
#include "ProtoDate.h"
#include "FixedVector.h"

namespace calendar
{

	Julian::StaticConstructor::StaticConstructor()
	{
		EPOCH = Gregorian::toFixed(0LL, 12, 30);
	}

	Julian::StaticConstructor Julian::staticConstructor;

	Julian::Julian()
	{
	}

	Julian::Julian(long long const date) : StandardDate(date)
	{
	}

	Julian::Julian(Date const date) : StandardDate(date)
	{
	}

	Julian::Julian(long long const year, int const month, int const day) : StandardDate(year, month, day)
	{
	}

	long long Julian::toFixed(long long const year, int const month, int const day)
	{
		constexpr long long y = (year < 0LL) ? (year + 1LL) : year;
		return Julian::EPOCH - 1LL + 365LL * (y - 1LL) + ProtoDate::quotient(static_cast<double>(y - 1LL), 4.0) + ProtoDate::quotient(367 * month - 362, 12.0) + ((month <= 2) ? 0 : (isLeapYear(year) ? -1 : -2)) + day;
	}

	long long Julian::toFixed()
	{
		return toFixed(this->year, this->month, this->day);
	}

	void Julian::fromFixed(long long const date)
	{
		constexpr long long approx = ProtoDate::quotient(static_cast<double>(4LL * (date - Julian::EPOCH) + 1464LL), 1461.0);
		this->year = ((approx <= 0LL) ? (approx - 1LL) : approx);
		constexpr long long priorDays = date - toFixed(this->year, 1, 1);
		constexpr int correction = (date < toFixed(this->year, 3, 1)) ? 0 : (isLeapYear(this->year) ? 1 : 2);
		this->month = static_cast<int>(ProtoDate::quotient(static_cast<double>(12LL * (priorDays + correction) + 373LL), 367.0));
		this->day = static_cast<int>(date - toFixed(this->year, this->month, 1) + 1LL);
	}

	long long Julian::BCE(long long const n)
	{
		return -n;
	}

	long long Julian::CE(long long const n)
	{
		return n;
	}

	bool Julian::isLeapYear(long long const jYear)
	{
		return ProtoDate::mod(jYear, 4LL) == ((jYear > 0LL) ? 0 : 3);
	}

	FixedVector *Julian::inGregorian(int const jMonth, int const jDay, long long const gYear)
	{
		constexpr long long jan1 = Gregorian::toFixed(gYear, 1, 1);
		constexpr long long dec31 = Gregorian::toFixed(gYear, 12, 31);
		Julian tempVar(jan1);
		constexpr long long y = (&tempVar)->year;
		constexpr long long yPrime = (y == -1LL) ? 1LL : (y + 1LL);
		constexpr long long date1 = toFixed(y, jMonth, jDay);
		constexpr long long date2 = toFixed(yPrime, jMonth, jDay);
		FixedVector * const result = new FixedVector(1, 1);
		if (jan1 <= date1 && date1 <= dec31)
		{
			result->addFixed(date1);
		}
		if (jan1 <= date2 && date2 <= dec31)
		{
			result->addFixed(date2);
		}
		return result;
	}

	FixedVector *Julian::easternOrthodoxChristmas(long long const gYear)
	{
		return inGregorian(12, 25, gYear);
	}

	std::wstring Julian::format()
	{
		return MessageFormat::format(L"{0} {1} {2,number,#} {3}", std::optional<int>(this->day), ProtoDate::nameFromMonth(this->month, Gregorian::monthNames), std::optional<long long>((this->year < 0LL) ? (-this->year) : this->year), (this->year < 0LL) ? L"B.C.E." : L"C.E.");
	}

	bool Julian::equals(std::any const obj)
	{
		return obj.type() == typeid(Julian) && this->internalEquals(obj);
	}
}
