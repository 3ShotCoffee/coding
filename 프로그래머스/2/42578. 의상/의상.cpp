#include <string>
#include <vector>
#include <set>

using namespace std;

struct cmp {
    bool operator()(const vector<string>& v1, const vector<string>& v2) const {
        return v1[1] < v2[1];
    }
};

int solution(vector<vector<string>> input) {
    multiset<vector<string>, cmp> clothes;
    
    for (vector<string> in : input) clothes.insert(in);
    
    int answer = 1;
    for (auto it = clothes.begin(); it != clothes.end(); ) {
        auto range = clothes.equal_range(*it);
        answer *= (distance(range.first, range.second) + 1);
        it = range.second;
    }
    
    return answer - 1;
}