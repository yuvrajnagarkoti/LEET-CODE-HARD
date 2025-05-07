class Solution
{
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        // Count available letters
        vector<int> letterCount(26, 0);
        for (char ch : letters)
        {
            letterCount[ch - 'a']++;
        }

        return backtrack(0, words, letterCount, score);
    }

private:
    int backtrack(int index, vector<string> &words, vector<int> &letterCount, vector<int> &score)
    {
        if (index == words.size())
            return 0;

        // Option 1: skip current word
        int maxScore = backtrack(index + 1, words, letterCount, score);

        // Option 2: include current word if possible
        string &word = words[index];
        vector<int> tempCount(26, 0);
        int wordScore = 0;
        bool canForm = true;

        for (char ch : word)
        {
            int i = ch - 'a';
            tempCount[i]++;
            if (tempCount[i] > letterCount[i])
            {
                canForm = false;
            }
            wordScore += score[i];
        }

        if (canForm)
        {
            // Use up the letters
            for (int i = 0; i < 26; ++i)
            {
                letterCount[i] -= tempCount[i];
            }

            // Recurse
            maxScore = max(maxScore, wordScore + backtrack(index + 1, words, letterCount, score));

            // Backtrack
            for (int i = 0; i < 26; ++i)
            {
                letterCount[i] += tempCount[i];
            }
        }

        return maxScore;
    }
};
