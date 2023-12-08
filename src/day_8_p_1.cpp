// --- Day 8: Haunted Wasteland ---

// You're still riding a camel across Desert Island when you spot a sandstorm quickly approaching. When you turn to warn the Elf, she disappears before
// your eyes! To be fair, she had just finished warning you about ghosts a few minutes ago.

// One of the camel's pouches is labeled "maps" - sure enough, it's full of documents (your puzzle input) about how to navigate the desert. At least,
// you're pretty sure that's what they are; one of the documents contains a list of left/right instructions, and the rest of the documents seem to
// describe some kind of network of labeled nodes.

// It seems like you're meant to use the left/right instructions to navigate the network. Perhaps if you have the camel follow the same instructions,
// you can escape the haunted wasteland!

// After examining the maps for a bit, two nodes stick out: AAA and ZZZ. You feel like AAA is where you are now, and you have to follow the left/right
// instructions until you reach ZZZ.

// This format defines each node of the network individually. For example:

// RL

// AAA = (BBB, CCC)
// BBB = (DDD, EEE)
// CCC = (ZZZ, GGG)
// DDD = (DDD, DDD)
// EEE = (EEE, EEE)
// GGG = (GGG, GGG)
// ZZZ = (ZZZ, ZZZ)

// Starting with AAA, you need to look up the next element based on the next left/right instruction in your input. In this example, start with AAA and
// go right (R) by choosing the right element of AAA, CCC. Then, L means to choose the left element of CCC, ZZZ. By following the left/right instructions,
// you reach ZZZ in 2 steps.

// Of course, you might not find ZZZ right away. If you run out of left/right instructions, repeat the whole sequence of instructions as necessary: RL
// really means RLRLRLRLRLRLRLRL... and so on. For example, here is a situation that takes 6 steps to reach ZZZ:

// LLR

// AAA = (BBB, BBB)
// BBB = (AAA, ZZZ)
// ZZZ = (ZZZ, ZZZ)

// Starting at AAA, follow the left/right instructions. How many steps are required to reach ZZZ?

// To begin, get your puzzle input.

#include "util/util.h"
#include <map>

namespace day_8
{
    namespace part_1
    {
        std::map<std::string, std::pair<std::string, std::string>> nodes;
        std::string directions;

        void print_nodes()
        {
            for (auto node : nodes)
            {
                std::cout << node.first << " -> " << node.second.first << ", " << node.second.second << "\n";
            }
        }

        u_int32_t follow_directions(std::string start)
        {
            std::string current_node = start;
            u_int32_t steps = 0;
            while (current_node != "ZZZ")
            {
                for (auto turn : directions)
                {
                    if (turn == 'L')
                    {
                        current_node = nodes[current_node].first;
                    }
                    else if (turn == 'R')
                    {
                        current_node = nodes[current_node].second;
                    }
                    steps++;
                    if (current_node == "ZZZ")
                    {
                        break;
                    }
                }
            }
            return steps;
        }

        void run()
        {
            auto my_file = util::read_file("inputs/day_8.txt");

            if (!my_file.empty())
            {
                directions = my_file[0];

                for (u_int32_t i = 2; i < my_file.size(); i++)
                {
                    nodes[my_file[i].substr(0, 3)] = {my_file[i].substr(7, 3), my_file[i].substr(12, 3)};
                }
                print_nodes();

                u_int32_t steps = follow_directions("AAA");
                std::cout << "Steps: " << steps << "\n";
            }
        }
    }
}