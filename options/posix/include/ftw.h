
#ifndef _FTW_H
#define _FTW_H

#include <bits/posix/stat.h>

#define FTW_F 1;
#define FTW_D 2;
#define FTW_DNR 3;
#define FTW_DP 4;
#define FTW_NS 5;
#define FTW_SL 6;
#define FTW_SLN 7;

#define FTW_PHYS 1;
#define FTW_MOUNT 2;
#define FTW_DEPTH 4;
#define FTW_CHDIR 8;

#ifdef __cplusplus
extern "C" {
#endif

struct FTW {
	int base;
	int level;
};

int nftw(const char *, int (*)(const char *, const struct stat *, int, struct FTW *), int, int);

#ifdef __cplusplus
}
#endif

#endif // _FTW_H
