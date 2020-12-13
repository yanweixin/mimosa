#include <stdio.h>
#include "time.h"
#include "log.h"

int _log_error(const char *msg, char const *caller_name) {
    printf("[%s] %s: %s\n", get_now_time_str(), caller_name, msg);
    return 0;
}

int _log_debug(const char *msg, char const *caller_name) {
    printf("[%s] %s: %s\n", get_now_time_str(), caller_name, msg);
    return 0;
}