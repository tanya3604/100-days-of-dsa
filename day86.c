#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int low = 0, high = n;
    int ans = 0;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(mid * mid == n) {
            ans = mid;
            break;
        }
        else if(mid * mid < n) {
            ans = mid;      // store possible answer
            low = mid + 1;  // move right
        }
        else {
            high = mid - 1; // move left
        }
    }

    printf("%d", ans);

    return 0;
}