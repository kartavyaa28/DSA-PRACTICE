class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long mid) {
        long long sum = 0;
        int cnt = 1; // at least one subarray
        for (int i : nums) {
            if (i > mid) return false; // single element exceeds mid
            if (sum + i > mid) {
                cnt++;       // start new subarray
                sum = i;   // reset sum
                if (cnt > k) return false;
            } else {
                sum += i;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end()); // min possible largest sum
        long long high = accumulate(nums.begin(), nums.end(), 0LL); // max possible largest sum
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canSplit(nums, k, mid)) {
                ans = mid;      // feasible, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;  // not feasible, increase limit
            }
        }
        return (int)ans;
    }
};
