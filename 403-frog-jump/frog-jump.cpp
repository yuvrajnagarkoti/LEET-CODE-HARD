class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> memo;

    bool cando(int i, int k, vector<int>& stones) {
        if (k <= 0)
            return false; // frog can't jump 0 or negative

        if (i == stones.size() - 1)
            return true;

        if (memo[i].count(k))
            return memo[i][k];

        for (int j = i + 1; j < stones.size(); j++) {
            int gap = stones[j] - stones[i];
            if (gap > k + 1)
                break;

            if (gap == k - 1 || gap == k || gap == k + 1) {
                if (cando(j, gap, stones))
                    return memo[i][k] = true;
            }
        }

        return memo[i][k] = false;
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1)
            return false; // First jump must be 1 unit
        return cando(1, 1, stones);
    }
};
