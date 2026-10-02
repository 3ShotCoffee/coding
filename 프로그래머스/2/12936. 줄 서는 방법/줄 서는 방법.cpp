#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define ll long long

ll fact[21];   // fact[i] = i!

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> numbers;    // 남은 수들 (순서대로)
    
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * (ll)i;
    }
    
    for (int i = 1; i <= n; i++) {
        numbers.push_back(i);
    }
    
    k--;    // 0-index
    
    while (n > 0) {
        ll mod = fact[n - 1];
        int idx = k / mod;
        k = k % mod;
        n--;
        answer.push_back(numbers[idx]);
        numbers.erase(numbers.begin() + idx);
    }
    
    return answer;
}

// 단순 순열. 다 해보고 다 넣어서 ans[k]를 찾는 방법을 생각.
// 20!가... 일단은 10^10만 해도 터진다는 걸 알 수 있음. 즉 다 구할수는 없다