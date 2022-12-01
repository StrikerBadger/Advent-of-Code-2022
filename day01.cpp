#include <iostream>
#include <fstream>
#include <list>
#include <string>
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
    int currSum = 0;
    int maxSum = 0;

    for (auto in = input.begin(); in != input.end(); in++) {
        std::string line = *in;
        if (line == "") {
            maxSum = currSum > maxSum ? currSum : maxSum;
            currSum = 0;
        }
        else {
            currSum += std::stoi(line);
        }
    }
    maxSum = currSum > maxSum ? currSum : maxSum;

    std::cout << maxSum << std::endl;
}

void replaceSmallest(std::vector<int> &vec, int x) {
    int smallest = 0x7FFFFFFF;
    int index = -1;
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i) < smallest) {
            index = i;
            smallest = vec.at(i);
        }
    }

    if (vec.at(index) < x) vec.at(index) = x;
} 

void taskTwo() {
    std::list<std::string> input = read_input();
    int currSum = 0;
    std::vector<int> sums = {0, 0, 0};

    for (auto in = input.begin(); in != input.end(); in++) {
        std::string line = *in;
        if (line == "") {
            replaceSmallest(sums, currSum);
            currSum = 0;
        }
        else {
            currSum += std::stoi(line);
        }
    }
    replaceSmallest(sums, currSum);
    
    int res = sums.at(0) + sums.at(1) + sums.at(2);

    std::cout << res << std::endl;
}

int main(int argc, char *argv[]) {

    taskOne();

    taskTwo();

    return 0;
}