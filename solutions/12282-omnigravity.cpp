#include <iostream>
#include <vector>
#include <map>
#include <cmath>

#define mp make_pair

using namespace std;

int key(vector<pair<int, int>>& b) {
    int sum = 0;
    int power = 0;
    for (int i = 0; i < 4; ++i) {
        sum += b[i].first*pow(10, power) + b[i].second*pow(10, power + 1);
        power += 2;
    }
    return sum;
}

// TODO: Implement
void moveTop(int i, vector<pair<int, int>>& b, bool obs[8][8]) {
    if (b[i].first == 0) return;
    if (obs[b[i].first-1][b[i].second] || obs[b[i].first-1][b[i].second+1]) return;

    for (int j = 0; j < 4; ++j) {
        if (i == j) continue;
        if (b[j].first < b[i].first && (b[j].second == b[i].second || b[j].second == b[i].second - 1 || b[j].second == b[i].second + 1)) {
            moveTop(j, b, obs);
        }
    }
}

void search(map<int, bool> comb, bool obs[8][8], vector<pair<int, int>> blocks, int& cnt) {
    int bkey = key(blocks);
    if (comb.find(bkey) != comb.end() && comb.find(bkey)->second) {
        return;
    }

    comb.insert({bkey, true});
    cnt += 1;

    // search all possibility here top, bottom, right, left
    vector<pair<int, int>> top = blocks;
    for (int i = 0; i < 4; ++i) moveTop(i, blocks, obs);
}

int main() {
    int T; cin >> T;
    int testcase = 0;

    while (T--) {
        int cnt = 1;
        map<int, bool> comb;
        bool obs[8][8] = {0};
        vector<pair<int, int>> blocks(4, pair<int, int>(-1, -1));

        // get input
        for (int i = 0; i < 8; ++i) {
            string str; cin >> str;
            for (int j = 0; j < str.length(); ++j) {
                if (str[j] == '#') {
                    obs[i][j] = true;
                } else if (str[j] >= 'A' && str[j] <= 'D') {
                    if (blocks[str[j] - 'A'].first == -1) {
                        cout << str[j] - 'A' << " " << i << " " << j << endl;
                        blocks[str[j] - 'A'].first = i;
                        blocks[str[j] - 'A'].second = j;
                    }
                }
            }
        }

        // recursive search all possibility
        comb.insert({key(blocks), true});
        search(comb, obs, blocks, cnt);

        string blank;
        printf("Case %d: %d\n", ++testcase, cnt);
    }

    return 0;
}