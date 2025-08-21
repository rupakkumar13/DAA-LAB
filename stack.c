#include<stdio.h>
# define max 1000
int arr[max];
int top = -1;

void push(){
    if(top == max - 1 ){
        printf("The stack is full \n");
    }
    else {
        int value;
        printf("enter the value ");
        scanf("%d",&value);
        top++;
        arr[top]=value;
        printf(" %d is pushed to the stack \n",arr[top]);
    }
}
void pop(){
    if(top == -1){
        printf("The stack is empty \n");
    }
    else{
        printf("%d is popped from the stack ",arr[top]);
                top--;
    }
}
void peek(){
    if ( top == -1){
        printf("the stack is empty \n");
    }
    else {
        printf("The top of the stack is %d \n",arr[top]);
    }
}
int main(){
    while(1)
{
    printf("enter 1 to push, 2 to pop, 3 to find the peek and 4 to exit from code ");
    int n;
    scanf("%d",&n);
    if(n==1) push();
    if(n==2) pop();
    if(n==3) peek();
    if(n==4) return 0;
}
}
