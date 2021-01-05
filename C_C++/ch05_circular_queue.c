#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void init_queue(QueueType *q) {
    // front와 rear의 위치가 같을 때
    q->front = q->rear = 0;
}

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

int is_full(QueueType *q) {
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력
void queue_print(QueueType *q) {
    printf("Queue(front=%d rear=%d = ", q->front, q->rear);

    if (!is_empty(q)) {
        int i=q->front;

        do {
            i = (i+1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);

            if (i == q->rear)
                break;
        } while (i != q->front);
    }

    printf("\n");
}

// 삽입
void enqueue(QueueType *q, element item) {
    if (is_full(q)) {
        error("큐 포화 상태 !!");
    }

    q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// 삭제
element dequeue(QueueType *q) {
    if (is_empty(q)) {
        error("큐 공백 상태 !!");
    }

    q->front = (q->front+1)%MAX_QUEUE_SIZE;

    return q->data[q->front];
}

// 삭제(peek)
element peek(QueueType *q) {
    if (is_empty(q))
        error("큐 공백 상태 !!");
    
    return q->data[(q->front+1)%MAX_QUEUE_SIZE];
}

int main() {
    QueueType queue;
    int element;

    init_queue(&queue);
    printf("--데이터 추가--");

    while (!is_full(&queue)) {
        printf("정수 입력 : ");
        scanf("%d", &element);
        enqueue(&queue, element);
        queue_print(&queue);
    }

    printf("큐 포화 상태 !!\n\n");

    printf("--데이터 삭제--");

    while (!is_empty(&queue)){
        element = dequeue(&queue);
        printf("꺼내진 정수 : %d \n", element);
        queue_print(&queue);
    }

    printf("큐 공백 상태 !!\n");
}