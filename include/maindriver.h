#ifndef MAINDRIVER_H
#define MAINDRIVER_H

#include "user.h"
#include "post.h"
#include "actions.h"
#include "action.h"
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
using namespace std;

class Driver : public Actions{
private:
    string current_username;
    int current_postno;
    unordered_map<string,User> userMap;
    unordered_map<string,Post> postMap;
    unordered_map<string, Action> actionMap;
public:
    Driver();
    void loginUser(string username);
    string generateNextPostID();
    void callAction(vector<string>tokens);
    void signupUser(string username);
    void createPost(string text);

};


#endif // MAINDRIVER_H
