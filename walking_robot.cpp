class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        int x = 0, y = 0;
        int d = 0;

        vector<pair<int,int>> dir = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };

        unordered_set<long long> st;
        
        for(auto obs : obstacles){
            long long k = (long long)obs[0]*100000 + obs[1];
            st.insert(k);
        }

        int maxdist = 0;

        for(int cmd : commands){
            
            if(cmd == -1){
                d = (d + 1) % 4;
            }
            else if(cmd == -2){
                d = (d + 3) % 4;
            }
            else{
                for(int s = 0; s < cmd; s++){
                    
                    int NewX = x + dir[d].first;
                    int NewY = y + dir[d].second;

                    long long k = (long long)NewX * 100000 + NewY;

                    if(st.count(k)) break;

                    x = NewX;
                    y = NewY;

                    maxdist = max(maxdist, x*x + y*y);
                }
            }
        }

        return maxdist;
    }
};