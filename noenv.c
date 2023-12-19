#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int is_valid_hex(char h, char * b) {
    if ('0' <= h && h <= '9') {
        *b = h - '0';
        return 1;
    } else if ('a' <= h && h <= 'f') {
        *b = h - 'a' + 0xa;
        return 1;
    } else if ('A' <= h && h <= 'F') {
        *b = h - 'a' + 0xa;
        return 1;
    }
    return 0;
}

int hex2byte(char hi, char lo, char * byte) {
    char h, l;
    if (is_valid_hex(hi, &h) && is_valid_hex(lo, &l)) {
        *byte = h << 4 | l;
        return 1;
    }
    return 0;
}

char * argvdup(const char * src) {
    if (src == NULL) return NULL;
    size_t len = strlen(src);
    size_t i = 0;
    size_t j = 0;
    char * res = (char *)malloc(sizeof(char) * len);
    while (i < len) {
        if (src[i] == '\\' && src[i + 1] == 'x' && i + 3 < len) {
            char c;
            if (hex2byte(src[i + 2], src[i + 3], &c)) {
                res[j] = c;
                i += 3;
            } else {
                res[j] = src[i];
            }
        } else {
            res[j] = src[i];
        }
        j++;
        i++;
    }
    res[j] = '\0';
    return res;
}

int main(int argc, char *const argv[]) {
    if (argc > 1) {
        char ** my_argv = (char **)malloc(sizeof(char *) * (argc - 1));
        for (int i = 1; i < argc; i++) {
            my_argv[i - 1] = argvdup(argv[i]);
	        printf("[+] copying argv[%d], len=%lu\r\n", i - 1, strlen(my_argv[i - 1]));
        }
        my_argv[argc - 1] = NULL;
        char ** my_envp = (char **)malloc(sizeof(char *));
        my_envp[0] = NULL;
        printf("[+] execute %s\r\n", argv[1]);
        execve(argv[1], my_argv, my_envp);
    }
}
