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
#include <vector>
#include <typeinfo>
#include "stringbuilder.h"

namespace calendar { class FixedVector; }

using FixedVector = calendar::FixedVector;

class Test
{
public:
	static constexpr int TRUE = 1;
	static constexpr int FALSE = 0;
	static std::vector<int> testDatesFixed;
	static std::vector<std::vector<int>> testDatesGregorian;
	static std::vector<std::vector<int>> testDatesJulian;
	static std::vector<std::vector<int>> testDatesISO;
	static std::vector<std::vector<int>> testDatesOldHinduSolar;
	static std::vector<std::vector<int>> testDatesOldHinduLunar;
	static std::vector<std::vector<int>> testDatesChinese;
	static std::vector<std::vector<int>> testDatesHinduSolar;
	static std::vector<std::vector<int>> testDatesHinduLunar;

private:
	class StaticConstructor
	{
	public:
		StaticConstructor();
	};

private:
	static Test::StaticConstructor staticConstructor;


	static void main(std::vector<std::wstring> &args);

public:
	static void testConversions();

	static void append(const std::wstring &s);

	static void appendln(const std::wstring &s);

	static void appendln();

	static void sampleHolidays();

	static std::wstring formatFixed(long long const date);

	static std::wstring formatFixedVector(FixedVector *const v);

	static void testFromFixed(std::type_info const testClass, std::vector<std::vector<int>> &testDates, std::vector const errors);

	static void testToFixed(std::type_info const testClass, std::vector<std::vector<int>> &testDates, std::vector const errors);

	static std::wstring formatErrors(std::vector const errors);

	static void testFormats();

	static void testFormat(std::type_info const testClass, long long const testDate);

	static void testTime();
};
