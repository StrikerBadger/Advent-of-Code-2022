#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

void read_input(std::vector<std::string> &inputVec) {
    std::ifstream inputFile("input.txt");
    std::string nextLine;

    while (std::getline(inputFile, nextLine)) inputVec.push_back(nextLine);
    inputFile.close();
}

void addScores(int &score, std::string &absoluteDir, std::unordered_map<std::string, int> &directories) {
    for (auto it = directories.begin(); it != directories.end(); it++) {
        if (!absoluteDir.starts_with(it->first))
            continue;
        it->second += score;
    }
    score = 0;
}

void taskOne(std::vector<std::string> &inputVec) {
    std::string currDir = "";
    std::unordered_map<std::string, int> directories;
    int currScore = 0;

    //Build the 
    for (std::string line : inputVec) {
        // Check if it is a cd Command
        if (line.substr(0, 4) == "$ cd") {
            if (currScore != 0) 
                addScores(currScore, currDir, directories);
            std::string relDir = line.substr(5, line.size()-5);

            // Edit the currDir accordingly and add it to the map
            if (relDir == "..") {
                currDir = currDir.substr(0, currDir.find_last_of('/'));
                continue;
            }
            currDir += (currDir.back() == '/' ? "" : "/") + (relDir != "/" ? relDir : "");
            directories.insert({currDir, 0});
        }
        else if (line.at(0) != '$') {
            if (line.substr(0, 3) == "dir")
                continue;
            currScore += std::stoi(line.substr(0, line.find_first_of(' ')+1));
        }
    }
    addScores(currScore, currDir, directories);

    int resScore = 0;
    for (auto it = directories.begin(); it != directories.end(); it++) {
        resScore += it->second <= 100000 ? it->second : 0;
    }

    std::cout << resScore << std::endl;
}

void taskTwo(std::vector<std::string> &inputVec) {

    for (std::string line : inputVec) {
        
    }
}

int main(int argc, char *argv[]) {
    std::vector<std::string> inputVec;
    read_input(inputVec);

    taskOne(inputVec);
    // taskTwo(inputVec);

    return 0;
}