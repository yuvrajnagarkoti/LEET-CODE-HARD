#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders)
    {
        set<string> foodItems;
        map<int, map<string, int>> tableData;
        // Step 1: Collect unique food items and populate tableData
        for (auto& order : orders)
        {
            string customer = order[0];
            int table = stoi(order[1]);
            string food = order[2];
            foodItems.insert(food);
            tableData[table][food]++;
        }

        // Step 2: Create header row
        vector<vector<string>> result;
        vector<string> header;
        header.push_back("Table");
        for (const string& food : foodItems)
        {
            header.push_back(food);
        }
        result.push_back(header);

        // Step 3: Fill table rows
        for (const auto& tableEntry : tableData)
        {
            vector<string> row;
            row.push_back(to_string(tableEntry.first));
            for (const string& food : foodItems)
            {
                row.push_back(to_string(tableEntry.second.count(food) ? tableEntry.second.at(food) : 0));
            }
            result.push_back(row);
        }

        return result;
    }
};
