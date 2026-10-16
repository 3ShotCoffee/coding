#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> stk;
    
    reverse(numbers.begin(), numbers.end());
    
    for (int now : numbers) {
        while (!stk.empty() && now >= stk.top()) stk.pop();
        if (stk.empty()) answer.push_back(-1);
        else answer.push_back(stk.top());
        stk.push(now);
    }
    
    reverse(answer.begin(), answer.end());
    
    
    return answer;
}

// 수가 쪼매 큼
// 뭔가 단조스택? 단조스택이네
// 뒤에서부터 보자.
// top으로 갈수록 감소하는 형태
    // now < top이면 top이 뒷큰수. now 넣기
    // now > top이면 아닐 때까지 stk pop해라.