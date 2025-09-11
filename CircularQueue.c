#include <stdio.h>

int FRONT=0 ,REAR = -1, size=0, capacity;

void EnQ(int CircularQ[],int value){
    if(size==capacity){return;}
    else{
        REAR = (FRONT + size)%capacity;
        CircularQ[REAR]=value;
        size++;
    }
}

void DeQ(){
    if(size==0){return;}
    if(FRONT==REAR){
        FRONT=0;
        REAR =-1;
    }
    else{
        FRONT = (FRONT+1)%capacity;
    }
    size--;
}

void display(int CircularQ[]){
    printf("Circular Queue: ");
    if(FRONT<=REAR){
        for(int i=FRONT;i<=REAR;i++){
            printf("%d\t",CircularQ[i]);
        }
    }
    else{
        for(int i=FRONT;i<=capacity-1;i++){
            printf("%d\t",CircularQ[i]);
        }
        for(int i=0;i<=REAR;i++){
            printf("%d\t",CircularQ[i]);
        }
    }
}

int main(){
    printf("\nEnter the size of Circular Queue: ");
    scanf("%d",&capacity);

    int CircularQ[capacity];


while(1){
        int choice,value;
        printf("\nSelect queue option!\n");
        printf("1. Enqueue\t2. Dequeue\t3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:if(size==capacity){
                printf("Queue Overflow!\n");
            }else{
                printf("\nEnter the element: \n");
                scanf("%d",&value);
                EnQ(CircularQ,value);
                display(CircularQ);
            }
            break;
            case 2:if(size==0){
                printf("Queue Empty!\n");
            }else{
                DeQ();
                display(CircularQ);
            }
            break;
            case 3: return 0;
            default:printf("Invalid choice!");
        }

    }
    
}
