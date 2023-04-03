//
// Created by Felix Hohne on 4/3/23.
//

#include "graphLoading.h"
#include <fstream>
#include <sstream>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <list>
#include <iostream>

void print_edge_list(std::list<std::pair<int, int>> parsed_edge_list) {
    for (const auto &token: parsed_edge_list) {
        std::cout << token.first << ", " << token.second << "\n";
    }
}


std::list<std::pair<int, int>> read_edge_list(std::string filename) {
    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if (!myFile.is_open()) throw std::runtime_error("Could not open file");

    std::string line;

    if (myFile.good()) {
        std::getline(myFile, line); // Ignore column descriptions
    }

    std::list<std::pair<int, int>> parsed_edge_list;
    while (std::getline(myFile, line)) {
        // Create a stringstream of the current line
        std::stringstream ss(line);

        int val_1;
        int val_2;
        ss >> val_1;
        ss >> val_2;

        parsed_edge_list.push_back(std::make_pair(val_1, val_2));
    }

    myFile.close();
    return parsed_edge_list;
}

