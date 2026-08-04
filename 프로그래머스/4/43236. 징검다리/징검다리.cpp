#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// num보다 작은 거리의 바위를 모두 제거했을 때
// 제거해야 하는 바위의 개수가 n보다 크면 false
bool possible(vector<int> dist, int num, int n) {
    int elim = 0;
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] < num) {
            if (i != dist.size() - 1) {
                dist[i + 1] += dist[i];
            }
            elim++;
        }
    }
    if (elim > n) return false;
    return true;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 0;
    int right = 1000000000;
    
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    
    vector<int> rocks_dist;
    for (int i = 0; i < rocks.size(); i++) {
        int d = (i == 0) ? rocks[i] : rocks[i] - rocks[i - 1];
        rocks_dist.push_back(d);
    }
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (possible(rocks_dist, mid, n)) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return answer;
}


// 2, 11, 14, 17, 21 (25)
// 2, 9, 3, 3, 4, 4
// 거리가 최소인 바위를 제거하면 되잖아?


// 거리의 최소값을 parametric search?
// 모든 바위 간 거리가 ans보다 큼 + 그중에서 가장 큰 ans
// O(log(dist))

// ans보다 작은 거리의 바위는 모두 제거
