#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define ll long long

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int now_pick = n - 1;       // 수거해야 하는 가장 끝 집
    int now_deli = n - 1;       // 배달해야 하는 가장 끝 집
    while (1) {
        int move = 0;           // 가야 하는 거리
        int now_cap = 0;        // 현재 트럭의 남은 공간
        
        // 가는 길에 배달
        while (now_cap < cap) {
            // 배달이 필요한 가장 끝 집
            while (now_deli >= 0 && deliveries[now_deli] == 0) now_deli--;
            if (now_deli == -1) break;
            move = max(move, now_deli + 1);
            int deli = min(cap - now_cap, deliveries[now_deli]);    // 남은 박스, 필요 박스
            deliveries[now_deli] -= deli;
            now_cap += deli;        // 공간 증가
        }
        
        now_cap = cap;  // 필요한 배달만큼만 싣고 갔다고 가정
        
        // 오는 길에 수거
        while (now_cap > 0) {
            // 수거가 필요한 가장 끝 집
            while (now_pick >= 0 && pickups[now_pick] == 0) now_pick--;
            if (now_pick == -1) break;
            move = max(move, now_pick + 1);
            int pick = min(now_cap, pickups[now_pick]);    // 남은 공간, 필요 공간
            pickups[now_pick] -= pick;
            now_cap -= pick;        // 공간 감소
        }
        
        if (move == 0) break;       // 배달도 수거도 끝
        
        answer += 2 * (ll)move;
        
        // cout << move << '\n';
    }
    
    return answer;
}

// 가는 것과 오는 것 따로 봐야 편할 듯
// 가는 길엔 배달만, 오는 길엔 수거만 해도 괜찮음. 가는 길에 지나치는 집 어차피 오는 길에 또 지나침.
// 그리디? 쪼갤 수가 있나?

// 집 1까지 있고 d[1] <= cap, p[q] <= cap이라고 하면 그냥 한번 왔다갔다 끝
// 둘 중 하나라도 > cap이면 그만큼 다시 갔다오면 됨.

// 집 여러개면 배달이든 수거든 멀리부터 하는게 다시 거기까지 안가도 되므로 이득임.
// 끝 집부터 cap 와리가리 쳐가면서 트럭을 채우면 됨.

// 막집에 배달 0개 수거 2개면...?
// 가면서 먼 집의 배달부터 처리. 오면서 먼 집의 수거부터 처리.