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

#include "Date.h"
#include <string>
#include <vector>
#include <any>

namespace calendar { class Date; }

namespace calendar
{

	class StandardDate : public Date
	{
	public:
		long long year = 0;
		int month = 0;
		int day = 0;

		StandardDate();

		StandardDate(long long const date);

		StandardDate(Date const date);

		StandardDate(long long const year, int const month, int const day);

		StandardDate(std::vector<int> &a);

		void fromArray(std::vector<int> &a) override;

	protected:
		std::wstring toStringFields() override;

		virtual bool internalEquals(std::any const obj);
	};

}
