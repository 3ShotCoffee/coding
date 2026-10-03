#include <iostream>
#include <vector>
using namespace std;

int on[200000001];

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int start = 1, end, len;
    for (int i = 0; i < stations.size(); i++) {
        end = stations[i] - w - 1;  // 다음 기지국 시작 범위 직전이 끝
        len = (end - start + 1);
        if (len > 0) {     // 전파가 닿지 않는 아파트가 있다면 기지국 설치
            answer += (len - 1) / (2 * w + 1) + 1;
        }
        start = stations[i] + w + 1;    // 이번 기지국 끝 범위 직후가 시작
    }
    // 끝에 마지막 기지국으로도 전파가 닿지 않는 곳이 있는 경우
    len = (n - start + 1);
    if (len > 0) {     // 전파가 닿지 않는 아파트가 있다면 기지국 설치
        answer += (len - 1) / (2 * w + 1) + 1;
    }
    
    return answer;
}

// O(NlogN)도 애매한 수준....
// 일단은 O(N)은 할 수 밖에는 없고 

// 연속으로 켜져 있지 않은 아파트의 개수 x를 덮기 위해서
// (x - 1) / (2 * W + 1) + 1개의 기지국이 필요

// 1, 2, 3 -> 1
// 4, 5, 6 -> 2

// 켜져 있지 않은 아파트는 s + W + 1에서 시작, s' - W - 1에서 끝.