#include <string>
#include <vector>

using namespace std;

vector<int> v(10);

int solution(vector<int> numbers) {
    int answer = 0;
    for(int i=0; i<numbers.size(); i++){
        v[numbers[i]] = 1;
    }
    for(int i=0; i<10; i++) if(!v[i]) answer += i;
    return answer;
}