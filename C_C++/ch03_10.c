#include <stdio.h>

/* 코드 실행 시 터미널 한글 깨짐 */

int i;
int items;

int delete(int array[], int loc) {
    for (i=loc; i<items-1; i++) {
        array[i] = array[i+1];
    }
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

    printf("삭제할 원소의 인덱스를 입력하세요. : ");
    scanf("%d", &loc);

    delete(array, loc);

    printf("삭제 후 결과 : ");

    for (i=0; i<items-1; i++) {
        printf("%d ", array[i]);
    }
}