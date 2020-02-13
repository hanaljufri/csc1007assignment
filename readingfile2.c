#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getfilesize(char *fname)
{
    FILE *fp = fopen(fname, "r");
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fclose(fp);
    return size;
}
 
// reads csv file into a local buffer
// tokenize string at comma or new line, 
// convert text data to integer and write it into 2D buffer
#define COL 6
void read2darray(char *fname, int (*array)[COL], int rows)
{
  // allocate memory buffer for file read 
  // and read csv file into buffer
  int size = getfilesize(fname);
  char *buf = malloc(size +1);
 
  FILE *fp = fopen(fname, "r");
  fread(buf, size, 1, fp);
  fclose(fp) ;
  
  //tokenize at comma or new line
  char *tok = strtok(buf, ",\n");
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<COL;j++)
    {
      if(tok == NULL)
      {
        break;
      }
      // convert text numeral to integer
      int val = atoi(tok);
      array[i][j] = val;
      //printf("%d ", val);
 
      // tokenize at comma or newline
      tok = strtok(NULL, ",\n");
    }
    
  }
  free(buf);
}