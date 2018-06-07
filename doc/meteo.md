# meteo.h

## Description

Library contains some weather and air condition related calculations.

## Usage


## API

### Heat Index

Heat index is calculated according to http://www.wpc.ncep.noaa.gov/html/heatindex_equation.shtml

* `float heatIndexF(float tempF, float humidity);`
  * Calculates heat index according to formula using Fahrenheit temperature scale
* `double heatIndexF(double tempF, double humidity);`
  * Calculates heat index according to formula using Fahrenheit temperature scale
* `float heatIndexC(float tempC, float humidity);`
  * Calculates heat index according to formula using Celsius temperature scale. Temperature is not converted into Fahrenheit and back. Formulas were recalculated for Celsius scale. Thanks to [Wolfram Alpha](https://www.wolframalpha.com) 
* `double heatIndexC(double tempC, double humidity);`
  * Calculates heat index according to formula using Celsius temperature scale.
	 
### Dew Point

http://irtfweb.ifa.hawaii.edu/~tcs3/tcs3/Misc/Dewpoint_Calculation_Humidity_Sensor_E.pdf
https://www.azosensors.com/article.aspx?ArticleID=23
https://en.wikipedia.org/wiki/Dew_point



