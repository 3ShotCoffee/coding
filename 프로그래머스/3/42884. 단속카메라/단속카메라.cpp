#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

struct Cmp {
    bool operator() (const vector<int>& p1, const vector<int>& p2) const {
        return p1[0] < p2[0];
    }
};

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), Cmp());
    
    // for every car
    int count = 1;
    int start = -30001, end = 30001;
    for (vector<int> car : routes) {
        // 카메라 설치가 가능한 구간을 좁혀나감
        start = max(start, car[0]);
        end = min(end, car[1]);
        
        // 겹치지 않는다 = 이 카메라로 감시가 불가능, 새 카메라 필요
        if (start > end) {
            start = car[0];
            end = car[1];
            count++;
        }
    }
    
    return count;
}

// 300,000,000

// 60,000개의 시간 중에서 포함되는 구간이 많은 시간을 이분탐색?
    // log(60,000)
    // 이거를 최악의 경우 모든 시간 번

// 시작순으로 정렬한 모든 차량에 대해서
// 	해당 차량을 커버하는 카메라가 없으면 해당 차량을 커버하면서 가장 많은 차량을 커버하는 카메라를 구하자!
// 		탐색 가능한 구간을 유지하면서 다음 차량들을 탐색하는데 이때 
// 		시작하는 시간이 더 느리다 -> 시작 업뎃
// 		끝나는 시간이 더 빠르다 -> 끝 업뎃
// 		해당 차량이 포함되지 않는다 -> 패스.