// O(nlogn) Solution
class Solution {
public:
    static bool predicate(pair<vector<int>, double> a, pair<vector<int>, double> b) {
        return a.second < b.second;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<vector<int>, double>> dists;
        for (vector<int> p : points) {
            dists.push_back(make_pair(p, sqrt(p[0]*p[0] + p[1]*p[1]) ));
        }
        return findMin(dists, K);
    }
    vector<vector<int>> findMin(vector<pair<vector<int>, double>>& dists, int K) {
        sort(dists.begin(), dists.end(), predicate);
        vector<vector<int>> res;
        for (int i = 0; i < K; ++i) {
            // DEBUG
            //cout << dists[i].first[0] << "," << dists[i].first[1] << " -> " << dists[i].second << endl;

            res.push_back(dists[i].first);
        }
        return res;
    }
};