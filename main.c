#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>

#define MaxData 130

int main()
{
  char directory;
  //user input of blocks per size
  printf("Input the Blocks per Directory lesser or equal to 130: ");
  scanf("%c", &directory);
  char direcarray[directory];
  
  char buffer[1024] ;
  char *record,*line;
  int i=0,j=0;
 
 //2d array
  //int mat[MaxData][MaxData];
  
  //normal array
  int mat[MaxData];
  
  FILE *fstream = fopen("test.csv","r");
  if(fstream == NULL)
  {
    printf("\n file opening failed ");
    return -1 ;
  }
  while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL)
  {
   record = strtok(line,";");
    while(record != NULL)
    {
    //printf("record : %s",record) ;   
    mat[i] = atoi(record) ;
    record = strtok(NULL,";");
    }
    ++i ;
   }

   // splitting array not working
   int chunk = round(MaxData / directory);
    for (int i = 0; i < directory; i++) {
    int start = i * chunk;
    int end = start + chunk - 1;
    if (i == directory - 1) 
    {
      end = MaxData - 1;
    }

    for (int i = start; i <= end; i++) 
    {
       printf("%d", mat[i] );
    }
       printf("\n");
    }

  //ending return
   return 0 ;

   
   }
 

 
