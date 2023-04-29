#ifndef UTIL_WIN32_H
#define UTIL_WIN32_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* 修改中文 Windows cmd.exe 编码 */
void Util_fixCmdEncoding() {
#ifdef _WIN32
    char buff[BUFFER_SIZE];
    char *res = malloc(1);
    // memset(res, 0, 1);
    FILE *fp = popen("chcp", "r");
    int i = 0;
    while (fgets(buff, BUFFER_SIZE, fp) != NULL) {
        i ++;
        res = realloc(res, i * BUFFER_SIZE);
        // strncat(res, buff, BUFFER_SIZE);
        strncpy(res+(i-1)*BUFFER_SIZE, buff, BUFFER_SIZE);
    }
    printf("%s\n", res);
    if (strstr(res, "65001") == NULL) {
        system("chcp 65001 > NUL");
    }
    pclose(fp);
    free(res);
#endif
}

#endif