#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILESIZE 100
FILE *fp;
typedef struct{
      char func[6];//to read add, read, delete based on first letter
      int filename;
      int data[FILESIZE];
}data;
data d[10];//basically able to read 10 lines so got 10 different set of data
int i = 0;
int readFile();
void add();
void read();
void delete();

int readFile(){

   char file_name[25];
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
   while(fgets(buff,sizeof(buff),fp)){
      int j = 0;
      token = strtok(buff,",");
      strcpy(d[i].func,token);
      token = strtok(NULL,",");
      d[i].filename = atoi(token);
      token = strtok(NULL,",");
      while(token != NULL){   
         d[i].data[j]= atoi(token);
         printf("%d,",d[i].data[j]);//so they do scan in the values
         token = strtok(NULL,",");
         j++;
      }
      i++;
   } 
   for(int c= 0; c < i;c++){
      printf("\nFunction:--%s--Filename:--%d--Data:",d[c].func,d[c].filename);
      int *ptr = d[c].data;
      int size = 0;
      while(*ptr !=0){
         *ptr++;
         size++;
      }
      for(int k = 0; k < 2; k++){//2 instead of size idk le la i fked up
         printf("%d,",d[c].data[k]);
      }
   }
   
   fclose(fp);

   return 0;
}
void main()
{
   printf("\n Contiguous File Allocation \n\n");
   readFile();
   for(int c= 0; c < i;c++){
      char *function = d[c].func;//d[1].func
      switch(*function){
         case 'a':
            printf("\naddpart1\n");
            add(c);
            break;
         case 'r':
            printf("\nreadpart1\n");
            read();
            break;
         case 'd':
            printf("\ndeletepart1\n");
            delete();
            break;
         default:
            printf("whycometildefault");
            break;
      }
   }

}

void add(int index){
   printf("%d",d[index].filename);
   //d[1].filename
   printf("--went into add function--");
}
void read(){
   printf("--went into read function--");
}
void delete(){
   printf("--went into delete function--");
}