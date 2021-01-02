#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 50

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} stackType;

// 스택 초기화
void init_stack(stackType *s) {
    s->top = -1;
}

int is_empty(stackType *s) {
    return (s->top == -1);
}

int is_full(stackType *s) {
    return (s->top == (MAX_STACK_SIZE)-1);
}

void push(stackType *s, element item) {
    // 스택이 꽉 찬 상태일 때
    if (is_full(s)) {
        fprintf(stderr, "스택 포화!\n");
        return;
    }
    // top을 먼저 옮기고 데이터 삽입
    else s->data[++(s->top)] = item;
}

int pop(stackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백!\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

int main() {
    stackType s;
    init_stack(&s);

    int n, tmp;

    printf("정수 배열의 크기 : ");
    scanf("%d", &n);

    printf("정수 입력 : ");

    for (int i=0; i<n; i++) {
        scanf("%d", &tmp);
        push(&s, tmp);
    }

    printf("반전된 배열 : ");

    for (int j=0; j<n; j++) {
        printf("%d ", pop(&s));
    }
}