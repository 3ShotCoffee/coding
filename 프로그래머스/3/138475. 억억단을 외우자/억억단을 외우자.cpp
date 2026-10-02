#include <string>
#include <vector>
#include <iostream>

using namespace std;

int yak_cnt[5000001];   // i의 약수의 개수
int maxi[5000001];      // s일때 가장 많이 등장한 수

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    
    // 각 수의 억억단 등장횟수 = 약수의 개수 찾기
    yak_cnt[1] = 1;
    for (int i = 2; i <= e; i++) {
        bool is_primary = true;
        for (int y = 2; y * y <= i; y++) {  // 1 이외 가장 작은 약수
            if (i % y == 0) {
                is_primary = false;
                // 약수로 나눠떨어지지 않을 때까지 나눔
                int orig = i / y; 
                while (orig % y == 0) orig /= y;
                yak_cnt[i] = yak_cnt[i / y] + yak_cnt[orig];
                break;
            }
        }
        if (is_primary) 
            yak_cnt[i] = 2;
    }
    
    // 범위 [s, e]에서 가장 많이 등장한 수 찾기
    int maxcnt = -1;
    int maxnum;
    for (int s = e; s >= 1; s--) {
        if (yak_cnt[s] >= maxcnt) {
            maxcnt = yak_cnt[s];
            maxnum = s;
        }
        maxi[s] = maxnum;
    }
    
    for (int s : starts) {
        answer.push_back(maxi[s]);
    }
    
    return answer;
}

// s <= x <= e인 x 중에서 억억단에서 가장 많이 등장한 수

// s <= i <= e인 i들에 대해서 억억단의 등장횟수를 각자 구해놓으면 참 좋겠다~
// i의 범위는 5,000,000
// 억억단 등장횟수 = 약수개수

// 20 -> 1, 2, 4, 5, 10, 20
// 36 -> 1, 2, 3, 4, 6, 9, 12, 18, 36 (9) (+ 4, 12, 36)
// 18 -> 1, 2, 3, 6, 9, 18 (6)
// 9 -> 1, 3, 9 (3)

// y로 안나눠지면 그게 한번도 반영이 안됐단 얘기니까 *2가 맞음
// y로 나눠지면 9에서 18로 갈 때 추가됐던 친구들만 다시 y곱해서 추가되는것임
    // 즉 y로 안 나눠질때까지 간다...

// 1 -> 1
// 2 -> 1, 2
// 3 -> 1, 3
// 4 -> 1, 2, 4 (+1)
// 5 -> 1, 5
// 6 -> 1, 2, 3, 6 (+2)
// 7
// 8 -> 1, 2, 4, 8 (+1)
// 9
// 10 -> 1, 2, 5, 10 (+2)

// 가장 작은 약수 d -> sqrt(e)까지만 보면 되니까 1000개 수준
// d로 한번 더 나눠지면 + 1
// d로 한번 더 안 나눠지면 + 2