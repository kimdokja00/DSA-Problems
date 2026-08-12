class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        vector<int> result(n,1);
        for(int i = 0;i<n;i++){
            if(nums[i]==0){
                result[end--]=0;
            }else{
                result[start++]=nums[i];

            }
        }
        nums = result;

    }
};