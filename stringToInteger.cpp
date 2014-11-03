#include <iostream>
#include <cstring>
#include <climits>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int atoi(const char *str) {
    //空指针
    if(str == NULL)
        return INT_MIN;
    const char *p = str;
    //忽略空白
    while(*p != '\0' && *p == ' ')
        ++p;
    //判断符号
    int flag = 1;
    if (*p == '-') {
        flag = -1;
        ++p;
    }
    else if(*p == '+')
        ++p;

    int sum = 0;
    while(p != NULL && *p != '\000') {
        int tmp = 0;
        if (*p >= '0' && *p <= '9') {
            tmp = *p - '0';
            ++p;
            if (sum == 0) {
                sum += tmp;
                continue;
            }
            if (sum * flag > INT_MAX / 10)
                return INT_MAX;
            else if (sum * flag < INT_MIN / 10)
                return INT_MIN;
            else if (sum * flag == INT_MAX / 10) {
                if (tmp >= INT_MAX % 10)
                    return INT_MAX;
                else {
                    sum *= 10;
                    sum += tmp;
                }
            }
            else if (sum * flag == INT_MIN / 10) {
                if (tmp >= INT_MIN % 10 * (-1)) {
                    return INT_MIN;
                }
                else {
                    sum *= 10;
                    sum += tmp;
                }
            }
            else {
                sum *= 10;
                sum += tmp;
            }
        }
        else {
            break;
        }
    }
    //if (sum == 0)
     //   return 0;
    //else
    return sum * flag;
}

int atoi2(const char* str) {
    int num = 0;
    int sign = 1;
    const int n = strlen(str);
    int i = 0;

    while (str[i] == ' ' && i < n) ++i;
    if (str[i] == '+') ++i;
    if (str[i] == '-') {
        sign = -1;
        ++i;
    }

    for (; i < n; ++i) {
        if (str[i] < '0' || str[i] > '9')
            break;
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + str[i] - '0';  
    }
    return num * sign;
}

int main() {
    char *str = (char *)malloc(1024);
    memset(str, 0, 1024);
    while(scanf("%s", str)) {
        int i = atoi(str);
        //int i = atoi2(str);
        cout << i << endl;
        memset(str, 0, 1024);
    }
}
