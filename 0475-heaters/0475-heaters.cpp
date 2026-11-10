class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int r = 0;

        for (int h : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), h);
            int d = INT_MAX;

            if (it != heaters.end()) {
                d = min(d, *it - h);
            }
            if (it != heaters.begin()) {
                d = min(d, h - *(it - 1));
            }

            r = max(r, d);
        }

        return r;
    }
};