class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        const int n = words.size();
        map<string, int> dup;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && dup.find(words[j]) == dup.end() && words[i].find(words[j]) != string::npos) {
                    ans.push_back(words[j]);
                    dup.insert(make_pair(words[j], 1));
                }
            }
        }
        return ans;
    }
};