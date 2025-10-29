#include <stdio.h>
#include <stdlib.h>

static void counting_sort(int *arr, size_t n, int min_value, int max_value) {
    if (n == 0 || min_value > max_value) {
        return;
    }

    size_t range = (size_t)(max_value - min_value + 1);
    int *counts = calloc(range, sizeof(int));
    if (!counts) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < n; ++i) {
        counts[arr[i] - min_value]++;
    }

    size_t idx = 0;
    for (size_t i = 0; i < range; ++i) {
        while (counts[i]-- > 0) {
            arr[idx++] = (int)(i + min_value);
        }
    }

    free(counts);
}

static void print_array(const int *arr, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        if (i) {
            putchar(' ');
        }
        printf("%d", arr[i]);
    }
    putchar('\n');
}

int main(void) {
    int data[] = {4, -1, 3, 4, 2, 0, -1, 5, 2, 3};
    size_t n = sizeof(data) / sizeof(data[0]);

    counting_sort(data, n, -1, 5);
    print_array(data, n);

    return 0;
}
