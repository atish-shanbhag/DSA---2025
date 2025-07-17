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

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> count;

        for(auto x : s){
            count[x]++;
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

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0}; // Assuming only lowercase English letters

        for(char x: s){
            count[x - 'a']++;
        }


        for(char x: t){
            count[x - 'a']--;
        }

        for(int val : count){
            if(val != 0){
                return false;
            }
        }
    return true;

    }
};

time complexity: O(n) for iterating through both strings
space complexity: O(1) since the size of the count array is fixed (26 for lowercase English letters).