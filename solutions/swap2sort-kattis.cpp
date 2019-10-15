#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<int N>
class quick_union{
public:
    quick_union()
    {
        for(int i =0; i < N; ++i){
            elements[i] = i;
        }
    }
    bool connected(int p, int q) const{
        // are they in the same connected component tree?
        int proot = root(p);
        int qroot = root(q);
        return (proot == qroot);
    }
    void union_components(int p, int q)
    {
        int proot = root(p);
        int qroot = root(q);
        elements[qroot] = proot;
    }
private:
    int root(int p) const{
        while(elements[p] != p){
            p = elements[p];
        }
        return p;
    }
    int elements[N];
};

int main() {
    int N, K; cin >> N >> K;

    quick_union<N + 1> q;

    for (int k = 0; k < K; ++k) {
        int A, B; cin >> A >> B;
        q.union_components(A, B);
    }

    for (int i = 1; i <= N / 2; ++i) {
        if (!q.connected(i, N + 1 - i)) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}