class Solution {
public:
    // hash_map + 数组
    // 运行时间 564ms
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        // <key: company, value: 每个公司出现在名单的索引>
        unordered_map<string, vector<int>> companyListIndex;
        for (int i = 0; i < favoriteCompanies.size(); ++i) {
            for (auto &cpn: favoriteCompanies[i]) {
                companyListIndex[cpn].push_back(i);
            }
        }

        vector<int> res;
        for (int i = 0; i < favoriteCompanies.size(); ++i) {
            bool isSubset = false;
            // 数组 [名单的索引] = 名单出现的次数
            int listIndexNumber[100] = {0};
            for (auto &cpn: favoriteCompanies[i]) {
                for (auto &index: companyListIndex[cpn]) {
                    if (index != i) listIndexNumber[index]++;
                    if (listIndexNumber[index] == favoriteCompanies[i].size()) {
                        isSubset = true;
                        break;
                    }
                }
            }
            if (!isSubset) res.push_back(i);
        }
        return res;
    }
};


/*
class Solution {
public:
    // 双hash_map
    // 运行时间 1412ms
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        // <key: company, value: 每个公司出现在名单的索引>
        unordered_map<string, vector<int>> companyListIndex;
        for (int i = 0; i < favoriteCompanies.size(); ++i) {
            for (auto &cpn: favoriteCompanies[i]) {
                companyListIndex[cpn].push_back(i);
            }
        }

        vector<int> res;
        for (int i = 0; i < favoriteCompanies.size(); ++i) {
            bool isSubset = false;
            // <key: 名单的索引, value: 名单出现的次数>
            unordered_map<int, int> listIndexNumber;
            for (auto &cpn: favoriteCompanies[i]) {
                for (auto &index: companyListIndex[cpn]) {
                    if (index != i) listIndexNumber[index]++;
                    if (listIndexNumber[index] == favoriteCompanies[i].size()) {
                        isSubset = true;
                        break;
                    }
                }
            }
            if (!isSubset) res.push_back(i);
        }
        return res;
    }
};
*/