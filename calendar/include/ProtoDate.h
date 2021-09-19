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
#include <vector>
#include <cmath>
#include <any>

namespace calendar { class Location; }
namespace calendar { class Date; }

namespace calendar
{

	class ProtoDate : public Date
	{
	public:
		static constexpr int JANUARY = 1;
		static constexpr int FEBRUARY = 2;
		static constexpr int MARCH = 3;
		static constexpr int APRIL = 4;
		static constexpr int MAY = 5;
		static constexpr int JUNE = 6;
		static constexpr int JULY = 7;
		static constexpr int AUGUST = 8;
		static constexpr int SEPTEMBER = 9;
		static constexpr int OCTOBER = 10;
		static constexpr int NOVEMBER = 11;
		static constexpr int DECEMBER = 12;
		static constexpr int SUNDAY = 0;
		static constexpr int MONDAY = 1;
		static constexpr int TUESDAY = 2;
		static constexpr int WEDNESDAY = 3;
		static constexpr int THURSDAY = 4;
		static constexpr int FRIDAY = 5;
		static constexpr int SATURDAY = 6;
		static constexpr double JD_EPOCH = -1721424.5;
		static constexpr long long MJD_EPOCH = 678576LL;
		static const double J2000;
		static constexpr double MEAN_TROPICAL_YEAR = 365.242189;
		static constexpr double MEAN_SYNODIC_MONTH = 29.530588853;
		static const double NEW;
		static const double FIRST_QUARTER;
		static const double FULL;
		static const double LAST_QUARTER;
		static const double SPRING;
		static const double SUMMER;
		static const double AUTUMN;
		static const double WINTER;
		static Location *const JERUSALEM;

		private:
			class StaticConstructor
			{
			public:
				StaticConstructor();
			};

		private:
			static ProtoDate::StaticConstructor staticConstructor;


	public:
		ProtoDate();

		ProtoDate(long long const date);

		ProtoDate(Date const date);

		virtual void fromFixed(long long const p0) = 0;

		virtual void fromDate(Date const fromDate);

		virtual void fromArray(std::vector<int> &p0) = 0;

		static void convert(Date const fromDate, ProtoDate *const toDate);

		static double currentMoment();

		static long long currentDate();

		static long long difference(Date const date1, Date const date2);

		static long long difference(long long const date1, Date const date2);

		static long long difference(Date const date1, long long const date2);

		static long long difference(long long const date1, long long const date2);

		static double mod(double const x, double const y);

		static int mod(int const x, int const y);

		static long long mod(long long const x, long long const y);

		static long long quotient(double const x, double const y);

		static int adjustedMod(int const x, int const y);

		static long long adjustedMod(long long const x, long long const y);

		static double adjustedMod(double const x, double const y);

		static long long dayOfWeekFromFixed(long long const date);

		static long long kDayOnOrBefore(long long const date, int const k);

		static long long kDayOnOrAfter(long long const date, int const k);

		static long long kDayNearest(long long const date, int const k);

		static long long kDayAfter(long long const date, int const k);

		static long long kDayBefore(long long const date, int const k);

		static long long nthKDay(int const n, int const k, long long const gDate);

		static long long firstKDay(int const k, long long const gDate);

		static long long lastKDay(int const k, long long const gDate);

		static int signum(double const x);

		static double square(double const x);

		static double poly(double const x, std::vector<double> &a);

		static double hr(double const x);

		static double mt(double const x);

		static double deg(double const x);

		static std::vector<double> deg(std::vector<double> &x);

		static double angle(double const d, double const m, double const s);

		static double degrees(double const theta);

		static double radiansToDegrees(double const theta);

		static double degreesToRadians(double const theta);

		static double sinDegrees(double const theta);

		static double cosDegrees(double const theta);

		static double tanDegrees(double const theta);

		static double arcTanDegrees(double const x, int const quad);

		static double arcSinDegrees(double const x);

		static double arcCosDegrees(double const x);

		static double standardFromUniversal(double const teeU, Location *const locale);

		static double universalFromStandard(double const teeS, Location *const locale);

		static double localFromUniversal(double const teeU, Location *const locale);

		static double universalFromLocal(double const teeEll, Location *const locale);

		static double standardFromLocal(double const teeEll, Location *const locale);

		static double localFromStandard(double const teeS, Location *const locale);

		static double midday(long long const date, Location *const locale);

		static double midnight(long long const date, Location *const locale);

		static double momentFromJD(double const jd);

		static double jdFromMoment(double const tee);

		static long long fixedFromJD(double const jd);

		static double jdFromFixed(long long const date);

		static long long fixedFromMJD(double const mjd);

		static double mjdFromFixed(long long const date);

		static double direction(Location *const locale, Location *const focus);

		static double julianCenturies(double const tee);

		static double obliquity(double const tee);

		static double momentFromDepression(double const approx, Location *const locale, double const alpha);

		static double dawn(long long const date, Location *const locale, double const alpha);

		static double dusk(long long const date, Location *const locale, double const alpha);

		static double sunrise(long long const date, Location *const locale);

		static double sunset(long long const date, Location *const locale);

		static double temporalHour(long long const date, Location *const locale);

		static double standardFromSundial(long long const date, double const hour, Location *const locale);

		static double universalFromDynamical(double const tee);

		static double dynamicalFromUniversal(double const tee);

		static double ephemerisCorrection(double const tee);

		static double equationOfTime(double const tee);

		static double localFromApparent(double const tee);

		static double apparentFromLocal(double const tee);

		static double solarLongitude(double const tee);

		static double nutation(double const tee);

		static double aberration(double const tee);

		static double solarLongitudeAfter(double const tee, double const phi);

		static double lunarLongitude(double const tee);

		static double nthNewMoon(long long const n);

		static double newMoonBefore(double const tee);

		static double newMoonAfter(double const tee);

		static double lunarPhase(double const tee);

		static double lunarPhaseBefore(double const tee, double const phi);

		static double lunarPhaseAfter(double const tee, double const phi);

		static double lunarLatitude(double const tee);

		static double lunarAltitude(double const tee, Location *const locale);

		static double estimatePriorSolarLongitude(double const tee, double const phi);

		static bool visibleCrescent(long long const date, Location *const locale);

		static long long phasisOnOrBefore(long long const date, Location *const locale);

		static double siderealFromMoment(double const tee);

		static std::wstring nameFromNumber(long long const number, std::vector<std::wstring> &nameList);

		static std::wstring nameFromDayOfWeek(long long const dayOfWeek, std::vector<std::wstring> &nameList);

		static std::wstring nameFromMonth(long long const month, std::vector<std::wstring> &nameList);

		virtual std::wstring toString();

		virtual std::wstring format();

	protected:
		virtual std::wstring toStringFields() = 0;

	public:
		virtual bool equals(std::any const p0) = 0;

	private:
		class ob
		{
		private:
			static const std::vector<double> coeffObliquity;

		};

	private:
		class ec
		{
		private:
			static const std::vector<double> coeff19th;
			static const std::vector<double> coeff18th;
			static const std::vector<double> coeff17th;
			static const std::vector<double> coeff16th;

		};

	private:
		class et
		{
		private:
			static const std::vector<double> coeffLongitude;
			static const std::vector<double> coeffAnomaly;
			static const std::vector<double> coeffEccentricity;

		};

	private:
		class sl
		{
		private:
			static const std::vector<int> coefficients;
			static const std::vector<double> multipliers;
			static const std::vector<double> addends;

		};

	private:
		class nu
		{
		private:
			static const std::vector<double> coeffa;
			static const std::vector<double> coeffb;

		};

	private:
		class llon
		{
		private:
			static const std::vector<double> coeffMeanMoon;
			static const std::vector<double> coeffElongation;
			static const std::vector<double> coeffSolarAnomaly;
			static const std::vector<double> coeffLunarAnomaly;
			static const std::vector<double> coeffMoonNode;
			static const std::vector<double> coeffCapE;
			static const std::vector<char> argsLunarElongation;
			static const std::vector<char> argsSolarAnomaly;
			static const std::vector<char> argsLunarAnomaly;
			static const std::vector<char> argsMoonFromNode;
			static const std::vector<int> sineCoefficients;

		};

	private:
		class nm
		{
		private:
			static const std::vector<double> coeffApprox;
			static const std::vector<double> coeffCapE;
			static const std::vector<double> coeffSolarAnomaly;
			static const std::vector<double> coeffLunarAnomaly;
			static const std::vector<double> coeffMoonArgument;
			static const std::vector<double> coeffCapOmega;
			static const std::vector<char> EFactor;
			static const std::vector<char> solarCoeff;
			static const std::vector<char> lunarCoeff;
			static const std::vector<char> moonCoeff;
			static const std::vector<double> sineCoeff;
			static const std::vector<double> addConst;
			static const std::vector<double> addCoeff;
			static const std::vector<double> addFactor;
			static const std::vector<double> extra;

		};

	private:
		class llat
		{
		private:
			static const std::vector<double> coeffLongitude;
			static const std::vector<double> coeffElongation;
			static const std::vector<double> coeffSolarAnomaly;
			static const std::vector<double> coeffLunarAnomaly;
			static const std::vector<double> coeffMoonNode;
			static const std::vector<double> coeffCapE;
			static const std::vector<char> argsLunarElongation;
			static const std::vector<char> argsSolarAnomaly;
			static const std::vector<char> argsLunarAnomaly;
			static const std::vector<char> argsMoonNode;
			static const std::vector<int> sineCoefficients;

		};

	private:
		class sfm
		{
		private:
			static const std::vector<double> siderealCoeff;

		};
	};

}
