#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int answer = 0;
unordered_map<string, int> sale;
unordered_map<string, int> my;

bool is_chk(){
    for(auto data : sale){
        if(my[data.first] != data.second) return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    for(int i=0; i<want.size(); i++) my[want[i]] = number[i];
    for(int i=0; i<10; i++) sale[discount[i]]++;
    if(is_chk()) answer++;
    for(int i=0; i + 10 <discount.size(); i++){
        sale[discount[i]]--;
        sale[discount[i + 10]]++;
        if(is_chk()) answer++;
    }
    return answer;
}