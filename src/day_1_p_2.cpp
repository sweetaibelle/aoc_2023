#include <iostream>
#include <fstream>
#include <string>
#include <format>

namespace day_1
{
    namespace part_2
    {
        const std::string num_desc[] = {
            "zero",
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine"};

        u_int32_t get_value(std::string line)
        {
            auto temp_line = line;
            u_int32_t ex_num = 0;

            for (u_int32_t i = 0; i < 10; i++)
            {
                bool done = false;
                while (!done)
                {
                    size_t pos = temp_line.find(num_desc[i]);
                    if (pos == std::string::npos)
                        done = true;
                    else
                    {
                        std::string temp = std::format("{}{}{}", num_desc[i][0], i, num_desc[i][num_desc[i].length() - 1]);
                        temp_line.replace(pos, num_desc[i].length(), temp);
                    }
                }
            }

            u_int8_t first_value, current_value = 0;
            bool is_first = true;

            for (char &c : temp_line)
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
            ex_num = (first_value * 10) + current_value;
            std::cout << line << " == " << temp_line << " == " << ex_num << std::endl;

            return ex_num;
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
                    if (line != "")
                        final_countdown += get_value(line);
                }
                std::cout << "Final countdown ==" << final_countdown << std::endl;
            }

            std::cout << "This is day 1 of the advent of code in C++.\n";
        }
    }
}