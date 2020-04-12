class Solution {
public:
    int search(vector<int>& p, int e) {
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == e) {
                return i;
            }
        }
        return -1;
    }

    vector<int> processQueries(vector<int>& q, int m) {
        vector<int> ans;
        // vector<int> p(m);
        int next = -1;
        int cnt = 0;
        vector<int> state(m);
        for (int i = 1; i <= m; ++i) {
            // p[i-1] = i;
            state[i-1] = i-1;
        }
        for (int i = 0; i < q.size(); ++i) {
            // int index = search(p, q[i]);
            // ans.push_back(index);
            // p.erase(p.begin() + index);
            // p.insert(p.begin(), q[i]);

            // for (int j = 0; j < p.size(); ++j) {
            //     cout << p[j] << " ";
            // }
            // cout << endl;
            int index = state[q[i]-1] + cnt;
            if (index > m-1) index = m-1;
            ans.push_back(index);
            // insert
            state[q[i]-1] = next;
            next += -1;
            ++cnt;
        }
        return ans;
    }
};