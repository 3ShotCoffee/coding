#include <numeric>
#include <iostream>
using namespace std;

#define ll long long

ll w, h, g;

ll solution(int W, int H) {
    g = (ll)gcd(W, H);          // gcd

    w = (ll)W / g; h = (ll)H / g;   // 최소 블락의 크기 (h, w)
    
    ll answer = (ll)W * H - (w + h - 1) * g;
    
    return answer;
}