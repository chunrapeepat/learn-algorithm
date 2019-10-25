#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    while (true) {
        int participants, budget, hotels, weeks;
//        cin >> participants >> budget >> hotels >> weeks;
        if (scanf("%d %d %d %d", &participants, &budget, &hotels, &weeks) != 4) break;
//        cout << "DEBUG: " << participants << " " << budget << " " << hotels << " " << weeks << endl;

        int total_cost = 999999999;

        for (int h = 0; h < hotels; ++h) {
            int cost;
            cin >> cost;

            bool is_available_room = false;

            for (int w = 0; w < weeks; ++w) {
                int a;
                cin >> a;

                if (is_available_room) continue;

                if (a >= participants) {
                    is_available_room = true;
                }
            }

            if (is_available_room && cost * participants <= budget) {
                int temp = cost * participants;
                if (temp < total_cost) {
                    total_cost = temp;
                }
            }
        }

        if (total_cost == 999999999) {
            cout << "stay home" << endl;
        } else {
            cout << total_cost << endl;
        }
    }
}