/**
 * \file
 * \brief File with input functions
 */
#include <iostream>

bool try_input(int &number) {
    std::cin >> number;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        return false;
    }
    return true;
}

int get_int(int left, int right) {
    int res = 0;
    while (!try_input(res) || left > res || right < res);
            std::cout << "Try again" << std::endl;
    return res;
}