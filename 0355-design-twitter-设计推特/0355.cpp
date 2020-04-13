const int recentNum = 10;

// 推特推文
struct Tweet {
    int id = 0;
    int time = 0;
    Tweet(int _id, int _time): id(_id), time(_time) {}
    
    bool operator>(const Tweet &r) {
        return this->time > r.time;
    }
    
    bool operator<(const Tweet &r) {
        return this->time < r.time;
    }
};

// 用户
struct User {
    vector<Tweet> tweets;       // tweetId, time
    set<int> follow;
};

// 推特
class Twitter {
    int time = 0;
    unordered_map<int, User> users;

    void searchTweet(list<Tweet> &lst, const int &userId) {
        // lst: time由小到大递增
        const auto &tweets = users[userId].tweets;
        for (int i = tweets.size() - 1; i >= 0; --i) {
            // 判断当前推特时间是否过旧, 若过旧即停止搜索该人推特
            if (lst.size() > recentNum && tweets[i].time < lst.front().time) {
                break;
            }
            // 时间符合, 搜索插入位置
            auto p = lst.begin();
            while (p != lst.end()) {
                if ((*p).time > tweets[i].time) break;
                p++;
            }
            lst.insert(p, 1, tweets[i]);
            // 判断是否超出长度
            if (lst.size() > recentNum) {
                lst.pop_front();
            }
        } 
    }
public:
    /** Initialize your data structure here. */
    Twitter() {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        users[userId].tweets.push_back(Tweet(tweetId, time++));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        list<Tweet> lst;
        vector<int> rtn;
        // 搜索已关注的人 的推特
        bool isFollowSelf = false;
        for (auto &followeeId: users[userId].follow) {
            if (followeeId == userId) isFollowSelf = true;
            searchTweet(lst, followeeId);   
        }
        // 搜索自己 的推特
        if (!isFollowSelf) {
            searchTweet(lst, userId);
        }
        // 整理返回结果
        for(auto p = lst.rbegin(); p != lst.rend(); ++p) {
            rtn.push_back((*p).id);
        }
        return rtn;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        users[followerId].follow.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        users[followerId].follow.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */