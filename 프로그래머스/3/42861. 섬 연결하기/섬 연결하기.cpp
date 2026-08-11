#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> edges;

struct Cmp {
    bool operator()(vector<int> &a, vector<int> &b) const {
        return a[2] < b[2];    
    }
};

queue<int> Q;
bool visited[100];
bool is_connected(int n, int from, int to) {
    // init 
    for (int i = 0; i < n; i++) visited[i] = false;
    while(!Q.empty()) Q.pop();
    
    Q.push(from);
    visited[from] = true;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        
        // 도달이 가능
        if (cur == to) return true;
        
        for (int nxt : edges[cur]) {
            if (visited[nxt]) continue;
            Q.push(nxt);
            visited[nxt] = true;
        }
    }
    // 도달이 불가능
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0, edge_cnt = 0;
    
    sort(costs.begin(), costs.end(), Cmp());
    
    edges.resize(n);
    
    for (vector<int> road : costs) {
        if (edge_cnt == n - 1) break;
        if (is_connected(n, road[0], road[1])) 
            continue;                   
        
        // connect edge
        edges[road[0]].push_back(road[1]);
        edges[road[1]].push_back(road[0]);
      
        answer += road[2];
        edge_cnt++;
    }
    
    return answer;
}