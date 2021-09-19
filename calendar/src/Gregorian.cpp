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

#include "Gregorian.h"
#include "Date.h"
#include "ProtoDate.h"

namespace calendar
{

	const std::vector<std::wstring> Gregorian::dayOfWeekNames;
	const std::vector<std::wstring> Gregorian::monthNames;

	Gregorian::StaticConstructor::StaticConstructor()
	{
		dayOfWeekNames = std::vector<std::wstring> {L"Sunday", L"Monday", L"Tuesday", L"Wednesday", L"Thursday", L"Friday", L"Saturday"};
		monthNames = std::vector<std::wstring> {L"January", L"February", L"March", L"April", L"May", L"June", L"July", L"August", L"September", L"October", L"November", L"December"};
	}

	Gregorian::StaticConstructor Gregorian::staticConstructor;

	Gregorian::Gregorian()
	{
	}

	Gregorian::Gregorian(long long const date) : StandardDate(date)
	{
	}

	Gregorian::Gregorian(Date const date) : StandardDate(date)
	{
	}

	Gregorian::Gregorian(long long const year, int const month, int const day) : StandardDate(year, month, day)
	{
	}

	long long Gregorian::toFixed(long long const year, int const month, int const day)
	{
		return 0LL + 365LL * (year - 1LL) + ProtoDate::quotient(static_cast<double>(year - 1LL), 4.0) - ProtoDate::quotient(static_cast<double>(year - 1LL), 100.0) + ProtoDate::quotient(static_cast<double>(year - 1LL), 400.0) + ProtoDate::quotient(367 * month - 362, 12.0) + ((month <= 2) ? 0 : (isLeapYear(year) ? -1 : -2)) + day;
	}

	long long Gregorian::toFixed()
	{
		return toFixed(this->year, this->month, this->day);
	}

	void Gregorian::fromFixed(long long const date)
	{
		this->year = yearFromFixed(date);
		constexpr long long priorDays = date - toFixed(this->year, 1, 1);
		constexpr int correction = (date < toFixed(this->year, 3, 1)) ? 0 : (isLeapYear(this->year) ? 1 : 2);
		this->month = static_cast<int>(ProtoDate::quotient(static_cast<double>(12LL * (priorDays + correction) + 373LL), 367.0));
		this->day = static_cast<int>(date - toFixed(this->year, this->month, 1) + 1LL);
	}

	long long Gregorian::altFixedFromGregorian(long long const year, int const month, int const day)
	{
		constexpr long long m = ProtoDate::adjustedMod(month - 2, 12);
		constexpr long long y = year + ProtoDate::quotient(month + 9, 12.0);
		return -306LL + 365LL * (y - 1LL) + ProtoDate::quotient(static_cast<double>(y - 1LL), 4.0) - ProtoDate::quotient(static_cast<double>(y - 1LL), 100.0) + ProtoDate::quotient(static_cast<double>(y - 1LL), 400.0) + ProtoDate::quotient(static_cast<double>(3LL * m - 1LL), 5.0) + 30LL * (m - 1LL) + day;
	}

	void Gregorian::altGregorianFromFixed(long long const date)
	{
		constexpr long long y = yearFromFixed(0LL + date + 306LL);
		constexpr long long priorDays = date - toFixed(y - 1LL, 3, 1);
		this->month = static_cast<int>(ProtoDate::adjustedMod(ProtoDate::quotient(static_cast<double>(5LL * priorDays + 155LL), 153.0) + 2LL, 12LL));
		this->year = y - ProtoDate::quotient(this->month + 9, 12.0);
		this->day = static_cast<int>(1LL + date - toFixed(this->year, this->month, 1));
	}

	bool Gregorian::isLeapYear(long long const gYear)
	{
		bool result = false;
		if (ProtoDate::mod(gYear, 4LL) == 0LL)
		{
			constexpr long long n = ProtoDate::mod(gYear, 400LL);
			if (n != 100LL && n != 200LL && n != 300LL)
			{
				result = true;
			}
		}
		return result;
	}

	long long Gregorian::yearFromFixed(long long const date)
	{
		constexpr long long l0 = date - 1LL;
		constexpr long long n400 = ProtoDate::quotient(static_cast<double>(l0), 146097.0);
		constexpr long long d1 = ProtoDate::mod(l0, 146097LL);
		constexpr long long n401 = ProtoDate::quotient(static_cast<double>(d1), 36524.0);
		constexpr long long d2 = ProtoDate::mod(d1, 36524LL);
		constexpr long long n402 = ProtoDate::quotient(static_cast<double>(d2), 1461.0);
		constexpr long long d3 = ProtoDate::mod(d2, 1461LL);
		constexpr long long n403 = ProtoDate::quotient(static_cast<double>(d3), 365.0);
		constexpr long long year = 400LL * n400 + 100LL * n401 + 4LL * n402 + n403;
		return (n401 == 4LL || n403 == 4LL) ? year : (year + 1LL);
	}

	long long Gregorian::altGregorianYearFromFixed(long long const date)
	{
		constexpr long long approx = ProtoDate::quotient(static_cast<double>(date - 1LL + 2LL), 365.2425);
		constexpr long long start = 1LL + 365LL * approx + ProtoDate::quotient(static_cast<double>(approx), 4.0) - ProtoDate::quotient(static_cast<double>(approx), 100.0) + ProtoDate::quotient(static_cast<double>(approx), 400.0);
		return (date < start) ? approx : (approx + 1LL);
	}

	int Gregorian::lastDayOfMonth()
	{
		switch (this->month)
		{
			case 2:
			{
				if (isLeapYear(this->year))
				{
					return 29;
				}
				return 28;
			}
			case 4:
			case 6:
			case 9:
			case 11:
			{
				return 30;
			}
			default:
			{
				return 31;
			}
		}
	}

	long long Gregorian::dayNumber()
	{
		return ProtoDate::difference(toFixed(this->year - 1LL, 12, 31), this->toFixed());
	}

	long long Gregorian::daysRemaining()
	{
		return ProtoDate::difference(this->toFixed(), toFixed(this->year, 12, 31));
	}

	long long Gregorian::independenceDay(long long const gYear)
	{
		return toFixed(gYear, 7, 4);
	}

	long long Gregorian::laborDay(long long const gYear)
	{
		return ProtoDate::firstKDay(1, toFixed(gYear, 9, 1));
	}

	long long Gregorian::memorialDay(long long const gYear)
	{
		return ProtoDate::lastKDay(1, toFixed(gYear, 5, 31));
	}

	long long Gregorian::electionDay(long long const gYear)
	{
		return ProtoDate::firstKDay(2, toFixed(gYear, 11, 2));
	}

	long long Gregorian::daylightSavingStart(long long const gYear)
	{
		return ProtoDate::firstKDay(0, toFixed(gYear, 4, 1));
	}

	long long Gregorian::daylightSavingEnd(long long const gYear)
	{
		return ProtoDate::lastKDay(0, toFixed(gYear, 10, 31));
	}

	long long Gregorian::christmas(long long const gYear)
	{
		return toFixed(gYear, 12, 25);
	}

	long long Gregorian::advent(long long const gYear)
	{
		return ProtoDate::kDayNearest(toFixed(gYear, 11, 30), 0);
	}

	long long Gregorian::epiphany(long long const gYear)
	{
		return ProtoDate::firstKDay(0, toFixed(gYear, 1, 2));
	}

	std::wstring Gregorian::format()
	{
		return MessageFormat::format(L"{0}, {1} {2} {3,number,#}", ProtoDate::nameFromDayOfWeek(this->toFixed(), Gregorian::dayOfWeekNames), std::optional<int>(this->day), ProtoDate::nameFromMonth(this->month, Gregorian::monthNames), std::optional<long long>(this->year));
	}

	bool Gregorian::equals(std::any const obj)
	{
		return obj.type() == typeid(Gregorian) && this->internalEquals(obj);
	}
}
