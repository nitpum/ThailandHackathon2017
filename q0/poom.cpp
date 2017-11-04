#include <stdio.h>
#include <string.h>

char line[1000000][300];

struct data {
    int number;
    int id;
    int des;
    char date1[25];
    char data2[25];
}

struct data phone[10000];

int main () {

    int count = 0;
    while(gets(line[count])) {
        printf("test[%d]: %s \n", count, line[count]);
        count++;
    }
    strtok(line[497], ",");

    printf("%s", line[497]);

    return 0;
}

void SpaceSeparate (char *s, char data[][40]) {
    char * word;
    int count = 0;
    word = strtok(s, ",");
    for (int i = 0; i < 5;i++) {
        if (i == 0)
        {

        }
    }
    while (word != NULL) {
        strcpy(data[count++], word);
        word = strtok(NULL, " ");
    }
    data[count][0] = '\0';
}
