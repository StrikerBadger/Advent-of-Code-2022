#include <iostream>
#include <fstream>
#include <vector>

void read_input(std::vector<std::string> &inputVec) {
    std::ifstream inputFile("input.txt");
    std::string nextLine;

    while (std::getline(inputFile, nextLine)) inputVec.push_back(nextLine);
    inputFile.close();
}

void taskOne() {
    std::vector<std::string> inputVec;
    read_input(inputVec);

    for (std::string line : inputVec) {

    }
}

void taskTwo() {
    std::vector<std::string> inputVec;
    read_input(inputVec);

    for (std::string line : inputVec) {
        
    }
}

int main(int argc, char *argv[]) {
    
    taskOne();
    // taskTwo();

    return 0;
}