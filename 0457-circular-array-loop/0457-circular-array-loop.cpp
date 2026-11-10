class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        auto getNext = [&](int index, bool direction) {
            bool currentDirection = nums[index] > 0;
            if (currentDirection != direction) return -1;

            int nextIndex = (index + nums[index] % n + n) % n;
            if (nextIndex == index) return -1;

            return nextIndex;
        };

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;

            bool isForward = nums[i] > 0;
            int slow = i;
            int fast = i;

            while (true) {
                slow = getNext(slow, isForward);
                fast = getNext(fast, isForward);

                if (fast != -1) {
                    fast = getNext(fast, isForward);
                }

                if (slow == -1 || fast == -1) break;

                if (slow == fast) return true;
            }

            int current = i;
            while (nums[current] != 0 && (nums[current] > 0) == isForward) {
                int nextIndex = (current + nums[current] % n + n) % n;
                nums[current] = 0;
                current = nextIndex;
            }
        }

        return false;
    }
};