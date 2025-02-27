#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


bool isHex(const std::string& str) {
    if (str.size() < 3 || (str[0] != '0' || (str[1] != 'x' && str[1] != 'X'))) return false;
    for (size_t i = 2; i < str.size(); ++i)
        if (!std::isxdigit(str[i])) return false;
    return true;
}


bool isDecimal(const std::string& str) {
    if (str.empty()) return false;
    size_t start = 0;

    if (str[0] == '-') start = 1;
    for (size_t i = start; i < str.size(); ++i) {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}
int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    long num1, num2;
    try {
        if(isHex(std::string(argv[1]))) {
            num1 = std::stol(argv[1], nullptr, 16);
        } else if(isDecimal(std::string(argv[1]))) {
            num1 = std::stol(argv[1]);
        }else{
        throw std::invalid_argument("Error");
	}		

        if(isHex(std::string(argv[2]))) {
            num2 = std::stol(argv[2], nullptr, 16);
        } else if(isDecimal(std::string(argv[2]))) {
            num2 = std::stol(argv[2]);
        }else{
        throw std::invalid_argument("Error");
	}	
    } catch (...) {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    long sum = num1 + num2;
    std::stringstream ss;
    ss << "0x" << std::uppercase << std::hex << sum << " " << std::dec << sum;
    std::cout << ss.str() << std::endl;

    return 0;
}
