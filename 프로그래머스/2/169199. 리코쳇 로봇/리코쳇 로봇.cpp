#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
    int r, c, t;
}Node;

int W, H;
bool visited[100][100];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};     // 상하좌우

void move_dir(int &row, int &col, int d, vector<string> &board) {
    while (1) {
        int newR = row + dir[d][0];
        int newC = col + dir[d][1];
        if (newR < 0 || newR >= H || newC < 0 || newC >= W) break;
        if (board[newR][newC] == 'D') break;
        row = newR, col = newC;
    }
}

int solution(vector<string> board) {
    int roboR, roboC, goalR, goalC;
    
    H = board.size();
    W = board[0].size();
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            visited[i][j] = false;
        }
    }
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j] == 'R') {
                roboR = i, roboC = j;
            }
            else if (board[i][j] == 'G') {
                goalR = i, goalC = j;
            }
        }
    }
    
    queue<Node> Q;
    Q.push({roboR, roboC, 0});
    visited[roboR][roboC] = true;
    while (!Q.empty()) {
        Node cur = Q.front(); Q.pop();
        
        if (cur.r == goalR && cur.c == goalC)
            return cur.t;
        
        for (int d = 0; d < 4; d++) {
            int newR = cur.r, newC = cur.c;
            move_dir(newR, newC, d, board);        // d 방향으로 쭉 이동
            
            if (visited[newR][newC]) continue;
            Q.push({newR, newC, cur.t + 1});
            visited[newR][newC] = true;
        }
    }
    
    return -1;
}

// 상태 총 개수가 최대 100 * 100
// 상태마다 처리를 최대 400?
// -> 시간복잡도 널널하다