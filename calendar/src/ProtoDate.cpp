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

#include "ProtoDate.h"
#include "Location.h"
#include "Gregorian.h"
#include "Date.h"
#include "TimeException.h"

namespace calendar
{

	const double ProtoDate::J2000 = 0;
	const double ProtoDate::NEW = 0;
	const double ProtoDate::FIRST_QUARTER = 0;
	const double ProtoDate::FULL = 0;
	const double ProtoDate::LAST_QUARTER = 0;
	const double ProtoDate::SPRING = 0;
	const double ProtoDate::SUMMER = 0;
	const double ProtoDate::AUTUMN = 0;
	const double ProtoDate::WINTER = 0;
	Location *const ProtoDate::JERUSALEM;

	ProtoDate::StaticConstructor::StaticConstructor()
	{
		J2000 = hr(12.0) + Gregorian::toFixed(2000LL, 1, 1);
		
		NEW = deg(0.0);
		FIRST_QUARTER = deg(90.0);
		FULL = deg(180.0);
		LAST_QUARTER = deg(270.0);
		SPRING = deg(0.0);
		SUMMER = deg(90.0);
		AUTUMN = deg(180.0);
		WINTER = deg(270.0);
		
		JERUSALEM = new Location(L"Jerusalem, Israel", deg(31.8), deg(35.2), mt(800.0), 2.0);
		
		coeffObliquity = std::vector<double> {0.0, ProtoDate::angle(0.0, 0.0, -46.815), ProtoDate::angle(0.0, 0.0, -5.9E-4), ProtoDate::angle(0.0, 0.0, 0.001813)};
		coeff19th = std::vector<double> {-2.0E-5, 2.97E-4, 0.025184, -0.181133, 0.55304, -0.861938, 0.677066, -0.212591};
		coeff18th = std::vector<double> {-9.0E-6, 0.003844, 0.083563, 0.865736, 4.867575, 15.845535, 31.332267, 38.291999, 28.316289, 11.636204, 2.043794};
		coeff17th = std::vector<double> {8.118780842, -0.005092142, 0.003336121, -2.66484E-5};
		coeff16th = std::vector<double> {196.58333, -4.0675, 0.0219167};
		coeffLongitude = ProtoDate::deg(std::vector<double> {280.46645, 36000.76983, 3.032E-4});
		coeffAnomaly = ProtoDate::deg(std::vector<double> {357.5291, 35999.0503, -1.559E-4, -4.8E-7});
		coeffEccentricity = ProtoDate::deg(std::vector<double> {0.016708617, -4.2037E-5, -1.236E-7});
		coefficients = std::vector<int> {403406, 195207, 119433, 112392, 3891, 2819, 1721, 660, 350, 334, 314, 268, 242, 234, 158, 132, 129, 114, 99, 93, 86, 78, 72, 68, 64, 46, 38, 37, 32, 29, 28, 27, 27, 25, 24, 21, 21, 20, 18, 17, 14, 13, 13, 13, 12, 10, 10, 10, 10};
		multipliers = std::vector<double> {0.9287892, 35999.1376958, 35999.4089666, 35998.7287385, 71998.20261, 71998.4403, 36000.35726, 71997.4812, 32964.4678, -19.441, 445267.1117, 45036.884, 3.1008, 22518.4434, -19.9739, 65928.9345, 9038.0293, 3034.7684, 33718.148, 3034.448, -2280.773, 29929.992, 31556.493, 149.588, 9037.75, 107997.405, -4444.176, 151.771, 67555.316, 31556.08, -4561.54, 107996.706, 1221.655, 62894.167, 31437.369, 14578.298, -31931.757, 34777.243, 1221.999, 62894.511, -4442.039, 107997.909, 119.066, 16859.071, -4.578, 26895.292, -39.127, 12297.536, 90073.778};
		addends = std::vector<double> {270.54861, 340.19128, 63.91854, 331.2622, 317.843, 86.631, 240.052, 310.26, 247.23, 260.87, 297.82, 343.14, 166.79, 81.53, 3.5, 132.75, 182.95, 162.03, 29.8, 266.4, 249.2, 157.6, 257.8, 185.1, 69.9, 8.0, 197.1, 250.4, 65.3, 162.7, 341.5, 291.6, 98.5, 146.7, 110.0, 5.2, 342.6, 230.9, 256.1, 45.3, 242.9, 115.2, 151.8, 285.3, 53.3, 126.6, 205.7, 85.9, 146.1};
		coeffa = ProtoDate::deg(std::vector<double> {124.9, -1934.134, 0.002063});
		coeffb = ProtoDate::deg(std::vector<double> {201.11, 72001.5377, 5.7E-4});
		coeffMeanMoon = ProtoDate::deg(std::vector<double> {218.3164591, 481267.88134236, -0.0013268, 1.855835023689734E-6, -1.5338834862103876E-8});
		coeffElongation = ProtoDate::deg(std::vector<double> {297.8502042, 445267.1115168, -0.00163, 1.8319447192361523E-6, -8.844469995135542E-9});
		coeffSolarAnomaly = ProtoDate::deg(std::vector<double> {357.5291092, 35999.0502909, -1.536E-4, 4.083299305839118E-8});
		coeffLunarAnomaly = ProtoDate::deg(std::vector<double> {134.9634114, 477198.8676313, 0.008997, 1.4347408140719379E-5, -6.797172376291463E-8});
		coeffMoonNode = ProtoDate::deg(std::vector<double> {93.2720993, 483202.0175273, -0.0034029, -2.8360748723766307E-7, 1.1583324645839848E-9});
		coeffCapE = std::vector<double> {1.0, -0.002516, -7.4E-6};
		argsLunarElongation = std::vector<char> {0, 2, 2, 0, 0, 0, 2, 2, 2, 2, 0, 1, 0, 2, 0, 0, 4, 0, 4, 2, 2, 1, 1, 2, 2, 4, 2, 0, 2, 2, 1, 2, 0, 0, 2, 2, 2, 4, 0, 3, 2, 4, 0, 2, 2, 2, 4, 0, 4, 1, 2, 0, 1, 3, 4, 2, 0, 1, 2};
		argsSolarAnomaly = std::vector<char> {0, 0, 0, 0, 1, 0, 0, -1, 0, -1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, -1, 0, 0, 0, 1, 0, -1, 0, -2, 1, 2, -2, 0, 0, -1, 0, 0, 1, -1, 2, 2, 1, -1, 0, 0, -1, 0, 1, 0, 1, 0, 0, -1, 2, 1, 0};
		argsLunarAnomaly = std::vector<char> {1, -1, 0, 2, 0, 0, -2, -1, 1, 0, -1, 0, 1, 0, 1, 1, -1, 3, -2, -1, 0, -1, 0, 1, 2, 0, -3, -2, -1, -2, 1, 0, 2, 0, -1, 1, 0, -1, 2, -1, 1, -2, -1, -1, -2, 0, 1, 4, 0, -2, 0, 2, 1, -2, -3, 2, 1, -1, 3};
		argsMoonFromNode = std::vector<char> {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, -2, 2, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, -2, 2, 0, 2, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, -2, -2, 0, 0, 0, 0, 0, 0, 0};
		sineCoefficients = std::vector<int> {6288774, 1274027, 658314, 213618, -185116, -114332, 58793, 57066, 53322, 45758, -40923, -34720, -30383, 15327, -12528, 10980, 10675, 10034, 8548, -7888, -6766, -5163, 4987, 4036, 3994, 3861, 3665, -2689, -2602, 2390, -2348, 2236, -2120, -2069, 2048, -1773, -1595, 1215, -1110, -892, -810, 759, -713, -700, 691, 596, 549, 537, 520, -487, -399, -381, 351, -340, 330, 327, -323, 299, 294};
		coeffApprox = std::vector<double> {730125.59765, 36524.90882283305, 1.337E-4, -1.5E-7, 7.3E-10};
		coeffCapE = std::vector<double> {1.0, -0.002516, -7.4E-6};
		coeffSolarAnomaly = ProtoDate::deg(std::vector<double> {2.5534, 35998.960422026496, -2.18E-5, -1.1E-7});
		coeffLunarAnomaly = ProtoDate::deg(std::vector<double> {201.5643, 477197.67640106793, 0.0107438, 1.239E-5, -5.8E-8});
		coeffMoonArgument = ProtoDate::deg(std::vector<double> {160.7108, 483200.81131396897, -0.0016341, -2.27E-6, 1.1E-8});
		coeffCapOmega = std::vector<double> {124.7746, -1934.1313612299998, 0.0020691, 2.15E-6};
		EFactor = std::vector<char> {0, 1, 0, 0, 1, 1, 2, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		solarCoeff = std::vector<char> {0, 1, 0, 0, -1, 1, 2, 0, 0, 1, 0, 1, 1, -1, 2, 0, 3, 1, 0, 1, -1, -1, 1, 0};
		lunarCoeff = std::vector<char> {1, 0, 2, 0, 1, 1, 0, 1, 1, 2, 3, 0, 0, 2, 1, 2, 0, 1, 2, 1, 1, 1, 3, 4};
		moonCoeff = std::vector<char> {0, 0, 0, 2, 0, 0, 0, -2, 2, 0, 0, 2, -2, 0, 0, -2, 0, -2, 2, 2, 2, -2, 0, 0};
		sineCoeff = std::vector<double> {-0.4072, 0.17241, 0.01608, 0.01039, 0.00739, -0.00514, 0.00208, -0.00111, -5.7E-4, 5.6E-4, -4.2E-4, 4.2E-4, 3.8E-4, -2.4E-4, -7.0E-5, 4.0E-5, 4.0E-5, 3.0E-5, 3.0E-5, -3.0E-5, 3.0E-5, -2.0E-5, -2.0E-5, 2.0E-5};
		addConst = std::vector<double> {251.88, 251.83, 349.42, 84.66, 141.74, 207.14, 154.84, 34.52, 207.19, 291.34, 161.72, 239.56, 331.55};
		addCoeff = std::vector<double> {0.016321, 26.641886, 36.412478, 18.206239, 53.303771, 2.453732, 7.30686, 27.261239, 0.121824, 1.844379, 24.198154, 25.513099, 3.592518};
		addFactor = std::vector<double> {1.65E-4, 1.64E-4, 1.26E-4, 1.1E-4, 6.2E-5, 6.0E-5, 5.6E-5, 4.7E-5, 4.2E-5, 4.0E-5, 3.7E-5, 3.5E-5, 2.3E-5};
		extra = ProtoDate::deg(std::vector<double> {299.77, 132.8475848, -0.009173});
		coeffLongitude = ProtoDate::deg(std::vector<double> {218.3164591, 481267.88134236, -0.0013268, 1.855835023689734E-6, -1.5338834862103876E-8});
		coeffElongation = ProtoDate::deg(std::vector<double> {297.8502042, 445267.1115168, -0.00163, 1.8319447192361523E-6, -8.844469995135542E-9});
		coeffSolarAnomaly = ProtoDate::deg(std::vector<double> {357.5291092, 35999.0502909, -1.536E-4, 4.083299305839118E-8});
		coeffLunarAnomaly = ProtoDate::deg(std::vector<double> {134.9634114, 477198.8676313, 0.008997, 1.4347408140719379E-5, -6.797172376291463E-8});
		coeffMoonNode = ProtoDate::deg(std::vector<double> {93.2720993, 483202.0175273, -0.0034029, -2.8360748723766307E-7, 1.1583324645839848E-9});
		coeffCapE = std::vector<double> {1.0, -0.002516, -7.4E-6};
		argsLunarElongation = std::vector<char> {0, 0, 0, 2, 2, 2, 2, 0, 2, 0, 2, 2, 2, 2, 2, 2, 2, 0, 4, 0, 0, 0, 1, 0, 0, 0, 1, 0, 4, 4, 0, 4, 2, 2, 2, 2, 0, 2, 2, 2, 2, 4, 2, 2, 0, 2, 1, 1, 0, 2, 1, 2, 0, 4, 4, 1, 4, 1, 4, 2};
		argsSolarAnomaly = std::vector<char> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1, -1, -1, -1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 1, 0, -1, -2, 0, 1, 1, 1, 1, 1, 0, -1, 1, 0, -1, 0, 0, 0, -1, -2};
		argsLunarAnomaly = std::vector<char> {0, 1, 1, 0, -1, -1, 0, 2, 1, 2, 0, -2, 1, 0, -1, 0, -1, -1, -1, 0, 0, -1, 0, 1, 1, 0, 0, 3, 0, -1, 1, -2, 0, 2, 1, -2, 3, 2, -3, -1, 0, 0, 1, 0, 1, 1, 0, 0, -2, -1, 1, -2, 2, -2, -1, 1, 1, -2, 0, 0};
		argsMoonNode = std::vector<char> {1, 1, -1, -1, 1, -1, 1, 1, -1, -1, -1, -1, 1, -1, 1, 1, -1, -1, -1, 1, 3, 1, 1, 1, -1, -1, -1, 1, -1, 1, -3, 1, -3, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, -1, 3, -1, -1, 1, -1, -1, 1, -1, 1, -1, -1, -1, -1, -1, -1, 1};
		sineCoefficients = std::vector<int> {5128122, 280602, 277693, 173237, 55413, 46271, 32573, 17198, 9266, 8822, 8216, 4324, 4200, -3359, 2463, 2211, 2065, -1870, 1828, -1794, -1749, -1565, -1491, -1475, -1410, -1344, -1335, 1107, 1021, 833, 777, 671, 607, 596, 491, -451, 439, 422, 421, -366, -351, 331, 315, 302, -283, -229, 223, 223, -220, -220, -185, 181, -177, 176, 166, -164, 132, -119, 115, 107};
		siderealCoeff = ProtoDate::deg(std::vector<double> {280.46061837, 1.3185000770053742E7, 3.87933E-4, 2.5833118057349522E-8});
	}

	ProtoDate::StaticConstructor ProtoDate::staticConstructor;

	ProtoDate::ProtoDate()
	{
	}

	ProtoDate::ProtoDate(long long const date)
	{
		this->fromFixed(date);
	}

	ProtoDate::ProtoDate(Date const date)
	{
		this->fromDate(date);
	}

	void ProtoDate::fromDate(Date const fromDate)
	{
		convert(fromDate, this);
	}

	void ProtoDate::convert(Date const fromDate, ProtoDate *const toDate)
	{
		toDate->fromFixed(fromDate->toFixed());
	}

	double ProtoDate::currentMoment()
	{
		return Gregorian::toFixed(1970LL, 1, 1) + System::currentTimeMillis() / 8.64E7;
	}

	long long ProtoDate::currentDate()
	{
		return static_cast<long long>(currentMoment());
	}

	long long ProtoDate::difference(Date const date1, Date const date2)
	{
		return date2->toFixed() - date1->toFixed();
	}

	long long ProtoDate::difference(long long const date1, Date const date2)
	{
		return date2->toFixed() - date1;
	}

	long long ProtoDate::difference(Date const date1, long long const date2)
	{
		return date2 - date1->toFixed();
	}

	long long ProtoDate::difference(long long const date1, long long const date2)
	{
		return date2 - date1;
	}

	double ProtoDate::mod(double const x, double const y)
	{
		return x - y * std::floor(x / y);
	}

	int ProtoDate::mod(int const x, int const y)
	{
		return static_cast<int>(x - y * std::floor(x / static_cast<double>(y)));
	}

	long long ProtoDate::mod(long long const x, long long const y)
	{
		return static_cast<long long>(x - y * std::floor(x / static_cast<double>(y)));
	}

	long long ProtoDate::quotient(double const x, double const y)
	{
		return static_cast<long long>(std::floor(x / y));
	}

	int ProtoDate::adjustedMod(int const x, int const y)
	{
		return y + mod(x, -y);
	}

	long long ProtoDate::adjustedMod(long long const x, long long const y)
	{
		return y + mod(x, -y);
	}

	double ProtoDate::adjustedMod(double const x, double const y)
	{
		return y + mod(x, -y);
	}

	long long ProtoDate::dayOfWeekFromFixed(long long const date)
	{
		return mod(date, 7LL);
	}

	long long ProtoDate::kDayOnOrBefore(long long const date, int const k)
	{
		return date - dayOfWeekFromFixed(date - k);
	}

	long long ProtoDate::kDayOnOrAfter(long long const date, int const k)
	{
		return kDayOnOrBefore(date + 6LL, k);
	}

	long long ProtoDate::kDayNearest(long long const date, int const k)
	{
		return kDayOnOrBefore(date + 3LL, k);
	}

	long long ProtoDate::kDayAfter(long long const date, int const k)
	{
		return kDayOnOrBefore(date + 7LL, k);
	}

	long long ProtoDate::kDayBefore(long long const date, int const k)
	{
		return kDayOnOrBefore(date - 1LL, k);
	}

	long long ProtoDate::nthKDay(int const n, int const k, long long const gDate)
	{
		return (n > 0) ? (kDayBefore(gDate, k) + 7 * n) : (kDayAfter(gDate, k) + 7 * n);
	}

	long long ProtoDate::firstKDay(int const k, long long const gDate)
	{
		return nthKDay(1, k, gDate);
	}

	long long ProtoDate::lastKDay(int const k, long long const gDate)
	{
		return nthKDay(-1, k, gDate);
	}

	int ProtoDate::signum(double const x)
	{
		if (x < 0.0)
		{
			return -1;
		}
		if (x > 0.0)
		{
			return 1;
		}
		return 0;
	}

	double ProtoDate::square(double const x)
	{
		return x * x;
	}

	double ProtoDate::poly(double const x, std::vector<double> &a)
	{
		double result = a[0];
		for (int i = 1; i < a.size(); ++i)
		{
			result += a[i] * std::pow(x, i);
		}
		return result;
	}

	double ProtoDate::hr(double const x)
	{
		return x / 24.0;
	}

	double ProtoDate::mt(double const x)
	{
		return x;
	}

	double ProtoDate::deg(double const x)
	{
		return x;
	}

	std::vector<double> ProtoDate::deg(std::vector<double> &x)
	{
		return x;
	}

	double ProtoDate::angle(double const d, double const m, double const s)
	{
		return d + (m + s / 60.0) / 60.0;
	}

	double ProtoDate::degrees(double const theta)
	{
		return mod(theta, 360.0);
	}

	double ProtoDate::radiansToDegrees(double const theta)
	{
		return degrees(theta / 3.141592653589793 * 180.0);
	}

	double ProtoDate::degreesToRadians(double const theta)
	{
		return degrees(theta) * 3.141592653589793 / 180.0;
	}

	double ProtoDate::sinDegrees(double const theta)
	{
		return std::sin(degreesToRadians(theta));
	}

	double ProtoDate::cosDegrees(double const theta)
	{
		return std::cos(degreesToRadians(theta));
	}

	double ProtoDate::tanDegrees(double const theta)
	{
		return std::tan(degreesToRadians(theta));
	}

	double ProtoDate::arcTanDegrees(double const x, int const quad)
	{
		constexpr double alpha = radiansToDegrees(std::atan(x));
		return mod((quad == 1 || quad == 4) ? alpha : (alpha + deg(180.0)), 360.0);
	}

	double ProtoDate::arcSinDegrees(double const x)
	{
		return radiansToDegrees(std::asin(x));
	}

	double ProtoDate::arcCosDegrees(double const x)
	{
		return radiansToDegrees(std::acos(x));
	}

	double ProtoDate::standardFromUniversal(double const teeU, Location *const locale)
	{
		return teeU + locale->zone / 24.0;
	}

	double ProtoDate::universalFromStandard(double const teeS, Location *const locale)
	{
		return teeS - locale->zone / 24.0;
	}

	double ProtoDate::localFromUniversal(double const teeU, Location *const locale)
	{
		return teeU + locale->longitude / deg(360.0);
	}

	double ProtoDate::universalFromLocal(double const teeEll, Location *const locale)
	{
		return teeEll - locale->longitude / deg(360.0);
	}

	double ProtoDate::standardFromLocal(double const teeEll, Location *const locale)
	{
		return standardFromUniversal(universalFromLocal(teeEll, locale), locale);
	}

	double ProtoDate::localFromStandard(double const teeS, Location *const locale)
	{
		return localFromUniversal(universalFromStandard(teeS, locale), locale);
	}

	double ProtoDate::midday(long long const date, Location *const locale)
	{
		return standardFromLocal(localFromApparent(date + hr(12.0)), locale);
	}

	double ProtoDate::midnight(long long const date, Location *const locale)
	{
		return standardFromLocal(localFromApparent(static_cast<double>(date)), locale);
	}

	double ProtoDate::momentFromJD(double const jd)
	{
		return jd - 1721424.5;
	}

	double ProtoDate::jdFromMoment(double const tee)
	{
		return tee + 1721424.5;
	}

	long long ProtoDate::fixedFromJD(double const jd)
	{
		return static_cast<long long>(std::floor(momentFromJD(jd)));
	}

	double ProtoDate::jdFromFixed(long long const date)
	{
		return jdFromMoment(static_cast<double>(date));
	}

	long long ProtoDate::fixedFromMJD(double const mjd)
	{
		return static_cast<long long>(std::floor(mjd + 678576.0));
	}

	double ProtoDate::mjdFromFixed(long long const date)
	{
		return static_cast<double>(date - 678576LL);
	}

	double ProtoDate::direction(Location *const locale, Location *const focus)
	{
		constexpr double phi = locale->latitude;
		constexpr double phiPrime = focus->latitude;
		constexpr double psi = locale->longitude;
		constexpr double psiPrime = focus->longitude;
		constexpr double denom = cosDegrees(phi) * tanDegrees(phiPrime) - sinDegrees(phi) * cosDegrees(psi - psiPrime);
		return (denom == 0.0) ? 0.0 : mod(arcTanDegrees(sinDegrees(psiPrime - psi) / denom, (denom < 0.0) ? 2 : 1), 360.0);
	}

	double ProtoDate::julianCenturies(double const tee)
	{
		return (dynamicalFromUniversal(tee) - ProtoDate::J2000) / 36525.0;
	}

	double ProtoDate::obliquity(double const tee)
	{
		constexpr double c = julianCenturies(tee);
		return angle(23.0, 26.0, 21.448) + poly(c, ob::coeffObliquity);
	}

	double ProtoDate::momentFromDepression(double const approx, Location *const locale, double const alpha)
	{
		constexpr double phi = locale->latitude;
		constexpr double tee = universalFromLocal(approx, locale);
		constexpr double delta = arcSinDegrees(sinDegrees(obliquity(tee)) * sinDegrees(solarLongitude(tee)));
		constexpr bool morning = mod(approx, 1.0) < 0.5;
		constexpr double sineOffset = tanDegrees(phi) * tanDegrees(delta) + sinDegrees(alpha) / (cosDegrees(delta) * cosDegrees(phi));
		constexpr double offset = mod(0.5 + arcSinDegrees(sineOffset) / deg(360.0), 1.0) - 0.5;
		if (std::abs(sineOffset) > 1.0)
		{
			throw TimeException();
		}
		return localFromApparent(std::floor(approx) + (morning ? (0.25 - offset) : (0.75 + offset)));
	}

	double ProtoDate::dawn(long long const date, Location *const locale, double const alpha)
	{
		double approx;
		try
		{
			approx = momentFromDepression(date + 0.25, locale, alpha);
		}
		catch (const TimeException &ex)
		{
			approx = static_cast<double>(date);
		}
		constexpr double result = momentFromDepression(approx, locale, alpha);
		return standardFromLocal(result, locale);
	}

	double ProtoDate::dusk(long long const date, Location *const locale, double const alpha)
	{
		double approx;
		try
		{
			approx = momentFromDepression(date + 0.75, locale, alpha);
		}
		catch (const TimeException &ex)
		{
			approx = date + 0.99;
		}
		constexpr double result = momentFromDepression(approx, locale, alpha);
		return standardFromLocal(result, locale);
	}

	double ProtoDate::sunrise(long long const date, Location *const locale)
	{
		constexpr double h = std::max(0.0, locale->elevation);
		constexpr double capR = mt(6372000.0);
		constexpr double dip = arcCosDegrees(capR / (capR + h));
		constexpr double alpha = angle(0.0, 50.0, 0.0) + dip;
		return dawn(date, locale, alpha);
	}

	double ProtoDate::sunset(long long const date, Location *const locale)
	{
		constexpr double h = std::max(0.0, locale->elevation);
		constexpr double capR = mt(6372000.0);
		constexpr double dip = arcCosDegrees(capR / (capR + h));
		constexpr double alpha = angle(0.0, 50.0, 0.0) + dip;
		return dusk(date, locale, alpha);
	}

	double ProtoDate::temporalHour(long long const date, Location *const locale)
	{
		return (sunset(date, locale) - sunrise(date, locale)) / 12.0;
	}

	double ProtoDate::standardFromSundial(long long const date, double const hour, Location *const locale)
	{
		constexpr double tee = temporalHour(date, locale);
		return sunrise(date, locale) + ((6.0 <= hour && hour <= 18.0) ? ((hour - 6.0) * tee) : ((hour - 6.0) * (0.08333333333333333 - tee)));
	}

	double ProtoDate::universalFromDynamical(double const tee)
	{
		return tee - ephemerisCorrection(tee);
	}

	double ProtoDate::dynamicalFromUniversal(double const tee)
	{
		return tee + ephemerisCorrection(tee);
	}

	double ProtoDate::ephemerisCorrection(double const tee)
	{
		constexpr long long year = Gregorian::yearFromFixed(static_cast<long long>(std::floor(tee)));
		constexpr double c = difference(Gregorian::toFixed(1900LL, 1, 1), Gregorian::toFixed(year, 7, 1)) / 36525.0;
		double result;
		if (1988LL <= year && year <= 2019LL)
		{
			result = (year - 1933LL) / 86400.0;
		}
		else if (1900LL <= year && year <= 1987LL)
		{
			result = poly(c, ec::coeff19th);
		}
		else if (1800LL <= year && year <= 1899LL)
		{
			result = poly(c, ec::coeff18th);
		}
		else if (1700LL <= year && year <= 1799LL)
		{
			result = poly(static_cast<double>(year - 1700LL), ec::coeff17th) / 86400.0;
		}
		else
		{
			if (1620LL > year || year > 1699LL)
			{
				constexpr double x = hr(12.0) + difference(Gregorian::toFixed(1810LL, 1, 1), Gregorian::toFixed(year, 1, 1));
				return (x * x / 4.104848E7 - 15.0) / 86400.0;
			}
			result = poly(static_cast<double>(year - 1600LL), ec::coeff16th) / 86400.0;
		}
		return result;
	}

	double ProtoDate::equationOfTime(double const tee)
	{
		constexpr double c = julianCenturies(tee);
		constexpr double longitude = poly(c, et::coeffLongitude);
		constexpr double anomaly = poly(c, et::coeffAnomaly);
		constexpr double eccentricity = poly(c, et::coeffEccentricity);
		constexpr double varepsilon = obliquity(tee);
		constexpr double y = square(tanDegrees(varepsilon / 2.0));
		constexpr double equation = 0.15915494309189535 * (y * sinDegrees(2.0 * longitude) + -2.0 * eccentricity * sinDegrees(anomaly) + 4.0 * eccentricity * y * sinDegrees(anomaly) * cosDegrees(2.0 * longitude) + -0.5 * y * y * sinDegrees(4.0 * longitude) + -1.25 * eccentricity * eccentricity * sinDegrees(2.0 * anomaly));

		return signum(equation) * std::min(std::abs(equation), hr(12.0));
	}

	double ProtoDate::localFromApparent(double const tee)
	{
		return tee - equationOfTime(tee);
	}

	double ProtoDate::apparentFromLocal(double const tee)
	{
		return tee + equationOfTime(tee);
	}

	double ProtoDate::solarLongitude(double const tee)
	{
		constexpr double c = julianCenturies(tee);
		double sigma = 0.0;
		for (int i = 0; i < sl::coefficients->length; ++i)
		{
			sigma += sl::coefficients[i] * sinDegrees(sl::multipliers[i] * c + sl::addends[i]);
		}
		constexpr double longitude = deg(282.7771834) + 36000.76953744 * c + 5.729577951308232E-6 * sigma;

		return mod(longitude + aberration(tee) + nutation(tee), 360.0);
	}

	double ProtoDate::nutation(double const tee)
	{
		constexpr double c = julianCenturies(tee);
		constexpr double capA = poly(c, nu::coeffa);
		constexpr double capB = poly(c, nu::coeffb);

		return deg(-0.004778) * sinDegrees(capA) + deg(-3.667E-4) * sinDegrees(capB);
	}

	double ProtoDate::aberration(double const tee)
	{
		constexpr double c = julianCenturies(tee);
		return deg(9.74E-5) * cosDegrees(deg(177.63) + deg(35999.01848) * c) - deg(0.005575);
	}

	double ProtoDate::solarLongitudeAfter(double const tee, double const phi)
	{
		constexpr double varepsilon = 1.0E-5;
		constexpr double rate = 365.242189 / deg(360.0);
		constexpr double tau = tee + rate * mod(phi - solarLongitude(tee), 360.0);
		constexpr double l = std::max(tee, tau - 5.0);
		constexpr double u = tau + 5.0;
		double lo = l;
		double hi = u;
		double x = (hi + lo) / 2.0;
		while (hi - lo > varepsilon)
		{
			if (mod(solarLongitude(x) - phi, 360.0) < deg(180.0))
			{
				hi = x;
			}
			else
			{
				lo = x;
			}
			x = (hi + lo) / 2.0;
		}
		return x;
	}

	double ProtoDate::lunarLongitude(double const tee)
	{
		constexpr double c = julianCenturies(tee);
		constexpr double meanMoon = degrees(poly(c, llon::coeffMeanMoon));
		constexpr double elongation = degrees(poly(c, llon::coeffElongation));
		constexpr double solarAnomaly = degrees(poly(c, llon::coeffSolarAnomaly));
		constexpr double lunarAnomaly = degrees(poly(c, llon::coeffLunarAnomaly));
		constexpr double moonNode = degrees(poly(c, llon::coeffMoonNode));
		constexpr double capE = poly(c, llon::coeffCapE);
		double sigma = 0.0;
		for (int i = 0; i < llon::argsLunarElongation->length; ++i)
		{
			constexpr double x = llon::argsSolarAnomaly[i];
			sigma += llon::sineCoefficients[i] * std::pow(capE, std::abs(x)) * sinDegrees(llon::argsLunarElongation[i] * elongation + x * solarAnomaly + llon::argsLunarAnomaly[i] * lunarAnomaly + llon::argsMoonFromNode[i] * moonNode);
		}
		constexpr double correction = deg(1.0) / 1000000.0 * sigma;
		constexpr double venus = deg(3958.0) / 1000000.0 * sinDegrees(119.75 + c * 131.849);
		constexpr double jupiter = deg(318.0) / 1000000.0 * sinDegrees(53.09 + c * 479264.29);
		constexpr double flatEarth = deg(1962.0) / 1000000.0 * sinDegrees(meanMoon - moonNode);

		return mod(meanMoon + correction + venus + jupiter + flatEarth + nutation(tee), 360.0);
	}

	double ProtoDate::nthNewMoon(long long const n)
	{
		constexpr double k = static_cast<double>(n - 24724LL);
		constexpr double c = k / 1236.85;
		constexpr double approx = poly(c, nm::coeffApprox);
		constexpr double capE = poly(c, nm::coeffCapE);
		constexpr double solarAnomaly = poly(c, nm::coeffSolarAnomaly);
		constexpr double lunarAnomaly = poly(c, nm::coeffLunarAnomaly);
		constexpr double moonArgument = poly(c, nm::coeffMoonArgument);
		constexpr double capOmega = poly(c, nm::coeffCapOmega);
		double correction = -1.7E-4 * sinDegrees(capOmega);
		for (int ix = 0; ix < nm::sineCoeff->length; ++ix)
		{
			correction += nm::sineCoeff[ix] * std::pow(capE, nm::EFactor[ix]) * sinDegrees(nm::solarCoeff[ix] * solarAnomaly + nm::lunarCoeff[ix] * lunarAnomaly + nm::moonCoeff[ix] * moonArgument);
		}
		double additional = 0.0;
		for (int ix2 = 0; ix2 < nm::addConst->length; ++ix2)
		{
			additional += nm::addFactor[ix2] * sinDegrees(nm::addConst[ix2] + nm::addCoeff[ix2] * k);
		}
		constexpr double extra = 3.25E-4 * sinDegrees(poly(c, nm::extra));

		return universalFromDynamical(approx + correction + extra + additional);
	}

	double ProtoDate::newMoonBefore(double const tee)
	{
		constexpr double t0 = nthNewMoon(0LL);
		constexpr double phi = lunarPhase(tee);
		constexpr long long n = static_cast<long long>(std::round((tee - t0) / 29.530588853 - phi / deg(360.0)));
		long long k;
		for (k = n - 1LL; nthNewMoon(k) < tee; ++k)
		{
		}
		--k;

		return nthNewMoon(k);
	}

	double ProtoDate::newMoonAfter(double const tee)
	{
		constexpr double t0 = nthNewMoon(0LL);
		constexpr double phi = lunarPhase(tee);
		long long k;
		for (long long n = k = static_cast<long long>(std::round((tee - t0) / 29.530588853 - phi / deg(360.0))); nthNewMoon(k) < tee; ++k)
		{
		}

		return nthNewMoon(k);
	}

	double ProtoDate::lunarPhase(double const tee)
	{
		return mod(lunarLongitude(tee) - solarLongitude(tee), 360.0);
	}

	double ProtoDate::lunarPhaseBefore(double const tee, double const phi)
	{
		constexpr double varepsilon = 1.0E-5;
		constexpr double tau = tee - 0.08202941348055556 * mod(lunarPhase(tee) - phi, deg(360.0));
		constexpr double l = tau - 2.0;
		constexpr double u = std::min(tee, tau + 2.0);
		double lo = l;
		double hi = u;
		double x = (hi + lo) / 2.0;
		while (hi - lo > varepsilon)
		{
			if (mod(lunarPhase(x) - phi, 360.0) < deg(180.0))
			{
				hi = x;
			}
			else
			{
				lo = x;
			}
			x = (hi + lo) / 2.0;
		}
		return x;
	}

	double ProtoDate::lunarPhaseAfter(double const tee, double const phi)
	{
		constexpr double varepsilon = 1.0E-5;
		constexpr double tau = tee + 0.08202941348055556 * mod(phi - lunarPhase(tee), deg(360.0));
		constexpr double l = std::max(tee, tau - 2.0);
		constexpr double u = tau + 2.0;
		double lo = l;
		double hi = u;
		double x = (hi + lo) / 2.0;
		while (hi - lo > varepsilon)
		{
			if (mod(lunarPhase(x) - phi, 360.0) < deg(180.0))
			{
				hi = x;
			}
			else
			{
				lo = x;
			}
			x = (hi + lo) / 2.0;
		}
		return x;
	}

	double ProtoDate::lunarLatitude(double const tee)
	{
		constexpr double c = julianCenturies(tee);
		constexpr double longitude = degrees(poly(c, llat::coeffLongitude));
		constexpr double elongation = degrees(poly(c, llat::coeffElongation));
		constexpr double solarAnomaly = degrees(poly(c, llat::coeffSolarAnomaly));
		constexpr double lunarAnomaly = degrees(poly(c, llat::coeffLunarAnomaly));
		constexpr double moonNode = degrees(poly(c, llat::coeffMoonNode));
		constexpr double capE = poly(c, llat::coeffCapE);
		double latitude = 0.0;
		for (int i = 0; i < llat::argsLunarElongation->length; ++i)
		{
			constexpr double x = llat::argsSolarAnomaly[i];
			latitude += llat::sineCoefficients[i] * std::pow(capE, std::abs(x)) * sinDegrees(llat::argsLunarElongation[i] * elongation + x * solarAnomaly + llat::argsLunarAnomaly[i] * lunarAnomaly + llat::argsMoonNode[i] * moonNode);
		}
		latitude *= deg(1.0) / 1000000.0;
		constexpr double venus = deg(175.0) / 1000000.0 * (sinDegrees(deg(119.75) + c * 131.849 + moonNode) + sinDegrees(deg(119.75) + c * 131.849 - moonNode));
		constexpr double flatEarth = deg(-2235.0) / 1000000.0 * sinDegrees(longitude) + deg(127.0) / 1000000.0 * sinDegrees(longitude - lunarAnomaly) + deg(-115.0) / 1000000.0 * sinDegrees(longitude + lunarAnomaly);
		constexpr double extra = deg(382.0) / 1000000.0 * sinDegrees(deg(313.45) + c * deg(481266.484));

		return mod(latitude + venus + flatEarth + extra, 360.0);
	}

	double ProtoDate::lunarAltitude(double const tee, Location *const locale)
	{
		constexpr double phi = locale->latitude;
		constexpr double psi = locale->longitude;
		constexpr double varepsilon = obliquity(tee);
		constexpr double lambda = lunarLongitude(tee);
		constexpr double beta = lunarLatitude(tee);
		constexpr double alpha = arcTanDegrees((sinDegrees(lambda) * cosDegrees(varepsilon) - tanDegrees(beta) * sinDegrees(varepsilon)) / cosDegrees(lambda), static_cast<int>(quotient(lambda, deg(90.0))) + 1);
		constexpr double delta = arcSinDegrees(sinDegrees(beta) * cosDegrees(varepsilon) + cosDegrees(beta) * sinDegrees(varepsilon) * sinDegrees(lambda));
		constexpr double theta0 = siderealFromMoment(tee);
		constexpr double capH = mod(theta0 + psi - alpha, 360.0);
		constexpr double altitude = arcSinDegrees(sinDegrees(phi) * sinDegrees(delta) + cosDegrees(phi) * cosDegrees(delta) * cosDegrees(capH));

		return mod(altitude + deg(180.0), 360.0) - deg(180.0);
	}

	double ProtoDate::estimatePriorSolarLongitude(double const tee, double const phi)
	{
		constexpr double rate = 365.242189 / deg(360.0);
		constexpr double tau = tee - rate * mod(solarLongitude(tee) - phi, 360.0);
		constexpr double capDelta = mod(solarLongitude(tau) - phi + deg(180.0), 360.0) - deg(180.0);

		return std::min(tee, tau - rate * capDelta);
	}

	bool ProtoDate::visibleCrescent(long long const date, Location *const locale)
	{
		constexpr double tee = universalFromStandard(dusk(date - 1LL, locale, deg(4.5)), locale);
		constexpr double phase = lunarPhase(tee);
		constexpr double altitude = lunarAltitude(tee, locale);
		constexpr double arcOfLight = arcCosDegrees(cosDegrees(lunarLatitude(tee)) * cosDegrees(phase));

		return ProtoDate::NEW < phase && phase < ProtoDate::FIRST_QUARTER && deg(10.6) <= arcOfLight && arcOfLight <= deg(90.0) && altitude > deg(4.1);
	}

	long long ProtoDate::phasisOnOrBefore(long long const date, Location *const locale)
	{
		constexpr long long mean = static_cast<long long>(date - std::floor(lunarPhase(static_cast<double>(date)) / deg(360.0) * 29.530588853));
		long long d;
		for (long long tau = d = ((date - mean <= 3LL && !visibleCrescent(date, locale)) ? (mean - 30LL) : (mean - 2LL)); !visibleCrescent(d, locale); ++d)
		{
		}
		return d;
	}

	double ProtoDate::siderealFromMoment(double const tee)
	{
		constexpr double c = (tee - ProtoDate::J2000) / 36525.0;
		return mod(poly(c, sfm::siderealCoeff), 360.0);
	}

	std::wstring ProtoDate::nameFromNumber(long long const number, std::vector<std::wstring> &nameList)
	{
		return nameList[static_cast<int>(adjustedMod(number, nameList.size())) - 1];
	}

	std::wstring ProtoDate::nameFromDayOfWeek(long long const dayOfWeek, std::vector<std::wstring> &nameList)
	{
		return nameFromNumber(dayOfWeek + 1LL, nameList);
	}

	std::wstring ProtoDate::nameFromMonth(long long const month, std::vector<std::wstring> &nameList)
	{
		return nameFromNumber(month, nameList);
	}

	std::wstring ProtoDate::toString()
	{
		return std::wstring::valueOf(this->getClass().getName()) + L"[" + this->toStringFields() + L"]";
	}

	std::wstring ProtoDate::format()
	{
		return this->toString();
	}

	const std::vector<double> ProtoDate::ob::coeffObliquity;
	const std::vector<double> ProtoDate::ec::coeff19th;
	const std::vector<double> ProtoDate::ec::coeff18th;
	const std::vector<double> ProtoDate::ec::coeff17th;
	const std::vector<double> ProtoDate::ec::coeff16th;
	const std::vector<double> ProtoDate::et::coeffLongitude;
	const std::vector<double> ProtoDate::et::coeffAnomaly;
	const std::vector<double> ProtoDate::et::coeffEccentricity;
	const std::vector<int> ProtoDate::sl::coefficients;
	const std::vector<double> ProtoDate::sl::multipliers;
	const std::vector<double> ProtoDate::sl::addends;
	const std::vector<double> ProtoDate::nu::coeffa;
	const std::vector<double> ProtoDate::nu::coeffb;
	const std::vector<double> ProtoDate::llon::coeffMeanMoon;
	const std::vector<double> ProtoDate::llon::coeffElongation;
	const std::vector<double> ProtoDate::llon::coeffSolarAnomaly;
	const std::vector<double> ProtoDate::llon::coeffLunarAnomaly;
	const std::vector<double> ProtoDate::llon::coeffMoonNode;
	const std::vector<double> ProtoDate::llon::coeffCapE;
	const std::vector<char> ProtoDate::llon::argsLunarElongation;
	const std::vector<char> ProtoDate::llon::argsSolarAnomaly;
	const std::vector<char> ProtoDate::llon::argsLunarAnomaly;
	const std::vector<char> ProtoDate::llon::argsMoonFromNode;
	const std::vector<int> ProtoDate::llon::sineCoefficients;
	const std::vector<double> ProtoDate::nm::coeffApprox;
	const std::vector<double> ProtoDate::nm::coeffCapE;
	const std::vector<double> ProtoDate::nm::coeffSolarAnomaly;
	const std::vector<double> ProtoDate::nm::coeffLunarAnomaly;
	const std::vector<double> ProtoDate::nm::coeffMoonArgument;
	const std::vector<double> ProtoDate::nm::coeffCapOmega;
	const std::vector<char> ProtoDate::nm::EFactor;
	const std::vector<char> ProtoDate::nm::solarCoeff;
	const std::vector<char> ProtoDate::nm::lunarCoeff;
	const std::vector<char> ProtoDate::nm::moonCoeff;
	const std::vector<double> ProtoDate::nm::sineCoeff;
	const std::vector<double> ProtoDate::nm::addConst;
	const std::vector<double> ProtoDate::nm::addCoeff;
	const std::vector<double> ProtoDate::nm::addFactor;
	const std::vector<double> ProtoDate::nm::extra;
	const std::vector<double> ProtoDate::llat::coeffLongitude;
	const std::vector<double> ProtoDate::llat::coeffElongation;
	const std::vector<double> ProtoDate::llat::coeffSolarAnomaly;
	const std::vector<double> ProtoDate::llat::coeffLunarAnomaly;
	const std::vector<double> ProtoDate::llat::coeffMoonNode;
	const std::vector<double> ProtoDate::llat::coeffCapE;
	const std::vector<char> ProtoDate::llat::argsLunarElongation;
	const std::vector<char> ProtoDate::llat::argsSolarAnomaly;
	const std::vector<char> ProtoDate::llat::argsLunarAnomaly;
	const std::vector<char> ProtoDate::llat::argsMoonNode;
	const std::vector<int> ProtoDate::llat::sineCoefficients;
	const std::vector<double> ProtoDate::sfm::siderealCoeff;
}
