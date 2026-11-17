/* dlfcn.h for the PS Vita.
 *
 * A Vita application cannot load shared objects. Common::DynamicLibrary is compiled on every
 * platform but nothing in this build opens one, so nothing is defined: a new caller fails at
 * link time rather than on the console.
 */

#pragma once

#define RTLD_LAZY 0x1
#define RTLD_NOW 0x2
#define RTLD_GLOBAL 0x100
#define RTLD_LOCAL 0x0

#ifdef __cplusplus
extern "C" {
#endif

void* dlopen(const char* filename, int flags);
void* dlsym(void* handle, const char* symbol);
int dlclose(void* handle);
char* dlerror(void);

#ifdef __cplusplus
}
#endif
