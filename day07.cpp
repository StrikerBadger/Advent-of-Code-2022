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

/** Helper function to add the file sizes to all relevant direcories
 *  Given an absolute path to a directory every absolute path delimited at '/' is a parent directory of the given directory (Prefix checking)
 * */ 
void addScores(int &score, std::string &absoluteDir, std::unordered_map<std::string, int> &directories) {
    for (auto it = directories.begin(); it != directories.end(); it++) {
        if (!absoluteDir.starts_with(it->first))
            continue;
        it->second += score;
    }
    score = 0;
}

void taskOne(std::vector<std::string> &inputVec, std::unordered_map<std::string, int> &directories) {
    std::string currDir = "";
    int currScore = 0;

    // Fill the map with the {absolute path, size}
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
        // Add the cumulated files sizes
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

void taskTwo(std::vector<std::string> &inputVec, std::unordered_map<std::string, int> &directories) {
    int toFree = 30000000 - (70000000 - directories.at("/"));
    int minDelete = __INT_MAX__;

    // Small for loop to find the size of the smallest directory which frees up enough space
    for (auto it = directories.begin(); it != directories.end(); it++) {
        if (toFree >  it->second) 
            continue;
        minDelete = it->second < minDelete ? it->second : minDelete;
    }

    std::cout << minDelete << std::endl;
}

int main(int argc, char *argv[]) {
    std::vector<std::string> inputVec;
    read_input(inputVec);

    std::unordered_map<std::string, int> directories;

    taskOne(inputVec, directories);
    taskTwo(inputVec, directories);

    return 0;
}