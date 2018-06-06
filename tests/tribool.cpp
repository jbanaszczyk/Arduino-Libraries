#include "stdafx.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../src/tribool.h"


TEST(tribool, false)
{
	using namespace jb::logic;

	const tribool value_false(false);

	ASSERT_FALSE(value_false);
	ASSERT_TRUE(value_false == false);
	ASSERT_TRUE(false == value_false);
	ASSERT_TRUE(value_false != true);
	ASSERT_TRUE(true != value_false);
	ASSERT_TRUE(unknown(value_false == unknown));
	ASSERT_TRUE(unknown(unknown == value_false));
	ASSERT_TRUE(unknown(value_false != unknown));
	ASSERT_TRUE(unknown(unknown != value_false));
	ASSERT_TRUE(value_false == value_false);
	ASSERT_FALSE(value_false != value_false);
	ASSERT_FALSE(value_false && true);
	ASSERT_FALSE(true && value_false);
	ASSERT_TRUE(value_false || true);
	ASSERT_TRUE(true || value_false);
	ASSERT_EQ('0', char(value_false));
}

TEST(tribool, true)
{
	using namespace jb::logic;

	const tribool value_true(true);

	ASSERT_TRUE(value_true);
	ASSERT_TRUE(value_true == true);
	ASSERT_TRUE(true == value_true);
	ASSERT_TRUE(value_true != false);
	ASSERT_TRUE(false != value_true);
	ASSERT_TRUE(unknown(value_true == unknown));
	ASSERT_TRUE(unknown(unknown == value_true));
	ASSERT_TRUE(unknown(value_true != unknown));
	ASSERT_TRUE(unknown(unknown != value_true));
	ASSERT_TRUE(value_true == value_true);
	ASSERT_FALSE(value_true != value_true);
	ASSERT_EQ('1', char(value_true));
}

TEST(tribool, unknown)
{
	using namespace jb::logic;

	const tribool value_unknown(unknown);

	ASSERT_TRUE(unknown(value_unknown || !value_unknown));
	ASSERT_TRUE(unknown(value_unknown == true));
	ASSERT_TRUE(unknown(true == value_unknown));
	ASSERT_TRUE(unknown(value_unknown == false));
	ASSERT_TRUE(unknown(false == value_unknown));
	ASSERT_TRUE(unknown(value_unknown == unknown));
	ASSERT_TRUE(unknown(unknown == value_unknown));
	ASSERT_TRUE(unknown(value_unknown != unknown));
	ASSERT_TRUE(unknown(unknown != value_unknown));
	ASSERT_TRUE(unknown(value_unknown == value_unknown));
	ASSERT_TRUE(unknown(value_unknown != value_unknown));
	ASSERT_EQ('?', char(value_unknown));
}

TEST(tribool, relations)
{
	using namespace jb::logic;

	const tribool value_true(true);
	const tribool value_false(false);
	const tribool value_unknown(unknown);

	ASSERT_FALSE(value_false == value_true);
	ASSERT_TRUE(value_false != value_true);
	ASSERT_TRUE(unknown(value_false == value_unknown));
	ASSERT_TRUE(unknown(value_false != value_unknown));
	ASSERT_TRUE(unknown(value_true == value_unknown));
	ASSERT_TRUE(unknown(value_true != value_unknown));
}

TEST(tribool, operators)
{
	using namespace jb::logic;

	const tribool value_true(true);
	const tribool value_false(false);
	const tribool value_unknown(unknown);

	ASSERT_FALSE(value_false && value_true);
	ASSERT_TRUE(value_false || value_true);
	ASSERT_FALSE(value_false && value_unknown);
	ASSERT_TRUE(unknown(value_true && value_unknown));
	ASSERT_TRUE(unknown(value_unknown && value_unknown));
	ASSERT_TRUE(unknown(value_unknown || value_unknown));
	ASSERT_TRUE(unknown(value_false || value_unknown));
	ASSERT_TRUE(value_true || value_unknown);

	ASSERT_TRUE(unknown(value_true && unknown));
	ASSERT_TRUE(unknown(unknown && value_true));
	ASSERT_FALSE(value_false && unknown);
	ASSERT_FALSE(unknown && value_false);

	ASSERT_TRUE(unknown || value_true);
	ASSERT_TRUE(value_true || unknown);
	ASSERT_TRUE(unknown(value_false || unknown));
	ASSERT_TRUE(unknown(unknown || value_false));
}

TEST(tribool, ifUnknown)
{
	using namespace jb::logic;

	const tribool value_unknown(unknown);

	// Test the if (value_unknown) ... else (!value_unknown) ... else ... idiom
	if (value_unknown)
	{
		FAIL();
	}
	else if (!value_unknown)
	{
		FAIL();
	}
	else
	{
		SUCCEED();
	}
}

TEST(tribool, ifTrue)
{
	using namespace jb::logic;

	const tribool value_true(true);

	if (value_true)
	{
		SUCCEED();
	}
	else if (!value_true)
	{
		FAIL();
	}
	else
	{
		FAIL();
	}
}

TEST(tribool, ifFalse)
{
	using namespace jb::logic;

	const tribool value_false(false);

	if (value_false)
	{
		FAIL();
	}
	else if (!value_false)
	{
		SUCCEED();
	}
	else
	{
		FAIL();
	}
}

TEST(tribool, constexpr)
{
	using namespace jb::logic;

	constexpr bool res_ors = unknown(false || tribool(false) || false || unknown); // true
	ASSERT_TRUE(res_ors);
	char array_ors[res_ors ? 2 : 3];
	ASSERT_TRUE(sizeof(array_ors) / sizeof(char) == 2);

	constexpr bool res_ands = !unknown(!(true && tribool(true) && true && unknown)); // false
	ASSERT_FALSE(res_ands);
	char array_ands[res_ands ? 2 : 3];
	ASSERT_TRUE(sizeof(array_ands) / sizeof(char) == 3);

	// We avoid checking the tribool::operator safe_bool(),
	// because GCC-4.8 fails to evaluate it at compile-time.
	constexpr tribool xyz = (tribool(true) || tribool(unknown));
	static_assert(xyz, "Must be true!");
}

