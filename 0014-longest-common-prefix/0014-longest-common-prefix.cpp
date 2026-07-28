class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return ""; // handling edge case , if string is already empty
        //sorting lexicographically
        sort(strs.begin(),strs.end());
        string first = strs[0]; // first string 
        string last = strs[strs.size()-1]; //storing last element
        string ans = "";

        // looping for comparing characters
        int minLength = min(first.size(),last.size());
        for(int i = 0;i < minLength; i++)
        {
            if(first[i] != last[i]) break;
            ans+=first[i];
        }

        return ans;

    }
};