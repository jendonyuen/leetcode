class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> res;
        unordered_map<string, int> nameIndex;
        for (auto &name : names) {
            if (nameIndex.find(name) == nameIndex.end()) {
                nameIndex[name] = 1;
                res.push_back(name);
            } else {
                int i = nameIndex[name];
                while(nameIndex.find(name + "(" + to_string(i) + ")") != nameIndex.end()) {
                    i++;
                }
                nameIndex[name] = i + 1;
                string newName = name + "(" + to_string(i) + ")";
                nameIndex[newName] = 1;
                res.push_back(newName);
            }
        }
        return res;
    }
};