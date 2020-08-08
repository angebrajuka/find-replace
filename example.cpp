#include "find-replace.h"

int main() {
    std::map<std::string, std::string> dictionary = fr::loadDictionaryFromFile("dictionary.txt");
    std::cout << fr::translate(fr::getInput(), dictionary) << std::endl;
}