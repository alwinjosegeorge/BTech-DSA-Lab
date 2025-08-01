#include <stdio.h>
int FRONT = 0,REAR=-1;

void Enqueue(int Q[],int value,int MAX){
    if(REAR==MAX-1){
        printf("Queue Overflow!\n");
    }
    else{
        Q[++REAR]=value;
        printf("Enqueued %d!\n",value);
        printf("QUEUE Elements: ");
        for(int i=FRONT;i<=REAR;i++){
      printf("%d\t",Q[i]);
      }
      printf("\n");
    }
}

void Dequeue(int Q[]){
    if(FRONT>REAR){
        printf("Queue Underflow!\n");
    }else{
        printf("Dequeued %d!\n",Q[FRONT]);
        FRONT++;
        printf("QUEUE Elements: ");
        for(int i=FRONT;i<=REAR;i++){
      printf("%d\t",Q[i]);
      }
        printf("\n");
    }
}

int main(){
    int MAX;
    printf("Enter the size of queue: ");
    scanf("%d",&MAX);
    int queue[MAX];
    while(1){
        int choice,value;
        printf("\n---------!Select queue option!---------\n");
        printf("1. Enqueue\t");
        printf("2. Dequeue\t");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: if(REAR==MAX-1){
            printf("Queue is FULL cannot enqueue.");
            break;
            }else{
            printf("Enter the element to enqueue: ");
            scanf("%d",&value);
            Enqueue(queue,value,MAX);
            }
            break;
            case 2:printf("Dequeuing........done!\n");
            Dequeue(queue);
            break;
            case 3: return 0;
            default:printf("Invalid choice!");
        }

    }
    
}
