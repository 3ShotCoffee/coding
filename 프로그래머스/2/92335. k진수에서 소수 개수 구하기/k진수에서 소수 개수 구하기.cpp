#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

#define ll long long

using namespace std;

string change_base(int n, int k) {
    string ret = "";
    while (n > 0) {
        ret += to_string(n % k);
        n /= k;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int solution(int n, int k) {
    int answer = 0;
    
    string kbase = change_base(n, k);
    stringstream ss(kbase);
    string token;
    
    //cout << kbase << '\n';
    
    // 0 tokenize
    while (getline(ss, token, '0')) {
        //cout << token << '\n';
        if (token.size() == 0) continue; 
        ll cand = stol(token);
        if (cand == 1) continue;
        bool is_prime = true;
        for (int i = 2; (ll)i * (ll)i <= cand; i++) {
            if (cand % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) answer++;
    }
    
    return answer;
}

// 3진수 변환 스트링 만들기
// 0 파싱
// 소수인지 확인