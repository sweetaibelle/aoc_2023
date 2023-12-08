#include "util/util.h"

namespace day_8
{
    namespace part_2
    {
        void run()
        {
            auto my_file = util::read_file("inputs/day_8.txt");

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