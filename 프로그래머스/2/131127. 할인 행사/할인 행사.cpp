#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define LEN 10

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> possible;
    map<string, int> wants;
    
    // wants
    for (int i = 0; i < want.size(); i++) {
        wants[want[i]] = number[i];
    }
    
    // 첫 10개 아이템
    for (int i = 0; i < LEN; i++) {
        string item = discount[i];
        if (possible.find(item) != possible.end()) {
            possible[item]++;
        }
        else {
            possible[item] = 1;
        }
    }
    
    // 같으면 +1
    if (possible == wants) answer++;
    
    for (int i = 1; i - 1 + LEN < discount.size(); i++) {
        string prev = discount[i - 1];
        string now = discount[i - 1 + LEN];
        possible[prev]--;
        if (possible[prev] == 0) {
            possible.erase(prev);
        }
        if (possible.find(now) != possible.end()) {
            possible[now]++;
        }
        else {
            possible[now] = 1;
        }
        if (possible == wants) answer++;
    }
    
    return answer;
}

// 단순히 생각해서 그냥 각 discount 날짜마다 want를 대조하면 됨
// 엥 근데 이게 시간초과가 아니네?
// 이전에 있던 걸 쉽게 빼고 쉽게 넣으려면 map을 쓰는 게 좋겠당