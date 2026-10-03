#include <string>
#include <vector>

using namespace std;

#define ll long long
#define MAXB 10000000

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for (ll i = begin; i <= end; i++) {
        // 1이면 0 넣기
        if (i == 1) {
            answer.push_back(0);
            continue;
        }
        // 자기 자신을 제외한 가장 큰 약수찾기 (sqrt(j)까지 보자)
        bool prim = true;
        int ans = 1;    // 소수면 1
        for (ll j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                // 약수쌍 (j, i / j) 중에 큰 걸 선택하되 i / j는 10,000,000 이하여야 함.
                ans = max(ans, (int)((i / j <= MAXB) ? (i / j) : j));
            }
        }
        answer.push_back(ans);
    }
    
    return answer;
}

// (본인 제외한) 배수 위치에 설치한다~
// 즉 block[x] = 자기 자신을 제외한 x의 가장 큰 약수. = x / 가장작은 약수
// 약수 구하기는 시간복잡도가 sqrt(N) -> 약 10^4 ~ 10^5 정도?
// 쿼리가 5000개니까 좀 빡빡하지만 가능한 정도임. 일단 가보자