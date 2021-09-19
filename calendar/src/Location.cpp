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

#include "Location.h"
#include "ProtoDate.h"

namespace calendar
{

	Location *const Location::URBANA;
	Location *const Location::LOS_ANGELES;

	Location::StaticConstructor::StaticConstructor()
	{
		URBANA = new Location(L"Urbana, IL, USA", 40.1, -88.2, ProtoDate::mt(225.0), -6.0);
		LOS_ANGELES = new Location(L"Los Angeles, CA, USA", ProtoDate::angle(34.0, 4.0, 0.0), -ProtoDate::angle(118.0, 15.0, 0.0), ProtoDate::mt(0.0), -8.0);
	}

	Location::StaticConstructor Location::staticConstructor;

	Location::Location()
	{
	}

	Location::Location(const std::wstring &name, double const latitude, double const longitude, double const elevation, double const zone)
	{
		this->name = name;
		this->latitude = latitude;
		this->longitude = longitude;
		this->elevation = elevation;
		this->zone = zone;
	}

	std::wstring Location::toString()
	{
		return std::wstring::valueOf(this->getClass().getName()) + L"[latitude=" + std::to_wstring(this->latitude) + L",longitude=" + std::to_wstring(this->longitude) + L",elevation=" + std::to_wstring(this->elevation) + L",zone=" + std::to_wstring(this->zone) + L"]";
	}

	std::wstring Location::format()
	{
		return MessageFormat::format(L"{0}: lat {1} long {2} elev {3} zone {4}", std::wstring(this->name), std::optional<double>(this->latitude), std::optional<double>(this->longitude), std::optional<double>(this->elevation), std::optional<double>(this->zone));
	}

	bool Location::equals(std::any const obj)
	{
		if (this == obj)
		{
			return true;
		}
		if (!(obj.type() == typeid(Location)))
		{
			return false;
		}
		Location * const o = std::any_cast<Location*>(obj);
		return o->latitude == this->latitude && o->longitude == this->longitude && o->elevation == this->elevation && o->zone == this->zone;
	}
}
