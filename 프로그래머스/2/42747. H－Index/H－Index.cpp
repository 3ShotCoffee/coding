#include <string>
#include <vector>

using namespace std;

#define MAXH 10000

int solution(vector<int> citations) {
    
    for (int h = 0; h <= MAXH; h++) {
        int cnt = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= h) cnt++;
        }
        if (cnt < h) return h - 1;
    }
    
    return MAXH;
}

// 숫자가 작아서 그냥 뭔가 하나씩 다 체크해보면 될 것 같은 느낌이 듦.
// 