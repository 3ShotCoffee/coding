#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int>> edges;
vector<bool> visited;
queue<int> Q;

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    
    edges.resize(n + 1);
    visited.resize(n + 1);
    
    for (vector<int>& edge : wires) {
        edges[edge[0]].push_back(edge[1]);
        edges[edge[1]].push_back(edge[0]);
    }
    
    // 각 엣지를 끊는다고 해보자. 걍... BFS를 하면됨
    for (vector<int>& edge : wires) {
        // init visited
        for (int i = 1; i <= n; i++) {
            visited[i] = false;
        }
        // 1번 정점에서 시작
        Q.push(1);
        visited[1] = true;
        int count = 1;
        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            // 다음으로 갈 수 있는 정점 고르기
            for (int nxt : edges[cur]) {
                if (edge[0] == cur && edge[1] == nxt || edge[0] == nxt && edge[1] == cur) continue;
                if (visited[nxt]) continue;
                Q.push(nxt);
                visited[nxt] = true;
                count++;
            }
        }
        int diff = abs((n - count) - count);
        answer = min(answer, diff);
    }
    
    return answer;
}

// edge 개수가 최대 100개 정도
// 정점 개수도 트리니까 딱 그정도
// 그러면 그냥 다 해보면 되긴함
// 전체 정점 개수 - 1번 정점에서 시작해서 쭉 뻗어서 나온 개수