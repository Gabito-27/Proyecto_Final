#include <stdio.h>
#include <string.h>

int compare(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}

int main() {
    char names[10][50];
    int i;

    printf("Ingrese 10 nombres:\n");
    for (i = 0; i < 10; i++) {
        scanf("%s", names[i]);
    }

    ale(names, 10, sizeof(names[0]), compare);

    printf("\nNombres ordenados:\n");
    for (i = 0; i < 10; i++) {
        printf("%s\n", names[i]);
    }
    return 0;
}