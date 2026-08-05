#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<set<int>> dp;

int create_NN(int N, int times) {
    int ret = N;
    for (int i = 1; i < times; i++) {
        ret *= 10;
        ret += N;
    }
    return ret;
}

void memo(int N, int times) {
    set<int> ret;
    int nn = create_NN(N, times);
    
    ret.insert(nn);     // nn 넣기
    for (int i = 1; i <= times / 2; i++) {   // dp[i] ? dp[times - i]
        for (int a : dp[i]) {
            for (int b : dp[times - i]) {
                ret.insert(a + b);
                ret.insert(a - b);
                ret.insert(b - a);
                ret.insert(a * b);
                if (b != 0)
                    ret.insert(a / b);
                if (a != 0)
                    ret.insert(b / a);
            }
        }
    }
    dp.push_back(ret);
}

void print_set(set<int>& s) {
    for (int i : s) {
        cout << i << " ";
    }
    cout << '\n';
}

int solution(int N, int number) {
    dp.push_back({0});
    dp.push_back({N});    // 1번 사용해서 만들 수 있는 숫자
    
    if (number == N) {
        return 1;
    }
    
    for (int times = 2; times <= 8; times++) {
        memo(N, times);
        if (dp[times].find(number) != dp[times].end()) {
            return times;
        }
    }
    
    return -1;
}
    
// N을 한 개 써서 만들 수 있는 숫자
// 2 : 55, 5 + 5 (10), 5 - 5 (0), 5 * 5 (25), 5 / 5 (1)
// 3 : 555, (55 ? 5), ((5 ? 5) ? 5), (5 ? (5 ? 5))

// dp[2] ? dp[1]
    
// (5 ? 5) ? (5 ? 5)