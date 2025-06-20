#include <string>
#include <vector>

using namespace std;

int cnt1 = 0, cnt2 = 0;
vector<int> v1(10001);
vector<int> v2(10001);

int solution(vector<int> topping) {
    int answer = 0;
    for(int i=0; i<topping.size(); i++){
        if(!v2[topping[i]]) cnt2++;
        v2[topping[i]]++;
    }
    for(int i=0; i<topping.size(); i++){
        v2[topping[i]]--;
        if(!v2[topping[i]]) cnt2--;
        if(!v1[topping[i]]) cnt1++;
        v1[topping[i]]++;
        if(cnt1 == cnt2) answer++;
    }
    return answer;
}