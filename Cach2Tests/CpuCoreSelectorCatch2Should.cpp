#define CATCH_CONFIG_MAIN
#include "../../../../../C++/TestAdapter_Catch2/ReferenceTests/src/catch2/catch.hpp"
#include "../OptimalNumberOfThreads/CpuCoreSelector.hpp"
#include "../OptimalNumberOfThreads/CpuCoreSelector.cpp"
#include <thread>


TEST_CASE("ThreadManager returns correct thread counts", "[ThreadManager]") {
    SECTION("Return all cores for All option") {
        REQUIRE(CpuCoreSelector::getOptimalCount(CpuSelectionOption::All) == std::thread::hardware_concurrency());
    }

    SECTION("Return half cores for Half option") {
        REQUIRE(CpuCoreSelector::getOptimalCount(CpuSelectionOption::Half) == std::thread::hardware_concurrency() / 2);
    }

    // Add more sections for Third, Quarter, and Specific options
}

TEST_CASE("ThreadManager handles invalid cases", "[ThreadManager]") {
    SECTION("Handle invalid specific count gracefully") {
        // You can test for an unusually high specific count, expecting it to return the max hardware concurrency
        REQUIRE(CpuCoreSelector::getOptimalCount(CpuSelectionOption::Specific, 10000) <= std::thread::hardware_concurrency());
    }

    // Add more sections for any other invalid or edge cases you want to test
}