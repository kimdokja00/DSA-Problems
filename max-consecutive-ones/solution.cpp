class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            }
            if (nums[i] != 1 && count > 0) {
                if (count > max) {
                    max = count;
                }
                count = 0;
            }
            if (count > max) {
                    max = count;
                }

        }
        return max;
    }
};