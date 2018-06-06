[![download](https://img.shields.io/badge/current-download-brightgreen.svg)](https://github.com/jbanaszczyk/ArduinoLibraries/archive/master.zip)
[![Version](https://img.shields.io/badge/release-0.0-red.svg)](https://github.com/jbanaszczyk/ArduinoLibraries/releases)
[![Platform](https://img.shields.io/badge/platform-arduino-blue.svg)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/c%2B%2B-11/14-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![License](https://img.shields.io/badge/license-BSL-blue.svg)](https://www.boost.org/LICENSE_1_0.txt)


# my Arduino Libraries

I'm proud to present my some commonly used libraries (tribool, units, compact optional) for Arduino.

## License

"my Arduino Libraries" library is distributed under [Boost Software License 1.0 (BSL-1.0)](https://www.boost.org/LICENSE_1_0.txt).

## libaries

| library | short                    | download                                                                                   | documentation                                                                                |
|:--------|:-------------------------|:-------------------------------------------------------------------------------------------|:---------------------------------------------------------------------------------------------|
| tribool | true/false/unknown logic | [src/tribool.h](https://github.com/jbanaszczyk/ArduinoLibraries/raw/master/src/tribool.h) | [doc/tribool.md](https://github.com/jbanaszczyk/ArduinoLibraries/blob/master/doc/tribool.md) |


## For beginners: principles of use

1. Just copy requested file from my GitHub into your project
   * it is located in `src` directory
2. Review `examples` directory.
   * find example ending with `01`. 
     * Like `tribool01`. It is simplest example for `tribool` library
	* There is example sketch (for example: `tribool01.ino`)
	* Look at the beginning of the file
	* Copy lines `#include ...` and `using ...` into your sketch
3. Voila

## End of section "For beginners"

Probably there is nothing interesting below. Feel free to skip the rest.

---

## Design principles

**Motivation**
* "My Arduino Libraries" contains reusable code selected from my projects.

**Platform, language**
* "My Arduino Libraries" are designed using C++11.
* Code is as portable as possible. That means, that it should work on any platform.

**Arduino specific**
* If reasonable I'm using Arduino specific features and exclusions
* Important flags, features and exclusions
  * `-std=gnu++11` : "My Arduino Libraries" are designed using C++11
  * `-Os` : [optimize for size](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#Optimize-Options) - sometimes it matters
  * `-fno-exceptions` : not using `try`/`catch` nor `noexcept` 
  * `-fno-threadsafe-statics` : Arduino executor is single threaded, compiler does not care on thread safety, my library does not care about thread safety
  * `int24_t` : can be used as base type for specific enumerations
  * `PROGMEM` : used if it is reasonable (to store large `const` structures or strings)
  * C++ Standard Library : Arduino does not implement C++ Standard Library, so many features are not available and not used (for example: `type_traits` are not implemented)

**Headers only**
* Most of "My Arduino Libraries" are in the designed as "single header" and "headers only". 
  * Yes, it increases compile time.

**Namespaces**
* "My Arduino Libraries" avoids namespace pollution
* Most of functionality is located within `namespace jb` or within anonymous namespace.

## Cloning, testing

Refer to [cloning.md](doc/cloning.md)
