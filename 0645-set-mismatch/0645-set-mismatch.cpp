class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> ans;

        // Count frequency
        for (int x : nums) {
            mp[x]++;
        }

        int repeating = -1, missing = -1;

        // Check all numbers from 1..n
        for (int i = 1; i <= n; i++) {
            if (mp[i] == 2) repeating = i;
            if (mp[i] == 0) missing = i; // unordered_map auto-inserts missing keys with value 0 when accessed.  
        }

        ans.push_back(repeating);
        ans.push_back(missing);
        return ans;
    }
};
