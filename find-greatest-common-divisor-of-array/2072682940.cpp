class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a ,b;
        a = nums[0];
        b = nums[nums.size()-1];
        int result = gcd(a , b);
        return result;
    }
};