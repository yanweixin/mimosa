#include <string.h>
#include <time.h>

//char *get_time_str(time_t t);
//
//char *get_now_time_str();

char *get_time_str(time_t t) {
    struct tm *timeinfo = localtime(&t);
    char *time_str = asctime(timeinfo);
    time_str[strlen(time_str) - 1] = '\0';
    return time_str;
}

char *get_now_time_str() {
    return get_time_str(time(NULL));
}
