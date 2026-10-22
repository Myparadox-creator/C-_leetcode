class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {

        int ans = 0;

        for (int i = 0; i < houses.size(); i++) {

            int nearest = INT_MAX;

            for (int j = 0; j < heaters.size(); j++) {

                int distance = abs(houses[i] - heaters[j]);

                nearest = min(nearest, distance);
            }

            ans = max(ans, nearest);
        }

        return ans;
    }
};