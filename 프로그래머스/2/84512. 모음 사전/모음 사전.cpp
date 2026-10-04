#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<char> letters;
string str = "";
set<string> words;

void dfs(int depth) {
    if (depth == 5) return;
    for (int i = 0; i < 5; i++) {
        str.append(1, letters[i]);
        words.insert(str);
        dfs(depth + 1);
        str.pop_back();
    }
}

int solution(string word) {
    letters = {'A', 'E', 'I', 'O', 'U'};
    
    dfs(0);
    
    auto it = words.find(word);
    
    return (distance(words.begin(), it) + 1);
}

// 6! 정도? 그렇게 크지는 않음.
// set

// 1 A
// 2 AA
// 3 AAA
// 4 AAAA
// 5 AAAAA
// 6 AAAAE
// 7 AAAAI
// 8 AAAAO
// 9 AAAAU
// 0 AAAE