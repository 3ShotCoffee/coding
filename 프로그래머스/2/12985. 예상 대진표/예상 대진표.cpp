#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{   
    int newA = a, newB = b;
    int round = 1;
    
    while (1) {
        newA = (newA - 1) / 2 + 1;
        newB = (newB - 1) / 2 + 1;
        if (newA == newB) break;
        round++;
    }
    
    return round;
}

// 공통 부모가 언제 나오는지 확인하면 됨
// 내가 지금 n번째 참가자면 다음 라운드에서 (n - 1) / 2 + 1번이 됨.
// 그렇게 두명을 계에에속 다음 라운드로 진행을 시키는데 이때 같은 번호가 된 라운드 직전 라운드에서 만나는거지
