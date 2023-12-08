#include "util.h"

// A lot of this code is just going to be stuff I found on the internet. I'm not going to try to reinvent the wheel here.
// I'm just going to try to make it work for my purposes.
// https://stackoverflow.com/questions/66897068/can-trim-of-a-string-be-done-inplace-with-c20-ranges

namespace util
{
    std::vector<std::string> split(const std::string &s, char c)
    {
        std::vector<std::string> result;
        size_t begin = 0;
        while (true)
        {
            size_t end = s.find_first_of(c, begin);
            result.push_back(s.substr(begin, end - begin));

            if (end == std::string::npos)
            {
                break;
            }

            begin = end + 1;
        }
        return result;
    }

    void trim(std::string &s)
    {
        auto not_space = [](unsigned char c)
        {
            return !std::isspace(c);
        };

        // Erase the spaces at the back.
        s.erase(std::ranges::find_if(s | std::views::reverse, not_space).base(),s.end());

        // Erase the spaces at the front.
        s.erase(s.begin(), std::ranges::find_if(s, not_space));
    }
}