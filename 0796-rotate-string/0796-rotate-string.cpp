class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())return false;
        if(s.length() == 1)
        {
            if(s == goal)return true;
            return false;

        }
        string newS = s + s;
        for(int i = 0; i< newS.length(); i++)
        {
            if(newS.substr(i,goal.length()) == goal)
            {
                return true;
            }
        }
        return false;
        
    }
};