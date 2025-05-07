class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        vector<int> count(26, 0);
        for (char c : letters)
        {
            count[c - 'a']++;
        }
        return backtrack(words, score, count, 0);
    }

    int backtrack(vector<string>& words, vector<int>& score, vector<int>& count, int index)
    {
        if (index == words.size()) return 0;
        // Option 1: skip this word
        int maxScore = backtrack(words, score, count, index + 1);

        // Option 2: try to include this word if possible
        vector<int> tempCount = count;
        string word = words[index];
        bool canUse = true;
        int wordScore = 0;

        for (char c : word) {
            if (--tempCount[c - 'a'] < 0) {
                canUse = false;
                break;
            }
            wordScore += score[c - 'a'];
        }

        if (canUse) {
            maxScore = max(maxScore, wordScore + backtrack(words, score, tempCount, index + 1));
        }
        return maxScore;
    }
};
