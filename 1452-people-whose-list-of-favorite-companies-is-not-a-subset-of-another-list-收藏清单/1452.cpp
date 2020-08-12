/*
搜索引擎一般会建立倒排索引: 记录每个关键词在哪个文档中出现。
本题用HashMap记录每个公司在哪些清单中出现, 比如:
假设favoriteCompanies中的第1个清单为[a, b, c]
第一次遍历得知
"a"出现在第1, 2, 4清单
"b"出现在第1, 4, 5清单
"c"出现在第1, 3, 4清单
显而易见, 第1个清单的每个名字, 除了在本清单中都出现了, 也都在第4个清单中出现，那么根据题意(没有重复清单)第1个清单必为第4个清单的子集;

所以第二次遍历统计每个清单中，其他清单下标出现的次数，如果出现次数==该清单的size, 则该清单必为其子集。


我的题解链接：https://leetcode-cn.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/solution/c-hen-hao-li-jie-de-hashmap-tong-ji-gong-si-ming-c/
*/


class Solution {
public:
    // HashMap + 数组 
    // 运行时间532ms
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        // HashMap <key: 公司名, value: 每个公司出现过的清单下标>
        unordered_map<string, vector<int>> companyListIndex;
        for (int i = 0; i < favoriteCompanies.size(); ++i) {
            for (auto &company: favoriteCompanies[i]) {
                companyListIndex[company].push_back(i);
            }
        }

        vector<int> res;
        for (int i = 0; i < favoriteCompanies.size(); ++i) {
            bool isSubset = false;
            // [清单下标] = 对应下标出现的次数
            int number[100] = {0};
            for (auto &company: favoriteCompanies[i]) {
                if (companyListIndex[company].size() == 1) break;
                for (auto &index: companyListIndex[company]) {
                    if (index != i) number[index]++;
                    if (number[index] == favoriteCompanies[i].size()) {
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