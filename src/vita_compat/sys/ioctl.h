/* sys/ioctl.h for the PS Vita.
 *
 * The console's newlib has no ioctl. Boost.Asio and libressl's BIO sockets include this for
 * FIONBIO and FIONREAD on sockets; neither socket path is reached by this build, so nothing is
 * defined: a new caller fails at link time rather than on the console.
 */

#pragma once

#ifndef FIONBIO
#define FIONBIO 0x8004667e
#endif
#ifndef FIONREAD
#define FIONREAD 0x4004667f
#endif

#ifdef __cplusplus
extern "C" {
#endif

int ioctl(int fd, unsigned long request, ...);

#ifdef __cplusplus
}
#endif
