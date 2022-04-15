// efficient solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    ++j;
                    continue;
                } else if (sum > 0) {
                    --k;
                    continue;
                } else {
                    vector<int> v{nums[i], nums[j], nums[k]};
                    result.push_back(v);
                    --k;
                    continue;
                }
            }
        }
        return result;
    }
};

// first attempt -> time limit exceeded
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        map<int, vector<vector<int>>> sumMap;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int sum = nums[i] + nums[j];
                if (sumMap.find(sum) == sumMap.end()) {
                    vector<vector<int>> v;
                    sumMap.insert({sum, v});
                }
                vector<int> r{nums[i], nums[j], i, j};
                sumMap.find(sum)->second.push_back(r);
            }
        }
        map<vector<int>, bool> checker;
        for (int i = 0; i < nums.size(); ++i) {
            int inv = -1 * nums[i];
            if (sumMap.find(inv) == sumMap.end()) continue;
            vector<vector<int>> v = sumMap.find(inv)->second;
            for (int idx = 0; idx < v.size(); ++idx) {
                vector<int> r = v[idx];
                if (r[2] == i || r[3] == i) continue;
                vector<int> t{r[0], r[1], nums[i]};
                sort(t.begin(), t.end());
                if (checker.find(t) != checker.end()) continue;
                checker[t] = true;
                result.push_back(t);
            }
        }
        return result;
    }
};
