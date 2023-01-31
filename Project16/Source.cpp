#include<iostream>
#include <stdlib.h>

using namespace std;

char board[3][3];

//lists of the prototypes
void initializeBoard();
void printBoard();
void getChoice(char p);
bool isValid(int r, int c); //give me back whether these are in range of the board
bool isWin();   //this tells me whether someone won the game or not

bool isWin() {

    if (
        ((board[0][0] == 'X') && (board[0][1] == 'X') && (board[0][2] == 'X')) ||
        ((board[1][0] == 'X') && (board[1][1] == 'X') && (board[1][2] == 'X')) ||
        ((board[2][0] == 'X') && (board[2][1] == 'X') && (board[2][2] == 'X')) ||
        ((board[0][0] == 'X') && (board[1][0] == 'X') && (board[2][0] == 'X')) ||
        ((board[0][1] == 'X') && (board[1][1] == 'X') && (board[2][1] == 'X')) ||
        ((board[0][2] == 'X') && (board[1][2] == 'X') && (board[2][2] == 'X')) ||
        ((board[0][0] == 'X') && (board[1][1] == 'X') && (board[2][2] == 'X')) ||
        ((board[0][2] == 'X') && (board[1][1] == 'X') && (board[2][0] == 'X'))
        ) return true;
    else return false;

}
bool isWin1() {

    if (
        ((board[0][0] == 'O') && (board[0][1] == 'O') && (board[0][2] == 'O')) ||
        ((board[1][0] == 'O') && (board[1][1] == 'O') && (board[1][2] == 'O')) ||
        ((board[2][0] == 'O') && (board[2][1] == 'O') && (board[2][2] == 'O')) ||
        ((board[0][0] == 'O') && (board[1][0] == 'O') && (board[2][0] == 'O')) ||
        ((board[0][1] == 'O') && (board[1][1] == 'O') && (board[2][1] == 'O')) ||
        ((board[0][2] == 'O') && (board[1][2] == 'O') && (board[2][2] == 'O')) ||
        ((board[0][0] == 'O') && (board[1][1] == 'O') && (board[2][2] == 'O')) ||
        ((board[0][2] == 'O') && (board[1][1] == 'O') && (board[2][0] == 'O'))
        ) return true;
    else return false;

}

bool isValid(int x) {
    if ((x < 0) || (x > 2))
        return false;
    else return true;

}
bool validplace(int a, int b) {
    if (board[a][b] != 'e') {
        return true;
    }
    else return false;
}

void getChoice(char p) {
    int rowChoice;
    int colChoice;
    
    bool check = true;
        while (check) {
            cout << "Player " << p << " select a row: ";
            cin >> rowChoice;

            while (!isValid(rowChoice)) {
                cout << "Player " << p << " select a VALID row: ";
                cin >> rowChoice;
            }

            cout << "Player " << p << " select a column: ";
            cin >> colChoice;

            while (!isValid(colChoice)) {
                cout << "Player " << p << " select a VALID col: ";
                cin >> colChoice;
            }
            check = ((board[rowChoice][colChoice] == 'X') || (board[rowChoice][colChoice] == 'O'));
                if (check) {
                    cout << "Wrong Input!" << endl;
                    
                }
                else {
                    check = false;
                    board[rowChoice][colChoice] = p;
                }
        }
}

void printBoard() {
    //this is a function to initialize the board to all empty which
    //I designate as the letter e

    cout << "-------------" << endl;
    for (int r = 0; r < 3; r++) {

        cout << "|";

        for (int c = 0; c < 3; c++) {

            cout << " " << board[r][c] << " |";
        } //ending the printout of every column

        cout << endl;
        cout << "-------------" << endl;

    } //ending every row
}




void initializeBoard() {
    //this is a function to initialize the board to all empty which
    //I designate as the letter e

    for (int r = 0; r < 3; r++) {

        for (int c = 0; c < 3; c++) {

            board[r][c] = 'e';
        }
    }
}

int main() {

    initializeBoard();
    printBoard();
    for (int i = 0; i < 9;i++) {
        int a;
        int b;

        if ((i % 2) == 0) { //if i is even, this is player X's turn
            getChoice('X');
            printBoard();
            if (isWin()) {
                cout << "PLAYER X WON !!!" << endl;
                break;
            }
        }
        else { //this is O's turn
            getChoice('O');
            printBoard();
            if (isWin1()) {
                cout << "PLAYER O WON !!!" << endl;
                break;
            }
        }
        i++;
        if (i == 8) {
            cout << "It's a tie!";
        }
    }



    return 0;
}