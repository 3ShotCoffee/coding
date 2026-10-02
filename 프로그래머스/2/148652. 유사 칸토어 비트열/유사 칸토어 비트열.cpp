#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MOD 5
#define ll long long

int one_or_zero(int depth, ll idx) {
    if (depth == 0) return 1;
    int parent = one_or_zero(depth - 1, idx / 5);
    if (parent == 1) {  // 내가 1에서 파생됨 : 중간만 0
        if (idx % 5 == 2) return 0;
        else return 1;
    }
    else return 0;
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    // 입력 l, r은 1-index one-or-zero는 0-index
    for (ll i = l - 1; i <= r - 1; i++) {
        if (one_or_zero(n, i)) answer++;
    }
    
    return answer;
}

// k[0] = 1
// k[1] = 11011
// k[2] = 11011.11011.00000.11011.11011
// k[2][3]      3 = 0 * 5 + 3   즉 0번째 블럭의 3번.
// k[2][16].    16 = 3 * 5 + 1  즉 3번째 블럭의 1번.

// k[3] = 11011.11011.00000.11011.11011 (2) + 00000.00000.00000.00000.00000. + 11011.11011.00000.11011.11011 (2)
// dp로 저장을 하는 것보다 (메모리 너무 큼)
// 어차피 부모만 따라 들어가니까 최대 20인 단순 재귀가 낫다