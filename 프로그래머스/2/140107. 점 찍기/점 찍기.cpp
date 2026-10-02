#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for (int i = 0; i <= d; i += k) {
        long long maxJ2 = (long long)d * d - (long long)i * i;
        answer += (long long)(floor(sqrtl(maxJ2)) / k + 1);
        //cout << i << " " << answer << '\n';
    }
    
    return answer;
}