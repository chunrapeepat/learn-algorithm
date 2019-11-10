class Solution {
public:
    vector<vector<int>> reconstructMatrix(int u, int l, vector<int>& colsum) {
        int sum = 0;
        int U = u;
        int L = l;
        vector<vector<int>> result;
        for (int i = 0; i < colsum.size(); ++i) sum += colsum[i];
        if (u + l != sum) return result;

        const int n = colsum.size();
        vector<int> upper = vector<int>(n);
        vector<int> lower = vector<int>(n);

        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 0) continue;
            if (colsum[i] == 2) {
                if (u > 0 && l > 0) {
                    u--;
                    l--;
                    upper[i] = 1;
                    lower[i] = 1;
                }
            } else {
                if (u > l) {
                    if (u > 0) {
                        u--;
                        upper[i] = 1;
                    }
                } else {
                    if (l > 0) {
                        l--;
                        lower[i] = 1;
                    }
                }
            }
        }

        int upper_check = 0;
        int lower_check = 0;
        for (int i = 0; i < n; ++i) {
            upper_check += upper[i];
            lower_check += lower[i];
        }

        // cout << U << "-" << upper_check << " " << L << "-" << lower_check << endl;

        if (upper_check != U || lower_check != L) {
            return result;
        }

        result.push_back(upper);
        result.push_back(lower);

        return result;
    }
};