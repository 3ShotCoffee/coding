#include <string>
#include <vector>

using namespace std;

// 문자열 형태의 시간을 분으로 환산
int str2min(string str) {
    string hr = str.substr(0, 2);
    string mn = str.substr(3, 2);
    
    return stoi(hr) * 60 + stoi(mn);
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<vector<int>> time_pairs;
    
    // 분으로 환산, 대실 종료 시간에 청소시간 (+10)
    for (vector<string>& time : book_time) {
        time_pairs.push_back({str2min(time[0]), str2min(time[1]) + 10});
    }
    
    for (int i = 0; i < time_pairs.size(); i++) {
        int cnt = 1;
        int check = time_pairs[i][0];   // 체크할 시작 시간
        for (int j = 0; j < time_pairs.size(); j++) {
            if (i == j) continue;
            // 해당 대실의 시작 시간이 다른 대실의 시작과 같거나 크고 끝보다 작을 때 둘이 겹친다고 할 수 있음
            if (check >= time_pairs[j][0] && check < time_pairs[j][1]) cnt++;
        }
        answer = max(answer, cnt);
    }
    
    
    return answer;
}

// 모든 끝나는 시간에 + 10분
// 간단히 생각해서 대실이 3개가 겹치는 시간대가 있으므로 3개가 필요한것임
// 모든 시작 시간을 검색해서 몇개 대실에 포함이 되는지 확인하면 됨

// 시작 시간이 최대 1000개, 선형 검색만 해도 1000. 즉 시간복잡도 널널
