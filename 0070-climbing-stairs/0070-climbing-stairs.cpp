class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        
        int prev2 = 1; // Represents t[i - 2] (starts at step 1)
        int prev1 = 2; // Represents t[i - 1] (starts at step 2)
        
        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;  
    }
};