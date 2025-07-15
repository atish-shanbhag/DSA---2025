Brute force:

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