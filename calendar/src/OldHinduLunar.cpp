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

#include "OldHinduLunar.h"
#include "ProtoDate.h"
#include "OldHinduSolar.h"

namespace calendar
{

	const std::vector<std::wstring> OldHinduLunar::dayOfWeekNames;
	const std::vector<std::wstring> OldHinduLunar::monthNames;

	OldHinduLunar::StaticConstructor::StaticConstructor()
	{
		dayOfWeekNames = std::vector<std::wstring> {L"Ravivara", L"Chandravara", L"Mangalavara", L"Buddhavara", L"Brihaspatvara", L"Sukravara", L"Sanivara"};
		monthNames = std::vector<std::wstring> {L"Chaitra", L"Vaisakha", L"Jyaishtha", L"Ashadha", L"Sravana", L"Bhadrapada", L"Asvina", L"Kartika", L"Margasirsha", L"Pausha", L"Magha", L"Phalguna"};
	}

	OldHinduLunar::StaticConstructor OldHinduLunar::staticConstructor;

	OldHinduLunar::OldHinduLunar()
	{
	}

	OldHinduLunar::OldHinduLunar(long long const date) : Date(date)
	{
	}

	OldHinduLunar::OldHinduLunar(Date const date) : Date(date)
	{
	}

	OldHinduLunar::OldHinduLunar(long long const year, int const month, bool const leapMonth, int const day)
	{
		this->year = year;
		this->month = month;
		this->leapMonth = leapMonth;
		this->day = day;
	}

	long long OldHinduLunar::toFixed(long long const year, int const month, bool const leapMonth, int const day)
	{
		constexpr double mina = (12LL * year - 1LL) * 30.43822337962963;
		constexpr double lunarNewYear = 29.530581807581694 * (ProtoDate::quotient(mina, 29.530581807581694) + 1LL);
		return static_cast<long long>(std::floor(OldHinduSolar::EPOCH + lunarNewYear + 29.530581807581694 * ((!leapMonth && std::ceil((lunarNewYear - mina) / 0.907641572047936) <= month) ? month : (month - 1)) + (day - 1) * 0.9843527269193898 + 0.75));
	}

	long long OldHinduLunar::toFixed()
	{
		return toFixed(this->year, this->month, this->leapMonth, this->day);
	}

	void OldHinduLunar::fromFixed(long long const date)
	{
		constexpr double sun = OldHinduSolar::dayCount(date) + 0.25;
		constexpr double newMoon = sun - ProtoDate::mod(sun, 29.530581807581694);
		this->leapMonth = (0.907641572047936 >= ProtoDate::mod(newMoon, 30.43822337962963) && ProtoDate::mod(newMoon, 30.43822337962963) > 0.0);
		this->month = 1 + static_cast<int>(ProtoDate::mod(std::ceil(newMoon / 30.43822337962963), 12.0));
		this->day = 1 + static_cast<int>(ProtoDate::mod(ProtoDate::quotient(sun, 0.9843527269193898), 30LL));
		this->year = static_cast<long long>(std::ceil((newMoon + 30.43822337962963) / 365.25868055555554)) - 1LL;
	}

	void OldHinduLunar::fromArray(std::vector<int> &a)
	{
		this->year = a[0];
		this->month = a[1];
		this->leapMonth = (a[2] != 0);
		this->day = a[3];
	}

	bool OldHinduLunar::isLeapYear(long long const lYear)
	{
		return ProtoDate::mod(lYear * 365.25868055555554 - 30.43822337962963, 29.530581807581694) >= 18.638882943006465;
	}

	std::wstring OldHinduLunar::toStringFields()
	{
		return L"year=" + std::to_wstring(this->year) + L",month=" + std::to_wstring(this->month) + L",leapMonth=" + StringHelper::toString(this->leapMonth) + L",day=" + std::to_wstring(this->day);
	}

	std::wstring OldHinduLunar::format()
	{
		return MessageFormat::format(L"{0}, {1} {2}{3} {4,number,#} K.Y.", ProtoDate::nameFromDayOfWeek(this->toFixed(), OldHinduLunar::dayOfWeekNames), std::optional<int>(this->day), ProtoDate::nameFromMonth(this->month, OldHinduLunar::monthNames), this->leapMonth ? L" II" : L"", std::optional<long long>(this->year));
	}

	bool OldHinduLunar::equals(std::any const obj)
	{
		if (this == obj)
		{
			return true;
		}
		if (!(obj.type() == typeid(OldHinduLunar)))
		{
			return false;
		}
		OldHinduLunar * const o = std::any_cast<OldHinduLunar*>(obj);
		return o->year == this->year && o->month == this->month && o->leapMonth == this->leapMonth && o->day == this->day;
	}
}
