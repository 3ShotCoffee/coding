#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

vector<int> missiles;

// 먼저 끝나는 미사일 먼저
struct Cmp {
    bool operator() (const vector<int>& v1, const vector<int>& v2) const {
        return v1[1] < v2[1];
    }
};

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    for (int i = 0; i < targets.size(); i++) {
        targets[i][0] = 2 * targets[i][0];
        targets[i][1] = 2 * targets[i][1];
    }
    
    sort(targets.begin(), targets.end(), Cmp());
    
    int latest = -1;
    for (int i = 0; i < targets.size(); i++) {
        // 가장 최근에 쐈던 미사일 x좌표보다 먼저 시작 -> 겹침
        if (targets[i][0] < latest) continue;
        
        // end - 1 좌표에 미사일 쏘기
        latest = targets[i][1] - 1;
        answer++;
    }
    
    return answer;
}