class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq; // using map to calculate freq of each element
        for(auto x : s)
        {
            freq[x]++;
        }

        vector<pair<char,int>>v; // storing into vector to perform sorting on the basis of freq

        for(auto x : freq)
        {
            v.push_back(x);
        }

        //using lambda function and here auto is pair<char,int>
        sort(v.begin(),v.end(), [](auto &a , auto &b){ 
            return a.second > b.second; 
        });

        //building answer
        string ans;
        for(auto x : v)
        {
            ans+=string(x.second,x.first); //string builder string(count,char)
        }

        return ans;

        
    }
};