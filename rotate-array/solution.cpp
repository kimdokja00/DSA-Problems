class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> result(nums.size(),1);
        int n = nums.size();
        for(int i =0;i<n;i++){
            result[(i+k)%n]=nums[i];
        }
        nums = result;
    }
};