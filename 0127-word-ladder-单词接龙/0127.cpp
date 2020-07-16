// 双向BFS 使用queue 128ms
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, unordered_set<string>> dict;
        bool isEndWordInDict = false;
        for (auto &word: wordList) {
            if (word == endWord) isEndWordInDict = true;
            for (int i = 0; i < word.size(); ++i) {
                string s = word;
                s[i] = '*';
                dict[s].insert(word);
            }
        }
        if (!isEndWordInDict) return 0;
        
        queue<string> begWords({beginWord}), endWords({endWord});
        unordered_set<string> begVisited;
        unordered_set<string> endVisited;
        begVisited.insert(beginWord);
        endVisited.insert(endWord);
        int count = 1;
        while(!begWords.empty() && !endWords.empty()) {
            count++;
            if (begWords.size() > endWords.size()) {
                swap(begWords, endWords);
                swap(begVisited, endVisited);
            }
            for (int k = begWords.size(); k > 0; --k) {
                string cur = begWords.front();
                begWords.pop();
                begVisited.insert(cur);
                for (int i = 0; i < cur.size(); ++i) {
                    string t = cur;
                    t[i] = '*';
                    if (dict.count(t)) {
                        for (auto it = dict[t].begin(); it != dict[t].end(); ++it) {
                            if (!begVisited.count(*it)) {
                                begVisited.insert(*it);
                                if (endVisited.count(*it)) {
                                    return count;    
                                } else {
                                    begWords.push(*it);
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};



// 双向BFS 212 ms
class Solution {
    unordered_map<string, unordered_set<string>> dict;
    unordered_set<string> begWords;
    unordered_set<string> endWords;
    unordered_set<string> begVisited;
    unordered_set<string> endVisited;
    unordered_set<string> next;
    int count = 1;

    bool bfs(unordered_set<string>& src, unordered_set<string>& dst, unordered_set<string>& visited) {
            count++;
            while(!src.empty()) {
                auto it = src.begin();
                string s = *it;
                visited.insert(s);
                // cout << s << endl;
                for (int i = 0; i < s.size(); ++i) {
                    string t = s;
                    t[i] = '*';
                    if (dict.count(t)) {
                        for (auto it = dict[t].begin(); it != dict[t].end(); ++it) {
                            if (!visited.count(*it)) {
                                // cout << "!" << *it << endl;
                                visited.insert(*it);
                                if (dst.count(*it)) {
                                    return true;    
                                } else {
                                    next.insert(*it);
                                }
                            }
                        }
                    } 
                }
                src.erase(it);
            }
            src = next;
            next.clear();
            return false;
        }


public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isEndWordInDict = false;
        for (auto &word: wordList) {
            if (word == endWord) isEndWordInDict = true;
            for (int i = 0; i < word.size(); ++i) {
                string s = word;
                s[i] = '*';
                dict[s].insert(word);
            }
        }
        if (!isEndWordInDict) return 0;
        
        begWords = {beginWord};
        endWords = {endWord};
        bool flag = true;
        while(!begWords.empty() && !endWords.empty()) {
            if (flag) {
                if (bfs(begWords, endWords, begVisited)) return count;
            }
            else {
                if (bfs(endWords, begWords, endVisited)) return count;
            }
            flag = !flag;
        }
        return 0;
    }
};


// 单向BFS 268 ms
// hashset优化
// 单向BFS
class Solution {
    unordered_map<string, unordered_set<string>> dict;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isEndWordInDict = false;
        for (auto &word: wordList) {
            if (word == endWord) isEndWordInDict = true;
            for (int i = 0; i < word.size(); ++i) {
                string s = word;
                s[i] = '*';
                dict[s].insert(word);
            }
        }
        if (!isEndWordInDict) return 0;
        
        unordered_set<string> visited;
        unordered_set<string> begWords = {beginWord};
        unordered_set<string> endWords = {endWord};
        unordered_set<string> nextBeg;
        unordered_set<string> nextEnd;
        int count = 1;
        while(!begWords.empty() && !endWords.empty()) {
            count++;
            while(!begWords.empty()) {
                auto it = begWords.begin();
                string s = *it;
                visited.insert(s);
                for (int i = 0; i < s.size(); ++i) {
                    string t = s;
                    t[i] = '*';
                    if (dict.count(t)) {
                        for (auto it = dict[t].begin(); it != dict[t].end(); ++it) {
                            if (!visited.count(*it)) {
                                visited.insert(*it);
                                if (endWords.count(*it)) {
                                    return count;    
                                } else {
                                    nextBeg.insert(*it);
                                }
                            }
                        }
                    } 
                }
                begWords.erase(it);
            }
            begWords = nextBeg;
            nextBeg.clear();
        }
        
        return 0;
    }
};

/*
// 单向BFS 超时, 通过33/43
class Solution {
    inline bool transform(string &src, string &dst) {
        int count = 0;
        for (int i = 0; i < src.size(); ++i) {
            count += src[i] != dst[i] ? 1 : 0;
            if (count > 1) break;
        }
        // cout << src << ":" << dst << " res:" << int(count == 1) << endl;
        return count == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> us;
        for (auto &word: wordList) {
            us.insert(word);
        }
        if (!us.count(endWord)) return 0;
        
        vector<string> words = {endWord};
        vector<string> nextWords;
        int count = 1, res = INT_MAX;
        us.clear();
        while(!words.empty()) {
            // for (auto &word: words) cout << word << ","; cout << endl;
            count++;
            for (auto &curWord: words) {
                if (transform(curWord, beginWord)) res = min(res, count);
                for (auto &dstWord: wordList) {
                    if (!us.count(dstWord) && transform(curWord, dstWord)) {
                        us.insert(dstWord);
                        nextWords.push_back(dstWord);
                    }
                }
            }
            words = nextWords;
            nextWords.clear();
        }
        
        return res == INT_MAX ? 0 : res;
    }
};
*/