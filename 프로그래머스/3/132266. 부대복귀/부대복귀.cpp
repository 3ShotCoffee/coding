#include <string>
#include <vector>
#include <queue>

using namespace std;

#define pii pair<int, int>

vector<vector<int>> edges;

queue<pii> Q;    // (location, time)
bool visited[100001];
int shortest_return(int n, int source, int dest) {
    // init visited
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    // clear Q
    while (!Q.empty()) { 
        Q.pop(); 
    }
    
    Q.push({source, 0});
    visited[source] = true;
    while (!Q.empty()) {
        pii cur = Q.front(); Q.pop();
        
        // 도착
        if (cur.first == dest) {
            return cur.second;
        }
        
        // 다음으로 갈 수 있는 곳 탐색
        for (int nxt : edges[cur.first]) {
            if (visited[nxt]) continue;
            Q.push({nxt, cur.second + 1});
            visited[nxt] = true;
        }
    }
    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    // 서로 갈 수 있다.
    edges.resize(n + 1);
    for (vector<int> road : roads) {
        edges[road[0]].push_back(road[1]);
        edges[road[1]].push_back(road[0]);
    }
    
    for (int s : sources) {
        int time = shortest_return(n, s, destination); 
        answer.push_back(time);
    }
    
    return answer;
}