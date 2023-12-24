#include "pch.h"

#include <gtest/gtest.h>
#include "../OptimalNumberOfThreads/ThreadManager.h"

class ThreadManagerShould : public ::testing::Test {
protected:
    
};

// Positive Test Cases
TEST_F(ThreadManagerShould, ReturnAllCoresWhenAllOptionIsUsed) {
    int threadsToUse = ThreadManager::getOptimalThreadCount(ThreadOption::All);
    EXPECT_EQ(threadsToUse, std::thread::hardware_concurrency());
}

TEST_F(ThreadManagerShould, ReturnHalfCoresWhenHalfOptionIsUsed) {
    int threadsToUse = ThreadManager::getOptimalThreadCount(ThreadOption::Half);
    EXPECT_EQ(threadsToUse, std::thread::hardware_concurrency() / 2);
}

TEST_F(ThreadManagerShould, ReturnThirdCoresWhenThirdOptionIsUsed) {
    int threadsToUse = ThreadManager::getOptimalThreadCount(ThreadOption::Third);
    EXPECT_EQ(threadsToUse, std::thread::hardware_concurrency() / 3);
}

TEST_F(ThreadManagerShould, ReturnHalfCoresWhenQuarterOptionIsUsed) {
    int threadsToUse = ThreadManager::getOptimalThreadCount(ThreadOption::Quarter);
    EXPECT_EQ(threadsToUse, std::thread::hardware_concurrency() / 4);
}

TEST_F(ThreadManagerShould, ReturnSpecificNumberWhenSpecificOptionAndNumberAreGiven) {
    unsigned int specificNumber = 4;
    int threadsToUse = ThreadManager::getOptimalThreadCount(ThreadOption::Specific, specificNumber);
    EXPECT_EQ(threadsToUse, specificNumber);
}

// Test for Specific option with number greater than available cores
TEST_F(ThreadManagerShould, CapSpecificNumberAtMaxCores) {
    unsigned int largeNumber = 10000;  // Arbitrary large number
    unsigned int nCores = std::thread::hardware_concurrency();
    int threadsToUse = ThreadManager::getOptimalThreadCount(ThreadOption::Specific, largeNumber);
    EXPECT_EQ(threadsToUse, nCores);
}

// Negative Test Cases - not many left, as enum restricts invalid inputs

// Assuming that you want to test behavior for invalid enum values
// This requires a bit of hacking since enum class doesn't allow invalid values directly
// A possible approach is to cast an invalid integer to the enum class
TEST_F(ThreadManagerShould, HandleInvalidEnumValueGracefully) {
    int threadsToUse = ThreadManager::getOptimalThreadCount(static_cast<ThreadOption>(-1));
    // default behavior, defaulting to 1 thread
    EXPECT_EQ(threadsToUse, 1);
}