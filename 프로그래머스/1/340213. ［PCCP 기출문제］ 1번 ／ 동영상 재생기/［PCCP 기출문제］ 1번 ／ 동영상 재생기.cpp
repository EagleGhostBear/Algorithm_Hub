#include <string>
#include <vector>
#include <iostream>

using namespace std;

int to_sec(string data){
    int m = stoi(data.substr(0, 2));
    int s = stoi(data.substr(3, 2));
    return m * 60 + s;
}

string fit_string(string s){
    string tmp = "";
    if(s.size() < 2) tmp += "0";
    return tmp + s;
}

string to_time(int sec){
    string m = fit_string(to_string(sec / 60));
    string s = fit_string(to_string(sec % 60));
    return m + ":" + s;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    
    int runtime = to_sec(video_len);
    int now = to_sec(pos);
    int op_s = to_sec(op_start);
    int op_e = to_sec(op_end);
    
    for(int i=0; i<commands.size(); i++){
        string command = commands[i];
        if(op_s <= now && now <= op_e) now = op_e;
        
        if(command == "prev"){
            if(now < 10) now = 0;
            else now -= 10;
        }
        else{
            if(now + 10 > runtime) now = runtime;
            else now += 10;
        }
        
        if(op_s <= now && now <= op_e) now = op_e;
    }
    
    return to_time(now);
}
/*
동영상 재생기
1. 10초전
2. 10초후
3. 오프닝 건너뛰기

3600 + 60
*/