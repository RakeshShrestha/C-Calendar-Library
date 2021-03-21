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

#include "StandardDate.h"

namespace calendar
{

	StandardDate::StandardDate()
	{
	}

	StandardDate::StandardDate(long long const date) : Date(date)
	{
	}

	StandardDate::StandardDate(Date const date) : Date(date)
	{
	}

	StandardDate::StandardDate(long long const year, int const month, int const day)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}

	StandardDate::StandardDate(std::vector<int> &a)
	{
		this->fromArray(a);
	}

	void StandardDate::fromArray(std::vector<int> &a)
	{
		this->year = a[0];
		this->month = a[1];
		this->day = a[2];
	}

	std::wstring StandardDate::toStringFields()
	{
		return L"year=" + std::to_wstring(this->year) + L",month=" + std::to_wstring(this->month) + L",day=" + std::to_wstring(this->day);
	}

	bool StandardDate::internalEquals(std::any const obj)
	{
		StandardDate * const o = std::any_cast<StandardDate*>(obj);
		return this == obj || (o->year == this->year && o->month == this->month && o->day == this->day);
	}
}
