#include <stdio.h>
#include <stdlib.h>

#define MAX 25

int insertheap(int item, int a[], int n) {
    int c = n, p;
    if (c == MAX) {
        printf("Heap is full\n");
        return n;
    }
    c = n + 1; // c is child index
    p = c / 2; // p is parent index
    while (c != 1 && item > a[p]) { // reheapification upward
        a[c] = a[p];
        c = p;
        p = c / 2;
    }
    a[c] = item;
    return n + 1;
}

int main1()
{
    int a[MAX], n = 0, i, item;
    printf("Enter the elements of the heap\n");
    printf("Enter -1 to stop\n");
    scanf("%d", &item);
    while (item != -1) {
        n = insertheap(item, a, n);
        scanf("%d", &item);
    }
    printf("Heap is\n");
    for (i = 1; i <= n; i++)
        printf("%d\n", a[i]);
    return 0;
}

