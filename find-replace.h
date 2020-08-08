#ifndef FIND_REPLACE_H
#define FIND_REPLACE_H

#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <sstream>
#include <fstream>

namespace fr {
    std::string getInput() {
        char *input;
        std::cin.getline(input, 2147483647);
        return input;
    }

    std::string replace(std::string const &in, std::string const &from, std::string const &to)
    {
        return std::regex_replace(in, std::regex(from), to);
    }

    std::string translate(std::string input, std::map<std::string, std::string> dictionary) {
        for(std::pair<std::string, std::string> iter : dictionary) {
            input = replace(input, iter.first, iter.second);
        }
        return input;
    }

    std::map<std::string, std::string> loadDictionaryFromFile(const char *file) {
        std::map<std::string, std::string> dictionary;
        
        std::ifstream inFile = std::ifstream(file);
        std::string nextLine;
        std::istringstream iss;

        while(std::getline(inFile, nextLine)) {
            std::string english, stonks;
            std::istringstream(nextLine) >> english >> stonks;
            dictionary[english] = stonks;
        }

        return dictionary;
    }
}

#endif