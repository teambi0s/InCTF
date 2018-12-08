
typedef unsigned long size_t;
typedef unsigned long long ssize_t;

int write(int fd, const char* buf, int len);
void exit(int status);
ssize_t reader(int fd, void *buf, size_t count);
int strncmp(const char *s1, const char *s2, size_t n);
int strcmp(const char *s1, const char *s2);


int puts(const char* s);
size_t strlen(const char* s);
ssize_t read(int fd, void *buf, size_t count);
