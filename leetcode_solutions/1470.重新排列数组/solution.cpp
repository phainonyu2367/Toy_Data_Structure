#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> newNums;
        newNums.resize(2 * n, 0);
        for (int i = 0; i < n; ++i) {
            newNums[2 * i] = nums[i];
            newNums[2 * i + 1] = nums[n + i];
        }
        return newNums;
    }
};