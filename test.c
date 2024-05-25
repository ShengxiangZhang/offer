#include<stdio.h>

int main(){
    char* buf[2];
    buf[0] = "aa";
    buf[1] = "ab";
    printf("%s", buf);
    return 0;
}