class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for(int num : asteroids){
            bool alive = true;

            while(!ans.empty() && ans.back() > 0 && num < 0){
                if(abs(ans.back()) < abs(num)){
                    ans.pop_back();
                }
                else if(abs(ans.back()) == abs(num)){
                    ans.pop_back();
                    alive = false;
                    break;
                }
                else{
                    alive = false;
                    break;
                }
            }

            if(alive) ans.push_back(num);
        }

        return ans;
    }
};