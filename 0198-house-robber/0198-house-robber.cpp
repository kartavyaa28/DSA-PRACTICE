class Solution {
public:
    int rob(vector<int>& nums) {
        //used tabulation
        int n = nums.size();

        if(n == 1)return nums[0];
        vector<int>t(n+1);
        t[0] = 0;
        t[1] = nums[0];
        for(int i = 2; i <=n; i++)
        {
            int skip = t[i-1];
            int steal = nums[i-1] + t[i-2];
            t[i] = max(skip,steal);
        }

        return t[n];
        
    }
};