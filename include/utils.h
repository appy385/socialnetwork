#ifndef UTILS_H
#define UTILS_H

#include <ctime>
#include <string>
#include<map>
#include <sys/time.h>
using namespace std;

class Utils{
public:
    string getTimeAgo(long long timestamp); 

};

#endif // UTILS_H