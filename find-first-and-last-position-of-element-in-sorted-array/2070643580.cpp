class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n;
        int count = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                count++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                n=i;
                return {n,n+count};
                break;
            }
        }
        return {-1,-1};
    }
};