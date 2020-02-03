#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getResult(FILE *filed);

struct fileStructure
{
    char fileName;
    char actions;
    char dataContain[];
};

int main()
{
    struct fileStructure inf[20];
    char rfileName[100];
    
    printf("\nEnter file name: ");
    scanf("%s", &rfileName);
    //printf("test %s" , &fileName);
    FILE *fileOpen = fopen(rfileName, "r");
    // printf("\nhere");
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
    printf("%s", inf[0].actions);
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
        strcpy(info[count].actions, token); // for first instruction
        printf(token);
        token = strtok(NULL, ",");

        if (&info[count].actions == "read")
        {
            strcpy(&info[count].dataContain[0], token);
        }
        else
        {
            strcpy(&info[count].fileName, token);

            int dataNo = 0;
            token = strtok(NULL, ",");
            while (token != NULL)
            {
                strcpy(&info[count].dataContain[dataNo], token);
                token = strtok(NULL, ",");
                //  strcpy(&info[count].dataContain[dataNo], token);
                dataNo++;
            }
        }
        count++;
    }
    printf("%s" , info[count].actions);
}