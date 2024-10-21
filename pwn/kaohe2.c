#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void init() {
  setvbuf(stdin, 0LL, 2, 0LL);
  setvbuf(stdout, 0LL, 2, 0LL);
  setvbuf(stderr, 0LL, 2, 0LL);
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int isBlacklisted(char *input) {
    char *blacklist[] = {"ls","cd","cat","echo"};
    int blacklist_size = sizeof(blacklist) / sizeof(blacklist[0]);
    for (int i = 0; i < blacklist_size; i++) {
        if (strstr(input, blacklist[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

int main() {
    init();
    char input[100];
    printf("请输入一个字符串：");
    scanf("%s", input);
	reverseString(input);
	isBlacklisted(input);
	if (isBlacklisted(input)) {
        printf("输入的字符串包含禁止使用的指令。\n");
        exit(0);
    } 
    system(input);
    return 0;
}
