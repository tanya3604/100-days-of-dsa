#include <stdio.h>
#include <stdlib.h>

// Comparator for start time
int cmpStart(const void *a, const void *b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

// Comparator for end time
int cmpEnd(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int minRooms(int intervals[][2], int n) {
    int start[n], end[n];

    // Separate start and end times
    for(int i = 0; i < n; i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    // Sort both arrays
    qsort(start, n, sizeof(int), cmpEnd);
    qsort(end, n, sizeof(int), cmpEnd);

    int i = 0, j = 0;
    int rooms = 0, maxRooms = 0;

    while(i < n && j < n) {
        if(start[i] < end[j]) {
            rooms++;      // need new room
            if(rooms > maxRooms)
                maxRooms = rooms;
            i++;
        } else {
            rooms--;      // free a room
            j++;
        }
    }

    return maxRooms;
}

int main() {
    int n;
    scanf("%d", &n);

    int intervals[n][2];

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    printf("%d\n", minRooms(intervals, n));
    return 0;
}