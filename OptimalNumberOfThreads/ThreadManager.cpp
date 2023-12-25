#include "ThreadManager.hpp"
#include <thread>
#include <algorithm>

unsigned int ThreadManager::getOptimalThreadCount(ThreadOption option, unsigned int specificCount) {
    unsigned int nCores = std::thread::hardware_concurrency();
    switch (option) {
    case ThreadOption::All:
        return nCores;
    case ThreadOption::Half:
        return nCores / 2;
    case ThreadOption::Third:
        return nCores / 3;
    case ThreadOption::Quarter:
        return nCores / 4;
    case ThreadOption::Specific:
        return std::min(specificCount, nCores);
    default:
        return 1;  // Default case for safety
    }
}

