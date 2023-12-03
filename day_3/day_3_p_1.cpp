#include "util/util.h"
#include "day_3/day_3.h"

namespace day_3_part_1
{
    void run()
    {
        std::ifstream my_file("inputs/day_3.txt");

        if (!my_file.is_open())
        {
            std::cout << "day_3.txt not found" << std::endl;
            return;
        }
        else
        {
            std::cout << "day_3.txt found" << std::endl;
        }
    }
}