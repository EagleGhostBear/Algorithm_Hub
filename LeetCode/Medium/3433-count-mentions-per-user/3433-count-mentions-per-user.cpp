class Solution {
public:
    void find_idx(vector<int>& member, string s){
        string tmp = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                member.push_back(stoi(tmp.substr(2)));
                tmp = "";
            }
            else tmp += s[i];
        }
        member.push_back(stoi(tmp.substr(2)));
        return;
    }
    struct node{
        string msg, member;
        int time;
    };
    struct compare{
        bool operator()(node left, node right){
            if(left.time < right.time) return true;
            if(left.time > right.time) return false;

            if(left.msg == "OFFLINE" && right.msg == "MESSAGE") return true;
            return false;
        }
    };

    void solve(vector<node>& new_event, vector<vector<string>>& events){
        for(auto event : events){
            new_event.push_back({event[0], event[2], stoi(event[1])});
        }
        sort(new_event.begin(), new_event.end(), compare());
        return;
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<node> new_event;
        solve(new_event, events);
        vector<int> mention(numberOfUsers, 0);
        unordered_map<int, bool> online;
        priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // offline
        for(int i=0; i<numberOfUsers; i++) online[i] = true;

        for(auto event : new_event){
            // offline 복귀자 연산
            while(pq.size() && pq.top().first <= event.time){
                online[pq.top().second] = true;
                pq.pop();
            }

            if(event.msg == "MESSAGE"){
                if(event.member.size() == 3 && event.member == "ALL"){
                    for(int i=0; i<mention.size(); i++) mention[i]++;
                }
                else if(event.member.size() == 4 && event.member == "HERE"){
                    for(auto now : online) mention[now.first]++;
                }
                else{
                    vector<int> member;
                    find_idx(member, event.member);
                    for(auto idx : member) mention[idx]++;
                }
            }
            else if(event.msg == "OFFLINE"){
                int idx = stoi(event.member);
                pq.push({event.time + 60, idx});
                online.erase(idx);
            }
            // for(auto c : online) cout << c.first << " ";
            // cout << "\n";
        }
        return mention;
    }
};
/*
저장해야 하는 상태
멤버는 최대 100
1. 유저들 멘션 횟수(list)
2. 유저들 온, 오프라인 상태(list or map)
3. 오프라인 유저 복귀 시간(priority_queue)
*/