/**
  * * @file   testebbchar.c
 * @author Derek Molloy
 * @date   7 April 2015
 * @version 0.1
 * @brief  A Linux user space program that communicates with the ebbchar.c LKM. It passes a
 * string to the LKM and reads the response from the LKM. For this example to work the device
 * must be called /dev/ebbchar.
 * @see http://www.derekmolloy.ie/ for a full description and follow-up descriptions.
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<math.h>
 
#define BUFFER_LENGTH 256               ///< The buffer length (crude but fine)
static char receive[BUFFER_LENGTH];     ///< The receive buffer from the LKM
 
int main(){
   int ret, fd;
   char choice[BUFFER_LENGTH];
   int x0;
   char X0[BUFFER_LENGTH];
   int x1;
   char X1[BUFFER_LENGTH];
   int x2;
   char X2[BUFFER_LENGTH];
   int y0;
   char Y0[BUFFER_LENGTH];
   int y1;
   char Y1[BUFFER_LENGTH];
   int y2;
   char Y2[BUFFER_LENGTH];
   int h;
   char Hohe[BUFFER_LENGTH];
   char falsch[]="ihre wahl ist falch";
   int r;
   int pi=3;
   int volume=0;
   int area=0;
   char KernelArea[BUFFER_LENGTH];
   char KernelVolume[BUFFER_LENGTH];
   char uyari[]="3 Koordinaten an selben Punkt eingegeben";

   printf("Starting device test code example...\n");
   fd = open("/dev/ebbchar", O_RDWR);             
   if (fd < 0){
      perror("Failed to open the device... ");
      return errno;
   }
  
  
    printf("Bitte wahlen Sie die Form aus,die Sie mit den angegebenen Buchstaben berechnen möchten\n:");
    printf("Dreieckiges Prisma (P,p) / Kegel (K,k)=");
   scanf("%c",choice);
   ret = write(fd, choice, strlen(choice)); 
    if (ret < 0){
      perror("Failed to write the message to the device.");
      return errno;
    }
   if(*choice=='K'){
     
     printf("Bitte geben Sie die Radius und h als Ganzzahlen ein\n");
      printf("Radius:");
      scanf("%d",&r);
      printf("Hohe h:");
      scanf("%d",&h);

      
     area=pi*r*r;
     printf("Grundflache=%d\n",area);
     sprintf(KernelArea,"%d",area);
     ret = write(fd,KernelArea, strlen(KernelArea)); 
      if (ret < 0){
      perror("Failed to write the message to the device.");
      return errno;
     }
      
     volume=(pi*r*r*h)/3;
     printf("Volumen=%d\n",volume);
     sprintf(KernelVolume,"%d",volume);
     ret = write(fd,KernelVolume, strlen(KernelVolume)); 
      if (ret < 0){
      perror("Failed to write the message to the device.");
      return errno;
     }

   }
     else if(*choice=='P'){

   printf("Bitte geben Sie die Punkte X0,Y0,X1,Y1,X2,Y2 und h als Ganzezahlen ein\n");
   printf("1.Koordinate X0:");
   scanf("%d",&x0);
   printf("1.Koordinate Y0:");
   scanf("%d",&y0);
   printf("2.Koordinate X1:");
   scanf("%d",&x1);
   printf("2.Koordinate Y1:");
   scanf("%d",&y0);
   printf("3.Koordinate X2:");
   scanf("%d",&x2);
   printf("3.Koordinate Y2:");
   scanf("%d",&y2);
   printf("4.hohe h:");
   scanf("%d",&h);


   sprintf(X0,"%d",x0);
   sprintf(X1,"%d",x1);
   sprintf(X2,"%d",x2);
   sprintf(Y0,"%d",y0);
   sprintf(Y1,"%d",y1);
   sprintf(Y2,"%d",y2);
   sprintf(Hohe,"%d",h);


     if(((x0==x1 && x1==x2) && (y0==y1 && y1==y2)) ||(x0==x1 && y0==y1) || (x1==x2 && y1==y2) || (x0==x2 && y0==y2)){
      printf("(%d,%d)(%d,%d)(%d,%d) %s \n",x0,y0,x1,y1,x2,y2,uyari);
      ret = write(fd, uyari, strlen(uyari)); 
      if (ret < 0){
      perror("Failed to write the message to the device.");
      return errno;
      }
     return 0;
    }
     
     
     area=(abs(x0*(y1-y2)+x1*(y2-y0)+x2*(y0-y1)))/2;
     printf("Grundflache= %d\n",area);
     sprintf(KernelArea,"%d",area);
     ret = write(fd, KernelArea, strlen(KernelArea)); 
      if (ret < 0){
      perror("Failed to write the message to the device.");
      return errno;
     }
      
     volume=(abs(x0*(y1-y2)+x1*(y2-y0)+x2*(y0-y1))*h)/2;
     printf("Volumen=%d\n",volume);
     sprintf(KernelVolume,"%d",volume);
     ret = write(fd, KernelVolume, strlen(KernelVolume)); 
      if (ret < 0){
      perror("Failed to write the message to the device.");
      return errno;

     }
     
   }
   else{
     printf(" %s \n",falsch);
      ret = write(fd, falsch, strlen(falsch)); 
      if (ret < 0){
      perror("Failed to write the message to the device.");
      return errno;
      }
   }


   printf("Press ENTER to read back from the device...\n");
   getchar();
 

   printf("The received message is: [Prozess ist erfolgreich abgeschlossen!]\n");
   printf("End of the program\n");
   return 0;
}



