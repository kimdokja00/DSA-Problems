class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *max_element(nums.begin(), nums.end());
      
        vector<int> cnt(max_val + 1, 0);
        for (int x : nums) {
            cnt[x]++;
        }

        vector<long long> exact_gcd(max_val + 1, 0);

        for (int i = max_val; i >= 1; i--) {
            long long multiples_count = 0;

            for (int j = i; j <= max_val; j += i) {
                multiples_count += cnt[j];
            }

            long long pairs_count = multiples_count * (multiples_count - 1) / 2;

            for (int j = 2 * i; j <= max_val; j += i) {
                pairs_count -= exact_gcd[j];
            }
            
            exact_gcd[i] = pairs_count;
        }

        vector<long long> prefix(max_val + 1, 0);
        for (int i = 1; i <= max_val; i++) {
            prefix[i] = prefix[i - 1] + exact_gcd[i];
        }

        vector<int> result;
        result.reserve(queries.size());
        for (long long q : queries) {

            auto it = upper_bound(prefix.begin() + 1, prefix.end(), q);
            result.push_back(distance(prefix.begin(), it));
        }

        return result;
    }
};