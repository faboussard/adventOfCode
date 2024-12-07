// sort both lists

// extract lists from file:
// make pair  l1 and l2 (split on space)
// create a vector with pushback pair.first
// same for l2.
// pair up the smallest numbers in the left list with the smallest in the right
// list = pair up the numbers calculate b - a sum the difference

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string input = argv[1];
    std::ifstream file(input);

    std::vector<int> list1;
    std::vector<int> list2;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << input << std::endl;
        return 1;
    }

    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string input_list1, input_list2;
        char delimiter = ' ';
        if (std::getline(iss, input_list1, delimiter) && std::getline(iss, input_list2)) {
            list1.push_back(std::stoi(input_list1));
            list2.push_back(std::stoi(input_list2));
        }
    }

    file.close();

    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    int diff = 0;
    for (size_t i = 0; i < list1.size() && i < list2.size(); ++i) {
        diff += std::abs(list2[i] - list1[i]);
    }

    std::cout << "Difference is " << diff << std::endl;

    return 0;
}