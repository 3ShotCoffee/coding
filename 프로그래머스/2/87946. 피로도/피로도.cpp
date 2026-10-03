#include <string>
#include <vector>

using namespace std;

vector<int> combination;

int count(int k, vector<vector<int>>& dungeons) {
    int cnt = 0;
    for (int i : combination) {
        if (k >= dungeons[i][0]) {
            cnt++;
            k -= dungeons[i][1];
        }
    }
    return cnt;
}

int N;
int answer = 0;
vector<bool> visited;

void comb(int depth, int k, vector<vector<int>>& dungeons) {
    if (depth == N) {
        answer = max(answer, count(k, dungeons));
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        combination.push_back(i);
        comb(depth + 1, k, dungeons);
        visited[i] = false;
        combination.pop_back();
    }
}


int solution(int k, vector<vector<int>> dungeons) {
    N = dungeons.size();
    
    for (int i = 0; i < N; i++) 
        visited.push_back(false);
    
    comb(0, k, dungeons);

    return answer;
}

// "지금 탐험할 수 있는 던전의 집합이 있을 때 그 중 소모 피로도가 가장 적은 던전을 택하는 게 이득" ?
// 각 던전에서 얻을 수 있는 이득은 동일. 굳이 피로도가 많이 소모되는 던전 택할 이유 x

// 100
// (80, 20) (90, 30)
// (40, 20) (90, 30) << 반례

// 최소 필요 피로도 순으로 정렬. 갈 수 있으면 가는 게 맞다?
// (90, 25) (80, 5) (70, 30) << 반례

// ㅋㅋ.. 걍 완탐으로 풀면 되네