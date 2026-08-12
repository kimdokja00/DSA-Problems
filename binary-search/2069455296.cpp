class Solution {
public:
    int search(vector<int>& nums, int target) {
        int count =0 ;
        int n;
        for(int i = 0 ;i< nums.size();i++){
            if(nums[i]==target){
                n=i;
                count += 1;
            }
        }
        if(count == 0 ){
            n=-1;
        }return n;
 }
};