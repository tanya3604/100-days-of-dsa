#include <stdio.h>
#include <stdlib.h>

// Structure for car
struct Car {
    int pos;
    double time;
};

// Comparator (descending position)
int compare(const void *a, const void *b) {
    struct Car *c1 = (struct Car *)a;
    struct Car *c2 = (struct Car *)b;
    return c2->pos - c1->pos;
}

int carFleet(int target, int position[], int speed[], int n) {
    struct Car cars[n];

    // Calculate time for each car
    for(int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Sort by position descending
    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    double lastTime = 0;

    for(int i = 0; i < n; i++) {
        if(cars[i].time > lastTime) {
            fleets++;
            lastTime = cars[i].time;
        }
    }

    return fleets;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    int position[n], speed[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    printf("%d\n", carFleet(target, position, speed, n));
    return 0;
}