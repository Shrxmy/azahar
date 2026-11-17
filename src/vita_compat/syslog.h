/* syslog.h for the PS Vita.
 *
 * There is no system log. libressl includes this from cryptlib.c and its syslog_r compat, and
 * patches/vita routes its one fatal message to stderr instead; the declarations only have to
 * exist. Nothing is defined: a new caller fails at link time rather than logging into the void.
 */

#pragma once

#include <stdarg.h>

#define LOG_EMERG 0
#define LOG_ALERT 1
#define LOG_CRIT 2
#define LOG_ERR 3
#define LOG_WARNING 4
#define LOG_NOTICE 5
#define LOG_INFO 6
#define LOG_DEBUG 7

#define LOG_KERN (0 << 3)
#define LOG_USER (1 << 3)
#define LOG_DAEMON (3 << 3)
#define LOG_LOCAL0 (16 << 3)
#define LOG_LOCAL1 (17 << 3)
#define LOG_LOCAL2 (18 << 3)

#define LOG_PID 0x01
#define LOG_CONS 0x02
#define LOG_NDELAY 0x08

#ifdef __cplusplus
extern "C" {
#endif

void openlog(const char* ident, int option, int facility);
void closelog(void);
void syslog(int priority, const char* format, ...);
void vsyslog(int priority, const char* format, va_list ap);

#ifdef __cplusplus
}
#endif
