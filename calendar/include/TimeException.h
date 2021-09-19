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
#include <stdexcept>

namespace calender
{

	class TimeException : public std::runtime_error
	{
	public:
		TimeException();

		TimeException(const std::wstring &s);
	};

}
