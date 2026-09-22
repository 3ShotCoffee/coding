#include <string>
#include <vector>

using namespace std;

typedef struct {
    int o_num, x_num;
    bool o_bingo, x_bingo;
} Result;

Result calc_result(vector<string>& board) {
    Result res = {0, 0, false, false};
    for (int i = 0; i < 3; i++) {
        // row bingo
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'O') res.o_bingo = true;
            else if (board[i][0] == 'X') res.x_bingo = true;
        }
        // col bingo
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'O') res.o_bingo = true;
            else if (board[0][i] == 'X') res.x_bingo = true;
        }
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O') res.o_num++;
            if (board[i][j] == 'X') res.x_num++;
        }
    }
    // diagonal bingo
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'O') res.o_bingo = true;
        else if (board[0][0] == 'X') res.x_bingo = true;
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        if (board[2][0] == 'O') res.o_bingo = true;
        else if (board[2][0] == 'X') res.x_bingo = true;
    }
    return res;
}

int solution(vector<string> board) {
    Result res = calc_result(board);
    
    if (res.o_num >= res.x_num + 2) return 0;
    if (res.x_num > res.o_num) return 0;
    if (res.o_bingo && res.x_num >= res.o_num) return 0;
    if (res.x_bingo && res.o_num > res.x_num) return 0;
    
    return 1;
}

// O 선공 :
// O가 X보다 2개 이상 더 많으면 return 0
// X가 O보다 1개 이상 더 많으면 return 0
// O 빙고가 있는데 X가 0 개수와 같거나 많으면 return 0
// X 빙고가 있는데 O가 X 개수보다 1개 이상 더 많으면 return 0