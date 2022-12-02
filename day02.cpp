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

    int score = 0;

    for (std::list<std::string>::iterator in = input.begin(); in != input.end(); in++) {
        std::string strat = *in;
        if (strat[0]+23 == strat[2]) 
            score += 3; // draw
        else if ((strat[0] == 'A' && strat[2] == 'Y') || (strat[0] == 'B' and strat[2] == 'Z') || (strat[0] == 'C' and strat[2] == 'X')) 
            score += 6; //win
        // when we lose we do not add any score
        score += strat[2] == 'X' ? 1 : (strat[2] == 'Y' ? 2 : 3); // conditional to add score from choice
    }

    std::cout << score << std::endl;
}

void taskTwo() {
    std::list<std::string> input = read_input();

    int score = 0;

    for (std::list<std::string>::iterator in = input.begin(); in != input.end(); in++) {
        std::string strat = *in;

        // add score from win
        if (strat[2] != 'X')
            score += strat[2] == 'Y' ? 3 : 6;

        // Adds the score from the choice
        if (strat[2] == 'X') 
            score += (strat[0]%'A'+2)%3 + 1;
        else if (strat[2] == 'Y') 
            score += strat[0]%'A' + 1;
        else 
            score += (strat[0]%'A'+1)%3 + 1;
    }

    std::cout << score << std::endl;
}

int main(int argc, char *argv[]) {
    taskOne();
    taskTwo();
}