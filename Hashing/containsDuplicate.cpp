Brute force:
Explanation:
We compare every possible pair in the array to check if any two numbers are the same. If we find any such pair, we return true; otherwise, return false after all checks.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i< n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]==nums[j])
                return true;
            }
        }
        return false;
    }
};

Time complexity: O(n^2);
space complexity: O(1);
TLE


Approach using Sorting:

Explanation:
Sorting the array makes any duplicates appear next to each other. We simply check if any adjacent elements are equal.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;
    }
};


Time complexity: O(nlogn);
space complexity: O(1)



Approach using Hash set:
Explanation:
We use a hash set to store elements as we iterate. If we find a number already in the set, it means we've seen it before → its a duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num) > 0)
                return true;
            seen.insert(num);
        }
        return false;
    }
};


Time complexity: O(n);
space complexity: O(n);


Approach using hash map:
// Explanation:
We use a hash map to keep count of how many times each number appears. If any number appears more than once, its a duplicate.


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int num:nums){
            if(seen[num] >= 1)
                return true;
                seen[num]++;
        }
        return false;
    }
};

Time complexity: O(n);
space complexity: O(n);