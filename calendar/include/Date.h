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

#include "ProtoDate.h"

namespace calender { class ProtoDate; }

namespace calender
{

	class Date : public ProtoDate
	{
	public:
		Date();

		Date(long long const date);

		Date(const Date &date);

		virtual long long toFixed() = 0;

		virtual void convertTo(ProtoDate *const toDate);
	};

}
