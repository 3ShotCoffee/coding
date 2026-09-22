#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<bool> visited;

int dfs(int i, int depth, vector<int>& cards) {
    if (visited[i-1]) return depth;
    visited[i-1] = true;
    return dfs(cards[i-1], depth + 1, cards);
}

int solution(vector<int> cards) {
    int N = cards.size();
    
    // init visited
    visited.resize(N);
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    
    vector<int> sizes;
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        int size = dfs(cards[i], 1, cards);
        sizes.push_back(size);
    }
    
    sort(sizes.begin(), sizes.end());
    
    if (sizes.size() >= 2)
        return sizes[sizes.size() - 2] * sizes[sizes.size() - 1];
    else
        return 0;
    
}

// 서로 같은 수를 가리키거나 할 수 없음. 따라서 깔끔한 사이클이 나온다.
// 사이클에 속하는 상자들의 개수.