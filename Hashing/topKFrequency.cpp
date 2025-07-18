class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            mp[nums[i]]++; // Count frequency of each number
        }

        priority_queue<pair<int, int>> pq; // Max heap to store frequency and number

        for(auto it: mp){
            pq.push({it.second, it.first}); // Push frequency and number into the max heap
        }

        vector<int> ans; // Vector to store the top k frequent elements

        while(k--){
            int val = pq.top().second; // Get the number with the highest frequency
            ans.push_back(val); // Add it to the result vector
            pq.pop(); // Remove the top element from the heap
        }
        return ans; // Return the vector containing the top k frequent elements
    }
}


// Explanation:

Step 1: Count Frequencies
// We use an unordered_map to count the frequency of each number in the input vector nums.
// The key is the number, and the value is its frequency.
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

// Step 2: Use a Max Heap
// We use a priority queue (max heap) to store pairs of frequency and number.
        priority_queue<pair<int, int>> pq;

        for(auto it: mp){
            pq.push({it.second, it.first});
        }

// Step 3: Extract Top K Frequent Elements
// We pop the top k elements from the max heap, which gives us the k most frequent          
// elements in descending order of frequency.
        vector<int> ans;
        while(k--){
            int val = pq.top().second; // Get the number with the highest frequency
            ans.push_back(val); // Add it to the result vector
            pq.pop(); // Remove the top element from the heap
        }
        return ans; // Return the vector containing the top k frequent elements


Step-by-step Complexity Analysis
🔹 Step 1: Counting Frequencies

for (int i = 0; i < n; i++) {
    mp[nums[i]]++;
}
Time: O(n) — loop through the nums array once.

Space: O(n) — in the worst case, all numbers are unique → mp stores n keys.

🔹 Step 2: Building the Heap

for (auto it : mp) {
    pq.push({it.second, it.first});
}
Number of unique elements = u (≤ n)

You push each unique element into the priority queue.

Time: Each push into a priority queue takes O(log u) time.
Total = O(u log u)

Space: O(u) for the heap.

🔹 Step 3: Extracting Top K Elements

while (k--) {
    int val = pq.top().second;
    pq.pop();
    ans.push_back(val);
}
You pop k elements from the heap.

Each pop operation is O(log u)

Time: O(k log u)

Space: O(k) for storing the result in ans

✅ Final Time and Space Complexity
🔸 Time Complexity:

O(n)                 → for counting frequencies  
+ O(u log u)         → for building the heap  
+ O(k log u)         → for extracting top k elements
Since u ≤ n (number of unique elements ≤ total elements), we can simplify:

🔹 Total Time: O(n + n log n + k log n) = O(n log n) in worst case

But if number of unique elements is much less than n, it’s closer to:

🟢 Average case: O(n + u log u)

🔸 Space Complexity:

O(n) → for hashmap  
+ O(u) → for heap  
+ O(k) → for answer
Overall:

🔹 Total Space: O(n) (since u and k ≤ n)