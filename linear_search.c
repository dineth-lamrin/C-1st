#include <stdio.h>
#include <stdlib.h>

// linear_search(array_pointer, no_of_items, item_we_need_to_find)

int linear_search(int *nums, int n, int needle) {
    for (int i = 0; i < n; i++) {
        if (*(nums+i) == needle)
            return i;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    int numbers[5] = {10, 9, 98, 100, 5};
    char qn[20];
    sprintf(qn, "index of %s :", argv[1]);
    size_t len = sizeof(numbers)/sizeof(numbers[0]);
    int index = linear_search(numbers, len, atoi(argv[1]));

    printf("%s %d\n", qn, index);

    
    return 0;
}
