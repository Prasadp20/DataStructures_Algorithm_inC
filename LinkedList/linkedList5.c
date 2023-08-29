#include<stdio.h>
#include<stdlib.h>

typedef struct Movie{

	char movieName[20];
	float movieRating;
	struct Movie *next;
}mv;

mv *head = NULL;

void addNode()
{
	mv *newNode = (mv *)malloc(sizeof(mv));

	printf("Enter movie name : ");
	fgets(newNode -> movieName, 20, stdin);
	printf("Enter movie rating : ");
	scanf("%f", &newNode -> movieRating);
	newNode -> next = NULL;
	
	getchar();
	if(head == NULL){
	
		head = newNode;
	}else{

		mv *temp = head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newNode;
	}	
}
void printLinkedList()
{
	mv *temp = head;

	while(temp != NULL)
	{
		printf(" |%s -> %0.1f| \n", temp -> movieName, temp -> movieRating);
		temp = temp -> next;
	}
	printf("\n");
}
void main()
{
	addNode();
	addNode();
	//addNode();
	printLinkedList();
}
