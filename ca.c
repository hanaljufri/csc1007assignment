#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILESIZE 130
FILE *fp;
typedef struct{
      char func[6];//to read add, read, delete based on first letter
      int filename;
      int data[FILESIZE];
}data;
data d[10];//basically able to read 10 lines so got 10 different set of data
int i = 0,pos = 0, B = 0;
int readFile();
void add();
void read();
void delete();
int bFull();

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
            //printf("%d",(int)sizeof(d[c].data));
            add(c);
            break;
         case 'r':
            printf("\nreadpart1\n");
            read(c);
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
   /*if(bFull()){
      pos--;
      printf("\n\nNot Enough Free Space Available \n");
      return;
   }*/
   //d[1].filename
   printf("--went into add function--");

}
void read(int index){
   printf("Filename: %d\n",d[index].filename);
   printf("Data inside: ");
   for(int k = 0; k < 2; k++){//weird but i lost le
         printf("%d,",d[index].data[k]);
   }
   printf("--went into read function--");
}
void delete(){
   printf("--went into delete function--");
}
int bFull(){
   for(i = 1,B = 0;i<=pos;i++){
      B = B + sizeof(d[i].data);
   }
   if(B>FILESIZE){
      return 1;
   }else{
      return 0;
   }
}