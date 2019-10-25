#include <iostream>

#define LSB(i) ((i) & (-i))

using namespace std;

int find(int* tree, int index) {
	int sum = 0;

	while (index > 0) {
		sum += tree[index];
		index -= LSB(index);
	}

	return sum;
}

int main() {
	int case_number = 1;

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	while (true) {
		int n_potentio;
		cin >> n_potentio;

		if (n_potentio == 0) {
			return 0;
		}

		n_potentio += 1;

		int fenwick_tree[n_potentio]; fenwick_tree[0] = 0;
		int f[n_potentio]; f[0] = 0;
		int cf[n_potentio]; cf[0] = 0;

		for (int i = 1; i < n_potentio; ++i) {
			int ohm;
			cin >> ohm;

			f[i] = ohm;
			cf[i] = ohm + cf[i - 1];

			fenwick_tree[i] = cf[i] - cf[i - LSB(i)];
		}

		cout << "Case " << case_number++ << ":" << endl;

//		for (int i = 1; i < n_potentio; ++i) {
//			cout << "[DEBUG] Index: " << i << " Value: " << fenwick_tree[i] << endl;
//		}

		while (true) {
			string END = "END";
			string MEASURE = "M";
			string SUBSTITUDE = "S";

			string command;
			cin >> command;

			if (command.compare(END) == 0) {
				cout << endl;
				break;
			}

			int param1;
			int param2;
			cin >> param1 >> param2;

			if (command.compare(MEASURE) == 0) {
				int result = find(fenwick_tree, param2) - find(fenwick_tree, param1 - 1);
				cout << result << endl;
			}
			if (command.compare(SUBSTITUDE) == 0) {
				int index = param1;
				int value = param2;

				int diff = value - f[index];

//				cout << "[DEBUG] Index: " << index << " Diff: " << diff << endl;

				while (index < n_potentio) {
					fenwick_tree[index]	+= diff;
					index += LSB(index);
				}
			}
		}
	}

	return 0;
}
