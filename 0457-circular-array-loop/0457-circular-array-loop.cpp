class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            
            unordered_set<int> visited;
            int current = i;
            bool isForward = nums[i] > 0;
            
            while (true) {
                if ((nums[current] > 0) != isForward) break;
                
                if (visited.count(current)) {
                    int nextPos = (current + nums[current] % n + n) % n;
                    if (current != nextPos) return true;
                    break;
                }
                
                visited.insert(current);
                int nextPos = (current + nums[current] % n + n) % n;
                if (current == nextPos) break;
                current = nextPos;
            }
            
            current = i;
            while (nums[current] != 0 && (nums[current] > 0) == isForward) {
                int nextPos = (current + nums[current] % n + n) % n;
                nums[current] = 0;
                current = nextPos;
            }
        }
        
        return false;
    }
};