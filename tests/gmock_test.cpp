#include "stdafx.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
	testing::InitGoogleMock(&argc, argv);
	testing::GMOCK_FLAG(catch_leaked_mocks) = true;
	testing::GMOCK_FLAG(verbose) = testing::internal::kWarningVerbosity;
	return RUN_ALL_TESTS();
}
