# tribool.h

## Description

Arduino port of [Boost.Tribool](https://www.boost.org/doc/libs/1_67_0/doc/html/tribool.html), Copyright © 2002-2004 Douglas Gregor

The 3-state boolean library along with support functions and operator overloads that implement 3-state boolean logic.

## Usage

```C++
#include <tribool.h>
...
using namespace jb::logic;
tribool state = unknown;
...
if (state)	{
	// action if true
} else if (!state) {
	// action if false
} else {
	// action if unknown
}
```

## API

### Literals

`tribool.h` provides literals (a bit similar to `bool`): `false`, `true`, `unknown`

### Basic operators

| A       | !A      |
|:--------|:--------|
| false   | true    |
| true    | false   |
| unknown | unknown |

| A       | B       | A && B  |
|:--------|:--------|:--------|
| false   | false   | false   |
| false   | true    | false   | 
| false   | unknown | false   | 
| true    | false   | false   |
| true    | true    | true    |
| true    | unknown | unknown |
| unknown | false   | false   |
| unknown | true    | unknown |
| unknown | unknown | unknown |

| A       | B       | A \|\| B  |
|:--------|:--------|:--------|
| false   | false   | false   |
| false   | true    | true    |
| false   | unknown | unknown |
| true    | false   | true    |
| true    | true    | true    |
| true    | unknown | true    |
| unknown | false   | unknown |
| unknown | true    | true    |
| unknown | unknown | unknown |

### Comparing

Tribool provides comparison operators. Be careful: `unknown` is a kind of "not a value" (a bit similar to `NaN`).
* it is not a true, that two unknown values are equal
* it is not a true, that two unknown values are not equal
* Value of `unknown == unknown` is `unknown` 

To check if value is `unknown` use:
```C++
    if ( unknown(state) ) ...
```
or
```C++
    if ( ! state.isBool() ) ...
```

| A       | B       | A == B  |
|:--------|:--------|:--------|
| false   | false   | true    |
| false   | true    | false   | 
| false   | unknown | unknown |
| true    | false   | false   |
| true    | true    | true    |
| true    | unknown | unknown |
| unknown | false   | unknown |
| unknown | true    | unknown |
| unknown | unknown | unknown |

### Printing

There is provided conversion to char

| A       | char(A) |
|:--------|:--------|
| false   | '0'     |
| true    | '1'     |
| unknown | '?'     |

```C++
    Serial.print(char(state));
```
