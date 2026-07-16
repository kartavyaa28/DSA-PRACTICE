class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n == 1) return nums[0]; // if size of arr is 0
        if(nums[0] != nums[1])return nums[0]; //handling first element
        if(nums[n-1] != nums[n-2]) return nums[n-1]; // handling last element
        int low=1;
        int high=n-2;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            {
                return nums[mid];
            }

            //we are on left half so eliminate it
            if(mid % 2 == 1 && nums[mid] == nums[mid-1] || mid % 2 == 0 && nums[mid+1] == nums[mid])
            {
                low = mid+1;

            }
            //we are on right half so eliminate it
            else
            {
                high = mid-1;
            }
        }

        return -1;
        
    }
};