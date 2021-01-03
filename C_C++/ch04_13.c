#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void push(stackType *s, char item) {
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

/*  아이디어 :
    1) 두 개의 스택 생성
    2) 첫번째 스택에 입력한 정수 다 넣기
    3) 첫번째 스택에 있는 정수가 두번째 스택에 없다면 두번째 스택으로 push
    4) 두번째 스택 출력
*/

int main() {
    stackType s1, s2;

    init_stack(&s1);
    init_stack(&s2);

    char input[MAX_STACK_SIZE] = {};

    printf("input integer : ");
    scanf("%s", input);

    for (int i=0; i<strlen(input); i++) {
        if (input[i] != input[i+1]) {
            /*
                char, int 섞여 있을 경우 모든 변수는 int형으로 변환
                -> '0'을 빼주지 않으면 그 문자의 아스키 값이 저장됨 
            */
            push(&s1, input[i]-'0');
        }
    }

    while (!is_empty(&s1)) {
        push(&s2, pop(&s1)); 
    }
    
    printf("result : ");

    while (!is_empty(&s2)) {
        printf("%d", pop(&s2));
    }  
   
}