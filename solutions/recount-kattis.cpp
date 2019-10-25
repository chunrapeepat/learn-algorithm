#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> votes;
    int max = 0;
    bool dup = false;

    while (1) {
        string name; getline(cin, name);
        if (name.compare("***") == 0) break;

        if (votes.find(name) == votes.end()) {
            votes[name] = 1;
        } else {
            ++votes[name];
        }

        if (votes[name] > max) {
            max = votes[name];
            dup = false;
        } else if (votes[name] == max) {
            dup = true;
        }
    }

    if (dup) {
        cout << "Runoff!" << endl;
    } else {
        for (pair<string, int> p: votes) {
            if (p.second == max) {
                cout << p.first << endl;
                break;
            }
        }
    }
    return 0;
}
