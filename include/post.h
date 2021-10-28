#ifndef __POST_H__
#define __POST_H__

#include<iostream>
#include <utils.h>
#include <chrono>
#include <sys/time.h>
#include<vector>
#include<string>
#include <ctime>
#include <map>
#include <unordered_set>
#include <stdlib.h>
#include<unistd.h>
using namespace std;

class Post {
private:
    string id;
    string author;
    string text;
    int upvotes;
    int downvotes;
    int score;
    int no_comments;
    long long timestamp;
    map<long long ,Post> comments;

public:
    Post();
    Post(string id,string author,string text);
    void addUpvote();
    void addDownvote();
    void computeScore();
    void addComment(Post comment);
    time_t getTimestamp() const ;
    string getID() const;
    string getAuthor() const;
    int getScore() const;
    int getCommentsNumber() const;
    void print(int level = 0);

};

class cmp {
private:
    unordered_set<string> followingIDs;
public:
    cmp(unordered_set<string> followingIDs) : followingIDs(followingIDs) {}

    bool operator()(const Post &p1, const Post &p2) {
        bool follow1 = followingIDs.find(p1.getAuthor())!=followingIDs.end();
        bool follow2 = followingIDs.find(p2.getAuthor())!=followingIDs.end();
        if(!follow1 && !follow2){
            if(p1.getScore() == p2.getScore()){
                if(p1.getCommentsNumber() == p2.getCommentsNumber()){
                    return p1.getTimestamp() >=  p2.getTimestamp();
                }

                return p1.getCommentsNumber()>p2.getCommentsNumber();

            }
            
            return  p1.getScore()>p2.getScore();
            
        }

        return follow1;
    }
};



#endif // __POST_H__