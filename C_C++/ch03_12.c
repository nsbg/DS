#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

// typedef를 붙이면 구조체를 새로운 자료형으로 사용 가능
typedef struct ch03_12
{
    int num;
    char str[20];
} test;

int main() {
    test *p;

    // 동적 메모리 할당
    p = (test *)malloc(sizeof(test));

    p->num = 100;

    // 문자열은 왜 바로 할당이 안되고 strcpy 사용?
    strcpy(p->str, "just testing");

    printf("%d\n%s", p->num, p->str);

    free(p);
}
