// the Twitter class can be directly copied for leetcode solution
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>
using namespace std;

class Twitter {
   // to store who each user is following
    unordered_map<int, unordered_set<int>> followers;
    // to store every tweet made
    stack<pair<int, int>> global;
public:
    Twitter() {;
    }
    
    void postTweet(int userId, int tweetId) {
        // add tweet to global stack
        global.push({userId, tweetId});
        // a user (by default) follows themself since their own tweets show in their feed
        followers[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        // counter to ensure we only get a max of 10 tweets
        int i = 0;
        // return vector
        vector<int> ret;
        // temporary stack used to restore original global stack after popping tweets
        stack<pair<int, int>> temp;
        while (!global.empty() && i < 10) {
            // get next global tweet
            pair<int, int> next = global.top();
            // check if current user is following the user who made this tweet
            if (followers[userId].find(next.first) != followers[userId].end()) {
                ret.push_back(next.second);
                i++;
            }
            global.pop();
            temp.push(next);
        }
        // restore original global stack of tweets for future use
        while (!temp.empty()) {
            pair<int, int> next = temp.top();
            global.push(next);
            temp.pop();
        }
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        // insert followee into follower's list
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // remove followee from follower's list
        followers[followerId].erase(followeeId);
    }
};

int main(){

}