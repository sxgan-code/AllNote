#include <stdio.h>

#define MAX_SIZE 8
#define SUCCESS 1
#define ERROR 0
#define TRUE 1
#define FALSE 0



int getElement(int list[] ,int i , int p);


int main(){
    int p;
    int arr[MAX_SIZE]={2,5,11,36,25,11,5,48};
    getElement(arr,3,p);
    printf("%d\n", p);
}

int getElement(int list[] ,int i , int p){
    if (MAX_SIZE==0 || i<=0 || i>MAX_SIZE){
        return ERROR;
    }

    p = list[i-1];
    return SUCCESS;
}


