#include <iostream>

using namespace std;

void display(const int board[][4]);
void moveLeft(int board[][4]);
void moveUp(int board[][4]);
void moveRight(int board[][4]);
void moveDown(int board[][4]);

int main() {
    int board[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> board[i][j];
        }
    }
    int direction;
    cin >> direction;

    switch (direction) {
        case 0: {
            moveLeft(board);
            break;
        }

        case 1: {
            moveUp(board);
            break;
        }

        case 2: {
            moveRight(board);
            break;
        }

        case 3: {
            moveDown(board);
            break;
        }
    }

    display(board);
}

void display(const int board[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void moveLeft(int board[][4]) {
    for (int i = 0; i < 4; i++) {
        int location = -1, counter = 0;
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                counter++;
                if (counter == 1) location = j;
            }
            else if (board[i][j] != 0 && location != -1) {
                board[i][location] = board[i][j];
                board[i][j] = 0;
                location = j;
                counter = 0;
            }
        }
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i][j + 1]) {
                board[i][j] = board[i][j] * 2;
                for (int k = j + 1; k < 3; k++) {
                    board[i][k] = board[i][k + 1];
                }
                board[i][3] = 0;
            }
        }
    }
}

void moveUp(int board[][4]) {
    for (int j = 0; j < 4; j++) {
        int location = -1, counter = 0;
        for (int i = 0; i < 4; i++) {
            if (board[i][j] == 0) {
                counter++;
                if (counter == 1) location = i;
            }
            else if (board[i][j] != 0 && location != -1) {
                board[location][j] = board[i][j];
                board[i][j] = 0;
                location = i;
                counter = 0;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j]) {
                board[i][j] = board[i][j] * 2;
                for (int k = i + 1; k < 3; k++) {
                    board[k][j] = board[k + 1][j];
                }
                board[3][j] = 0;
            }
        }
    }
}

void moveRight(int board[][4]) {
    for (int i = 0; i < 4; i++) {
        int location = -1, counter = 0;
        for (int j = 3; j > -1; j--) {
            if (board[i][j] == 0) {
                counter++;
                if (counter == 1) location = j;
            }
            else if (board[i][j] != 0 && location != -1) {
                board[i][location] = board[i][j];
                board[i][j] = 0;
                location = j;
                counter = 0;
            }
        }
        for (int j = 3; j > 0; j--) {
            if (board[i][j] != 0 && board[i][j] == board[i][j - 1]) {
                board[i][j] = board[i][j] * 2;
                for (int k = j - 1; k > 0; k--) {
                    board[i][k] = board[i][k - 1];
                }
                board[i][0] = 0;
            }
        }
    }
}

void moveDown(int board[][4]) {
    for (int j = 0; j < 4; j++) {
        int location = -1, counter = 0;
        for (int i = 3; i > -1; i--) {
            if (board[i][j] == 0) {
                counter++;
                if (counter == 1) location = i;
            }
            else if (board[i][j] != 0 && location != -1) {
                board[location][j] = board[i][j];
                board[i][j] = 0;
                location = i;
                counter = 0;
            }
        }
        for (int i = 3; i > 0; i--) {
            if (board[i][j] != 0 && board[i][j] == board[i - 1][j]) {
                board[i][j] = board[i][j] * 2;
                for (int k = i - 1; k > 0; k--) {
                    board[k][j] = board[k - 1][j];
                }
                board[0][j] = 0;
            }
        }
    }
}