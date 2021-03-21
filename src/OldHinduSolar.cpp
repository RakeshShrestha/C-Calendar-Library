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

#include "OldHinduSolar.h"
#include "Julian.h"
#include "Date.h"
#include "ProtoDate.h"

namespace calendar
{

	const std::vector<std::wstring> OldHinduSolar::dayOfWeekNames;
	const std::vector<std::wstring> OldHinduSolar::monthNames;

	OldHinduSolar::StaticConstructor::StaticConstructor()
	{
		EPOCH = Julian::toFixed(Julian::BCE(3102LL), 2, 18);
		dayOfWeekNames = std::vector<std::wstring> {L"Ravivara", L"Chandravara", L"Mangalavara", L"Buddhavara", L"Brihaspatvara", L"Sukravara", L"Sanivara"};
		monthNames = std::vector<std::wstring> {L"Mesha", L"Vrishabha", L"Mithuna", L"Karka", L"Simha", L"Kanya", L"Tula", L"Vrischika", L"Dhanu", L"Makara", L"Kumbha", L"Mina"};
	}

	OldHinduSolar::StaticConstructor OldHinduSolar::staticConstructor;

	OldHinduSolar::OldHinduSolar()
	{
	}

	OldHinduSolar::OldHinduSolar(long long const date) : StandardDate(date)
	{
	}

	OldHinduSolar::OldHinduSolar(Date const date) : StandardDate(date)
	{
	}

	OldHinduSolar::OldHinduSolar(long long const year, int const month, int const day) : StandardDate(year, month, day)
	{
	}

	long long OldHinduSolar::toFixed(long long const year, int const month, int const day)
	{
		return static_cast<long long>(std::ceil(OldHinduSolar::EPOCH + year * 365.25868055555554 + (month - 1) * 30.43822337962963 + day - 1.25));
	}

	long long OldHinduSolar::toFixed()
	{
		return toFixed(this->year, this->month, this->day);
	}

	void OldHinduSolar::fromFixed(long long const date)
	{
		constexpr double sun = dayCount(date) + 0.25;
		this->year = ProtoDate::quotient(sun, 365.25868055555554);
		this->month = 1 + static_cast<int>(ProtoDate::mod(ProtoDate::quotient(sun, 30.43822337962963), 12LL));
		this->day = 1 + static_cast<int>(std::floor(ProtoDate::mod(sun, 30.43822337962963)));
	}

	long long OldHinduSolar::dayCount(long long const date)
	{
		return date - OldHinduSolar::EPOCH;
	}

	double OldHinduSolar::dayCount(double const date)
	{
		return date - OldHinduSolar::EPOCH;
	}

	int OldHinduSolar::jovianYear(long long const date)
	{
		return 1 + static_cast<int>(ProtoDate::mod(ProtoDate::quotient(static_cast<double>(dayCount(date)), 361.0226810973467), 60LL));
	}

	std::wstring OldHinduSolar::format()
	{
		return MessageFormat::format(L"{0}, {1} {2} {3,number,#} K.Y.", ProtoDate::nameFromDayOfWeek(this->toFixed(), OldHinduSolar::dayOfWeekNames), std::optional<int>(this->day), ProtoDate::nameFromMonth(this->month, OldHinduSolar::monthNames), std::optional<long long>(this->year));
	}

	bool OldHinduSolar::equals(std::any const obj)
	{
		return obj.type() == typeid(OldHinduSolar) && this->internalEquals(obj);
	}
}
