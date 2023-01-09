#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 3, COLS = 3;

// Function prototypes
void drawBoard(const vector<vector<char>>& board);
bool checkWin(const vector<vector<char>>& board, char player);

int main() {
    vector<vector<char>> board(ROWS, vector<char>(COLS, ' '));
    char currentPlayer = 'X';

    while (true) {
        // Draw the board
        drawBoard(board);

        // Get the player's move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row col): ";
        cin >> row >> col;

        // Check for valid input
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Switch players
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    return 0;
}

// Draw the board
void drawBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " " << endl;
        if (i != ROWS - 1) {
            cout << "---+---+---" << endl;
        }
    }
    cout << endl;
}

// Check for a win
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}
