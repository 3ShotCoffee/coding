#include <string>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <iostream>

using namespace std;

typedef struct {
    int time, temp;
    int acc;            // (i - 1) 시간까지의 소비전력만
} Node;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = INT_MAX;
    int N = onboard.size();
    
    queue<Node> Q;
    map<int, int> accum[1001];
    
    Q.push({0, temperature, 0});
    accum[0][temperature] = 0;
    while (!Q.empty()) {
        Node cur = Q.front(); Q.pop();
        
        // outdated 상태 제거
        if (cur.acc > accum[cur.time][cur.temp]) {
            continue;
        }
        
        // 시간 끝까지 봄
        if (cur.time == N) {
            answer = min(answer, cur.acc);
            continue;
        }
        
        // 온도 유지, 1도 감소, 1도 상승
        int new_time = cur.time + 1;
        int new_temp[3] = {cur.temp, cur.temp - 1, cur.temp + 1};
        int new_acc[3] = {cur.acc + ((temperature == cur.temp) ? 0 : b), cur.acc + ((temperature < cur.temp) ? 0 : a), \
            cur.acc + ((temperature > cur.temp) ? 0 : a)};
        
        for (int i = 0; i < 3; i++) {
            // 온도 범위 제한
            if (new_temp[i] < -10 || new_temp[i] > 40) continue;
            // 만약 다음 시간에 승객이 탑승중인데 온도가 적절치 못하다면 패스
            if (new_time < N && onboard[new_time] == 1 && (new_temp[i] < t1 || new_temp[i] > t2)) continue;
            // 만약 다음 시간에 같은 온도인데 누적전류가 더 나은 상태가 이미 있다면 패스
            if (accum[new_time].find(new_temp[i]) != accum[new_time].end() && accum[new_time][new_temp[i]] <= new_acc[i]) continue;
            
            Q.push({new_time, new_temp[i], new_acc[i]});
            accum[new_time][new_temp[i]] = new_acc[i];
        }
    }
    
    return answer;
}

// 각 시간마다 다음 시간으로 가는 3가지 선택지 
    // 희망온도와 같음 = 지금 온도를 유지    -> 비용 b
    // 희망온도가 낮음 = 온도를 1도 내리기   -> 실외온도 < 현재온도 ? 0 : a
    // 희망온도가 높음 = 온도를 1도 올리기   -> 실외온도 > 현재온도 ? 0 : a

// 상태를 {시간, (승객), 현재온도} = 전력으로 잡으면 여러번 방문할 필요가 없을듯
// bfs?

// 누적전력을 상태에 포함을 해야 bfs로 방문을 한번만 한다 해도 누적 전력이 제대로 계산될듯

// 현재 온도는 직전 시간의 소비 전력을 알려줌

// Q.push({cur.time + 1, cur.temp, cur.acc + b});      // 온도 유지
// Q.push({cur.time + 1, cur.temp - 1, cur.acc + (temperature < cur.temp) ? 0 : b});   // 1도 내리기
// Q.push({cur.time + 1, cur.temp + 1, cur.acc + (temperature > cur.temp) ? 0 : b});   // 1도 올리기