class Solution {
public:
    int reqDays(vector<int>& arr, int capacity) {
        int day = 1;
        int loadCapacity = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (loadCapacity + arr[i] > capacity) {
                day = day + 1;
                loadCapacity = arr[i];
            } else
                loadCapacity += arr[i];
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = 0;
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (reqDays(weights, mid) <= days) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};