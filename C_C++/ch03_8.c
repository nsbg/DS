#include <stdio.h>

// ���� ���� ����
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

    printf("�迭�� ���� ������ �Է��ϼ���. : ");
    scanf("%d", &items);

    printf("%d���� ���ڸ� �Է��ϼ���. : ", items);
    
    for (i = 0; i < items; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("���� ��ġ�� ������ ���ڸ� �Է��ϼ��� : ");
    scanf("%d %d", &loc, &value);

    insert(array, loc, value);
    
    printf("���� �� ��� : ");

    for (i=0; i<items+1; i++) {
        printf("%d ", array[i]);
    }
}