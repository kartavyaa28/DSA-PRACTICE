class Solution {
private:
    bool checkEqual(int a[26], int b[26])
    {
        for(int i = 0; i < 26; i++)
        {
            if(a[i] != b[i])
            {
                return false;
            }
        }

        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0};
        int freq2[26] = {0};
         
        // counted every char count in s1
        for(int i=0; i < s1.length(); i++)
        {
            int index = s1[i] - 'a';
            freq1[index]++;
        }

        //traverse s2 string in window size of s1 length and compare

        int i = 0;
        int windowSize = s1.length();

        //running for first window
        while(i < windowSize && i < s2.length())
        {
            freq2[s2[i] - 'a']++;
            i++;
        }

        if(checkEqual(freq1, freq2))
            return true;

        //aage ki window process karo 

        while( i < s2.length())
        {
            char newChar = s2[i];
            freq2[newChar - 'a']++; // index is newChar - 'a' also above all;

            char oldChar = s2[i - windowSize];
            freq2[oldChar - 'a']--; // window slided
            i++;

            
            if(checkEqual(freq1, freq2))
                return true;
        }    

        return false;
        
    }
};