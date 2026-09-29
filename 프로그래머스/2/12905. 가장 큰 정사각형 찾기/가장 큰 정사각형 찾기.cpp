#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int W, H;
int dir[3][2] = {{-1, 0}, {-1, -1}, {0, -1}};
int dp[1000][1000];     // (r, c)를 포함하는 가장 큰 정사각형의 변 길이

int resolve(int row, int col, vector<vector<int>> &board) {
    if (dp[row][col] != -1) 
        return dp[row][col];
    int ret;
    if (board[row][col] == 0) {
        ret = 0;
    }
    else {
        ret = INT_MAX;
        for (int d = 0; d < 3; d++) {
            int newR = row + dir[d][0];
            int newC = col + dir[d][1];
            
            int ref = (newR < 0 || newR >= H || newC < 0 || newC >= W) ? 0 : resolve(newR, newC, board);
            ret = min(ret, ref);
        }
        ret++;
    }
    dp[row][col] = ret;
    return ret;
}

int solution(vector<vector<int>> board)
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int answer = 0;
    
    H = board.size();
    W = board[0].size();
    
    // init dp
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = board[0][0];
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            answer = max(answer, resolve(i, j, board));
        }
    }
    
    return answer * answer;
}

// (row, col)을 포함하는 가장 큰 정사각형의 변 길이
// dp[r][c]
    // board[r][c] = 0이면 : 그냥 0
    // board[r][c] = 1이면 : min(dp[북], dp[북서], dp[서]) + 1
