// Queue implementation by using Array - 

#include<stdio.h>

int size = 0;
int front = -1;
int rear = -1;
int flag = 0;

int Enqueue(int arr[])
{
	if(rear == size - 1){
	
		return -1;
	}
	else{
	
		if(front == -1){
		
			front++;
		}
		rear++;
		printf("Enter Data : \n");
		scanf("%d", &arr[rear]);
		return 0;
	}
}

void Dequeue(int arr[])
{
	if(front == -1 || front > rear){
	
		flag = 0;
		return -1;
	}
	else{
	
		flag = 1;
		int val = arr[front];
		if(front == rear){
		
			front = -1;
			rear = -1;
		}
		else{
		
			front++;
		}
		return val;
	}
}

int Frontt(int arr[])
{
	if(front == -1){
	
		flag = 0;
		return -1;
	}
	else{
	
		flag = 1;
		return arr[front];
	}
}

int PrintQueue(int arr[])
{
	if(front == -1){
	
		return -1;
	}
	else{
	
		for(int i = front; i < rear; i++)
		{
			printf("%d  ", arr[i]);
		}
		printf("\n");
	}
}
void main()
{
	char choise;
	printf("Enter Size of Array : ");
	sca~nf("%d",&size);

	int arr[size];

	do{
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Frontt\n");
		printf("4. PrintQueue\n");

		int ch = 0;
		printf("Enter Your Choise Here : ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1 : 
				{
					int ret = Enqueue(arr);
					if(ret == -1){
					
						printf("Queue is Overflow\n");
					}
				}
				break;
			case 2 : 
				{
					int ret = Dequeue(arr);
					if(flag == 1){
					
						printf("%d is dequeue\n", ret);
					}
					else{
					
						printf("Queue is Underflow\n");
					}
				}
				break;
			case 3 : 
				{
					int ret = Frontt(arr);
					if(flag == 1){
					
						printf("Front = %d\n",ret);
					}
					else{
					
						printf("Queue is Empty\n");
					}
				}
				break;
			case 4 : 
				{
					int ret = PrintQueue(arr);
					if(ret == -1){
					
						printf("Queue is Empty\n");
					}
				}
				break;
			default:
				printf("You entered wrong choise : \n");
				break;
		}

		getchar();
		printf("Do You Want To Continue : \n");
		scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
}

