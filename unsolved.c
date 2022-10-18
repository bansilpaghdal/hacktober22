#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n,num,i,j;
    int k=0;
    scanf("%d", &n);
    num=n;
  	// Complete the code to print the pattern.

      for( i=0;i<2*n-1;i++)
      {   for(j=0;j<2*n-1;j++)
      {

      {if(i==k||j==k||i==2*n-2-k||j==2*n-2-k)
         { printf("%d   ",num);
          }
          else printf(" ");


      }


      }
k++;
num--;
printf("\n");
      if(k>2*n-1)
        break;
      }

    return 0;
}


