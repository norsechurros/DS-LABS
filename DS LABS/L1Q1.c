#include <stdio.h>

int main1()
{
        printf("Enter array: ");
        int arr[10],num;

        for(int i =0; i <10;i++)
        {
            scanf("%d",&arr[i]);
        }

        printf("Enter number to be found: ");
        scanf("%d", &num);

       int result =  Binsrch(arr,1,10,num);
       if(result !=1)
        printf("Element found!");
       else
        printf("Element not found");
}

int Binsrch(int arr[],int lb,int ub,int num1 )
{
    if(lb<=ub)
        {int mid = (lb+ub)/2;

    if(num1==mid)
        return mid;

    if(arr[mid]>num1)
        return Binsrch(arr,lb,mid-1,num1);

    if(arr[mid]<num1)
        return Binsrch(arr,mid+1,ub,num1);}

        return -1;

}
