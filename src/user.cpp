#include "user.h"

User::User() {
}

User::User(string username): username(username) {
}

void User::addFollowing(string username) {
    followings.insert(username);
}

void User::addPost(string postid) {
    postids.insert(postid);
}

unordered_set<string>User::getFollowing() {
    return followings;
}

unordered_set<string> User::getPosts() {
    return postids;
}

