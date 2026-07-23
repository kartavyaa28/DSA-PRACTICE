class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int ptr = 0;
        for (int x : pushed) {
            st.push(x);
            while (!st.empty() && st.top() == popped[ptr]) {
                st.pop();
                ptr++;
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};