 /**
  * * @file   testebbchar.c
 * @author Derek Molloy
 * @date   7 April 2015
 * @version 0.1
 * @brief  A Linuinf208[0] user space program that communicates with the ebbchar.c LKM. It passes a
 * string to the LKM and reads the response from the LKM. For this einf208[0]ample to work the device
 * must be called /dev/ebbchar.
 * @see http://www.derekmolloy.ie/ for a full description and follow-up descriptions.
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
 
#define BUFFER_LENGTH 256
#define BUFFER1 256
#define BUFFER2 256
#define BUFFER3 256

static char receive[BUFFER_LENGTH];         ///<= The receive buffer from the LKM

int main(){
   int ret, fd;
   char son[BUFFER_LENGTH];
   char name1[BUFFER1];
   char name2[BUFFER2];
   char name3[BUFFER3];
   char inf208_1[BUFFER_LENGTH];
   char inf208_2[BUFFER_LENGTH];
   char inf208_3[BUFFER_LENGTH];
   char mec308_1[BUFFER_LENGTH];
   char mec308_2[BUFFER_LENGTH];
   char mec308_3[BUFFER_LENGTH];
   char mec324_1[BUFFER_LENGTH];
   char mec324_2[BUFFER_LENGTH];
   char mec324_3[BUFFER_LENGTH];

   printf("Starting device test code ...\n");
   fd = open("/dev/ebbchar", O_RDWR);             // Open the device with read/write access
   if (fd < 0){
      perror("Failed to open the device...");
      return errno;
   }

   printf("Student 1/3: \n");
   scanf("%[^\n]%*c", name1);                // Read in a string (with spaces)
   printf("Writing message to the device [%s].\n", name1);

   
   printf("INF208: ");
   scanf("%[^\n]%*c",inf208_1);
   ret = write(fd, inf208_1, strlen(inf208_1));
   if (ret < 0){
      perror("Sıkıntı burada da olabilir abi ama");
      return errno;
   }

   printf("MEC308: ");
   scanf("%[^\n]%*c",mec308_1);
   ret = write(fd, mec308_1, strlen(mec308_1));
   if (ret < 0){
      perror("Sıkıntı burada da olabilir abi ama");
      return errno;
   }
      
   printf("MEC324: ");
   scanf("%[^\n]%*c",mec324_1);
   ret = write(fd, mec324_1, strlen(mec324_1));
   if (ret < 0){
      perror("Sıkıntı burada da olabilir abi ama");
      return errno;
   }

   printf("Student 2/3: \n");
   scanf("%[^\n]%*c", name2);                // Read in a string (with spaces)
   printf("Writing message to the device [%s].\n", name2);

   
   printf("INF208: ");
   scanf("%[^\n]%*c",inf208_2);
   ret = write(fd, inf208_2, strlen(inf208_2));
   if (ret < 0){
      perror("Sıkıntı burada da olabilir abi ama");
      return errno;
   }

   printf("MEC308: ");
   scanf("%[^\n]%*c",mec308_2);
   ret = write(fd, mec308_2, strlen(mec308_2));
   if (ret < 0){
      perror("Sıkıntı burada da olabilir abi ama");
      return errno;
   }

      
   printf("MEC324: ");
   scanf("%[^\n]%*c",mec324_2);
   ret = write(fd, mec324_2, strlen(mec324_2));
   if (ret < 0){
      perror("Sıkıntı burada da olabilir abi ama");
      return errno;
   }

   printf("Student 3/3: \n");
   scanf("%[^\n]%*c", name3);                // Read in a string (with spaces)
   printf("Writing message to the device [%s].\n", name3);

   
   printf("INF208: ");
   scanf("%[^\n]%*c",inf208_3);
   ret = write(fd, inf208_3, strlen(inf208_3));
   if (ret < 0){
      perror("Sıkıntı burada da olabilir abi ama");
      return errno;
   }

   printf("MEC308: ");
   scanf("%[^\n]%*c",mec308_3);
   ret = write(fd, mec308_3, strlen(mec308_3));
   if (ret < 0){
      perror("Sıkıntı burada da olabilir abi ama");
      return errno;
   }
      
   printf("MEC324: ");
   scanf("%[^\n]%*c",mec324_3);
   ret = write(fd, mec324_3, strlen(mec324_3));
   if (ret < 0){
      perror("Sıkıntı burada da olabilir abi ama");
      return errno;
   }

   printf("Haben sie alle Werte gegeben?: ");
   scanf("%[^\n]%*c",son);
   printf("%s\n",son);
   ret = write(fd, son, strlen(son));
   if (ret < 0){
      perror("Sıkıntı burada da olabilir abi ama");
      return errno;
   }

   printf("The received message is: [%s]\n", name1);
   printf("The received message is: [%s]\n", inf208_1);
   printf("The received message is: [%s]\n", mec308_1);
   printf("The received message is: [%s]\n", mec324_1);

   printf("The received message is: [%s]\n", name2);
   printf("The received message is: [%s]\n", inf208_2);
   printf("The received message is: [%s]\n", mec308_2);
   printf("The received message is: [%s]\n", mec324_2);

   printf("The received message is: [%s]\n", name3);
   printf("The received message is: [%s]\n", inf208_3);
   printf("The received message is: [%s]\n", mec308_3);
   printf("The received message is: [%s]\n", mec324_3);
   printf("End of the program\n");


   return 0;
}

