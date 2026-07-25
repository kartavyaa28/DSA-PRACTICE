class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string result = "";
        for (char c : s) {
            if (c == '(') {
                if (!st.empty())
                    result += c; // not outermost
                st.push(c);
            } else {
                st.pop();
                if (!st.empty())
                    result += c; // not outermost means ) this is part of innermost content
            }
        }
        return result;
    }
};