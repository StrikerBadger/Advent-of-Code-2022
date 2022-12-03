#include <iostream>
#include <fstream>
#include <list>
#include <unordered_set>

std::list<std::string> read_input() {
    std::list<std::string> input;
    std::ifstream inputFile("input.txt");
    std::string nextLine;

    while (std::getline(inputFile, nextLine)) input.push_back(nextLine);
    inputFile.close();

    return input;
}

void taskOne() {
    std::list<std::string> input = read_input();

    int sum = 0;

    for (std::list<std::string>::iterator in = input.begin(); in != input.end(); in++) {
        std::string rucksack = *in;
        std::string left = rucksack.substr(0, rucksack.size()/2);
        std::string right = rucksack.substr(rucksack.size()/2, rucksack.size()/2);
        std::unordered_set<char> checked;

        for (char c : left) {
            if (checked.contains(c) || (right.find(c) == std::string::npos))
                continue;
            checked.insert(c);
            sum += islower(c) ? c%'a' + 1 : c%'A' + 27;
        }

    }

    std::cout << sum << std::endl;
}

void taskTwo() {
    std::list<std::string> input = read_input();
    std::list<std::string> group;
    int sum = 0;

    for (std::list<std::string>::iterator in = input.begin(); in != input.end(); in++) {
        group.push_back(*in);

        if (group.size() == 3) {
            std::string first = group.front();
            char badge;

            for (char c : first) {
                bool found = true;

                for (auto it = group.begin(); it != group.end(); it++) {
                    if ((*it).find(c) == std::string::npos) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    badge = c;
                    break;
                }
            }
            sum += islower(badge) ? badge%'a'+1 : badge%'A'+27;
            group.clear();
        }
    }

    std::cout << sum << std::endl;
}

int main(int argc, char *argv[]) {

    taskOne();
    taskTwo();

    return 0;
}