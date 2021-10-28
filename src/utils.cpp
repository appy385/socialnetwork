#include "utils.h"


string Utils::getTimeAgo(long long timestamp) {
    map<int,string> timeunit;
    timeunit[12 * 30 * 24 * 60 * 60] = "year",
    timeunit[30 * 24 * 60 * 60] =  "month",
    timeunit[24 * 60 * 60] = "day",
    timeunit[60 * 60] = "hour",
    timeunit[60] =  "minute",
    timeunit[1] = "second";
    struct timeval time_now;
    gettimeofday(&time_now, nullptr);
    long long currTimestamp = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000); //get current timestamp in milliseconds
    int time_difference = currTimestamp - timestamp;
    if( time_difference < 1000 ) { return "less than 1 second ago"; }
    for(map<int,string>::iterator it = timeunit.begin();it!=timeunit.end();it++){
        int d = time_difference / it->first;
        if(d>=1000){
            return "about " + to_string(d/1000) + " " + it->second + ((d>1000)?"s ":" ") + "ago";
        }
    }
    return "";
    
}
