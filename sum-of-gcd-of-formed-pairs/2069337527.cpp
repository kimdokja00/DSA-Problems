class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd(nums.size());
        long long sum = 0;
        int mxi=0;
        for(int i=0;i<nums.size();i++){
            int n =i;
            mxi =max(mxi,nums[i]);
        prefixGcd[i]= gcd(nums[i],mxi);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        for(int i =0;i<(prefixGcd.size()/2);i++){
            int n = prefixGcd.size();
            sum = sum + gcd(prefixGcd[i],prefixGcd[n-1-i]);
        }
        return sum;
    }
};