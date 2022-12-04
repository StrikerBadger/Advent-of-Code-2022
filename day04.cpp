#include <iostream>
#include <fstream>
#include <list>
#include <unordered_set>
#include <regex>
#include <vector>

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
    int count = 0;

    for (std::list<std::string>::iterator in = input.begin(); in != input.end(); in++) {
        std::string s = *in;

        // fuck it - input parsing using regex
        std::regex rangeRegex("\\d+");
        auto words_begin = std::sregex_iterator(s.begin(), s.end(), rangeRegex);
        auto words_end = std::sregex_iterator();
        std::vector<int> ranges;
        std::unordered_set<int> left;
        std::unordered_set<int> right;

        for (std::sregex_iterator it = words_begin; it != words_end; it++) {
            ranges.push_back(std::stoi((*it).str()));
        }
        
        for (int i = ranges.at(0); i <= ranges.at(1); i++) 
            left.insert(i);

        for (int i = ranges.at(2); i <= ranges.at(3); i++) 
            right.insert(i);

        // if the cardinality of the union of the sets is as big as the cardinality of the bigger set, then there is a complete overlap
        int biggerSize = std::max(left.size(), right.size());

        for (auto it = left.begin(); it != left.end(); it++)
            right.insert(*it);
        
        if (right.size() == biggerSize)
            count++;

    }

    std::cout << count << std::endl;
}

void taskTwo() {
    std::list<std::string> input = read_input();
    int count = 0;

    for (std::list<std::string>::iterator in = input.begin(); in != input.end(); in++) {
        std::string s = *in;

        // fuck it - input parsing using regex
        std::regex rangeRegex("\\d+");
        auto words_begin = std::sregex_iterator(s.begin(), s.end(), rangeRegex);
        auto words_end = std::sregex_iterator();
        std::vector<int> ranges;
        std::unordered_set<int> left;
        std::unordered_set<int> right;

        for (std::sregex_iterator it = words_begin; it != words_end; it++) {
            ranges.push_back(std::stoi((*it).str()));
        }
        
        for (int i = ranges.at(0); i <= ranges.at(1); i++) 
            left.insert(i);

        for (int i = ranges.at(2); i <= ranges.at(3); i++) 
            right.insert(i);

        // if the cardinality of the union of the sets is smaller than the sum of the cardinalities, then there is at least partial overlap
        int sizeSum = left.size() + right.size();

        for (auto it = left.begin(); it != left.end(); it++)
            right.insert(*it);
        
        if (right.size() < sizeSum)
            count++;

    }

    std::cout << count << std::endl;
}

int main(int argc, char *argv[]) {
    
    taskOne();
    taskTwo();

    return 0;
}