#include <stdio.h>

void calculate_stats(int arr[], int size, int *min, int *max, float *avg) {
    if (size <= 0) return;
    *min = arr[0];
    *max = arr[0];
    int sum = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
        sum += arr[i];
    }
    *avg = (float)sum / size;
}

int main() {
    int numbers[] = {15, 8, 23, 42, 4, 16};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int min, max;
    float avg;
    
    calculate_stats(numbers, size, &min, &max, &avg);
    
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\nMinimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Average: %.2f\n", avg);
    
    return 0;
}
