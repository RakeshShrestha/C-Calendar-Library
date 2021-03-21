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

#include "FixedVector.h"

namespace calendrica
{

	FixedVector::FixedVector(int const initialCapacity, int const capacityIncrement) : java::util::Vector(initialCapacity, capacityIncrement)
	{
	}

	FixedVector::FixedVector(int const initialCapacity) : java::util::Vector(initialCapacity)
	{
	}

	FixedVector::FixedVector()
	{
	}

	void FixedVector::addFixed(long long const fixed)
	{
		std::scoped_lock<std::mutex> lock(lock_object);
		std::vector::push_back(std::optional<long long>(fixed));
	}

	long long FixedVector::fixedAt(int const index)
	{
		std::scoped_lock<std::mutex> lock(lock_object);
		return std::vector[index];
	}
}
