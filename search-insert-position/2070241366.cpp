class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n;
        int count;
        for (int i = 0;i<nums.size();i++){
            if(nums[i]>=target){
                n=i;
                break;
            }
        }return n;

    }
};