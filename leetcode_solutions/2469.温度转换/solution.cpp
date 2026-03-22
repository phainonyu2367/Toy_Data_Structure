#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<double> convertTemperature(double celsius) {
        std::vector<double> ans{celsius + 273.15, celsius * 1.80 + 32.00};
        return ans;
    }
};