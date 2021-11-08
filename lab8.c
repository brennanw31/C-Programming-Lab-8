#include "lab8.h"

/*This function recieves a float number, then mallocs for a Weather struct whose
temperature value is that of the float passed to the function. A pointer to this
struct is returned*/
Weather* createNode(float temp)
{
	Weather *node = malloc(sizeof(Weather));
	if(node){
		node->temperature = temp;
		node->Ptr = NULL;
		return node;
	}
	else{
		printf("*** Error: Memory could not be allocated ***\n");
		return(NULL);
	}
}

/*This function returns an empty list without dummy nodes*/
Weather* initList()
{
	Weather *p = NULL; p->Ptr = NULL;
	return p;
}

/*This function recieves a linked-list and a float value, then creates a Weather struct whose
temperature value is set to that of the float passed to the function. This new struct is appended to
the head of the linked-list, and a pointer to the new head is returned*/
Weather* addToHead(Weather* node, float temp)
{
	Weather *p = createNode(temp);
	if(p){
		p->Ptr = node;
		return p;
	}
	else{
		printf("*** Error: Memory could not be allocated ***\n");
		return(NULL);
	}
}

/*This function recieves a linked-list and a float value, then creates a Weather struct whose
temperature value is set to that of the float passed to the function. This new struct is placed at the
tail of the linked-list, and a pointer to the list's head is returned*/
Weather* addToTail(Weather* node, float temp)
{
	Weather *p = createNode(temp);
	if(!p){
		printf("*** Error: Memory could not be allocated ***\n");
		return(NULL);
	}
	else{
		p->Ptr = NULL;
		Weather *last = node;
		while(last->Ptr != NULL){
			last = last->Ptr;
		}
		Weather *q = last->Ptr;
		last->Ptr = p;
		p->Ptr = q;
		return node;
	}
}

/*This function simply prints all float values in the list from head to tail*/
void printList(Weather* node)
{
	int i = 0;
	Weather *p = node;
	printf("\t");
	while(p != NULL){
		printf("%.1lf ", p->temperature);
		p = p->Ptr;
		++i;
		if(i > 0 && i%10 == 0){ printf("\n\t"); }
	}
}

/*This function computes the minimum and maximum values in a given list, and returns them through
the two float * parameters passed by reference. The int return value can be -1, indicating that the list
passed to the function is NULL or empty, or 1, indicating that the values were successfully found.*/
int checkMinMaxTemp(Weather* node, float* min, float* max)
{
	float j = node->temperature, k = node->temperature;
	if(!node){ return -1; }
	else{
		Weather *p = node;
		while(p != NULL){
			if(p->temperature < j){
				j = p->temperature;
			}
			if(p->temperature > k){
				k = p->temperature;
			}
			p = p->Ptr;
		}
		*min = j; *max = k;
		return 1;
	}
}

/*This function recieves a linked-list, frees all previously allocated memories associated with it,
then sets the list to NULL and returns it back to the calling function*/
Weather* freeList(Weather* node)
{
	if(!node){	return NULL;	}
	else{
		Weather *p = node;
		while(p != NULL){
			node = p;
			p = p->Ptr;
			free(node);
			node = NULL;
		}
		return NULL;
	}
}

















