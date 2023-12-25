
#pragma once
#include <thread>

enum class ThreadOption {
    All, Half, Third, Quarter, Specific
};


/// <summary>
///     The ThreadManager class takes a std::string in its constructor, which represents the setting for max_no_of_threads.
///     It calculates the optimal number of threads in the updateThreadCount method based on this setting.
///     getOptimalThreadCount method can be used to retrieve the calculated number of threads.
///     The class encapsulates the logic for determining the number of threads, making it reusable and easy to integrate.
/// </summary>
class ThreadManager
{
public:
    static unsigned int getOptimalThreadCount(ThreadOption option, unsigned int specificCount = 0);
};




