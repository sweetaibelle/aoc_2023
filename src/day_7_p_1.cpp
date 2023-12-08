// --- Day 7: Camel Cards ---

// Your all-expenses-paid trip turns out to be a one-way, five-minute ride in an airship. (At least it's a cool airship!) It drops you off at the edge
// of a vast desert and descends back to Island Island.

// "Did you bring the parts?"

// You turn around to see an Elf completely covered in white clothing, wearing goggles, and riding a large camel.

// "Did you bring the parts?" she asks again, louder this time. You aren't sure what parts she's looking for; you're here to figure out why the sand
// stopped.

// "The parts! For the sand, yes! Come with me; I will show you." She beckons you onto the camel.

// After riding a bit across the sands of Desert Island, you can see what look like very large rocks covering half of the horizon. The Elf explains
// that the rocks are all along the part of Desert Island that is directly above Island Island, making it hard to even get there. Normally, they use
// big machines to move the rocks and filter the sand, but the machines have broken down because Desert Island recently stopped receiving the parts
// they need to fix the machines.

// You've already assumed it'll be your job to figure out why the parts stopped when she asks if you can help. You agree automatically.

// Because the journey will take a few days, she offers to teach you the game of Camel Cards. Camel Cards is sort of similar to poker except it's
// designed to be easier to play while riding a camel.

// In Camel Cards, you get a list of hands, and your goal is to order them based on the strength of each hand. A hand consists of five cards labeled one
// of A, K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, or 2. The relative strength of each card follows this order, where A is the highest and 2 is the lowest.

// Every hand is exactly one type. From strongest to weakest, they are:

//     Five of a kind, where all five cards have the same label: AAAAA
//     Four of a kind, where four cards have the same label and one card has a different label: AA8AA
//     Full house, where three cards have the same label, and the remaining two cards share a different label: 23332
//     Three of a kind, where three cards have the same label, and the remaining two cards are each different from any other card in the hand: TTT98
//     Two pair, where two cards share one label, two other cards share a second label, and the remaining card has a third label: 23432
//     One pair, where two cards share one label, and the other three cards have a different label from the pair and each other: A23A4
//     High card, where all cards' labels are distinct: 23456

// Hands are primarily ordered based on type; for example, every full house is stronger than any three of a kind.

// If two hands have the same type, a second ordering rule takes effect. Start by comparing the first card in each hand. If these cards are different,
// the hand with the stronger first card is considered stronger. If the first card in each hand have the same label, however, then move on to
// considering the second card in each hand. If they differ, the hand with the higher second card wins; otherwise, continue with the third card in
// each hand, then the fourth, then the fifth.

// So, 33332 and 2AAAA are both four of a kind hands, but 33332 is stronger because its first card is stronger. Similarly, 77888 and 77788 are both
// a full house, but 77888 is stronger because its third card is stronger (and both hands have the same first and second card).

// To play Camel Cards, you are given a list of hands and their corresponding bid (your puzzle input). For example:

// 32T3K 765
// T55J5 684
// KK677 28
// KTJJT 220
// QQQJA 483

// This example shows five hands; each hand is followed by its bid amount. Each hand wins an amount equal to its bid multiplied by its rank, where
// the weakest hand gets rank 1, the second-weakest hand gets rank 2, and so on up to the strongest hand. Because there are five hands in this
// example, the strongest hand will have rank 5 and its bid will be multiplied by 5.

// So, the first step is to put the hands in order of strength:

//     32T3K is the only one pair and the other hands are all a stronger type, so it gets rank 1.
//     KK677 and KTJJT are both two pair. Their first cards both have the same label, but the second card of KK677 is stronger (K vs T), so KTJJT
//     gets rank 2 and KK677 gets rank 3.
//     T55J5 and QQQJA are both three of a kind. QQQJA has a stronger first card, so it gets rank 5 and T55J5 gets rank 4.

// Now, you can determine the total winnings of this set of hands by adding up the result of multiplying each hand's bid with its rank
// (765 * 1 + 220 * 2 + 28 * 3 + 684 * 4 + 483 * 5). So the total winnings in this example are 6440.

// Find the rank of every hand in your set. What are the total winnings?

#include "util/util.h"
#include <map>

namespace day_7
{
    namespace part_1
    {
        const std::array<std::string, 13> card_value = {"A", "K", "Q", "J", "T", "9", "8", "7", "6", "5", "4", "3", "2"};

        enum card_name
        {
            ACE,
            KING,
            QUEEN,
            JACK,
            TEN,
            NINE,
            EIGHT,
            SEVEN,
            SIX,
            FIVE,
            FOUR,
            THREE,
            TWO,
            ERROR
        };

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

        struct camel_round
        {
            std::array<card_name, 5> hand;
            hand_type type;
            u_int32_t bid;
        };

        card_name to_card_name(char c)
        {
            switch (c)
            {
            case 'A':
                return card_name::ACE;
            case 'K':
                return card_name::KING;
            case 'Q':
                return card_name::QUEEN;
            case 'J':
                return card_name::JACK;
            case 'T':
                return card_name::TEN;
            case '9':
                return card_name::NINE;
            case '8':
                return card_name::EIGHT;
            case '7':
                return card_name::SEVEN;
            case '6':
                return card_name::SIX;
            case '5':
                return card_name::FIVE;
            case '4':
                return card_name::FOUR;
            case '3':
                return card_name::THREE;
            case '2':
                return card_name::TWO;
            }
            return card_name::ERROR;
        }

        std::string card_to_string(card_name c)
        {
            switch (c)
            {
            case card_name::ACE:
                return "A";
            case card_name::KING:
                return "K";
            case card_name::QUEEN:
                return "Q";
            case card_name::JACK:
                return "J";
            case card_name::TEN:
                return "T";
            case card_name::NINE:
                return "9";
            case card_name::EIGHT:
                return "8";
            case card_name::SEVEN:
                return "7";
            case card_name::SIX:
                return "6";
            case card_name::FIVE:
                return "5";
            case card_name::FOUR:
                return "4";
            case card_name::THREE:
                return "3";
            case card_name::TWO:
                return "2";
            default:
                return "ERROR";
            }
            return "ERROR";
        }

        std::string hand_type_to_string(hand_type h)
        {
            switch (h)
            {
            case hand_type::HIGH_CARD:
                return "HIGH_CARD";
            case hand_type::ONE_PAIR:
                return "ONE_PAIR";
            case hand_type::TWO_PAIR:
                return "TWO_PAIR";
            case hand_type::THREE_OF_A_KIND:
                return "THREE_OF_A_KIND";
            case hand_type::FULL_HOUSE:
                return "FULL_HOUSE";
            case hand_type::FOUR_OF_A_KIND:
                return "FOUR_OF_A_KIND";
            case hand_type::FIVE_OF_A_KIND:
                return "FIVE_OF_A_KIND";
            }
            return "ERROR";
        }

        hand_type get_hand_type(const std::array<card_name, 5> &hand)
        {
            std::array<u_int8_t, 13> card_count = {0};
            for (auto &card : hand)
            {
                card_count[card]++;
            }
            u_int8_t pair_count = 0;
            bool has_trio = false;
            bool has_quad = false;
            bool has_five = false;

            for (u_int8_t card = 0; card < 13; card++)
            {
                switch (card_count[card])
                {
                case 2:
                    pair_count++;
                    break;
                case 3:
                    has_trio = true;
                    break;
                case 4:
                    has_quad = true;
                    break;
                case 5:
                    has_five = true;
                    break;
                }
            }

            if (has_five)
            {
                return hand_type::FIVE_OF_A_KIND;
            }
            else if (has_quad)
            {
                return hand_type::FOUR_OF_A_KIND;
            }
            else if ((pair_count == 1) && has_trio)
            {
                return hand_type::FULL_HOUSE;
            }
            else if (has_trio)
            {
                return hand_type::THREE_OF_A_KIND;
            }
            else if (pair_count == 2)
            {
                return hand_type::TWO_PAIR;
            }
            else if (pair_count == 1)
            {
                return hand_type::ONE_PAIR;
            }
            else
            {
                return hand_type::HIGH_CARD;
            }

            return hand_type::HIGH_CARD;
        }

        bool card_compare(const card_name &a, const card_name &b)
        {
            return (a > b);
        }

        bool hand_type_compare(const hand_type &a, const hand_type &b)
        {
            return (a < b);
        }

        bool round_compare(const camel_round &a, const camel_round &b)
        {
            if (a.type == b.type)
            {
                for(u_int8_t i = 0; i < 5; i++)
                {
                    if(a.hand[i] != b.hand[i])
                    {
                        return card_compare(a.hand[i], b.hand[i]);
                    }
                }
            }
            else
            {
                return hand_type_compare(a.type, b.type);
            }
            return false;
        }

        void run()
        {
            auto my_file = util::read_file("inputs/day_7.txt");
            std::vector<camel_round> rounds;

            if (!my_file.empty())
            {
                for (auto &line : my_file)
                {
                    auto split_line = util::split(line, ' ');
                    auto hand_str = split_line[0];
                    u_int32_t bid = std::atoi(split_line[1].c_str());

                    std::array<card_name, 5> hand;
                    for (u_int8_t i = 0; i < 5; i++)
                    {
                        hand[i] = to_card_name(hand_str[i]);
                    }

                    hand_type current_hand_type = get_hand_type(hand);
                    rounds.push_back({hand, current_hand_type, bid});
                }

                std::sort(rounds.begin(), rounds.end(), round_compare);
                u_int64_t winnings = 0;

                for (u_int32_t round_num = 0; round_num < rounds.size(); round_num++)
                {
                    std::cout << "Round " << round_num + 1 << ": ";
                    std::cout << "Hand: ";
                    for (u_int8_t i = 0; i < 5; i++)
                    {
                        std::cout << "'" << card_to_string(rounds[round_num].hand[i]) << "'"
                                  << " ";
                    }
                    std::cout << " Hand Type: " << hand_type_to_string(rounds[round_num].type);
                    std::cout << " Bid: " << rounds[round_num].bid << std::endl;
                    winnings += rounds[round_num].bid * (round_num + 1);
                }
                std::cout << "Total Winnings: " << winnings << std::endl;
            }
        }
    }
}