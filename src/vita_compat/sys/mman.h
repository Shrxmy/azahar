/* sys/mman.h for the PS Vita.
 *
 * The console's newlib has no mmap. Boost.Iostreams' mapped_file and httplib's file server
 * include this unconditionally; neither is reached by this build, so nothing is defined: a new
 * caller fails at link time rather than misbehaving on the console.
 */

#pragma once

#include <stddef.h>
#include <sys/types.h>

#define PROT_NONE 0x0
#define PROT_READ 0x1
#define PROT_WRITE 0x2
#define PROT_EXEC 0x4

#define MAP_SHARED 0x01
#define MAP_PRIVATE 0x02
#define MAP_FIXED 0x10
#define MAP_ANONYMOUS 0x20
#define MAP_ANON MAP_ANONYMOUS

#define MAP_FAILED ((void*)-1)

#define MS_ASYNC 0x1
#define MS_INVALIDATE 0x2
#define MS_SYNC 0x4

#ifdef __cplusplus
extern "C" {
#endif

void* mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset);
int munmap(void* addr, size_t length);
int msync(void* addr, size_t length, int flags);

#ifdef __cplusplus
}
#endif
