#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *start = NULL;

void AddNode(struct Node **start, int data){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	if(*start == NULL){
		*start = newNode;
	}else{
		struct Node *temp = *start;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void ShowAll(){
	struct Node *temp = start;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void ShowBackRun(struct Node *temp){
	if(temp == NULL){
		return;
	}
	ShowBackRun(temp->next);
	printf("%d ", temp->data);
}

void ShowBack(){
	ShowBackRun(start);
	printf("\n");
}

void Swap(struct Node **temp, int first_node, int second_node){
	struct Node *first_node_prev = NULL;
	struct Node *first_node_curr = *temp;
	struct Node *second_node_prev = NULL;
	struct Node *second_node_curr = *temp;

	while(first_node_curr != NULL && first_node_curr->data != first_node){
		first_node_prev = first_node_curr;
		first_node_curr = first_node_curr->next;
	}

	while(second_node_curr != NULL && second_node_curr->data != second_node){
		second_node_prev = second_node_curr;
		second_node_curr = second_node_curr->next;
	}

	if(first_node_curr == NULL || second_node_curr == NULL){
		//printf("Node not found\n");
		return;
	}

	if(first_node_prev == NULL){
		*temp = second_node_curr;
	}else{
		first_node_prev->next = second_node_curr;
	}

	if(second_node_prev == NULL){
		*temp = first_node_curr;
	}else{
		second_node_prev->next = first_node_curr;
	}

	struct Node *temp2 = first_node_curr->next;
	first_node_curr->next = second_node_curr->next;
	second_node_curr->next = temp2;
}

void Update(struct Node **temp, int old_data, int new_data){
	struct Node *temp2 = *temp;
	while(temp2 != NULL){
		if(temp2->data == old_data){
			temp2->data = new_data;
			return;
		}
		temp2 = temp2->next;
	}
}

int main(){
	AddNode(&start, 10);
	AddNode(&start, 20);
	AddNode(&start, 30);
	AddNode(&start, 40);
	ShowAll();
	Update(&start, 10, 99);
	ShowAll();
	Update(&start, 10, 98);
	ShowAll();
	printf("\n");

	start = NULL;
	AddNode(&start, 10);
	AddNode(&start, 20);
	AddNode(&start, 30);
	AddNode(&start, 40);
	ShowAll();
	ShowBack();
	printf("\n");

	start = NULL;
	AddNode(&start, 10);
	AddNode(&start, 20);
	AddNode(&start, 30);
	AddNode(&start, 40);
	ShowAll();
	Swap(&start, 20, 30);
	ShowAll();
	Swap(&start, 40, 10);
	ShowAll();
	printf("\n");
}
