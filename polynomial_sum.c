#include<stdio.h>
int main(){
  int poly1[10][2],poly2[10][2],result[20][2];
  int n1,n2,i=0,j=0,k=0;
  
  printf("Enter number of terms in first polynomial:");
  scanf("%d",&n1);
  printf("Enter coefficient and exponent for each term:\n");
  for(i=0;i<n1;i++){
    printf("Term%d:",i+1);
    scanf("%d%d",&poly1[i][0],&poly1[i][1]);
    }
    
  printf("Enter number of terms in second polynomial:");
  scanf("%d",&n2);
  printf("Enter coefficient and exponent for each term:\n");
  for(i=0;i<n2;i++){
    printf("Term%d:",i+1);
    scanf("%d%d",&poly2[i][0],&poly2[i][1]);
    }
    
  i=j=0;
  
  while(i<n1 && j<n2){
    if(poly1[i][1] == poly2[i][j]){
      result[k][0] = poly1[i][0] + poly2[j][0];
      result[k][1] = poly1[i][1];
      i++;j++;
    }
    else if(poly1[i][1]>poly2[j][1]){
      result[k][0] = poly1[j][0];
      result[k][1] = poly1[j][1];
      i++;
    }
    else{
      result[k][0] =  poly2[j][0];
      result[k][1] =  poly2[j][1];
      j++;
    }
    k++;
  }
  
  while(i<n1){
    result[k][0] = poly1[i][0];
    result[k][1] = poly1[i][1];
    i++;k++;
  }
  while(j<n2){
    result[k][0] = poly2[i][0];
    result[k][1] = poly2[i][1];
    j++;k++;
  }
  
  printf("Resultant polynomial: ");
  for(i=0;i<k;i++){
    printf("%dx^%d",result[i][0],result[i][1]);
    if(i<k-1){
      printf("+");
    }
  }
    return 0;
}  
  
      
