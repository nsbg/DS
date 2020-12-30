#include <stdio.h>

// 전역 변수 선언
int i;
int items;

void insert(int* arr, int loc, int value) {
    for (i=items; i>loc; i--) {
        arr[i] = arr[i-1];
    }

    arr[loc] = value;
}

int main() {
    int loc, value;
    int array[30];

    printf("배열의 원소 개수를 입력하세요. : ");
    scanf("%d", &items);

    printf("%d개의 숫자를 입력하세요. : ", items);
    
    for (i = 0; i < items; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("삽입 위치와 삽입할 숫자를 입력하세요 : ");
    scanf("%d %d", &loc, &value);

    insert(array, loc, value);
    
    printf("삽입 후 결과 : ");

    for (i=0; i<items+1; i++) {
        printf("%d ", array[i]);
    }
}