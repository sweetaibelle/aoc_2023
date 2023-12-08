#include "util/util.h"
#include "days.h"

int main()
{
    constexpr u_int8_t day = 8;
    constexpr u_int8_t part = 2;

    std::cout << std::format("Day {} Part {}\n", day, part);

    switch(day)
    {
        case 1: // Done.
            switch(part)
            {
                case 1: // Done.
                    day_1::part_1::run();
                    break;
                case 2: // Done.
                    day_1::part_2::run();
                    break;
            }
            break;
        
        case 2: // Done.
            switch(part)
            {
                case 1: // Done.
                    day_2::part_1::run();
                    break;
                case 2: // Done.
                    day_2::part_2::run();
                    break;
            }
            break;

        case 3: // Done.
            switch(part)
            {
                case 1: // Done.
                    day_3::part_1::run();
                    break;
                case 2: // Done.
                    day_3::part_2::run();
                    break;
            }
            break;
        
        case 4:
            switch(part)
            {
                case 1: // Done.
                    day_4::part_1::run();
                    break;
                case 2:
                    day_4::part_2::run();
                    break;
            }
            break;

        case 5:
            switch(part)
            {
                case 1:
                    day_5::part_1::run();
                    break;
                case 2:
                    day_5::part_2::run();
                    break;
            }
            break;
        
        case 6: // Done.
            switch(part)
            {
                case 1: // Done.
                    day_6::part_1::run();
                    break;
                case 2: // Done.
                    day_6::part_2::run();
                    break;
            }
            break;
        
        case 7:
            switch(part)
            {
                case 1: // Done.
                    day_7::part_1::run();
                    break;
                case 2:
                    day_7::part_2::run();
                    break;
            }
            break;
        
        case 8:
            switch(part)
            {
                case 1: // Done.
                    day_8::part_1::run();
                    break;
                case 2:
                    day_8::part_2::run();
                    break;
            }
            break;
        
        default:
            std::cout << "Invalid day or part.\n";
            break;
    }

    return 0;
}
