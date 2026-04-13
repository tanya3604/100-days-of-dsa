#include <stdio.h>
#define EMPTY -1

int table[100];

int main() {
    int m, n;
    char op[10];
    int key;

    scanf("%d", &m);   // table size
    scanf("%d", &n);   // number of operations

    // Initialize table
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        int h = key % m;

        if (op[0] == 'I') {  // INSERT
            int j = 0;
            int index;

            while (j < m) {
                index = (h + j * j) % m;

                if (table[index] == EMPTY) {
                    table[index] = key;
                    break;
                }
                j++;
            }
        } 
        else if (op[0] == 'S') {  // SEARCH
            int j = 0;
            int index;
            int found = 0;

            while (j < m) {
                index = (h + j * j) % m;

                if (table[index] == key) {
                    found = 1;
                    break;
                }
                if (table[index] == EMPTY) {
                    break;
                }
                j++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}