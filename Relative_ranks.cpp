class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> answer(n);

        for (int i = 0; i < n; i++) {
            int rank = 1;

            // Count how many scores are greater
            for (int j = 0; j < n; j++) {
                if (score[j] > score[i]) {
                    rank++;
                }
            }

            if (rank == 1)
                answer[i] = "Gold Medal";
            else if (rank == 2)
                answer[i] = "Silver Medal";
            else if (rank == 3)
                answer[i] = "Bronze Medal";
            else
                answer[i] = to_string(rank);
        }

        return answer;
    }
};