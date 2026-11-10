class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int r = 0, i = 0, n = heaters.size();

        for (int h : houses) {
            while (i < n - 1 && abs(heaters[i + 1] - h) <= abs(heaters[i] - h)) {
                i++;
            }
            r = max(r, abs(heaters[i] - h));
        }

        return r;
    }
};