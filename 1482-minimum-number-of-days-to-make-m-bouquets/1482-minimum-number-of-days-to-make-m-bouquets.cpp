class Solution {
public:
    bool possible(vector<int>& arr, int days, int m, int k) {
        int n = arr.size();
        int cnt = 0;
        int noofB = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= days)
                cnt++;
            else {
                noofB += (cnt / k);
                cnt = 0;
            }
        }
        noofB += (cnt / k);
        if (noofB >= m)
            return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        int n = bloomDay.size();
        long long val = 1LL * m * k;
        if (n < val)
            return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] < mini)
                mini = min(mini, bloomDay[i]);
            if (bloomDay[i] > maxi)
                maxi = max(maxi, bloomDay[i]);
        }

        int low = mini, high = maxi;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k) == true) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};