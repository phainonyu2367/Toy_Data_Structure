#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int min(int num1, int num2) {
        return num1 < num2 ? num1 : num2;
    }
public:
    int maxArea(vector<int>& height) {
        int size = height.size(), maxCapacity = 0, capacity = 0;
        
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                capacity = min(height[i], height[j]) * (j - i);
                if (capacity > maxCapacity) {
                    maxCapacity = capacity;
                }
            }
        }

        return maxCapacity;
    }
};
