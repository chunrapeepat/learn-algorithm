#include <iostream>

using namespace std;

double eval(string expr) {
    string xxx;
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] != ' ') {
            xxx += expr[i];
        }
    }

    string tok = xxx;
    for (int i = 0; i < tok.length(); i++) {
        if (tok[i] == '+') {
            return eval(tok.substr(0, i)) + eval(tok.substr(i+1, tok.length()-i-1));
        } else if (tok[i] == '-') {
            return eval(tok.substr(0, i)) - eval(tok.substr(i+1, tok.length()-i-1));
        }
    }

    for (int i = 0; i < tok.length(); i++) {
        if (tok[i] == '/') {
            return eval(tok.substr(0, i)) / eval(tok.substr(i+1, tok.length()-i-1));
        } else if (tok[i] == '*') {
            return eval(tok.substr(0, i)) * eval(tok.substr(i+1, tok.length()-i-1));
        }
    }
    return stod(tok.c_str());
}

char conv(int i) {
    if (i == 0) return '*';
    if (i == 1) return '+';
    if (i == 2) return '-';
    return '/';
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool found = false;
        for (int i = 0; i < 4 && !found; ++i) {
            for (int j = 0; j < 4 && !found; ++j) {
                for (int k = 0; k < 4 && !found; ++k) {
                    string expr = "4 ";
                    expr += conv(i);
                    expr += " 4 ";
                    expr += conv(j);
                    expr += " 4 ";
                    expr += conv(k);
                    expr += " 4";
                    if (eval(expr) == n) {
                        cout << expr << " = " << n << endl;
                        found = true;
                        break;
                    }
                }
            }
        }
        if (!found) {
            cout << "no solution" << endl;
        }
    }
    return 0;
}