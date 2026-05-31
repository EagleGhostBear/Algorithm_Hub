class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long tot = mass;
        for(int i=0; i<asteroids.size(); i++){
            if(tot < asteroids[i]) return false;
            tot += asteroids[i];
        }
        return true;
    }
};