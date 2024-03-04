#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace kf
{
    class Log
    {
    private:
        static std::string getCurrentDateTimeAsString();

    public:
        static bool enableLogging;
        static bool showTime;
        static void info(std::string message);
        static void success(std::string message);
        static void warn(std::string message);
        static void error(std::string message);
    };
}