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

#include "ChineseName.h"
#include "ProtoDate.h"
#include "DateException.h"

namespace calendar
{

	ChineseName::ChineseName()
	{
		this->stem = 1;
		this->branch = 1;
	}

	ChineseName::ChineseName(int const stem, int const branch)
	{
		if (ProtoDate::mod(stem, 2) == ProtoDate::mod(branch, 2))
		{
			this->stem = stem;
			this->branch = branch;
			return;
		}
		throw DateException();
	}
}
