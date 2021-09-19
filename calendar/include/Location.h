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
#include <any>
#include <optional>

namespace calendar
{

	class Location
	{
	public:
		std::wstring name;
		double latitude = 0;
		double longitude = 0;
		double elevation = 0;
		double zone = 0;
		static Location *const URBANA;
		static Location *const LOS_ANGELES;

		private:
			class StaticConstructor
			{
			public:
				StaticConstructor();
			};

		private:
			static Location::StaticConstructor staticConstructor;


	public:
		Location();

		Location(const std::wstring &name, double const latitude, double const longitude, double const elevation, double const zone);

		virtual std::wstring toString();

		virtual std::wstring format();

		virtual bool equals(std::any const obj);
	};

}
