#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <regex>

void read_input(std::vector<std::string> &inputVec) {
    std::ifstream inputFile("input.txt");
    std::string nextLine;

    while (std::getline(inputFile, nextLine)) inputVec.push_back(nextLine);
    inputFile.close();
}

void taskOne() {
    std::vector<std::string> inputVec;
    read_input(inputVec);
    // Hard code input, since there is only one input for the initial state
    std::vector<std::stack<char>> stacks;
    stacks.push_back(std::stack<char>({'G', 'T', 'R', 'W'}));
    stacks.push_back(std::stack<char>({'G', 'C', 'H', 'P', 'M', 'S', 'V', 'W'}));
    stacks.push_back(std::stack<char>({'C', 'L', 'T', 'S', 'G', 'M'}));
    stacks.push_back(std::stack<char>({'J', 'H', 'D', 'M', 'W', 'R', 'F'}));
    stacks.push_back(std::stack<char>({'P', 'Q', 'L', 'H', 'S', 'W', 'F', 'J'}));
    stacks.push_back(std::stack<char>({'P', 'J', 'D', 'N', 'F', 'M', 'S'}));
    stacks.push_back(std::stack<char>({'Z', 'B', 'D', 'F', 'G', 'C', 'S', 'J'}));
    stacks.push_back(std::stack<char>({'R', 'T', 'B'}));
    stacks.push_back(std::stack<char>({'H', 'N', 'W', 'L', 'C'}));

    for (std::string line : inputVec) {
        if (line.front() != 'm') 
            continue;
        
        // fuck it - input parsing using regex
        std::regex instructionRegex("\\d+");
        auto words_begin = std::sregex_iterator(line.begin(), line.end(), instructionRegex);
        auto words_end = std::sregex_iterator();
        std::vector<int> instructions;

        for (std::sregex_iterator it = words_begin; it != words_end; it++) {
            instructions.push_back(std::stoi((*it).str()));
        }

        // move the crates
        for (int i = 0; i < instructions.at(0); i++) {
            if (stacks.at(instructions.at(1)-1).empty())
                continue;
            char crate = stacks.at(instructions.at(1)-1).top();
            stacks.at(instructions.at(1)-1).pop();
            stacks.at(instructions.at(2)-1).push(crate);
        }
    }

    //print out the topmost crate for all towers
    for (std::stack<char> tower : stacks) {
        if (tower.empty()) 
            continue;
        std::cout << tower.top();
    }

    std::cout << std::endl;
}

void taskTwo() {
    std::vector<std::string> inputVec;
    read_input(inputVec);
    // Hard code input, since there is only one input for the initial state
    std::vector<std::stack<char>> stacks; 
    stacks.push_back(std::stack<char>({'G', 'T', 'R', 'W'}));
    stacks.push_back(std::stack<char>({'G', 'C', 'H', 'P', 'M', 'S', 'V', 'W'}));
    stacks.push_back(std::stack<char>({'C', 'L', 'T', 'S', 'G', 'M'}));
    stacks.push_back(std::stack<char>({'J', 'H', 'D', 'M', 'W', 'R', 'F'}));
    stacks.push_back(std::stack<char>({'P', 'Q', 'L', 'H', 'S', 'W', 'F', 'J'}));
    stacks.push_back(std::stack<char>({'P', 'J', 'D', 'N', 'F', 'M', 'S'}));
    stacks.push_back(std::stack<char>({'Z', 'B', 'D', 'F', 'G', 'C', 'S', 'J'}));
    stacks.push_back(std::stack<char>({'R', 'T', 'B'}));
    stacks.push_back(std::stack<char>({'H', 'N', 'W', 'L', 'C'}));

    for (std::string line : inputVec) {
        if (line.front() != 'm') 
            continue;
        
        // fuck it - input parsing using regex
        std::regex instructionRegex("\\d+");
        auto words_begin = std::sregex_iterator(line.begin(), line.end(), instructionRegex);
        auto words_end = std::sregex_iterator();
        std::vector<int> instructions;

        for (std::sregex_iterator it = words_begin; it != words_end; it++) {
            instructions.push_back(std::stoi((*it).str()));
        }

        // move the crates
        std::vector<char> loader;
        for (int i = 0; i < instructions.at(0); i++) {
            if (stacks.at(instructions.at(1)-1).empty())
                continue;
            char crate = stacks.at(instructions.at(1)-1).top();
            stacks.at(instructions.at(1)-1).pop();
            loader.push_back(crate);
        }
        for (char c : loader) {
            std::cout << c;
        }
        std::cout << std::endl;

        for (int i = loader.size()-1; i >= 0; i--) 
            stacks.at(instructions.at(2)-1).push(loader.at(i));
    }

    //print out the topmost crate for all towers
    for (std::stack<char> tower : stacks) {
        if (tower.empty()) 
            continue;
        std::cout << tower.top();
    }

    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    
    taskOne();
    taskTwo();

    return 0;
}