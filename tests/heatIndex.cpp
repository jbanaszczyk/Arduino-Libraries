#include "stdafx.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../src/meteo.h"

static float toFahrenheit(const float fromCelcius)
{
	return 1.8f * fromCelcius + 32.0f;
}

static float toCelsius(const float fromFahrenheit)
{
	return (fromFahrenheit - 32.0f) / 1.8f;
}

static double toFahrenheit(const double fromCelcius)
{
	return 1.8 * fromCelcius + 32.0;
}

static double toCelsius(const double fromFahrenheit)
{
	return (fromFahrenheit - 32.0) / 1.8;
}

class ConversionFloat : public testing::TestWithParam<std::tuple<float, float>>
{
};

class ConversionDouble : public testing::TestWithParam<std::tuple<double, double>>
{
};

TEST_P(ConversionFloat, F2C_float)
{
	using jb::meteo::heatIndexF;
	using jb::meteo::heatIndexC;
	const auto tempC = std::get<0>(GetParam());
	const auto hum = std::get<1>(GetParam());
	const auto expected = toCelsius(heatIndexF(toFahrenheit(tempC), hum));
	const auto result = heatIndexC(tempC, hum);
	ASSERT_NEAR(expected, result, 0.0005f);
}

TEST_P(ConversionDouble, F2C_double)
{
	using jb::meteo::heatIndexF;
	using jb::meteo::heatIndexC;
	const auto tempC = std::get<0>(GetParam());
	const auto hum = std::get<1>(GetParam());
	const auto expected = toCelsius(heatIndexF(toFahrenheit(tempC), hum));
	const auto result = heatIndexC(tempC, hum);
	ASSERT_NEAR(expected, result, 0.0005);
}

INSTANTIATE_TEST_CASE_P(HeatIndex, ConversionFloat, testing::Combine(testing::Range(0.f, 50.1f, 4.0f), testing::Values(0.f, 100.1f, 4.0f)));
INSTANTIATE_TEST_CASE_P(HeatIndex, ConversionDouble, testing::Combine(testing::Range(0., 50.1, 4.0), testing::Values(0., 100.1, 4.0)));
