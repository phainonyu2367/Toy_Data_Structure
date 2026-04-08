#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        int ptr1 = 0, ptr2 = 0;
        for (; ptr2 < nums.size(); ++ptr2) {
            if (nums[ptr2] != 0) {
                nums[ptr1] = nums[ptr2];
                ++ptr1;
            }
        }

        for (; ptr1 < nums.size(); ++ptr1) {
            nums[ptr1] = 0;
        }
    }
};