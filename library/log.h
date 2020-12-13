#ifndef MIMOSA_LOG_H
#define MIMOSA_LOG_H

#define log_error(msg) _log_error((msg), __func__)

int _log_error(const char *, char const *);

#define log_debug(msg) _log_error((msg), __func__)

int _log_debug(const char *, char const *);

#endif //MIMOSA_LOG_H
