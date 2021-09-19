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

#include "Test.h"
#include "Gregorian.h"
#include "ISO.h"
#include "Julian.h"
#include "OldHinduLunar.h"
#include "OldHinduSolar.h"
#include "Chinese.h"
#include "HinduLunar.h"
#include "HinduSolar.h"
#include "ProtoDate.h"
#include "Time.h"
#include "FixedVector.h"
#include "Date.h"

using Date = calendar::Date;
using FixedVector = calendar::FixedVector;
using Time = calendar::Time;
using ProtoDate = calendar::ProtoDate;
using HinduLunar = calendar::HinduLunar;
using HinduSolar = calendar::HinduSolar;
using Chinese = calendar::Chinese;
using OldHinduLunar = calendar::OldHinduLunar;
using OldHinduSolar = calendar::OldHinduSolar;
using ISO = calendar::ISO;
using Julian = calendar::Julian;
using Gregorian = calendar::Gregorian;

std::vector<int> Test::testDatesFixed;
std::vector<std::vector<int>> Test::testDatesGregorian;
std::vector<std::vector<int>> Test::testDatesJulian;
std::vector<std::vector<int>> Test::testDatesISO;
std::vector<std::vector<int>> Test::testDatesOldHinduSolar;
std::vector<std::vector<int>> Test::testDatesOldHinduLunar;
std::vector<std::vector<int>> Test::testDatesChinese;
std::vector<std::vector<int>> Test::testDatesHinduSolar;
std::vector<std::vector<int>> Test::testDatesHinduLunar;

Test::StaticConstructor::StaticConstructor()
{
	Test::testDatesFixed = std::vector<int> {-214193, -61387, 25469, 49217, 171307, 210155, 253427, 369740, 400085, 434355, 452605, 470160, 473837, 507850, 524156, 544676, 567118, 569477, 601716, 613424, 626596, 645554, 664224, 671401, 694799, 704424, 708842, 709409, 709580, 727274, 728714, 744313, 764652};
	Test::testDatesGregorian = std::vector<std::vector<int>>
	{
		std::vector<int> {-586, 7, 24},
		std::vector<int> {-168, 12, 5},
		std::vector<int> {70, 9, 24},
		std::vector<int> {135, 10, 2},
		std::vector<int> {470, 1, 8},
		std::vector<int> {576, 5, 20},
		std::vector<int> {694, 11, 10},
		std::vector<int> {1013, 4, 25},
		std::vector<int> {1096, 5, 24},
		std::vector<int> {1190, 3, 23},
		std::vector<int> {1240, 3, 10},
		std::vector<int> {1288, 4, 2},
		std::vector<int> {1298, 4, 27},
		std::vector<int> {1391, 6, 12},
		std::vector<int> {1436, 2, 3},
		std::vector<int> {1492, 4, 9},
		std::vector<int> {1553, 9, 19},
		std::vector<int> {1560, 3, 5},
		std::vector<int> {1648, 6, 10},
		std::vector<int> {1680, 6, 30},
		std::vector<int> {1716, 7, 24},
		std::vector<int> {1768, 6, 19},
		std::vector<int> {1819, 8, 2},
		std::vector<int> {1839, 3, 27},
		std::vector<int> {1903, 4, 19},
		std::vector<int> {1929, 8, 25},
		std::vector<int> {1941, 9, 29},
		std::vector<int> {1943, 4, 19},
		std::vector<int> {1943, 10, 7},
		std::vector<int> {1992, 3, 17},
		std::vector<int> {1996, 2, 25},
		std::vector<int> {2038, 11, 10},
		std::vector<int> {2094, 7, 18}
	};
	Test::testDatesJulian = std::vector<std::vector<int>>
	{
		std::vector<int> {-587, 7, 30},
		std::vector<int> {-169, 12, 8},
		std::vector<int> {70, 9, 26},
		std::vector<int> {135, 10, 3},
		std::vector<int> {470, 1, 7},
		std::vector<int> {576, 5, 18},
		std::vector<int> {694, 11, 7},
		std::vector<int> {1013, 4, 19},
		std::vector<int> {1096, 5, 18},
		std::vector<int> {1190, 3, 16},
		std::vector<int> {1240, 3, 3},
		std::vector<int> {1288, 3, 26},
		std::vector<int> {1298, 4, 20},
		std::vector<int> {1391, 6, 4},
		std::vector<int> {1436, 1, 25},
		std::vector<int> {1492, 3, 31},
		std::vector<int> {1553, 9, 9},
		std::vector<int> {1560, 2, 24},
		std::vector<int> {1648, 5, 31},
		std::vector<int> {1680, 6, 20},
		std::vector<int> {1716, 7, 13},
		std::vector<int> {1768, 6, 8},
		std::vector<int> {1819, 7, 21},
		std::vector<int> {1839, 3, 15},
		std::vector<int> {1903, 4, 6},
		std::vector<int> {1929, 8, 12},
		std::vector<int> {1941, 9, 16},
		std::vector<int> {1943, 4, 6},
		std::vector<int> {1943, 9, 24},
		std::vector<int> {1992, 3, 4},
		std::vector<int> {1996, 2, 12},
		std::vector<int> {2038, 10, 28},
		std::vector<int> {2094, 7, 5}
	};
	Test::testDatesISO = std::vector<std::vector<int>>
	{
		std::vector<int> {-586, 29, 7},
		std::vector<int> {-168, 49, 3},
		std::vector<int> {70, 39, 3},
		std::vector<int> {135, 39, 7},
		std::vector<int> {470, 2, 3},
		std::vector<int> {576, 21, 1},
		std::vector<int> {694, 45, 6},
		std::vector<int> {1013, 16, 7},
		std::vector<int> {1096, 21, 7},
		std::vector<int> {1190, 12, 5},
		std::vector<int> {1240, 10, 6},
		std::vector<int> {1288, 14, 5},
		std::vector<int> {1298, 17, 7},
		std::vector<int> {1391, 23, 7},
		std::vector<int> {1436, 5, 3},
		std::vector<int> {1492, 14, 6},
		std::vector<int> {1553, 38, 6},
		std::vector<int> {1560, 9, 6},
		std::vector<int> {1648, 24, 3},
		std::vector<int> {1680, 26, 7},
		std::vector<int> {1716, 30, 5},
		std::vector<int> {1768, 24, 7},
		std::vector<int> {1819, 31, 1},
		std::vector<int> {1839, 13, 3},
		std::vector<int> {1903, 16, 7},
		std::vector<int> {1929, 34, 7},
		std::vector<int> {1941, 40, 1},
		std::vector<int> {1943, 16, 1},
		std::vector<int> {1943, 40, 4},
		std::vector<int> {1992, 12, 2},
		std::vector<int> {1996, 8, 7},
		std::vector<int> {2038, 45, 3},
		std::vector<int> {2094, 28, 7}
	};
	Test::testDatesOldHinduSolar = std::vector<std::vector<int>>
	{
		std::vector<int> {2515, 5, 19},
		std::vector<int> {2933, 9, 26},
		std::vector<int> {3171, 7, 11},
		std::vector<int> {3236, 7, 17},
		std::vector<int> {3570, 10, 19},
		std::vector<int> {3677, 2, 28},
		std::vector<int> {3795, 8, 17},
		std::vector<int> {4114, 1, 26},
		std::vector<int> {4197, 2, 24},
		std::vector<int> {4290, 12, 20},
		std::vector<int> {4340, 12, 7},
		std::vector<int> {4388, 12, 30},
		std::vector<int> {4399, 1, 24},
		std::vector<int> {4492, 3, 7},
		std::vector<int> {4536, 10, 28},
		std::vector<int> {4593, 1, 3},
		std::vector<int> {4654, 6, 12},
		std::vector<int> {4660, 11, 27},
		std::vector<int> {4749, 3, 1},
		std::vector<int> {4781, 3, 21},
		std::vector<int> {4817, 4, 13},
		std::vector<int> {4869, 3, 8},
		std::vector<int> {4920, 4, 20},
		std::vector<int> {4939, 12, 13},
		std::vector<int> {5004, 1, 4},
		std::vector<int> {5030, 5, 11},
		std::vector<int> {5042, 6, 15},
		std::vector<int> {5044, 1, 4},
		std::vector<int> {5044, 6, 23},
		std::vector<int> {5092, 12, 2},
		std::vector<int> {5096, 11, 11},
		std::vector<int> {5139, 7, 26},
		std::vector<int> {5195, 4, 2}
	};
	Test::testDatesOldHinduLunar = std::vector<std::vector<int>>
	{
		std::vector<int> {2515, 6, 0, 11},
		std::vector<int> {2933, 9, 0, 26},
		std::vector<int> {3171, 8, 0, 3},
		std::vector<int> {3236, 8, 0, 9},
		std::vector<int> {3570, 11, 1, 19},
		std::vector<int> {3677, 3, 0, 5},
		std::vector<int> {3795, 9, 0, 15},
		std::vector<int> {4114, 2, 0, 7},
		std::vector<int> {4197, 2, 0, 24},
		std::vector<int> {4291, 1, 0, 9},
		std::vector<int> {4340, 12, 0, 9},
		std::vector<int> {4389, 1, 0, 23},
		std::vector<int> {4399, 2, 0, 8},
		std::vector<int> {4492, 4, 0, 2},
		std::vector<int> {4536, 11, 0, 7},
		std::vector<int> {4593, 1, 0, 3},
		std::vector<int> {4654, 7, 0, 2},
		std::vector<int> {4660, 11, 0, 29},
		std::vector<int> {4749, 3, 0, 20},
		std::vector<int> {4781, 4, 0, 4},
		std::vector<int> {4817, 5, 0, 6},
		std::vector<int> {4869, 4, 0, 5},
		std::vector<int> {4920, 5, 0, 12},
		std::vector<int> {4940, 1, 1, 13},
		std::vector<int> {5004, 1, 0, 23},
		std::vector<int> {5030, 5, 0, 21},
		std::vector<int> {5042, 7, 0, 9},
		std::vector<int> {5044, 1, 0, 15},
		std::vector<int> {5044, 7, 0, 9},
		std::vector<int> {5092, 12, 0, 14},
		std::vector<int> {5096, 12, 0, 7},
		std::vector<int> {5139, 8, 0, 14},
		std::vector<int> {5195, 4, 0, 6}
	};
	Test::testDatesChinese = std::vector<std::vector<int>>
	{
		std::vector<int> {35, 11, 6, 0, 12},
		std::vector<int> {42, 9, 10, 0, 27},
		std::vector<int> {46, 7, 8, 0, 4},
		std::vector<int> {47, 12, 8, 0, 9},
		std::vector<int> {52, 46, 11, 0, 20},
		std::vector<int> {54, 33, 4, 0, 5},
		std::vector<int> {56, 31, 10, 0, 15},
		std::vector<int> {61, 50, 3, 0, 7},
		std::vector<int> {63, 13, 4, 0, 24},
		std::vector<int> {64, 47, 2, 0, 9},
		std::vector<int> {65, 37, 2, 0, 9},
		std::vector<int> {66, 25, 2, 0, 23},
		std::vector<int> {66, 35, 3, 0, 9},
		std::vector<int> {68, 8, 5, 0, 2},
		std::vector<int> {68, 53, 1, 0, 8},
		std::vector<int> {69, 49, 3, 0, 4},
		std::vector<int> {70, 50, 8, 0, 2},
		std::vector<int> {70, 57, 1, 0, 29},
		std::vector<int> {72, 25, 4, 1, 20},
		std::vector<int> {72, 57, 6, 0, 5},
		std::vector<int> {73, 33, 6, 0, 6},
		std::vector<int> {74, 25, 5, 0, 5},
		std::vector<int> {75, 16, 6, 0, 12},
		std::vector<int> {75, 36, 2, 0, 13},
		std::vector<int> {76, 40, 3, 0, 22},
		std::vector<int> {77, 6, 7, 0, 21},
		std::vector<int> {77, 18, 8, 0, 9},
		std::vector<int> {77, 20, 3, 0, 15},
		std::vector<int> {77, 20, 9, 0, 9},
		std::vector<int> {78, 9, 2, 0, 14},
		std::vector<int> {78, 13, 1, 0, 7},
		std::vector<int> {78, 55, 10, 0, 14},
		std::vector<int> {79, 51, 6, 0, 7}
	};
	Test::testDatesHinduSolar = std::vector<std::vector<int>>
	{
		std::vector<int> {-664, 5, 19},
		std::vector<int> {-246, 9, 26},
		std::vector<int> {-8, 7, 9},
		std::vector<int> {57, 7, 16},
		std::vector<int> {391, 10, 21},
		std::vector<int> {498, 2, 31},
		std::vector<int> {616, 8, 16},
		std::vector<int> {935, 1, 28},
		std::vector<int> {1018, 2, 26},
		std::vector<int> {1111, 12, 23},
		std::vector<int> {1161, 12, 10},
		std::vector<int> {1210, 1, 2},
		std::vector<int> {1220, 1, 27},
		std::vector<int> {1313, 3, 8},
		std::vector<int> {1357, 10, 30},
		std::vector<int> {1414, 1, 5},
		std::vector<int> {1475, 6, 10},
		std::vector<int> {1481, 11, 29},
		std::vector<int> {1570, 3, 3},
		std::vector<int> {1602, 3, 22},
		std::vector<int> {1638, 4, 13},
		std::vector<int> {1690, 3, 10},
		std::vector<int> {1741, 4, 20},
		std::vector<int> {1760, 12, 16},
		std::vector<int> {1825, 1, 7},
		std::vector<int> {1851, 5, 10},
		std::vector<int> {1863, 6, 14},
		std::vector<int> {1865, 1, 7},
		std::vector<int> {1865, 6, 21},
		std::vector<int> {1913, 12, 4},
		std::vector<int> {1917, 11, 13},
		std::vector<int> {1960, 7, 24},
		std::vector<int> {2016, 4, 2}
	};
	Test::testDatesHinduLunar = std::vector<std::vector<int>>
	{
		std::vector<int> {-529, 6, 0, 11, 0},
		std::vector<int> {-111, 9, 0, 27, 0},
		std::vector<int> {127, 8, 0, 3, 0},
		std::vector<int> {192, 8, 0, 9, 0},
		std::vector<int> {526, 11, 0, 19, 0},
		std::vector<int> {633, 3, 0, 5, 0},
		std::vector<int> {751, 9, 0, 15, 0},
		std::vector<int> {1070, 2, 0, 6, 0},
		std::vector<int> {1153, 3, 1, 23, 0},
		std::vector<int> {1247, 1, 0, 8, 0},
		std::vector<int> {1297, 1, 0, 8, 0},
		std::vector<int> {1345, 1, 0, 22, 0},
		std::vector<int> {1355, 2, 0, 8, 0},
		std::vector<int> {1448, 4, 0, 1, 0},
		std::vector<int> {1492, 11, 0, 7, 0},
		std::vector<int> {1549, 2, 1, 3, 0},
		std::vector<int> {1610, 7, 0, 2, 0},
		std::vector<int> {1616, 11, 0, 28, 1},
		std::vector<int> {1705, 3, 0, 20, 0},
		std::vector<int> {1737, 4, 0, 4, 0},
		std::vector<int> {1773, 5, 0, 6, 0},
		std::vector<int> {1825, 4, 0, 5, 0},
		std::vector<int> {1876, 5, 0, 11, 0},
		std::vector<int> {1896, 1, 0, 13, 0},
		std::vector<int> {1960, 1, 0, 22, 0},
		std::vector<int> {1986, 5, 0, 20, 0},
		std::vector<int> {1998, 7, 0, 9, 0},
		std::vector<int> {2000, 1, 0, 14, 0},
		std::vector<int> {2000, 7, 0, 8, 0},
		std::vector<int> {2048, 12, 0, 14, 0},
		std::vector<int> {2052, 12, 0, 7, 0},
		std::vector<int> {2095, 8, 0, 14, 0},
		std::vector<int> {2151, 4, 0, 6, 0}
	};
}

Test::StaticConstructor Test::staticConstructor;

void Test::main(std::vector<std::wstring> &args)
{
	Time tempVar(ProtoDate::currentMoment());
	testConversions();
	appendln();
	testFormats();
	appendln();
	testTime();
	appendln();
	sampleHolidays();
}

void Test::testConversions()
{
}

void Test::append(const std::wstring &s)
{
}

void Test::appendln(const std::wstring &s)
{
}

void Test::appendln()
{
}

void Test::sampleHolidays()
{
	appendln(L"Some holidays:\n");
	appendln(L"Election Day: " + formatFixed(Gregorian::electionDay(2000LL)));
	appendln(L"Daylight Saving Start: " + formatFixed(Gregorian::daylightSavingStart(2000LL)));
	appendln(L"Daylight Saving End: " + formatFixed(Gregorian::daylightSavingEnd(2000LL)));
	appendln(L"Advent: " + formatFixed(Gregorian::advent(2000LL)));
	appendln(L"Eastern Orthodox Christmas: " + formatFixedVector(Julian::easternOrthodoxChristmas(2000LL)));
	appendln(L"Dragon Festival: " + formatFixed(Chinese::dragonFestival(2000LL)));
	appendln(L"Hindu Lunar New Year: " + formatFixed(HinduLunar::newYear(2000LL)));
	appendln(L"Sacred Wednesdays: " + formatFixedVector(HinduLunar::sacredWednesdaysInGregorian(2000LL)));
}

std::wstring Test::formatFixed(long long const date)
{
	Gregorian tempVar(date);
	return (&tempVar)->format();
}

std::wstring Test::formatFixedVector(FixedVector *const v)
{
	StringBuilder * const s = new StringBuilder();
	s->append(L"{");
	for (int i = 0; i < v->size(); ++i)
	{
		s->append(formatFixed(v->fixedAt(i)));
		if (i < v->size() - 1)
		{
			s->append(L", ");
		}
	}
	s->append(L"}");
	return s->toString();
}

void Test::testFromFixed(std::type_info const testClass, std::vector<std::vector<int>> &testDates, std::vector const errors)
{
	ProtoDate * const toDate = testClass.newInstance();
	ProtoDate * const compareDate = testClass.newInstance();
	errors.clear();
	for (int i = 0; i < Test::testDatesFixed.size(); ++i)
	{
		constexpr long long fromDate = Test::testDatesFixed[i];
		toDate->fromFixed(fromDate);
		compareDate->fromArray(testDates[i]);
		if (!toDate->equals(compareDate))
		{
			errors.push_back(L"{" + std::to_wstring(fromDate) + L", " + compareDate + L", " + toDate + L"}");
		}
	}
}

void Test::testToFixed(std::type_info const testClass, std::vector<std::vector<int>> &testDates, std::vector const errors)
{
	Date * const fromDate = testClass.newInstance();
	errors.clear();
	for (int i = 0; i < Test::testDatesFixed.size(); ++i)
	{
		fromDate->fromArray(testDates[i]);
		constexpr long long compareDate = Test::testDatesFixed[i];
		constexpr long long toDate = fromDate->toFixed();
		if (toDate != compareDate)
		{
			errors.push_back(L"{" + fromDate + L", " + std::to_wstring(compareDate) + L", " + std::to_wstring(toDate) + L"}");
		}
	}
}

std::wstring Test::formatErrors(std::vector const errors)
{
	StringBuilder * const s = new StringBuilder();
	if (errors.empty())
	{
	}
	else
	{
		Enumeration * const e = errors.elements();
		while (e->hasMoreElements())
		{
			s->append(e->nextElement());
			if (e->hasMoreElements())
			{
			}
		}
	}
	return s->toString();
}

void Test::testFormats()
{
}

void Test::testFormat(std::type_info const testClass, long long const testDate)
{
	ProtoDate * const date = testClass.newInstance();
	date->fromFixed(testDate);
}

void Test::testTime()
{
}
