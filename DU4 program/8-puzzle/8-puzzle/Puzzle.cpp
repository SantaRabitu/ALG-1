#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<list>
#include<chrono>
#include<stack>
#include<random>
#include<unordered_set>




using std::string;
using std::unordered_set;
using std::vector;
using std::swap;
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using Board = std::vector<std::vector<int>>;

const int _ = 0;

void printBoard(const Board& board) {
    for (int k = 0; k < board.size(); k++) {
        for (int l = 0; l < board[k].size(); l++) {
            if (board[k][l] == _) {
                cout << " _ ";
            }
            else {
                cout << " " << board[k][l] << " ";
            }
        }
        cout << endl;
    }
    cout << endl << endl;
}

string boardToString(const Board& board) {
    string result;
    for (const auto& row : board) {
        for (const auto& cell : row) {
            result += std::to_string(cell);
        }
    }
    return result;
}

bool WinningState(const Board& board) {

   static const Board hotovo = { { _,1,2},{3,4,5},{6,7,8 } };
 ///vyherny stav


    return board == hotovo;
}
bool solve(Board& board, unordered_set<string>& visited_states,int depth=0) {

    if (depth > 100) {  
        return false;
    }
    int r0 = -1;
    int s0 = -1;
    vector<pair<int, int>> possibleMoves = {/*hore,0*/{-1, 0},/*dole,0*/{1, 0},/*vlavo*/{0,-1},/*vpravo*/{0,1} };
    bool isEmpty = false;

    string boardStr = boardToString(board);
    if (visited_states.find(boardStr) != visited_states.end()) {
        return false; // Už sme navštívili tento stav
    }
    visited_states.insert(boardStr);

    for (int i = 0; i < board.size() && !isEmpty; i++) {
        for (int j = 0; j < board[i].size() && !isEmpty; j++) {
            if (board[i][j] == _) {
                r0 = i;
                s0 = j;
                isEmpty = true;
            }
        }
    }
    for (const auto& pohyb : possibleMoves) {
        
        int del_r = pohyb.first;
        int del_s = pohyb.second;
        
        int new_r = r0 + del_r;
        int new_s = s0 + del_s;

        if (new_r >= 0 && new_r < board.size() && new_s >= 0 && new_s < board[new_r].size()) {
            swap(board[r0][s0], board[new_r][new_s]);
            
            if (WinningState(board)) {
                cout << "Board after move:" << endl;
                printBoard(board);
                return true;
            }

            if (solve(board, visited_states, depth + 1)) {

                cout << "Board after move:" << endl;
                printBoard(board);
                return true;
            }

          

            swap(board[r0][s0], board[new_r][new_s]);
        }
    }
    return false;
}



int main() {

    unordered_set<string> visited;

    //cout << "zadajte N :" << endl;
    //int N;
    //cin >> N;
    Board board1 = { {1, 3, _}, {4, 8, 5}, {7, 2, 6} };
    Board board2 = { {1, 2, 3}, {4, 5, 6}, {8, 7, _} };
    Board board3 = { {5, 2, 7}, {3, _, 9}, {1, 4, 6} };


    printBoard(board1);
    printBoard(board2);
    printBoard(board3);

    if (solve(board1, visited)) {
        cout << "Board 1: Solvable" << endl;
    }
    else {
        cout << "Board 1: Not solvable" << endl;
    }

    if (solve(board2, visited)) {
        cout << "Board 2: Solvable" << endl;
    }
    else {
        cout << "Board 2: Not solvable" << endl;
    }

    if (solve(board3, visited)) {
        cout << "Board 3: Solvable" << endl;
    }
    else {
        cout << "Board 3: Not solvable" << endl;
    }

 
    return 0;
}

