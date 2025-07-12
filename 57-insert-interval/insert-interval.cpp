class Solution {
public:
    static vector<int> addinter(vector<vector<int>>& inter, vector<int>& newinter, int &i)
    {
        int low = min(inter[i][0], newinter[0]);
        int high = max(inter[i][1], newinter[1]);
        while (i < inter.size() && high >= inter[i][0])
        {
            high = max(high, inter[i][1]);
            i++;
        }
        return {low, high};
    }

    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newinter)
    {
        int i = 0;
        vector<vector<int>> ans;
        bool inserted = false;
        while (i < inter.size()) 
        {
            // If new interval is before current and hasn't been added
            if (!inserted && newinter[1] < inter[i][0])
            {
                ans.push_back(newinter);
                inserted = true;
            }
            // If intervals overlap
            if (!inserted && newinter[0] <= inter[i][1])
            {
                ans.push_back(addinter(inter, newinter, i));
                inserted = true;
            }
            else if (i < inter.size())
            {
                ans.push_back(inter[i]);
                i++;
            }
        }

        if (!inserted)
            ans.push_back(newinter);
        return ans;
    }
};
