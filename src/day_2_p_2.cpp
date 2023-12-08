#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <vector>
#include "util/util.h"

namespace day_2
{
    namespace part_2
    {
        struct cubes
        {
            int red;
            int blue;
            int green;
        };

        cubes count_cubes(std::string round)
        {
            cubes b = {0, 0, 0};

            auto temp = split(round, ',');
            for (auto temp_cube : temp)
            {
                size_t pos = 0;
                pos = temp_cube.find("green");
                if (pos != std::string::npos)
                {
                    temp_cube.erase(pos, 5);
                    b.green += std::atoi(temp_cube.c_str());
                }

                pos = temp_cube.find("red");
                if (pos != std::string::npos)
                {
                    temp_cube.erase(pos, 3);
                    b.red += std::atoi(temp_cube.c_str());
                }

                pos = temp_cube.find("blue");
                if (pos != std::string::npos)
                {
                    temp_cube.erase(pos, 4);
                    b.blue += std::atoi(temp_cube.c_str());
                }
            }
            return b;
        }

        int32_t test_game(std::string line)
        {

            auto split_line = split(line, ':');
            std::string str_idx = split_line[0];
            std::string str_games = split_line[1];

            // Remove "Game", and parse the number.
            str_idx.erase(0, 5);
            auto idx = std::atoi(str_idx.c_str());

            auto rounds = split(str_games, ';');

            cubes total = {0, 0, 0};
            for (auto round : rounds)
            {
                cubes b = count_cubes(round);
                if (b.red > total.red)
                    total.red = b.red;
                if (b.blue > total.blue)
                    total.blue = b.blue;
                if (b.green > total.green)
                    total.green = b.green;
            }
            std::cout << "Game " << idx << ": Total cubes: r:" << total.red << " g:" << total.green << " b:" << total.blue << "\n";
            return total.red * total.green * total.blue;
        }

        void run()
        {
            int32_t total_power = 0;

            std::ifstream my_file("inputs/day_2.txt");
            std::cout << "This is day 2 of the advent of code in C++.\n";

            if (my_file.is_open())
            {
                while (my_file)
                {
                    std::string line;
                    std::getline(my_file, line);
                    if (line != "")
                    {
                        auto game = test_game(line);
                        total_power += game;
                    }
                }
            }

            std::cout << "Total is " << total_power << ".\n";
        }
    }
}