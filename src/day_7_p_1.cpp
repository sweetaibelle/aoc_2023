#include "util/util.h"

namespace day_7
{
    namespace part_1
    {
        const std::vector<char> card_value = {'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2'};
        enum hand_type
        {
            HIGH_CARD,
            ONE_PAIR,
            TWO_PAIR,
            THREE_OF_A_KIND,
            FULL_HOUSE,
            FOUR_OF_A_KIND,
            FIVE_OF_A_KIND
        };

        void run()
        {
            auto my_file = util::read_file("inputs/day_7.txt");

            if (!my_file.empty())
            {
                for (auto &line : my_file)
                {
                    auto split_line = util::split(line, ' ');
                    auto hand_str = split_line[0];
                    u_int32_t bid = std::atoi(split_line[1].c_str());

                    std::array<char,5> hand;
                    std::cout << "Hand: " ;
                    for (u_int8_t i = 0; i < 5 ; i++)
                    {
                        hand[i] = hand_str[i];
                        std::cout << hand[i] << " ";
                    }
                    std::cout << " Bid: " << bid << std::endl;
                }
            }
        }
    }
}