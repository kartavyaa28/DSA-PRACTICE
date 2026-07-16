class Solution {
public:
    int findMax(vector<int>&arr)
    {
        int maxi=INT_MIN;
        for(int i=0 ; i < arr.size() ; ++i)
        {
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }

    long long TotalHour(vector<int>&arr , int hours)
    {
        long long totalhours=0;
        for(int i=0 ; i  < arr.size() ;++i)
        {
            totalhours+=ceil((double)arr[i]/(double)hours);
        }
        return totalhours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int k=0;
        int low=1;
        int high=findMax(piles);
        while(low<= high)
        {
            int mid = low+(high-low)/2;
            long long totalhours=TotalHour(piles,mid);
            if(totalhours<=h)
            {
                k=mid;
                high=mid-1;
            }

            else 
            low=mid+1;
        }
        return k;

        
    }
};