#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILESIZE 100
FILE *fp;
struct data{
      char func[6];//to read add, read, delete based on first letter
      int filename;
      int data;
};

int readFile(void);
void main()
{
   
/////////////////////////////////////////////////////////////////
   
   readFile();/*

   int listLength = 1;
   while((num = fgetc(fp))!= EOF){
      if(num =='\n'){
         listLength++;
      }
   }
   struct data *dt;
   if(dt == NULL){
      printf("Error when allocation mem");
      exit(EXIT_FAILURE);
   }
   int i = 0;
   while(fscanf(fp,"%c %d %d",(dt + i)->func,&(dt + i)->filename,&(dt + i)->data)!= EOF){
      i++;
   }
   printf("%c %d %d \n",(dt)->func,(dt)->filename,(dt)->data);*/

   



   
}
int readFile(){

   char file_name[25];
   char buf[10000];
   int i = 0;
   struct data d[10];//basically able to read 10 lines so got 10 different set of data

   printf("Enter name of a file you wish to see\n");
   gets(file_name);

   fp = fopen(file_name, "r"); // read mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");//if file does not exist
      exit(EXIT_FAILURE);
   }

   while(fscanf(fp,"%s %d %d",d[i].func,&d[i].filename,&d[i].data)!=EOF){
      i++;
   }
   for(int a = 0;a<i;a++){
      printf("%s %d %d\n",d[a].func,d[a].filename,d[a].data);
   }
   fclose(fp);

   return 0;
}
