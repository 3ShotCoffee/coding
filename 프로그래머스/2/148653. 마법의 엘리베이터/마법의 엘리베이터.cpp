#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(int storey) {
    int answer = 0;

    while (1) {
        int now = storey % 10;
        int nxt = (storey % 100) / 10;
        if (now > 5 || (now == 5 && nxt >= 5)) {     // 윗층으로 움직이기
            storey += (10 - now);
            answer += (10 - now);
        }
        else {              // 아랫층으로 움직이기
            storey -= now;
            answer += now;
        }
        if (storey == 0) break;
        storey /= 10;
    }

    return answer;
}