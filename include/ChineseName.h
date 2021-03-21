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

namespace calender
{

	class ChineseName
	{
	public:
		int stem = 0;
		int branch = 0;

		ChineseName();

		ChineseName(int const stem, int const branch);
	};

}
