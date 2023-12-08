#include "util/util.h"

namespace day_x
{
    namespace part_2
    {
        void run()
        {
            auto my_file = util::read_file("inputs/day_x.txt");

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