#include "util/util.h"

namespace day_7
{
    namespace part_1
    {
        void run()
        {
            auto my_file = util::read_file("inputs/day_7.txt");

            if (!my_file.empty())
            {
                for (auto &line : my_file)
                {
                    std::cout << line << std::endl;
                }
            }
        }
    }
}