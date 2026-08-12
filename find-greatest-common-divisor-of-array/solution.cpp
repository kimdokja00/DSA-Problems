class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a ,b;
        a = *max_element(nums.begin(),nums.end());
        b = *min_element(nums.begin(),nums.end()) ;
        int result = gcd(a , b);
        return result;
    }
};