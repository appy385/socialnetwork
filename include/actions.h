#ifndef ACTIONS_H
#define ACTIONS_H

#include<string>
using namespace std;

class Actions{
public:
    virtual void signupUser(string username) = 0;
    virtual void loginUser(string username) = 0;
    virtual void createPost(string text) = 0;
};

#endif // ACTIONS_H