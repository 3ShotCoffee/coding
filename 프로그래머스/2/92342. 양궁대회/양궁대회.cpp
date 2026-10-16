#include <string>
#include <vector>

using namespace std;

int score_ryan = 0;
int score_apeach = 0;
int max_diff = 0;
vector<int> sol, answer;

// sol이 answer보다 나은 답인지?
bool better_solution() {
    for (int i = answer.size() - 1; i >= 0; i--) {
        if (sol[i] > answer[i]) return true;
        if (sol[i] < answer[i]) return false;
    }
    return false;
}

void dfs(int depth, int arrow, vector<int>& info) {
    if (depth == 10) {
        int diff = score_ryan - score_apeach;
        sol.push_back(arrow);      // 남은 화살 0점에 다 넣기
        if ((diff == max_diff && better_solution()) || diff > max_diff) {
            max_diff = diff;
            answer = sol;
        }
        sol.pop_back();
        return;
    }
    if (info[depth] == 0) {     // 0이면
        // 이기기
        if (arrow - 1 >= 0) {
            score_ryan += 10 - depth;
            sol.push_back(1);
            dfs(depth + 1, arrow - 1, info);
            score_ryan -= 10 - depth;
            sol.pop_back();   
        }
        // 비기기
        sol.push_back(0);
        dfs(depth + 1, arrow, info);
        sol.pop_back();
    }
    else {
        // 이기기
        if (arrow - 1 - info[depth] >= 0) {
            score_ryan += 10 - depth;
            sol.push_back(1 + info[depth]);
            dfs(depth + 1, arrow - 1 - info[depth], info);
            score_ryan -= 10 - depth;
            sol.pop_back();   
        }
        // 지기
        score_apeach += 10 - depth;
        sol.push_back(0);
        dfs(depth + 1, arrow, info);
        score_apeach -= 10 - depth;
        sol.pop_back();
    }
}

vector<int> solution(int n, vector<int> info) {
    dfs(0, n, info);
    
    if (max_diff == 0) return {-1};
    else return answer;
}

// 0인경우 0이 아닌경우

// 10 -> 1까지 각 점수에서
    // 어피치가 x개를 쐈으면 x + 1개를 쏴서 점수를 가져올 수 있음.
    // 어쨌든 해당 점수를 이기기 vs 지기 선택할 수 있다. 근데 10단계니까 그냥 완탐해도 될 것 같음
    // dfs...?