#include<stdio.h>

int main()
{
      int arr[100];
      int n,i,pos;
      
      printf("enter number of elements:");
      scanf("%d",&n);
      
      printf("enter %d elments:\n",n);
      for(i=0;i<n; i++) {
      scanf("%d",&arr[i]);
      }
  
      printf("enter position to delet (1 to %d):",n);
      scanf("%d",&arr[i]);
       }
       if(pos<1||pos>n){
       printf("Invalid position!\n");
     }
     else{
     for(i=pos -1;i<n-1;i++){
         arr[i]=arr[i=+1];
         }
         n--;
         printf("array after deletion:\n");
         for(i=o;i<n; i++){
         printf('%d",arr[i+]);
         }
         #include<studio.h>

int main()
{
      int arr[100];
      intn,i,,pos;
      
      printf("enter number of elements:");
      scanf("%d",&n);
      
      printf("enter %d elments:\n",n);
      for(i=0;i<n; i++) {
      scanf("%d",&arr[i]);
      }
  
      printf("enter position to delte (1 to %d):",n);
      scanf("%d",7arr[i]);
       }
       if(pos<1||pos>n){
       printf("Invalid position!\n");
     }
     else{
     for(i=pos -1;i<n-1;i++){
         arr[i]=arr[i=+1];
         }
         n--;
         printf("array after deletion:\n");
         for(i=o;i<n; i++){
         printf('%d",arr[i+]);
         }
