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

#include "DateException.h"

namespace calender
{

	DateException::DateException()
	{
	}

	DateException::DateException(const std::wstring &s) : Exception(s)
	{
	}
}
