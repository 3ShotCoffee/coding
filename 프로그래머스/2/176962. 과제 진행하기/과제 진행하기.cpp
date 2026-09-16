#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

stack<vector<string>> stk;

struct comp {
    bool operator() (const vector<string>& v1, const vector<string>& v2) const {
        if (v1[1][0] != v2[1][0]) return v1[1][0] < v2[1][0];
        if (v1[1][1] != v2[1][1]) return v1[1][1] < v2[1][1];
        if (v1[1][3] != v2[1][3]) return v1[1][3] < v2[1][3];
        return v1[1][4] < v2[1][4];
    }
};

// 총 분으로 계산
int total_min(string str) {
    int ret = 0;
    ret += stoi(str.substr(0, 2)) * 60;
    ret += stoi(str.substr(3, 2));
    
    return ret;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(), comp());
    
    // 일찍 끝나는 과제순으로 하나씩 집어넣기
    for (vector<string> new_plan : plans) {
        // 첫 과제가 아니라면
        if (!stk.empty()) {
            string new_time = new_plan[1];          // 지금 당장 해야 하는 과제의 시작시간
            vector<string> old_plan = stk.top();    // 아까 시작했던 일
            bool empty = false;
            
            // 아까 시작했던 일이 끝났을까?
            int min_diff = total_min(new_time) - total_min(old_plan[1]);
            while (stoi(old_plan[2]) - min_diff <= 0) {             // 끝났으면 pop
                answer.push_back(old_plan[0]);
                min_diff -= stoi(old_plan[2]);
                stk.pop(); 
                if (stk.empty()) {
                    empty = true;
                    break;
                }
                old_plan = stk.top();
            }
            if (!empty) {
                old_plan[2] = to_string(stoi(old_plan[2]) - min_diff);  // 안 끝났더라도 남은 시간 깎기
                stk.pop(); stk.push(old_plan);
            }
        }
        stk.push(new_plan);
    }
    // 남은 과제들은 순서대로
    while (!stk.empty()) {
        answer.push_back(stk.top()[0]); stk.pop();
    }
    
    return answer;
}

// 과제마다 남은 시간을 업데이트해야함

// 마지막에 넣은 시간
