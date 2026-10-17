#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

#define pss pair<string, string>

vector<string> parse_music(string musicstr) {
    vector<string> ret;
    stringstream ss(musicstr);
    string token;
    while (getline(ss, token, ',')) {
        // cout << token << '\n';
        ret.push_back(token);
    }
    return ret;
}

int getmin(string start, string end) {
    int startmin = stoi(start.substr(0, 2)) * 60 + stoi(start.substr(3, 2));
    int endmin = stoi(end.substr(0, 2)) * 60 + stoi(end.substr(3, 2));
    return endmin - startmin;
}

// 필요 분만큼 자르거나 붙이기
string find_melody(vector<string> music) {
    int minute = getmin(music[0], music[1]);
    string ret = music[3];
    
    int song_min = ret.size() - count(ret.begin(), ret.end(), '#');
    int full_min = song_min;
    
    while (full_min < minute) {
        ret.append(music[3]);
        full_min += song_min;
    }
    while (full_min > minute) {
        if (ret.back() == '#') ret.pop_back();
        ret.pop_back();
        full_min--;
    }
    return ret;
}

string solution(string m, vector<string> musicinfos) {
    int max_min = 0;
    string max_name;
    
    for (string musicstr : musicinfos) {
        vector<string> music = parse_music(musicstr);
        int minute = getmin(music[0], music[1]);
        string melody = find_melody(music);
        
        auto it = melody.find(m);
        while (it != string::npos) {
            if (max_min < minute && (it + m.size() >= melody.size() || melody[it + m.size()] != '#')) {
                max_min = minute;
                max_name = music[2];  
                break;
            }
            it = melody.find(m, it + m.size());
        }
    }
    
    if (max_min == 0) return "(None)";
    else return max_name;
}

// 100개면 그냥 찾아도 됨?
