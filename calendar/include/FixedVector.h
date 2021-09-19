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

#include <vector>
#include <optional>
#include <mutex>

namespace calendar
{

	class FixedVector : public std::vector
	{
		private:
			std::mutex lock_object;

	public:
		FixedVector(int const initialCapacity, int const capacityIncrement);

		FixedVector(int const initialCapacity);

		FixedVector();

		void addFixed(long long const fixed);

		long long fixedAt(int const index);
	};

}
