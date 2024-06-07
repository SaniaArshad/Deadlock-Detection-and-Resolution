#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for input data
typedef struct input {
    int PID;
    int fileID;
    int secondFileID;
} input;

input in[100];

int main(int argc, char* argv[]) {
    // Open the input file
    FILE *fp = fopen("/home/user/CLionProjects/i202425_R_OSProject/task5p2.txt", "r");
    if (fp == NULL) {
        printf("Error: Failed to open the input file.\n");
        return 1;
    }

    // Read data from the file into the 'in' array
    char buffer[200];
    fgets(buffer, 200, fp);
    int i = 0;
    while (!feof(fp)) {
        input *c = in + i;
        sscanf(buffer, "%d %d %d ", &c->PID, &c->fileID, &c->secondFileID);
        fgets(buffer, 200, fp);
        i++;
    }
    int n = i;

    // Process input data
    int a[200]; // Array to store all file IDs
    int countProcess = 0;
    int countFiles = 0;
    for (i = 0; i < n; i++) {
        countProcess++;
        a[i] = in[i].fileID;
        a[n + i] = in[i].secondFileID;
    }

    // Count the number of unique files
    for (i = 0; i < n * 2; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                break;
            }
        }
        if (i == j) {
            countFiles++;
        }
    }

    // Output the number of processes and files
    printf("Number of processes: %d\n", countProcess);
    printf("Number of unique files: %d\n", countFiles);

    // Calculate minimum execution time
    int minimumExecutionTime = 0;
    int elementCount = 0;
    bool duplicatesFound = false;
    int dups = 0;
    for (int k = 1; k < n; k++) {
        for (int l = 0; l < i; l++) {
            if (a[i] == a[l]) {
                duplicatesFound = true;
                break;
            }
        }
        if (!duplicatesFound) {
            dups++;
        }
    }
    if (duplicatesFound) {
        minimumExecutionTime = 1 + elementCount;
    } else {
        minimumExecutionTime = dups + elementCount;
    }
    printf("Minimum Execution Time: %d\n", minimumExecutionTime);

    // Detect deadlocks and handle them
    bool deadlockDetect = false;
    int firstIndex, lastIndex, location = 0;
    for (int j = 0; j < n; j++) {
        for (int m = 0; m < n; m++) {
            if (in[j].fileID == in[m].secondFileID) {
                firstIndex = j;
                lastIndex = m;
                printf("Deadlock detected\n");
                deadlockDetect = true;
                break;
            }
        }
        break;
    }
    if (deadlockDetect) {
        for (int c = firstIndex; c < lastIndex; c++) {
            if (in[c].PID < in[location].PID) {
                location = c;
            }
        }
        printf("Terminate: %d\n", in[location].PID);
    }
    for (int j = firstIndex + 1; j < n - firstIndex; j++) {
        for (int m = lastIndex + 1; m < n - lastIndex; m++) {
            if (in[j].fileID == in[m].secondFileID) {
                printf("Deadlock detected\n");
                printf("Terminate: %d\n", in[m].PID);
                break;
            }
        }
    }

    // Handle execution time for deadlock resolution
    int executionTime = 0;
    int firstCount = 0;
    int tempArray[20];
    int tempArray2[20];
    if (deadlockDetect) {
        for (int j = 0; j < n; j++) {
            if (in[j].fileID == in[j + 1].secondFileID && in[j].secondFileID == in[j + 1].fileID) {
                printf("%d %d %d\n", executionTime, in[j].fileID, in[j].secondFileID);
                firstCount++;
            }
        }
        int c = 2 * firstCount;
        for (int j = 0; j < c; j++) {
            if (in[j].fileID == in[j + 1].secondFileID && in[j].secondFileID == in[j + 1].fileID) {
                for (int m = j; m < c; ++m) {
                    tempArray[m] = in[j].fileID;
                    tempArray2[m] = in[j].secondFileID;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (in[j].fileID == in[j + 1].secondFileID && in[j].secondFileID == in[j + 1].fileID) {
                for (int m = j; m < n; ++m) {
                    in[m].PID = in[m + 1].PID;
                    in[m].secondFileID = in[m + 1].secondFileID;
                    in[m].fileID = in[m + 1].fileID;
                }
            }
        }
        int secondCount = 0;
        executionTime++;
        for (int j = 0; j < n - firstCount; j++) {
            for (int m = 0; m < c; m++) {
                if ((in[j].fileID == tempArray[m] || in[j].fileID == tempArray2[m] || in[j].secondFileID == tempArray[m] || in[j].secondFileID == tempArray2[m]) && in[j].fileID != in[j + 1].secondFileID) {
                    printf("%d %d %d\n", executionTime, in[j].fileID, in[j].secondFileID);
                    secondCount++;
                    break;
                }
            }
        }
        for (int j = 0; j < n - firstCount; j++) {
            for (int m = 0; m < c; m++) {
                if ((in[j].fileID == tempArray[m] || in[j].fileID == tempArray2[m] || in[j].secondFileID == tempArray[m] || in[j].secondFileID == tempArray2[m]) && in[j].fileID != in[j + 1].secondFileID) {
                    for (int m = j; m < n - firstCount; ++m) {
                        in[m].PID = in[m + 1].PID;
                        in[m].secondFileID=in[m+1].secondFileID;
                        in[m].fileID=in[m+1].fileID;
                    }
                }
            }
        }
        for (int j = 0; j < n-firstCount-secondCount; j++) {
            executionTime++;
            printf("%d %d %d\n",executionTime,in[j].fileID,in[j].secondFileID);

        }

    }

}


