class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
            map<string, vector<string>> mp;  // use map to store sorted strings as keys and their anagrams as values

            for(int i=0; i<str.size(); i++){  // iterate through each string in the input vector
                string s = str[i]; // take the current string
                sort(s.begin(), s.end());   // sort the string to create a key
                mp[s].push_back(str[i]); // push the original string into the vector corresponding to the sorted key
            }

            vector<vector<string>> ans(mp.size()); // create a vector of vectors to hold the grouped anagrams

            int index = 0;
            for(auto x: mp){ // iterate through the map
                auto temp = x.second; // get the vector of anagrams for the current sorted key

                for(auto x: temp){ // iterate through the anagrams
                    ans[index].push_back(x); // push each anagram into the result vector
                }
                index++; // increment the index for the next group of anagrams
            }

            return ans;
    }
};

Explanation:
// We use a map to group anagrams together. The key is the sorted version of the string, and the value is a vector of strings that are anagrams of each other.
// We iterate through each string, sort it, and use it as a key to store the original string in the map.    
// Finally, we convert the map into a vector of vectors to return the grouped anagrams.

⏱️ TIME COMPLEXITY
Let:

n = number of strings in input vector str

k = maximum length of a single string

🔹 Step 1: Sorting each string
Sorting takes O(k log k) time per string.

For n strings: O(n × k log k) 


SPACE COMPLEXITY
🔹 Map Storage:
We're storing up to n strings grouped by their sorted versions.

Each group holds strings of total length ≈ n × k

So the map takes O(n × k) space

