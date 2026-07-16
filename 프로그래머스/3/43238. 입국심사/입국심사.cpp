#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 모두 심사하는 데 걸리는 시간을 parametric search로 찾기
long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long left = 1;
    long long right = (long long)n * times.back();       // 가장 느린 검사관이 모두 검사
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        
        long long total_people = 0;
        for (int i = 0; i < times.size(); i++) {
            total_people += (mid / times[i]);
        }
        
        if (total_people >= n) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    return answer;
}