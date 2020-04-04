#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int start;
    int end;
    int index;
    char assignedTo;
} Activity;

bool compareByStartTime(const Activity &a, const Activity &b) {
    return a.start < b.start;
}
bool compareByIndex(const Activity &a, const Activity &b) {
    return a.index < b.index;
}

// 'a' start time must be smaller than 'b'
bool isOverlapped(Activity a, Activity b) {
    if (a.start == -1 || b.start == -1) return false;
    return a.end > b.start;
}

void solve(int t) {
    int n; cin >> n;
    vector<Activity> acts;
    bool isImpossible = false;
    for (int i = 0; i < n; ++i) {
        int S, E; cin >> S >> E;
        Activity act = {S, E, i,'-'};
        acts.push_back(act);
    }

    sort(acts.begin(), acts.end(), compareByStartTime);

    Activity lastCActivity = {-1};
    Activity lastJActivity = {-1};

    for (int i = 0; i < n && !isImpossible; ++i) {
        if (!isOverlapped(lastCActivity, acts[i])) {
            acts[i].assignedTo = 'C';
            lastCActivity = acts[i];
        } else if (!isOverlapped(lastJActivity, acts[i])) {
            acts[i].assignedTo = 'J';
            lastJActivity = acts[i];
        } else {
            isImpossible = true;
        }
    }

    printf("Case #%d: ", t);
    if (isImpossible) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        sort(acts.begin(), acts.end(), compareByIndex);
        for (int i = 0; i < n; ++i) {
            cout << acts[i].assignedTo;
        }
        cout << endl;
    }
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve(t);
    }
    return 0;
}