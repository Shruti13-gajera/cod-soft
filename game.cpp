#include <iostream>
using namespace std;

// Function to display the current state of the board
void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---------\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to switch players
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to reset the board for a new game
void resetBoard(char board[3][3]) {
    char initial = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = initial++;
        }
    }
}

// Main function to run the game
int main() {
    char board[3][3];
    resetBoard(board);
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    cout << "Welcome to Tic-Tac-Toe!\n";
    
    while (true) {
        displayBoard(board);
        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        // Check if the input is valid
        if (move < 1 || move > 9) {
            cout << "Invalid move. Please try again.\n";
            continue;
        }

        // Convert move to board coordinates
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        // Check if the cell is already occupied
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already taken. Please try again.\n";
            continue;
        }

        // Update the board
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameWon = true;
        } 
        // Check if the game is a draw
        else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            gameDraw = true;
        }

        if (gameWon || gameDraw) {
            char playAgain;
            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;
            if (playAgain == 'y' || playAgain == 'Y') {
                resetBoard(board);
                currentPlayer = 'X';
                gameWon = false;
                gameDraw = false;
            } else {
                break;
            }
        } else {
            // Switch to the other player
            currentPlayer = switchPlayer(currentPlayer);
        }
    }

    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}