class Solution {

private:
    vector <int> cumulativeSum;
    int totalWeight;

public:
    Solution(vector<int>& w) {
        cumulativeSum.push_back (w[0]); // Initialize with the first weight
        for (int i = 1; i < w.size (); i++) {
            cumulativeSum.push_back (cumulativeSum.back () + w[i]);
        }
        totalWeight = cumulativeSum.back (); // Total weight is the last element of cumulativeSum
        srand (time (0)); // Seed the random number generator
    }
    
    int pickIndex() {
        int randomNumber = rand () % totalWeight; // [0, totalWeight - 1]

        int left = 0, right = cumulativeSum.size () - 1; 
        // Binary search for finding first index where,
        // cumulativeSum[i] > randomNumber
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (cumulativeSum[mid] <= randomNumber) {
                left = mid + 1; // Search in right half
            } else {
                right = mid; // Search in left half or at mid
            }
        }

        return left; // left == right at the end of the loop
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */