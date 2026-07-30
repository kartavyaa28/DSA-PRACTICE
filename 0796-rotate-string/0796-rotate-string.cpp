class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n = s.length();
        if (n == 1) {
            if (s == goal)
                return true;
            return false;
        }
        for (int i = 0; i < n; i++) {
            char first = s[0];
            for (int j = 1; j < n; j++) {
                s[j - 1] = s[j];
            }
            s[n - 1] = first;
            
            if (s == goal) {
                return true;
            }
        }

        return false;
    }
};