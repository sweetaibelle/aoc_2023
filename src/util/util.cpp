#include <vector>
#include <string>

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
}