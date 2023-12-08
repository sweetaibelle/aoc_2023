#include <iostream>
#include <fstream>
#include <string>

namespace day_1
{
    namespace part_1
    {
        u_int32_t get_value(std::string line)
        {
            u_int8_t first_value, current_value = 0;
            bool is_first = true;

            for (char &c : line)
            {
                if (c >= '0' && c <= '9')
                {
                    current_value = c - '0';

                    if (is_first)
                    {
                        is_first = false;
                        first_value = current_value;
                    }
                }
            }

            return (first_value * 10) + current_value;
        }

        void run()
        {
            u_int32_t final_countdown = 0;
            std::ifstream my_file("inputs/day_1.txt");

            if (my_file.is_open())
            {
                while (my_file)
                {
                    std::string line;
                    std::getline(my_file, line);
                    final_countdown += get_value(line);
                    std::cout << line << std::endl;
                }
                std::cout << "Final countdown ==" << final_countdown << std::endl;
            }

            std::cout << "This is day 1 of the advent of code in C++.\n";
        }
    }
}