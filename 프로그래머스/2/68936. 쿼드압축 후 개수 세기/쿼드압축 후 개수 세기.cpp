#include <string>
#include <vector>

using namespace std;

#define pii pair<int, int>

bool unary(int row, int col, int len, vector<vector<int>> &arr) {
    int base = arr[row][col];
    for (int i = row; i < row + len; i++) {
        for (int j = col; j < col + len; j++) {
            if (arr[i][j] != base) return false;
        }
    }
    return true;
}

// 0과 1의 개수
pii divide(int row, int col, int len, vector<vector<int>> &arr) {
    if (unary(row, col, len, arr)) {
        if (arr[row][col] == 1) return {0, 1};
        else return {1, 0};
    }
    pii ret = {0, 0};
    int half = len / 2;
    
    ret.first += divide(row, col, half, arr).first; 
    ret.second += divide(row, col, half, arr).second;
    ret.first += divide(row + half, col, half, arr).first; 
    ret.second += divide(row + half, col, half, arr).second; 
    ret.first += divide(row, col + half, half, arr).first;
    ret.second += divide(row, col + half, half, arr).second;
    ret.first += divide(row + half, col + half, half, arr).first;
    ret.second += divide(row + half, col + half, half, arr).second;
    
    return ret;
}


vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    pii ret = divide(0, 0, arr.size(), arr);
    
    answer.push_back(ret.first);
    answer.push_back(ret.second);
    
    return answer;
}

// len을 2배씩 해서 확인