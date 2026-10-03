#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// 0 번호 1 요청시간 2 소요시간
struct Cmp {
    bool operator()(const vector<int>& j1, const vector<int>& j2) const {
        if (j1[2] != j2[2]) return j1[2] > j2[2];
        if (j1[1] != j2[1]) return j1[1] > j2[1];
        return j1[0] > j2[0];
    }
};

// 요청시간 순, 요청시간 같으면 소요시간 순으로 소팅
struct CmpReq {
    bool operator()(const vector<int>& j1, const vector<int>& j2) const {
        if (j1[1] != j2[1]) return j1[1] < j2[1];
        return j1[2] < j2[2];
    }
};

priority_queue<vector<int>, vector<vector<int>>, Cmp> PQ;   // 대기큐

int solution(vector<vector<int>> jobs) {
    // 요청시간순으로 소팅되어 있어야 함
    int id = 0;
    vector<vector<int>> tmp;
    for (vector<int>& job : jobs) {
        tmp.push_back({id, job[0], job[1]}); id++;
    }
    sort(tmp.begin(), tmp.end(), CmpReq());
    jobs = tmp;
    
    id = 0;
    int start, end = 0;     // 0번 작업이 0ms에 끝났다고 가정
    int tat = 0;
    while (1) {
        // 작업 중에 요청된 잡들 모두 큐에 들어왔을 것
        // 혹은 요청이 없으면 다음 가장 빠르게 요청된 잡 하나만 큐에 넣기
        while (id < jobs.size() && (PQ.empty() || jobs[id][1] <= end)) {        
            PQ.push(jobs[id++]);
        }
        if (PQ.empty()) break;  // 그러고도 없다면 끝
        // 하나 꺼내서 바로 시작
        vector<int> job = PQ.top(); PQ.pop();
        start = max(job[1], end);       // 시작시간
        end = start + job[2];           // 끝시간
        tat += (end - job[1]);          // 반환시간
        // cout << "id : " << job[0] << " s : " << start << " e : " << end << " t : " << (end - job[1]) << '\n';
    }
    
    return (tat / jobs.size());
}

// 우선순위큐에 순서대로 넣으면 그만