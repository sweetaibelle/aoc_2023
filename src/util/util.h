#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <format>
#include <ranges>
#include <algorithm>

#pragma once

namespace util
{
    std::vector<std::string> split(const std::string &s, char c);
    void trim(std::string &s);
}