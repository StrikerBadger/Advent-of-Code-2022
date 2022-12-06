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
    std::string line = inputVec.at(0);
    int i;

    for (i = 0; i <= line.size()-4; i++) {
        std::string signal = line.substr(i, 4);
        bool doubleOccurence = false;

        // Iterate through the possible start package
        for (int j = 0; j < signal.size(); j++) {
            char check = signal.at(j);
            for (int k = 0; k < signal.size(); k++) {
                if (k == j) // do not check for character equality at same indexes :4head:
                    continue;
                if (check == signal.at(k)) {
                    doubleOccurence = true;
                    break;
                }
                // doubleOccurence can still occur after checking the first character; don't break!
            }
        }
        if (!doubleOccurence)
            break;
    }

    std::cout << i+4 << std::endl;
}

void taskTwo() {
    std::vector<std::string> inputVec;
    read_input(inputVec);
    std::string line = inputVec.at(0);
    int i;

    // same as taskOne, just a different offset
    for (i = 0; i <= line.size()-14; i++) {
        std::string signal = line.substr(i, 14);
        bool doubleOccurence = false;

        for (int j = 0; j < signal.size(); j++) {
            char check = signal.at(j);
            for (int k = 0; k < signal.size(); k++) {
                if (k == j) 
                    continue;
                if (check == signal.at(k)) {
                    doubleOccurence = true;
                    break;
                }
            }
        }
        if (!doubleOccurence)
            break;
    }

    std::cout << i+14 << std::endl;
}

int main(int argc, char *argv[]) {
    
    taskOne();
    taskTwo();

    return 0;
}