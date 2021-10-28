#include "maindriver.h"
#include<iostream>
#include<algorithm>
using namespace std;


Driver::Driver() {

    actionMap["signup"] = Action::signup;
    actionMap["login"] = Action::login;
    actionMap["post"] = Action::post;
    actionMap["reply"] = Action::reply;
    actionMap["shownewsfeed"] = Action::shownewsfeed;
    actionMap["follow"] = Action::follow;
    actionMap["upvote"] = Action::upvote;
    actionMap["downvote"] = Action::downvote;
    current_postno = 0;
    
}

void Driver::loginUser(string username) {
    if(userMap.find(username) == userMap.end()){
        throw string("Username does not exist!");
    }
    current_username = username;
}

void  Driver::createPost(string text){
    if(current_username.size() == 0){
        throw string("User is not Logged in!");
    }
    string id = generateNextPostID();
    Post post(id,current_username,text);
    if(postMap.find(id) != postMap.end()) throw string("Invalid post id created. It already exists!");
    postMap[id] = post;
}

string Driver::generateNextPostID() {
    current_postno++;
    return "00" + to_string(current_postno);
}

void Driver::signupUser(string username){
    if(userMap.find(username) != userMap.end()){
        throw string("Username already exists!");
    }
    
    User user(username);
    userMap[username] = user;
}

void Driver::callAction(vector<string>tokens) {
   
    Action action = actionMap[tokens[0]]; 
      
    switch ((int)action)
    {
        case (int)Action::signup:
            try{
                if(tokens.size()<2)  throw string("Username cannot be empty!");
                string username = tokens[1];
                signupUser(username);
            }
            catch(string &e){ 
                    cout<<"Error string message:"<< e<< endl;
            }
            catch(exception e){
                cout << e.what() << endl;
            }
            break;
        case (int)Action::login:
            try{
                if(tokens.size()<2)  throw string("Username cannot be empty!");
                string username = tokens[1];
                loginUser(username);
            }catch(string &e){ 
                    cout<<"Error string message:"<< e<< endl;
            }
            catch(exception e){
                cout << e.what() << endl;
            }
            break;
        case (int)Action::post:
            try{
                string message = tokens[1];
                createPost(message);
            }
            catch(string &e){ 
                    cout<<"Error string message:"<< e<< endl;
            }catch(exception e){
                cout << e.what() << endl;
            }
            break;
        case (int)Action::reply:
             try{
                if(current_username.size() == 0){
                    throw string("User is not Logged in!");
                }
                string postid = tokens[1];
                string message = tokens[2];
                string id = generateNextPostID();
                Post post(id,current_username,message);
                postMap[postid].addComment(post);
            }
            catch(string &e){ 
                    cout<<"Error string message:"<< e<< endl;
            }catch(exception e){
                cout << e.what() << endl;
            }
            break;
        case (int)Action::follow:
            try{
                if(tokens.size()<2)  throw string("Username cannot be empty!");
                string username = tokens[1];
                if(userMap.find(username) == userMap.end()){
                    throw string("Username does not exist!");
                }   
                userMap[current_username].addFollowing(username);     
            }catch(exception e){
                cout << e.what() << endl;
            }
            break;
        case (int)Action::upvote:
            try{
                if(tokens.size()<2)  throw string("Post id is necessary to upvote!");
                string postid = tokens[1];
                if(postMap.find(postid) == postMap.end()){
                    throw string("Post does not exist with post id:" + postid);
                } 
           
               postMap[postid].addUpvote();
               
            }catch(exception e){
                cout << e.what() << endl;
            }
            break;
         case (int)Action::downvote:
            try{
                if(tokens.size()<2)  throw string("Post id is necessary to downvote!");
                string postid = tokens[1];
                if(postMap.find(postid) == postMap.end()){
                    throw string("Post does not exist with post id:" + postid);
                } 
                postMap[postid].addDownvote();
               
            }catch(exception e){
                cout << e.what() << endl;
            }
            break;
        case (int)Action::shownewsfeed:
           try{
                unordered_set<string> followingIDs = userMap[current_username].getFollowing();
                vector<Post> posts;
                for(auto it: postMap){
                    posts.push_back(it.second);
                }
                sort(posts.begin(),posts.end(),cmp(followingIDs));
                cout <<"*----SHOW NEWS FEED----*\n\n";
                for(Post post: posts){
                        post.print();               
                }
               
            }catch(exception e){
                cout << e.what() << endl;
            }
            break;
        default:
            break;
    }
}
