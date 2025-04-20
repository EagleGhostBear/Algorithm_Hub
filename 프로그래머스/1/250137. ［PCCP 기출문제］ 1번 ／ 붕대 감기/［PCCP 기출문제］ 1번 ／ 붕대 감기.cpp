#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    
    int max_hp = health;
    int casting = bandage[0];
    int heal_sec = bandage[1];
    int heal_plus = bandage[2];
    
    int now = 0;
    for(int i=0; i<attacks.size(); i++){
        int time = attacks[i][0];
        int dmg = attacks[i][1];
        for(int cnt=1; cnt<time - now; cnt++){
            health += heal_sec;
            if(!(cnt % casting)) health += heal_plus;
            if(health > max_hp) health = max_hp;
        }
        health -= dmg;
        now = time;
        if(health < 1) return -1;
    }
    return health;
}