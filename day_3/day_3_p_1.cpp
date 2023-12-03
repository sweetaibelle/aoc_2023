#include "util/util.h"
#include "day_3/day_3.h"

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

namespace day_3_part_1
{
    struct obj_symbol
    {
        char symbol;
        u_int32_t x;
        u_int32_t y;
    };

    void run()
    {
        std::ifstream my_file("inputs/day_3.txt");
        std::vector<obj_symbol> symbols;

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

                    for (auto c : line)
                    {
                        if (c == '.')
                        {
                            // Do nothing.
                        }
                        else if (c >= '0' && c <= '9')
                        {
                            std::cout << "Number found: " << c << " at x:" << char_count << " y:" << line_count << "\n";
                        }
                        else
                        {
                            symbols.push_back({c, char_count, line_count});
                            std::cout << "Symbol found: " << c << " at x:" << char_count << " y:" << line_count << "\n";
                        }
                        char_count++;
                    }
                    line_count++;
                }
            }
        }

        std::cout << "Total symbols: " << symbols.size() << std::endl;

        return;
    }
}
