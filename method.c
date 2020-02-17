#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getResult(FILE *filed);

struct fileStructure
{
    //  char *fileName;
    char *actions;
    int dataContain[100];
};

int main()
{
    //struct fileStructure info[20];
    char rfileName[100];

    printf("\nEnter file name: ");
    scanf("%s", &rfileName);
    FILE *fileOpen = fopen(rfileName, "r");
    if (!fileOpen)
    {
        printf("\n\nUnable to find the file");
    }
    else
    {
        getResult(fileOpen);
    }

    printf("/noutside");
    fclose(fileOpen);
}

void getResult(FILE *filed)
{
    struct fileStructure info[20];
    int count = 0;
    char *token;
    char temp[100];
    while (fgets(temp, 100, filed))
    {

        token = strtok(temp, ",");
        int dataNo = 0;
        int run = 0;

        while (token != NULL)
        {
            if (run == 0)
            {
                info[count].actions = token;

                run = 1;
                token = strtok(NULL, ",");
            }
            else
            {
                int val = atoi(token);
                info[count].dataContain[dataNo] = val;
                token = strtok(NULL, ",");
                dataNo++;
            }
        }
        count++;
    }

    int elementNo = sizeof(info);
    for (int i = 0; i < 4; i++)
    {
        printf("data is %d\n", info[i].dataContain[1]);
        printf("action is %s\n", info[i].actions);
    }
}