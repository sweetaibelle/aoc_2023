#include "util/util.h"

// --- Day 3: Gear Ratios ---

// You and the Elf eventually reach a gondola lift station; he says the gondola lift will take you up to the water source, but this is as far as he
// can bring you. You go inside.

// It doesn't take long to find the gondolas, but there seems to be a problem: they're not moving.

// "Aaah!"

// You turn around to see a slightly-greasy Elf with a wrench and a look of surprise. "Sorry, I wasn't expecting anyone! The gondola lift isn't
// working right now; it'll still be a while before I can fix it." You offer to help.

// The engineer explains that an engine part seems to be missing from the engine, but nobody can figure out which one. If you can add up all the
// part numbers in the engine schematic, it should be easy to work out which part is missing.

// The engine schematic (your puzzle input) consists of a visual representation of the engine. There are lots of numbers and symbols you don't
// really understand, but apparently any number adjacent to a symbol, even diagonally, is a "part number" and should be included in your sum. (Periods (.) do not count as a symbol.)

// Here is an example engine schematic:

// 467..114..
// ...*......
// ..35..633.
// ......#...
// 617*......
// .....+.58.
// ..592.....
// ......755.
// ...$.*....
// .664.598..

// In this schematic, two numbers are not part numbers because they are not adjacent to a symbol: 114 (top right) and 58 (middle right). Every
// other number is adjacent to a symbol and so is a part number; their sum is 4361.

// Of course, the actual engine schematic is much larger. What is the sum of all of the part numbers in the engine schematic?

namespace day_3
{
    namespace part_1
    {
        struct obj_symbol
        {
            char symbol;
            u_int32_t x = 0;
            u_int32_t y = 0;
        };

        struct obj_number_box
        {
            u_int32_t number = 0;
            u_int32_t length = 0;
            u_int32_t x = 0;
            u_int32_t y = 0;
            bool touched = false;
        };

        std::vector<obj_symbol> symbols;
        std::vector<obj_number_box> number_boxes;

        void add_symbol(char c, u_int32_t char_count, u_int32_t line_count)
        {
            symbols.push_back({c, char_count, line_count});
        }

        void print_symbol(u_int32_t idx)
        {
            std::cout << "Symbol: " << symbols[idx].symbol << " at x:" << symbols[idx].x << " y:" << symbols[idx].y << "\n";
        }

        void add_num_box(u_int32_t num, u_int32_t len, u_int32_t char_count, u_int32_t line_count)
        {
            number_boxes.push_back({num, len, char_count, line_count, false});
        }

        void print_num_box(u_int32_t idx)
        {
            std::cout << "Number: " << number_boxes[idx].number << " at x:" << number_boxes[idx].x << " y:" << number_boxes[idx].y << "\n";
        }

        void box_collision(u_int32_t idx)
        {
            number_boxes[idx].touched = false;
            int32_t start_x = number_boxes[idx].x - 1;
            int32_t start_y = number_boxes[idx].y - 1;
            int32_t end_x = start_x + (number_boxes[idx].length - 1) + 2;
            int32_t end_y = start_y + 2;
            if (start_x < 0)
                start_x = 0;
            if (start_y < 0)
                start_y = 0;
            if (end_x > 140)
                end_x = 140;
            if (end_y > 140)
                end_y = 140;

            std::cout << "Possible collision box: " << start_x << " " << start_y << " " << end_x << " " << end_y << "\n";

            for (u_int32_t x = static_cast<u_int32_t>(start_x); x <= static_cast<u_int32_t>(end_x); x++)
            {
                for (u_int32_t y = static_cast<u_int32_t>(start_y); y <= static_cast<u_int32_t>(end_y); y++)
                {
                    for (auto symbol : symbols)
                    {
                        if (symbol.x == x && symbol.y == y)
                        {
                            std::cout << "Collision at x:" << x << " y:" << y << " symbol:" << symbol.symbol << "\n";
                            number_boxes[idx].touched = true;
                        }
                    }
                }
            }
        }

        void run()
        {
            std::ifstream my_file("inputs/day_3.txt");
            // std::ifstream my_file("inputs/day_3_boop.txt");

            if (!my_file.is_open())
            {
                std::cout << "day_3.txt not found" << std::endl;
            }
            else
            {
                std::cout << "day_3.txt found" << std::endl;
            }

            if (my_file.is_open())
            {
                u_int32_t line_count = 0;

                while (my_file)
                {
                    std::string line;
                    std::getline(my_file, line);

                    if (line != "")
                    {
                        std::cout << "Line " << line_count << ": " << line << "\n";
                        // Do something
                        u_int32_t char_count = 0;
                        bool reading_number = false;
                        u_int32_t cur_number = 0, cur_num_len = 0, cur_num_x = 0, cur_num_y = 0;
                        auto finalize_number = [&]()
                        {
                            add_num_box(cur_number, cur_num_len, cur_num_x, cur_num_y);
                            print_num_box(number_boxes.size() - 1);
                            cur_number = 0;
                            cur_num_len = 0;
                            cur_num_x = 0;
                            cur_num_y = 0;
                            reading_number = false;
                        };

                        for (auto c : line)
                        {
                            if (c == '.')
                            {
                                if (reading_number)
                                {
                                    finalize_number();
                                }
                                else
                                {
                                    // Do nothing.
                                }
                            }
                            else if (c >= '0' && c <= '9')
                            {
                                cur_num_len++;
                                if (reading_number)
                                {
                                    cur_number *= 10;
                                    cur_number += c - '0';
                                }
                                else
                                {
                                    cur_number = c - '0';
                                    cur_num_x = char_count;
                                    cur_num_y = line_count;
                                    reading_number = true;
                                }
                                reading_number = true;
                            }
                            else
                            {
                                if (reading_number)
                                {
                                    finalize_number();
                                }
                                add_symbol(c, char_count, line_count);
                                print_symbol(symbols.size() - 1);
                            }
                            char_count++;
                        }
                        if (reading_number)
                        {
                            finalize_number();
                        }
                        line_count++;
                    }
                }
            }

            /*
            std::cout << "Test number: 42\n";
            print_num_box(0);
            box_collision(0);
            */
            for (u_int32_t i = 0; i < number_boxes.size(); i++)
            {
                box_collision(i);
            }

            std::cout << "Total symbols: " << symbols.size() << "\n";
            std::cout << "Total numbers: " << number_boxes.size() << "\n";

            u_int32_t total = 0;
            for (u_int32_t i = 0; i < number_boxes.size(); i++)
            {
                if (number_boxes[i].touched)
                {
                    total += number_boxes[i].number;
                    std::cout << "Number " << number_boxes[i].number << " at x:" << number_boxes[i].x << " y:" << number_boxes[i].y << " is touched.\n";
                }
            }

            std::cout << "Sum of numbers touched: " << total << std::endl;

            return;
        }
    }
}
