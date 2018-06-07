#ifndef _JB_METEO_H_
#define _JB_METEO_H_

namespace jb {

	namespace meteo {

		/****************
		 * Heat index calculations
		 * According to: http://www.wpc.ncep.noaa.gov/html/heatindex_equation.shtml
		 * Formula conversion: thanks to Wolfram Alpha
		 ****************/
		float heatIndexF(float tempF, float humidity);
		float heatIndexC(float tempC, float humidity);
		double heatIndexF(double tempF, double humidity);
		double heatIndexC(double tempC, double humidity);

		float heatIndexF(const float tempF, const float humidity)
		{
			if (tempF <= 40.f)
			{
				return tempF;
			}

			const auto A = -10.3f + 1.1f * tempF + 0.47f * humidity;
			if (A < 79.0f)
			{
				return A;
			}

			const auto B = -42.379f + 2.04901523f * tempF + 10.14333127f * humidity - .22475541f * tempF * humidity - .00683783f * tempF * tempF - .05481717f * humidity * humidity + .00122874f * tempF * tempF * humidity + .00085282f * tempF * humidity * humidity - .00000199f * tempF * tempF * humidity * humidity;

			if (humidity <= 13.f && 80.f <= tempF && tempF <= 112.f)
			{
				return B - (13.f - humidity) / 4.f * sqrt((17.f - abs(tempF - 95.f)) / 17.f);
			}

			if (humidity > 85.f && 80.f <= tempF && tempF <= 87.f)
			{
				return B + (humidity - 85.f) / 10.f * ((87.f - tempF) / 5.f);
			}
			return B;
		}

		float heatIndexC(const float tempC, const float humidity)
		{
			if (tempC <= 4.444f)
			{
				return tempC;
			}

			const auto A = -3.94444f + 0.261111f * humidity + 1.1f * tempC;
			if (A < 26.111f)
			{
				return A;
			}

			const auto B = -8.78461f + (1.6114f - 0.0123081f * tempC) * tempC + humidity * (2.33854f + (-0.146116f + 0.00221173f * tempC) * tempC + humidity * (-0.0164248f + (0.725461e-3f - 3.582e-6f * tempC) * tempC));

			if (humidity <= 13.f && 26.667f <= tempC && tempC <= 44.444f)
			{
				return B + 0.0336855f * (humidity - 13.f) * sqrt(17.f - abs(63.f - 1.8f * tempC));
			}

			if (humidity > 85.f && 26.666f <= tempC && tempC <= 30.5565f)
			{
				return B + 0.0111111f * (humidity - 85.f) * (55.f - 1.8f * tempC);
			}

			return B;
		}

		double heatIndexF(const double tempF, const double humidity)
		{
			if (tempF <= 40.)
			{
				return tempF;
			}

			const auto A = -10.3 + 1.1 * tempF + 0.47 * humidity;
			if (A < 79.0)
			{
				return A;
			}

			const auto B = -42.379 + 2.04901523 * tempF + 10.14333127 * humidity - .22475541 * tempF * humidity - .00683783 * tempF * tempF - .05481717 * humidity * humidity + .00122874 * tempF * tempF * humidity + .00085282 * tempF * humidity * humidity - .00000199 * tempF * tempF * humidity * humidity;

			if (humidity <= 13. && 80. <= tempF && tempF <= 112.)
			{
				return B - (13. - humidity) / 4. * sqrt((17. - abs(tempF - 95.)) / 17.);
			}

			if (humidity > 85. && 80. <= tempF && tempF <= 87.)
			{
				return B + (humidity - 85.) / 10. * ((87. - tempF) / 5.);
			}
			return B;
		}

		double heatIndexC(const double tempC, const double humidity)
		{
			if (tempC <= 4.444)
			{
				return tempC;
			}

			const auto A = -3.94444 + 0.261111 * humidity + 1.1 * tempC;
			if (A < 26.111)
			{
				return A;
			}

			const auto B = -8.78461 + (1.6114 - 0.0123081 * tempC) * tempC + humidity * (2.33854 + (-0.146116 + 0.00221173 * tempC) * tempC + humidity * (-0.0164248 + (0.725461e-3 - 3.582e-6 * tempC) * tempC));

			if (humidity <= 13. && 26.667 <= tempC && tempC <= 44.444)
			{
				return B + 0.0336855 * (humidity - 13.) * sqrt(17. - abs(63. - 1.8 * tempC));
			}

			if (humidity > 85. && 26.666 <= tempC && tempC <= 30.5565)
			{
				return B + 0.0111111 * (humidity - 85.) * (55. - 1.8 * tempC);
			}

			return B;
		}
	}
}

#endif
