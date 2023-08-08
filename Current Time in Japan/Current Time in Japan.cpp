#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

int main() {
    // Get the current time in UTC
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    // Convert to Tokyo time (UTC+9)
    std::chrono::hours tokyo_offset(9);
    std::chrono::system_clock::time_point tokyo_time = now + tokyo_offset;

    // Convert the time point to a time_t object
    std::time_t tokyo_time_t = std::chrono::system_clock::to_time_t(tokyo_time);

    // Convert the time_t object to a local time structure (using localtime_s for thread safety)
    std::tm tokyo_time_info;
    localtime_s(&tokyo_time_info, &tokyo_time_t);

    // Format and print the time in Tokyo
    char time_str[100];
    std::strftime(time_str, sizeof(time_str), "%Y-%m-%d %I:%M:%S %p", &tokyo_time_info);

    std::cout << "Current time in Tokyo, Japan: " << time_str << std::endl;

    // Determine if it's AM or PM
    if (tokyo_time_info.tm_hour >= 0 && tokyo_time_info.tm_hour < 12)
        std::cout << "It's AM." << std::endl;
    else
        std::cout << "It's PM." << std::endl;

    return 0;
}

