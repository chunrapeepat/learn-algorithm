#include <iostream>
#include <vector>

using namespace std;

// 1. preprocess all weight of characters
// 2. check to first line of input is A > B or B > A
// 3. loop 2 sections: store the input and calculate sum
// 4. answer (if "Not" draw)

int calcSum(int n, int total) {
    if (n == 0) return total;
    int gms = 250;
    if (n & 1) gms += 250;
    return calcSum(n >> 1, total + gms);
}

int main() {
    int T; cin >> T;
    int testcase = 0;

    // preprocess sum
    vector<int> sums('Z' + 1, 0);
    for (int i = 'A'; i <= 'Z'; ++i) {
        sums[i] = calcSum(i, 0);
    }

    while (T--) {
        // get input
        vector<string> picture;
        for (int i = 0; i < 7; ++i) {
            string str; cin >> str;
            picture.push_back(str);
        }
        string divider; cin >> divider;

        // check given result
        int heavier = 0;
        for (int i = 0; i < 18; ++i) {
            if (picture[0][i] == '/') {
                if (i <= 7) heavier = 1;
                else heavier = -1;
                break;
            }
        }

        // calculate sum
        string left = "";
        string right = "";
        int sum_left = 0;
        int sum_right = 0;
        int i_left = 4;
        int i_right = 4;
        if (heavier == -1) {
            i_left = 5;
            i_right = 3;
        } else if (heavier == 1) {
            i_left = 3;
            i_right = 5;
        }
        for (int j = 1; j <= 6; ++j) {
            if (picture[i_left][j] >= 'A' && picture[i_left][j] <= 'Z') {
                left += picture[i_left][j];
                sum_left += sums[picture[i_left][j]];
            }
        }
        for (int j = 11; j <= 16; ++j) {
            if (picture[i_right][j] >= 'A' && picture[i_right][j] <= 'Z') {
                right += picture[i_right][j];
                sum_right += sums[picture[i_right][j]];
            }
        }

        // fill padding
        int ln = left.length();
        int rn = right.length();
        for (int i = 0; i < 6 - ln; ++i) {
            left += ".";
        }
        for (int i = 0; i < 6 - rn; ++i) {
            right += ".";
        }

        // answer
        int diff = sum_right - sum_left;
        if (diff < 0) diff = -1;
        else if (diff > 0) diff = 1;

        printf("Case %d:\n", ++testcase);
        if (diff == heavier) {
            cout << "The figure is correct." << endl;
        } else {
            if (diff == 0) {
                printf("........||........\n.../\\...||.../\\...\n../..\\..||../..\\..\n./....\\.||./....\\.\n/%s\\||/%s\\\n\\______/||\\______/\n........||........\n", left.c_str(), right.c_str());
            } else if (diff == 1) {
                printf(".../\\...||........\n../..\\..||........\n./....\\.||.../\\...\n/%s\\||../..\\..\n\\______/||./....\\.\n........||/%s\\\n........||\\______/\n", left.c_str(), right.c_str());
            } else {
                printf("........||.../\\...\n........||../..\\..\n.../\\...||./....\\.\n../..\\..||/%s\\\n./....\\.||\\______/\n/%s\\||........\n\\______/||........\n", right.c_str(), left.c_str());
            }
        }
    }

    return 0;
}