#include "post.h"

Post::Post(){

}

Post::Post(string id, string author,string text): id(id), author(author), text(text) {
    upvotes = 0;
    downvotes = 0;
    score = 0;
    no_comments = 0;
    sleep(5);
    struct timeval time_now;
    gettimeofday(&time_now, nullptr);
    timestamp = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000); //get current timestamp in milliseconds
}

void Post::addUpvote() {
    upvotes++;
    computeScore();
}

void Post::addDownvote() {
    downvotes++;
    computeScore();
}

void Post::computeScore() {
    score = upvotes - downvotes;
}

void Post::addComment(Post comment) {
    comments[comment.getTimestamp()] = comment;
    no_comments++;
}

time_t Post::getTimestamp() const {
    return timestamp;
}

string Post::getID() const {
    return id;
}

string Post::getAuthor() const {
    return author;
}

int Post::getScore() const {
     return score;
}

int Post::getCommentsNumber() const {
    return no_comments;
}

void Post::print(int level){
    Utils util;
    cout <<string(level, '\t') << "id :" << id << endl;
    cout <<string(level, '\t') <<  "(" << upvotes << "upvotes" <<  " , " << downvotes << "downvotes" << ")" << endl;
    cout <<string(level, '\t') << author << endl;
    cout <<string(level, '\t') << text <<endl;
    cout << string(level, '\t') <<  timestamp << " " << util.getTimeAgo(timestamp) <<endl;
    for(auto it: comments){
        it.second.print(level+1);
    }
}
