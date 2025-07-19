// Approach 1:  Brute force - sorting

// compare the characters in both strings and check if they have the same characters but in a different order. By tracking the count of each character, if the counts match for all characters, the strings are anagrams; otherwise, they are not.

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};

// Time complexity: O(nlogn) for sorting both strings
// Space complexity: O(1) if we ignore the space used by the sorting algorithm, otherwise O(n) for storing the sorted strings.

// Approach 2: Hash Table
Explanation:
We use a hash map to count characters in s and then subtract counts using t. If the final counts of all characters are zero, both strings are anagrams.


class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> count;

        for(auto x : s){ // Count characters in s
            count[x]++;  // Increment count for each character in s
        }


        for(auto x: t){
            count[x]--;
        }

        for(auto x: count){
            if(x.second !=0){
                return false;
            }
        }

        return true;


    }
};

time complexity: O(n) for iterating through both strings
space complexity: O(1) if we consider the character set to be constant (like lowercase English letters), otherwise O(n) for storing the counts of characters in the map.



Approach 3: Hash Table (Using Array):
Explanation:
Instead of a hash map, we use a fixed-size array to track character counts (only lowercase). It is faster and uses less memory when the character set is limited.


class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0}; // Assuming only lowercase English letters

        for(char x: s){ // Count characters in s
            count[x - 'a']++; // Increment count for each character in s
        }


        for(char x: t){
            count[x - 'a']--; // Decrement count for each character in t    
        }

        for(int val : count){ // Check if all counts are zero 
            // If any count is not zero, the strings are not anagrams
            // If the count is zero, it means the character appeared equally in both strings
            if(val != 0){
                return false;
            }
        }
    return true;

    }
};

time complexity: O(n) for iterating through both strings
space complexity: O(1) since the size of the count array is fixed (26 for lowercase English letters).