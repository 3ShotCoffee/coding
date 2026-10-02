#include <string>
#include <vector>

using namespace std;

#define ll long long

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (ll n : numbers) {
        ll orig = n;
        ll off = 1;
        bool delay = false;
        while (1) {
            // 현재 digit이 0이면 전에 1이 없으면 여기서 있으면 직전에 +1
            if (n % 2 == 0) {
                if (!delay) answer.push_back(orig + off);
                else answer.push_back(orig + off / 2);
                break;
            }
            else 
                delay = true;
            
            n /= 2;
            off *= 2;
        } 
    }
    
    return answer;
}

// lsb부터 봐야 함
// 현재 비트가 0이면 그걸 1로 바꿔주기만 하면 됨
// 현재 비트가 1이면? 
    // 다음 비트가 0이면 그냥 + 1해주면 됨
    // 다음 비트가 1이면... 일단 건너뛰고 바로 위 케이스가 나올때까지 존버

    // f(1) = 2     0001    0010    2개다름
    // f(3) = 5     0011    0101    2개다름
    // f(7) = 11    0111    1011    2개다름
    // f(15) = 23  01111   10111

// 10^15 = 2^50개 정도, 50개 비트 보면 된다
// 쿼리 10^5여도 충분한 수준