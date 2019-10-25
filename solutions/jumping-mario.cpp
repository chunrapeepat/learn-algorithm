#include <iostream>

using namespace std;

int main() {
    int testcase;
    cin >> testcase;

    for (int t = 1; t <= testcase; ++t) {
        int walls;
        cin >> walls;

        int up = 0;
        int down = 0;

        int first_position;
        cin >> first_position;

        for (int i = 0; i < walls - 1; ++i) {
            int height;
            cin >> height;

            if (first_position > height) down++;
            if (first_position < height) up++;

            first_position = height;
        }

        cout << "Case " << t << ": " << up << " " << down << endl;
    }

    return 0;
}

