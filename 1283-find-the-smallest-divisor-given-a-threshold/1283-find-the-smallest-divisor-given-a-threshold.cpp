class Solution {
public:
    // Helper function to calculate sum of division results
    int sumByD(vector<int>& arr, int div) {
        int sum = 0;
        for (int num : arr) {
            sum += ceil((double)num / div);
        }
        return sum;
    }

    // Function to find the smallest divisor
    int smallestDivisor(vector<int>& arr, int limit) {
        if (arr.size() > limit)
            return -1;

        int low = 1;
        int high = *max_element(arr.begin(), arr.end());

        // Binary search to find smallest divisor
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumByD(arr, mid) <= limit) {
                high = mid - 1; // Try smaller divisor
            } else {
                low = mid + 1; // Try larger divisor
            }
        }

        return low;
    }
};
