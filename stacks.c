#include<stdio.h>
#include<stdlib.h>


struct stack{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *ptr){
    return  ptr->top == -1;
}

int isfull(struct stack *ptr){
    return ptr->top == (ptr->size - 1);
}

void push(struct stack *sp, int val ){
    if(isfull(sp)){
        printf("stack overlfow\n");
    }else{
        sp->arr[++sp->top] = val;
        printf("pushed sucessfully : %d  current top : %d\n",val,sp->top);

    }
}

int pop(struct stack *sp){
    if(isEmpty(sp)){
        printf("stack underflow\n");
        return -1;
    }else{
        return sp->arr[sp->top--];
    }
}

int peek(struct stack *sp , int i){
    int arrindex = sp->top - i + 1;
    if(arrindex < 0)
       printf("not a valid pos\n");
    else{
            return sp->arr[arrindex];
    }
}

int main(){
  struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
  sp->size = 5;
  sp->top = -1;
  sp->arr = (int *)malloc(sp->size * sizeof(int));

  printf("poped : %d" , pop(sp));

  push(sp,1);
  push(sp,2);
  push(sp,3);
  push(sp,4);
  push(sp,5);
  push(sp,6);
  printf("poped : %d\n" , pop(sp));

  printf("element at pos %d is : %d", 3 , peek(sp,3));
  printf("\n%d",sp->top);
  return 0;
}