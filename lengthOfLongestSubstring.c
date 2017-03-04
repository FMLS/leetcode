#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int* lengthOfLongestSubstring(char* s) {
    int primes[] = {2,  3,  5,  7,  11,  13, 17, 19, 23, 29,
                  31, 37, 41, 43, 47,  53, 59, 61, 67, 71,
                  73, 79, 83, 89, 97, 101};
    int len = strlen(s);
    int i = 0, j = 0;
    int num = 1;
    int now_length = 0;
    int longest = 0;
    int flag = 0;
    int *result = (int*)malloc(sizeof(int) * 2);

    for(i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            int index = s[j] % 26;
            if (num % primes[index] == 0) {
                num = 1;
                if (now_length > longest) {
                    longest = now_length;
                    flag = j - 1;    
                }
                now_length = 0;
                break;
            }
            //不重复字符计算的数值;
            num *= primes[index];

            //现在不重复字母的长度
            now_length = j - i + 1;
        } 
    }
    result[0] = flag;
    result[1] = longest;
    return result;
}

int main(void) {
    char a[] = "aaaaabcdee";
    int *res = lengthOfLongestSubstring(a);
    int i = 0;
    printf("%d", res[1]);
    for (i = res[0]; i < res[0] + res[1]; i++) {
        printf("%c", a[i]);
    }
    return 0;
}