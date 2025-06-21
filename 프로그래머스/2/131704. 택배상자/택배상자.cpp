#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int> sub;

int solution(vector<int> order) {
    int idx = 0;
    for(int i=1; i<=order.size(); i++){
        if(order[idx] == i) idx++;
        else if(sub.size() && order[idx] == sub.top()){
            sub.pop();
            idx++;
            i--;
        }
        else sub.push(i);
    }
    while(sub.size() && order[idx] == sub.top()){
        sub.pop();
        idx++;
    }
    return idx;
}
/*
오름차순으로 전달됨
임시 보관함 = stack

4 3 1 2 5

1 2 3

4 3
*/