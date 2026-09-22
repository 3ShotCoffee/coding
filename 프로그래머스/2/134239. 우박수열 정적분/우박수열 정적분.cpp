#include <string>
#include <vector>

using namespace std;

int num[201];       // i번째 수
double acc[201];    // [0, i]에 대한 정적분 결과. i<=n

int number(int i) {
    if (num[i - 1] % 2 == 0) {
        num[i] = num[i - 1] / 2;
    }
    else { 
        num[i] = num[i - 1] * 3 + 1;
    }
    return num[i];
}

// [0, i]에 대한 정적분 결과 dp
double accumulate(int i) {
    double ret = acc[i-1] + (double)(num[i-1] + num[i]) / 2.0;
    acc[i] = ret;
    return ret;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    int n = 1;
    
    // fill num
    num[0] = k;     // 0번째 수는 k
    while (1) {
        if (number(n) == 1) break;
        n++;
    }
    
    // init acc
    acc[0] = 0.0;   // [0, 0] 구간 정적분은 0
    for (int i = 1; i <= n; i++) {
        accumulate(i);
    }
    
    for (vector<int> range : ranges) {
        int a = range[0], b = range[1];
        if (b <= 0) b += n;
        if (a > b)
            answer.push_back(-1);
        else
            answer.push_back(acc[b] - acc[a]);
    }
    
    return answer;
}