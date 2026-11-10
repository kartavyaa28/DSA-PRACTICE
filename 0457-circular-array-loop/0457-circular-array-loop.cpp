class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        auto getNext = [&](int curr, bool isForward) {
            bool direction = nums[curr] > 0;
            if (direction != isForward) return -1;
            
            int nextIndex = (curr + nums[curr] % n + n) % n;
            if (nextIndex == curr) return -1;
            
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

            int curr = i;
            while (nums[curr] != 0 && (nums[curr] > 0) == isForward) {
                int nextIndex = (curr + nums[curr] % n + n) % n;
                nums[curr] = 0;
                curr = nextIndex;
            }
        }

        return false;
    }
};