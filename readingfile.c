#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILESIZE 100
FILE *fp;
struct data{
      char func[6];//to read add, read, delete based on first letter
      int filename;
      int data[];
};

int readFile();
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
   int i = 0;
   struct data d[10];//basically able to read 10 lines so got 10 different set of data
   char *token;
   char buff[1024];

   printf("Enter name of a file you wish to see\n");
   gets(file_name);

   fp = fopen(file_name, "r"); // read mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");//if file does not exist
      exit(EXIT_FAILURE);
   }
   while(fgets(buff,1024,fp)!= NULL){
      token = strtok(buff,",");
      d[i].func == token;
      i++;
   }
   for(int c= 0; c < i;c++){
      printf("%s %d",d[c].func);
   }

   
   fclose(fp);

   return 0;

}
