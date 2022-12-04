#include <iostream>
#include <fstream>
#include <list>

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

    for (std::list<std::string>::iterator in = input.begin(); in != input.end(); in++) {
        std::string line = *in;
    }
}

void taskTwo() {
    std::list<std::string> input = read_input();

    for (std::list<std::string>::iterator in = input.begin(); in != input.end(); in++) {
        std::string line = *in;
    }
}

int main(int argc, char *argv[]) {
    
    taskOne();
    // taskTwo();

    return 0;
}