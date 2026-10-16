#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Node {
    int r, c, t;
};

int H, W;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<Node> Q;
vector<vector<bool>> visited;

int bfs(int startR, int startC, int endR, int endC, vector<string> &maps) {
    // init visited & Q
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            visited[i][j] = false;
        }
    }
    while (!Q.empty()) Q.pop();
    
    Q.push({startR, startC, 0});
    visited[startR][startC] = true;
    while (!Q.empty()) {
        Node cur = Q.front(); Q.pop();
        if (cur.r == endR && cur.c == endC) return cur.t;
        
        for (int i = 0; i < 4; i++) {
            int newR = cur.r + dir[i][0];
            int newC = cur.c + dir[i][1];
            
            if (newR < 0 || newR >= H || newC < 0 || newC >= W) continue;   // OOR
            if (maps[newR][newC] == 'X') continue;      // 벽
            if (visited[newR][newC]) continue;          // 방문
            
            Q.push({newR, newC, cur.t + 1});
            visited[newR][newC] = true;
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    H = maps.size();
    W = maps[0].size();
    
    visited.resize(maps.size());
    for (int i = 0; i < maps.size(); i++) {
        visited[i].resize(maps[i].size());
    }
    
    int startR, startC, exitR, exitC, leverR, leverC;
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] == 'S') {
                startR = i; startC = j;
            }
            if (maps[i][j] == 'E') {
                exitR = i; exitC = j;
            }
            if (maps[i][j] == 'L') {
                leverR = i; leverC = j;
            }
        }
    }
    
    int first = bfs(startR, startC, leverR, leverC, maps);
    int second = bfs(leverR, leverC, exitR, exitC, maps);
    
    if (first == -1 || second == -1) return -1;
    else return first + second;
}