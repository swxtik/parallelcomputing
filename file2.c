//Write an omp program to transform each element with a[i]=3*a[i]+2 using #pragma omp parallel for schedule (dynamic,2) then switch to (static,2)
#include <stdio.h>
#include <omp.h>

#define N 10

int main() {
    int a[N];
    
    // Initialize array
    for (int i = 0; i < N; i++) {
        a[i] = i;
    }

    printf("Original array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // First transformation using dynamic scheduling
    #pragma omp parallel for schedule(dynamic,2)
    for (int i = 0; i < N; i++) {
        a[i] = 3 * a[i] + 2;
    }

    printf("\nAfter transformation with schedule(dynamic,2):\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Second transformation using static scheduling
    #pragma omp parallel for schedule(static,2)
    for (int i = 0; i < N; i++) {
        a[i] = 3 * a[i] + 2;
    }

    printf("\nAfter transformation with schedule(static,2):\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}