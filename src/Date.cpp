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

#include "Date.h"

namespace calendar
{

	Date::Date()
	{
	}

	Date::Date(long long const date) : ProtoDate(date)
	{
	}

	Date::Date(const Date &date) : ProtoDate(date)
	{
	}

	void Date::convertTo(ProtoDate *const toDate)
	{
		ProtoDate::convert(this, toDate);
	}
}
