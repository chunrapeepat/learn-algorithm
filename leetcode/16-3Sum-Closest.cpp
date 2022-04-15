class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(result - target)) {
                    result = sum;
                }
                if (sum < target) {
                    ++j;
                    continue;
                } else if (sum > target) {
                    --k;
                    continue;
                } else {
                    return target;
                }
            }
        }
        return result;
    }
};
