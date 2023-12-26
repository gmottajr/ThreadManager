#include "pch.h"

#include <gtest/gtest.h>
#include "../OptimalNumberOfThreads/CpuCoreSelector.hpp"
#include "../OptimalNumberOfThreads/CpuCoreSelector.cpp"

class CpuCoreSelectorShould : public ::testing::Test {
protected:
    
};

// Positive Test Cases
TEST_F(CpuCoreSelectorShould, ReturnAllCoresWhenAllOptionIsUsed) {
    int threadsToUse = CpuCoreSelector::getOptimalCount(CpuSelectionOption::All);
    EXPECT_EQ(threadsToUse, std::thread::hardware_concurrency());
}

TEST_F(CpuCoreSelectorShould, ReturnHalfCoresWhenHalfOptionIsUsed) {
    int threadsToUse = CpuCoreSelector::getOptimalCount(CpuSelectionOption::Half);
    EXPECT_EQ(threadsToUse, std::thread::hardware_concurrency() / 2);
}

TEST_F(CpuCoreSelectorShould, ReturnThirdCoresWhenThirdOptionIsUsed) {
    int threadsToUse = CpuCoreSelector::getOptimalCount(CpuSelectionOption::Third);
    EXPECT_EQ(threadsToUse, std::thread::hardware_concurrency() / 3);
}

TEST_F(CpuCoreSelectorShould, ReturnHalfCoresWhenQuarterOptionIsUsed) {
    int threadsToUse = CpuCoreSelector::getOptimalCount(CpuSelectionOption::Quarter);
    EXPECT_EQ(threadsToUse, std::thread::hardware_concurrency() / 4);
}

TEST_F(CpuCoreSelectorShould, ReturnSpecificNumberWhenSpecificOptionAndNumberAreGiven) {
    unsigned int specificNumber = 4;
    int threadsToUse = CpuCoreSelector::getOptimalCount(CpuSelectionOption::Specific, specificNumber);
    EXPECT_EQ(threadsToUse, specificNumber);
}

// Test for Specific option with number greater than available cores
TEST_F(CpuCoreSelectorShould, CapSpecificNumberAtMaxCores) {
    unsigned int largeNumber = 10000;  // Arbitrary large number
    unsigned int nCores = std::thread::hardware_concurrency();
    int threadsToUse = CpuCoreSelector::getOptimalCount(CpuSelectionOption::Specific, largeNumber);
    EXPECT_EQ(threadsToUse, nCores);
}

// Negative Test Cases - not many left, as enum restricts invalid inputs

// Assuming that you want to test behavior for invalid enum values
// This requires a bit of hacking since enum class doesn't allow invalid values directly
// A possible approach is to cast an invalid integer to the enum class
TEST_F(CpuCoreSelectorShould, HandleInvalidEnumValueGracefully) {
    int threadsToUse = CpuCoreSelector::getOptimalCount(static_cast<CpuSelectionOption>(-1));
    // default behavior, defaulting to 1 thread
    EXPECT_EQ(threadsToUse, 1);
}