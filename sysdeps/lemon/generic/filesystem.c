#include <lemon/syscall.h>
#include <stddef.h>
#include <lemon/filesystem.h>

int lemon_open(const char* filename, int flags){
    int fd;
    syscall(SYS_OPEN, filename, &fd, 0, 0, 0);
    return fd;
}

void lemon_close(int fd){
    syscall(SYS_CLOSE, fd, 0, 0, 0, 0);
}

int lemon_read(int fd, void* buffer, size_t count){
    int ret;
    syscall(SYS_READ, fd, buffer, count, &ret, 0);
    return ret;
}

int lemon_write(int fd, const void* buffer, size_t count){
    int ret;
    syscall(SYS_WRITE, fd, buffer, count, &ret, 0);
    return ret;
}

off_t lemon_seek(int fd, off_t offset, int whence){
    uint64_t ret;
    syscall(SYS_LSEEK, fd, offset, whence, &ret, 0);
    return ret;
}

int lemon_readdir(int fd, uint64_t count, lemon_dirent_t* dirent){
    uint64_t ret;
    syscall(SYS_READDIR, fd, dirent, count, &ret, 0);
    return ret;
}
