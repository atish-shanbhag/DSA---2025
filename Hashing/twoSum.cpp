class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp; // Map to store the number and its index
        vector<int>ans; // Vector to store the result indices

        int n = nums.size();

        for(int i=0; i<n; i++){
            int comp = target - nums[i]; // Calculate the complement needed to reach the target
            if(mp.count(comp)){
                ans.push_back(mp[comp]); // If complement exists, push its index
                ans.push_back(i); // Push the current index
                return ans; // Return the result as soon as we find a pair
            }
            mp[nums[i]] = i; // Store the current number and its index in the map
        }
        return ans; // Return an empty vector if no pair is found
    }
}; 

// Explanation:
// We use an unordered_map to store each number and its index as we iterate through the nums
// array. For each number, we calculate the complement that would sum with it to reach the target.
// If the complement exists in the map, we have found our two indices and return them immediately.
// If we finish the loop without finding a pair, we return an empty vector.

// Time Complexity: O(n) — We traverse the nums array once.
// Space Complexity: O(n) — In the worst case, we store all n numbers in the map.