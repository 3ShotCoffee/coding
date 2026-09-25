#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

deque<string> cache;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    // 각 도시에 대해서
    for (string city : cities) {
        // 일단 대문자 변환
        transform(city.begin(), city.end(), city.begin(), ::toupper);
        auto it = find(cache.begin(), cache.end(), city);
        if (it != cache.end()) {    // 있으면 (hit) 삭제하고 맨위에다 삽입
            cache.erase(it);
            if (cache.size() + 1 <= cacheSize)
                cache.push_front(city);
            answer = answer + 1;
        }
        else {      // 없으면 (miss) 가장 아래 도시 빼고 현재 도시 맨위에다 삽입
            if (!cache.empty() && cache.size() >= cacheSize)
                cache.pop_back();
            if (cache.size() + 1 <= cacheSize)
                cache.push_front(city);
            answer = answer + 5;
        }
    }
    
    return answer;
}

// LRU -> 
// 도시 이름 찾아서 있으면 빼서 다시 가장 위로 넣음
// 없으면 가장 아래 도시를 빼고 지금 도시 이름을 가장 위로 넣음
// find, 중간 삭제, 끝 삭제, 위 삽입이 필요
// cacheSize <= 30이니까 사실 시간복잡도 크게 중요치 않다

