class Solution {
public:
    string expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // substring after expansion
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string ans = "";
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            // Odd length
            string odd = expandAroundCenter(s, i, i);
            if (odd.size() > maxLen) {
                ans = odd;
                maxLen = odd.size();
            }

            // Even length
            string even = expandAroundCenter(s, i, i + 1);
            if (even.size() > maxLen) {
                ans = even;
                maxLen = even.size();
            }
        }
        return ans;
    }
};