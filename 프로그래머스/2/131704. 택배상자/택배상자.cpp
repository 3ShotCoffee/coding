#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> stk;
    
    int now = 1;
    for (int want : order) {
        while (want > now) {
            stk.push(now);
            now++;
        }
        if (want == now) {
            now++;
            answer++;
        }
        else if (want < now) {
            if (!stk.empty() && stk.top() == want) {
                stk.pop();
                answer++;
            }
            else break;
        }
    }
    
    return answer;
}