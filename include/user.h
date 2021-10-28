#ifndef __USER_H__
#define __USER_H__

#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class User {
private:
    string username;
    unordered_set<string>postids;
    unordered_set<string>followings;

public:
    User();
    User(string username);
    void addFollowing(string username);
    void addPost(string postid);
    unordered_set<string> getFollowing();
    unordered_set<string> getPosts();
};


#endif // __USER_H__