#include "util/util.h"

namespace day_6_part_1
{
    void run()
    {
        std::ifstream my_file("inputs/day_6.txt");

        if (!my_file.is_open())
        {
            std::cout << "day_6.txt not found" << std::endl;
        }
        else
        {
            std::cout << "day_6.txt found" << std::endl;
        }

        if (my_file.is_open())
        {
            while (my_file)
            {
                std::string line;
                std::getline(my_file, line);

                if (line != "")
                {
                    //
                }
            }
        }
    }
}