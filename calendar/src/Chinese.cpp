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

#include "Chinese.h"
#include "Gregorian.h"
#include "ProtoDate.h"
#include "Location.h"
#include "ChineseName.h"
#include "DateException.h"

namespace calender
{

	const std::vector<std::wstring> Chinese::yearStemNames;
	const std::vector<std::wstring> Chinese::yearBranchNames;

	Chinese::StaticConstructor::StaticConstructor()
	{
		EPOCH = Gregorian::toFixed(-2636LL, 2, 15);
		yearStemNames = std::vector<std::wstring> {L"Jia", L"Yi", L"Bing", L"Ding", L"Wu", L"Ji", L"Geng", L"Xin", L"Ren", L"Gui"};
		yearBranchNames = std::vector<std::wstring> {L"Zi", L"Chou", L"Yin", L"Mao", L"Chen", L"Si", L"Wu", L"Wei", L"Shen", L"You", L"Xu", L"Hai"};
	}

	Chinese::StaticConstructor Chinese::staticConstructor;

	Chinese::Chinese()
	{
	}

	Chinese::Chinese(long long const date) : Date(date)
	{
	}

	Chinese::Chinese(Date const date) : Date(date)
	{
	}

	Chinese::Chinese(long long const cycle, int const year, int const month, bool const leapMonth, int const day)
	{
		this->cycle = cycle;
		this->year = year;
		this->month = month;
		this->leapMonth = leapMonth;
		this->day = day;
	}

	long long Chinese::toFixed(long long const cycle, int const year, int const month, bool const leapMonth, int const day)
	{
		constexpr long long midYear = static_cast<long long>(std::floor(Chinese::EPOCH + ((cycle - 1LL) * 60LL + (year - 1) + 0.5) * 365.242189));
		constexpr long long theNewYear = newYearOnOrBefore(midYear);
		constexpr long long p = newMoonOnOrAfter(theNewYear + 29 * (month - 1));
		Chinese * const d = new Chinese(p);
		constexpr long long priorNewMoon = (month == d->month && leapMonth == d->leapMonth) ? p : newMoonOnOrAfter(p + 1LL);
		return priorNewMoon + day - 1LL;
	}

	long long Chinese::toFixed()
	{
		return toFixed(this->cycle, this->year, this->month, this->leapMonth, this->day);
	}

	void Chinese::fromFixed(long long const date)
	{
		constexpr long long s1 = winterSolsticeOnOrBefore(date);
		constexpr long long s2 = winterSolsticeOnOrBefore(s1 + 370LL);
		constexpr long long m12 = newMoonOnOrAfter(s1 + 1LL);
		constexpr long long nextM11 = newMoonBefore(s2 + 1LL);
		constexpr long long i = newMoonBefore(date + 1LL);
		constexpr bool leapYear = static_cast<long long>(std::round((nextM11 - m12) / 29.530588853)) == 12LL;
		this->month = static_cast<int>(ProtoDate::adjustedMod(static_cast<long long>(std::round((i - m12) / 29.530588853)) - static_cast<long long>((leapYear && hasPriorLeapMonth(m12, i)) ? 1 : 0), 12LL));
		this->leapMonth = (leapYear && hasNoMajorSolarTerm(i) && !hasPriorLeapMonth(m12, newMoonBefore(i)));
		constexpr long long elapsedYears = static_cast<long long>(std::floor(1.5 - this->month / 12.0 + (date - Chinese::EPOCH) / 365.242189));
		this->cycle = ProtoDate::quotient(static_cast<double>(elapsedYears - 1LL), 60.0) + 1LL;
		this->year = static_cast<int>(ProtoDate::adjustedMod(elapsedYears, 60LL));
		this->day = static_cast<int>(date - i + 1LL);
	}

	void Chinese::fromArray(std::vector<int> &a)
	{
		this->cycle = a[0];
		this->year = a[1];
		this->month = a[2];
		this->leapMonth = (a[3] != 0);
		this->day = a[4];
	}

	double Chinese::solarLongitudeOnOrAfter(long long const date, double const theta)
	{
		Location * const beijing = chineseLocation(static_cast<double>(date));
		constexpr double tee = ProtoDate::solarLongitudeAfter(ProtoDate::universalFromStandard(static_cast<double>(date), beijing), theta);
		return ProtoDate::standardFromUniversal(tee, beijing);
	}

	double Chinese::midnightInChina(long long const date)
	{
		return ProtoDate::universalFromStandard(static_cast<double>(date), chineseLocation(static_cast<double>(date)));
	}

	long long Chinese::winterSolsticeOnOrBefore(long long const date)
	{
		constexpr double approx = ProtoDate::estimatePriorSolarLongitude(midnightInChina(date + 1LL), Chinese::WINTER);
		long long i;
		for (i = static_cast<long long>(std::floor(approx) - 1.0); Chinese::WINTER > ProtoDate::solarLongitude(midnightInChina(i + 1LL)); ++i)
		{
		}
		return i;
	}

	long long Chinese::newYearInSui(long long const date)
	{
		constexpr long long s1 = winterSolsticeOnOrBefore(date);
		constexpr long long s2 = winterSolsticeOnOrBefore(s1 + 370LL);
		constexpr long long m12 = newMoonOnOrAfter(s1 + 1LL);
		constexpr long long m13 = newMoonOnOrAfter(m12 + 1LL);
		constexpr long long nextM11 = newMoonBefore(s2 + 1LL);
		if (static_cast<long long>(std::round((nextM11 - m12) / 29.530588853)) == 12LL && (hasNoMajorSolarTerm(m12) || hasNoMajorSolarTerm(m13)))
		{
			return newMoonOnOrAfter(m13 + 1LL);
		}
		return m13;
	}

	long long Chinese::newYearOnOrBefore(long long const date)
	{
		constexpr long long newYear = newYearInSui(date);
		return (date >= newYear) ? newYear : newYearInSui(date - 180LL);
	}

	int Chinese::nameDifference(ChineseName *const name1, ChineseName *const name2)
	{
		constexpr int stemDifference = name2->stem - name1->stem;
		constexpr int branchDifference = name2->branch - name1->branch;
		return 1 + ProtoDate::mod(stemDifference - 1 + 25 * (branchDifference - stemDifference), 60);
	}

	long long Chinese::dayNameOnOrBefore(ChineseName *const name, long long const date)
	{
		return date - ProtoDate::mod(date + nameDifference(name, sexagesimalName(15LL)), 60LL);
	}

	int Chinese::currentMajorSolarTerm(long long const date)
	{
		constexpr double s = ProtoDate::solarLongitude(ProtoDate::universalFromStandard(static_cast<double>(date), chineseLocation(static_cast<double>(date))));
		return static_cast<int>(ProtoDate::adjustedMod(2LL + ProtoDate::quotient(s, ProtoDate::deg(30.0)), 12LL));
	}

	double Chinese::majorSolarTermOnOrAfter(long long const date)
	{
		constexpr double l = ProtoDate::mod(30.0 * std::ceil(ProtoDate::solarLongitude(midnightInChina(date)) / 30.0), 360.0);
		return solarLongitudeOnOrAfter(date, l);
	}

	int Chinese::currentMinorSolarTerm(long long const date)
	{
		constexpr double s = ProtoDate::solarLongitude(midnightInChina(date));
		return static_cast<int>(ProtoDate::adjustedMod(3LL + ProtoDate::quotient(s - ProtoDate::deg(15.0), ProtoDate::deg(30.0)), 12LL));
	}

	double Chinese::minorSolarTermOnOrAfter(long long const date)
	{
		constexpr double l = ProtoDate::mod(30.0 * std::ceil((ProtoDate::solarLongitude(midnightInChina(date)) - ProtoDate::deg(15.0)) / 30.0) + ProtoDate::deg(15.0), 360.0);
		return solarLongitudeOnOrAfter(date, l);
	}

	long long Chinese::newMoonBefore(long long const date)
	{
		constexpr double tee = ProtoDate::newMoonBefore(midnightInChina(date));
		return static_cast<long long>(std::floor(ProtoDate::standardFromUniversal(tee, chineseLocation(tee))));
	}

	long long Chinese::newMoonOnOrAfter(long long const date)
	{
		constexpr double tee = ProtoDate::newMoonAfter(midnightInChina(date));
		return static_cast<long long>(std::floor(ProtoDate::standardFromUniversal(tee, chineseLocation(tee))));
	}

	bool Chinese::hasNoMajorSolarTerm(long long const date)
	{
		return currentMajorSolarTerm(date) == currentMajorSolarTerm(newMoonOnOrAfter(date + 1LL));
	}

	bool Chinese::hasPriorLeapMonth(long long const mPrime, long long const m)
	{
		return m >= mPrime && (hasNoMajorSolarTerm(m) || hasPriorLeapMonth(mPrime, newMoonBefore(m)));
	}

	ChineseName *Chinese::sexagesimalName(long long const n)
	{
		try
		{
			return new ChineseName(static_cast<int>(ProtoDate::adjustedMod(n, 10LL)), static_cast<int>(ProtoDate::adjustedMod(n, 12LL)));
		}
		catch (const DateException &ex)
		{
			return new ChineseName();
		}
	}

	ChineseName *Chinese::nameOfYear(int const year)
	{
		return sexagesimalName(year);
	}

	ChineseName *Chinese::nameOfMonth(int const year, int const month)
	{
		constexpr long long elapsedMonths = 12LL * (year - 1) + (month - 1);
		return sexagesimalName(elapsedMonths + 15LL);
	}

	ChineseName *Chinese::nameOfDay(long long const fixed)
	{
		return sexagesimalName(fixed + 15LL);
	}

	Location *Chinese::beijing(double const tee)
	{
		constexpr long long year = Gregorian::yearFromFixed(static_cast<long long>(std::floor(tee)));
		return new Location(L"Beijing, China", ProtoDate::deg(39.55), ProtoDate::angle(116.0, 25.0, 0.0), ProtoDate::mt(43.5), (year < 1929LL) ? 7.761111111111111 : 8.0);
	}

	Location *Chinese::chineseLocation(double const tee)
	{
		return beijing(tee);
	}

	Location *Chinese::tokyo(double const date)
	{
		constexpr long long year = Gregorian::yearFromFixed(static_cast<long long>(std::floor(date)));
		if (year < 1888LL)
		{
			return new Location(L"Tokyo, Japan", ProtoDate::deg(35.7), ProtoDate::angle(139.0, 46.0, 0.0), ProtoDate::mt(24.0), 9.317777777777778);
		}
		return new Location(L"Tokyo, Japan", ProtoDate::deg(35.0), ProtoDate::deg(135.0), ProtoDate::mt(0.0), 9.0);
	}

	Location *Chinese::japaneseLocation(double const date)
	{
		return tokyo(date);
	}

	long long Chinese::newYear(long long const gYear)
	{
		return newYearOnOrBefore(Gregorian::toFixed(gYear, 7, 1));
	}

	long long Chinese::dragonFestival(long long const gYear)
	{
		constexpr long long elapsedYears = gYear - Gregorian::yearFromFixed(Chinese::EPOCH) + 1LL;
		constexpr long long cycle = ProtoDate::quotient(static_cast<double>(elapsedYears - 1LL), 60.0) + 1LL;
		constexpr int year = static_cast<int>(ProtoDate::adjustedMod(elapsedYears, 60LL));
		return toFixed(cycle, year, 5, false, 5);
	}

	long long Chinese::qingMing(long long const gYear)
	{
		return static_cast<long long>(std::floor(minorSolarTermOnOrAfter(Gregorian::toFixed(gYear, 3, 30))));
	}

	long long Chinese::age(Chinese *const birthdate, long long const date)
	{
		Chinese * const today = new Chinese(date);
		if (date >= birthdate->toFixed())
		{
			return 60LL * (today->cycle - birthdate->cycle) + (today->year - birthdate->year) + 1LL;
		}
		throw DateException();
	}

	std::wstring Chinese::toStringFields()
	{
		return L"cycle=" + std::to_wstring(this->cycle) + L",year=" + std::to_wstring(this->year) + L",month=" + std::to_wstring(this->month) + L",leapMonth=" + StringHelper::toString(this->leapMonth) + L",day=" + std::to_wstring(this->day);
	}

	std::wstring Chinese::format()
	{
		ChineseName * const yearName = nameOfYear(this->year);
		return MessageFormat::format(L"cycle {0,number,#}, year {1}-{2}, {3}month {4}, day {5}", std::optional<long long>(this->cycle), ProtoDate::nameFromNumber(yearName->stem, Chinese::yearStemNames), StringHelper::toLower(ProtoDate::nameFromNumber(yearName->branch, Chinese::yearBranchNames)), this->leapMonth ? L"leap " : L"", std::optional<int>(this->month), std::optional<int>(this->day));
	}

	bool Chinese::equals(std::any const obj)
	{
		if (this == obj)
		{
			return true;
		}
		if (!(obj.type() == typeid(Chinese)))
		{
			return false;
		}
		Chinese * const o = std::any_cast<Chinese*>(obj);
		return o->cycle == this->cycle && o->year == this->year && o->month == this->month && o->leapMonth == this->leapMonth && o->day == this->day;
	}
}
