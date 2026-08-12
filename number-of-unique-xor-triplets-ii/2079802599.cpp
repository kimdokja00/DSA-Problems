class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> unique_set(nums.begin(), nums.end());
        vector<int> U(unique_set.begin(), unique_set.end());

        int max_val = 0;
        for (int x : U) {
            max_val = max(max_val, x);
        }

        // Find upper bound for XOR results (smallest power of 2 > max_val)
        int limit = 1;
        while (limit <= max_val) {
            limit <<= 1;
        }

        // Step 2: Compute all unique pair XOR values
        std::vector<bool> pair_xor(limit, false);
        for (size_t i = 0; i < U.size(); ++i) {
            for (size_t j = i; j < U.size(); ++j) {
                pair_xor[U[i] ^ U[j]] = true;
            }
        }

        // Step 3: Compute all unique triplet XOR values
        std::vector<bool> triplet_xor(limit, false);
        for (int p = 0; p < limit; ++p) {
            if (pair_xor[p]) {
                for (int z : U) {
                    triplet_xor[p ^ z] = true;
                }
            }
        }

        // Step 4: Count total unique triplet XOR values
        int count = 0;
        for (int i = 0; i < limit; ++i) {
            if (triplet_xor[i]) {
                count++;
            }
        }

        return count;
    }
};