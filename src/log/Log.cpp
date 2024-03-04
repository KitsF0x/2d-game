#include "Log.hpp"

bool kf::Log::enableLogging{false};
bool kf::Log::showTime{false};

std::string kf::Log::getCurrentDateTimeAsString()
{
    if (!kf::Log::showTime)
        return "";
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

void kf::Log::info(std::string message)
{
    if (!kf::Log::enableLogging)
        return;
    std::cout << "[" << getCurrentDateTimeAsString() << "]\t"
              << "[INFO]\t" << message << std::endl;
}

void kf::Log::success(std::string message)
{
    if (!kf::Log::enableLogging)
        return;
    std::cout << "[" << getCurrentDateTimeAsString() << "]\t"
              << "[OK]\t" << message << std::endl;
}

void kf::Log::warn(std::string message)
{
    if (!kf::Log::enableLogging)
        return;
    std::cout << "[" << getCurrentDateTimeAsString() << "]\t"
              << "[WARN]\t" << message << std::endl;
}

void kf::Log::error(std::string message)
{
    if (!kf::Log::enableLogging)
        return;
    std::cout << "[" << getCurrentDateTimeAsString() << "]\t"
              << "[ERR]\t" << message << std::endl;
}
