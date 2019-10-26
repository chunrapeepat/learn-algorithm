#include <iostream>
#include <vector>

using namespace std;

bool intersect(vector<double>& start1, vector<double>& end1,
        vector<double>& start2, vector<double>& end2) {
    float ax = end1[0] - start1[0];
    float ay = end1[1] - start1[1];

    float bx = start2[0] - end2[0];
    float by = start2[1] - end2[1];

    float dx = start2[0] - start1[0];
    float dy = start2[1] - start1[1];

    float det = ax * by - ay * bx;

    if (det == 0) return false;

    float r = (dx * by - dy * bx) / det;
    float s = (ax * dy - ay * dx) / det;

    return !(r < 0 || r > 1 || s < 0 || s > 1);
}

int main() {
    while (1) {
        int n; cin >> n;
        if (n == 0) break;
        int N = n;

        vector<vector<vector<double>>> lines;
        while (N--) {
            double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            vector<vector<double>> line;
            vector<double> p1(2, 0); p1[0] = x1, p1[1] = y1;
            vector<double> p2(2, 0); p2[0] = x2, p2[1] = y2;
            line.push_back(p1);
            line.push_back(p2);

            lines.push_back(line);
        }

        int cnt = 0;
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    // check i, j should intersect
                    if (intersect(lines[i][0], lines[i][1], lines[j][0], lines[j][1])) {
                        // check j, k should intersect
                        if (intersect(lines[j][0], lines[j][1], lines[k][0], lines[k][1])) {
                            // check i, k should intersect
                            if (intersect(lines[i][0], lines[i][1], lines[k][0], lines[k][1])) {
                                ++cnt;
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}