#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 1. 도난과 여벌이 겹치는 학생을 제외하고 진짜 필요한 학생과 빌려줄 수 있는 학생을 분리
    vector<int> real_lost;
    vector<int> real_reserve;
    
    // 효율성을 위해 정렬
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // lost와 reserve에 모두 있는 학생을 제외하여 새로운 벡터에 추가
    for (int l_student : lost) {
        bool is_self_reserve = false;
        for (int i = 0; i < reserve.size(); ++i) {
            if (l_student == reserve[i]) {
                reserve.erase(reserve.begin() + i);
                is_self_reserve = true;
                break;
            }
        }
        if (!is_self_reserve) {
            real_lost.push_back(l_student);
        }
    }
    
    // 2. 초기 정답 계산 (체육복을 잃어버리지 않은 학생 수 + 스스로 해결한 학생 수)
    int answer = n - real_lost.size();
    
    // 3. 체육복 빌려주기
    for (int l_student : real_lost) {
        bool borrowed = false;
        // 먼저 앞 번호 학생에게 빌려줄 수 있는지 확인 (탐욕 알고리즘)
        for (int i = 0; i < reserve.size(); ++i) {
            if (l_student - 1 == reserve[i]) {
                reserve.erase(reserve.begin() + i);
                answer++;
                borrowed = true;
                break;
            }
        }
        // 앞 번호 학생에게 못 빌렸다면, 뒷 번호 학생에게 빌려줄 수 있는지 확인
        if (!borrowed) {
            for (int i = 0; i < reserve.size(); ++i) {
                if (l_student + 1 == reserve[i]) {
                    reserve.erase(reserve.begin() + i);
                    answer++;
                    break;
                }
            }
        }
    }
    
    return answer;
}