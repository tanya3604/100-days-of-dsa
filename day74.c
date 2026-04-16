#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][50];      // input names
    char unique[MAX][50];     // unique candidates
    int count[MAX] = {0};     // vote count

    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    int uniqueCount = 0;

    // Count votes
    for(int i = 0; i < n; i++) {
        int found = -1;

        for(int j = 0; j < uniqueCount; j++) {
            if(strcmp(names[i], unique[j]) == 0) {
                found = j;
                break;
            }
        }

        if(found != -1) {
            count[found]++;
        } else {
            strcpy(unique[uniqueCount], names[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[50];

    for(int i = 0; i < uniqueCount; i++) {
        if(count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
        else if(count[i] == maxVotes) {
            if(strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}