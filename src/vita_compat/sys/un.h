/* sys/un.h for the PS Vita.
 *
 * There are no Unix-domain sockets on the console. httplib and Boost.Asio include this
 * unconditionally and name sockaddr_un in code this build never runs; the console's
 * <sys/socket.h> is BSD-shaped, so this is the BSD layout to match it.
 */

#pragma once

#include <stdint.h>
#include <sys/socket.h>

#ifndef AF_UNIX
#define AF_UNIX 1
#endif
#ifndef AF_LOCAL
#define AF_LOCAL AF_UNIX
#endif

struct sockaddr_un {
    uint8_t sun_len;
    sa_family_t sun_family;
    char sun_path[104];
};
