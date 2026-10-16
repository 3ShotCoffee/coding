#include <string>
#include <vector>

using namespace std;

#define ll long long

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    int end = queue1.size();
    
    int pt1 = 0, pt2 = 0;
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < end; i++) {
        sum1 += (ll)queue1[i];
        sum2 += (ll)queue2[i];
    }
    
    // 둘 다 원래 길이를 넘었으면 보는 의미가 없음
    while (pt1 < end || pt2 < end) {    
        if (sum1 == sum2) {
            return pt1 + pt2;
        }
        else if (sum1 < sum2) {
            if (pt2 > end + pt1 - 1) break;
            int num = queue2[pt2++];
            queue1.push_back(num);
            sum2 -= (ll)num;
            sum1 += (ll)num;
        }
        else if (sum1 > sum2) {
            if (pt1 > end + pt2 - 1) break;
            int num = queue1[pt1++];
            queue2.push_back(num);
            sum1 -= (ll)num;
            sum2 += (ll)num;
        }
    }
    
    return answer;
}

// 뺐으면 넣어야 함...
// 큐에서 빼고 큐로 넣는 것이기 때문에 중간에 하나만 취사선택같은 것 없이 그냥 어디서 자를지만 선택이 가능
// 컷을 기준으로 앞은 줄 것 뒤는 남길 것
// "앞"의 합한 개수가 작업의 횟수가 됨

// 문제는 O(N^2)이 시간초과라는 것.
// 투포인터로 하면 해결되지 않을까?