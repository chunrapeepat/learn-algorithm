#include <iostream>

using namespace std;

#define LSOne(n) n&(-n)

class FenwickTree {
private:
    vector<int> fTree;
public:
    FenwickTree(int n) {
        fTree.assign(n+1, 0);
    }
    int rsq(int n) {
        int sum = 0;
        while (n) {
            sum += fTree[n];
            n -= LSOne(n);
        }
        return sum;
    }
    int getSum(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
    void assignValue(int pos, int value) {
        while (pos < (int) fTree.size()) {
            fTree[pos] += value;
            pos += LSOne(pos);
        }
    }
};

void main() {
    int n, q; cin >> n >> q;
    FenwickTree t1(n+1);
    FenwickTree t2(n+1);
    int i = 1;
    vector<int> a1(n+1);
    vector<int> a2(n+1);
    while (n--) {
        int num; cin >> num;
        int direction = (i % 2) ? 1 : -1;

        t1.assignValue(i, direction * num);
        t2.assignValue(i, -1 * direction * num);

        a1[i] = direction * num;
        a2[i] = -1 * direction * num;

        ++i;
    }
    while (q--) {
        int p, v; cin >> p >> v;
        int adj = v - a1[p];
        int adj2 = v - a2[p];

        t1.assignValue(p, adj);
        t2.assignValue(p, adj2);

        int direction = (p % 2) ? 1 : -1;
        a1[p] = direction * v;
        a2[p] = -1 * direction * v;
    }
    return 0;
}