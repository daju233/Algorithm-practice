#include <iostream>
#include <map>
#include <algorithm>

void toLower(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

std::map<std::string, int> countCombinations(const std::string &input) {
    std::map<std::string, int> freqMap;
    
    // Count pairs
    if(input.length()>=2){
    for(size_t i = 0; i < input.length() - 1; ++i) {
        std::string pair = input.substr(i, 2);
        freqMap[pair]++;
    }
    }
    
    // Count triplets
    if(input.length()>=3){
    for(size_t i = 0; i < input.length() - 2; ++i) {
        std::string triplet = input.substr(i, 3);
        freqMap[triplet]++;
    }
    }

    return freqMap;
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cout << "ERROR: Need a string." << std::endl;
        return 1;
    }
    std::string input(argv[1]);
    toLower(input);

    auto freqMap = countCombinations(input);

    for (const auto& pair : freqMap) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}
