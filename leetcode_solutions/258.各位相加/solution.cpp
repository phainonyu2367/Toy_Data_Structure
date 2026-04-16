#include <iostream>

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum < 10) {
            return sum;
        } else {
            return addDigits(sum);
        }
    }
};

int main() {
    int input;
    Solution sol;
    while (true) {
        std::cin >> input;
        if (input < 0) {
            return 0;
        }
        std::cout << "input:" << input << std::endl;
        std::cout << "output:" << sol.addDigits(input) << std::endl;
    }
}