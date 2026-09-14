#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

long long solution(int r1, int r2) {
    ll answer = 0;  

    for (int x = 1; x <= r2; x++) {
        ll high = (ll)r2 * (ll)r2 - (ll)x * (ll)x;
        ll low = (ll)r1 * (ll)r1 - (ll)x * (ll)x;
        
        low = (low < 0) ? 0 : low;
        
        ll cnt = 1 + floor(sqrt(high)) - ceil(sqrt(low));
        // cout << x << ": " << cnt << '\n';
        answer += cnt;
    }

    return answer * 4;
}