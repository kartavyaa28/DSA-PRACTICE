class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mapS;
        unordered_map<char,char>mapT;

        for(int i = 0; i < s.length(); ++i)
        {
            char c1 = s[i], c2 = t[i];
            // check c1 is already mapped or not
            if(mapS.count(c1))
            {
                //checking not mapping to any another char
                if(mapS[c1] != c2) return false;
            }
            else
            {
                mapS[c1] = c2;
            }
          
            // check c2 is already mapped or not
            if(mapT.count(c2))
            {
                //checking not mapping to any another char
                if(mapT[c2] != c1) return false;
            }
            else
            {
                mapT[c2] = c1;
            }
        }

        return true;
        
    }
};