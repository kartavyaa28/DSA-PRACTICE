class Solution {
public:
    bool isAnagram(string s, string t) {
        // Initialize a frequency array to store character counts
        int  freq[26] = {0};
         for(int i = 0; i < s.length(); i++)
         {
            freq[s[i] - 'a']++;// Increment frequency for each character in str1
         }
         for(int i = 0; i < t.length(); i++)
         {
            freq[t[i] - 'a']--;// Decrement frequency for each character in str2
         }
         for(auto it : freq)
         {
            if(it != 0) return false;
         }

         return true;
       
        
    }
};