class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            ans^=nums[i]; // XOR operation to find the unique number
        }
        return ans;
    }
};

// The function singleNumber takes a vector of integers as input and returns the integer that appears only once.
// It uses the XOR operation to find the unique number, as XOR of a number with itself is 0 and XOR with 0 is the number itself.
// This approach runs in O(n) time complexity and uses O(1) space complexity.

// Example usage:
// Solution sol;
// vector<int> nums = {4, 1, 2, 1, 2};
// int result = sol.singleNumber(nums); // result will be 4