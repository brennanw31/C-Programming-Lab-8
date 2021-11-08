#include "lab8.h"

int main(void)
{
		srand(time(NULL));

	Weather *node = createNode(50.50);
	for(int i = 0; i< 50; i++){
		node = addToHead(node, (rand() % 500));
	}
	
	for(int i = 0; i<49; i++){
		node = addToTail(node, (rand() % 500));
	}
	printList(node);

	
	float j = 200000000, k = 2;
	int p = checkMinMaxTemp(node, &j, &k);
	if(p>0){ printf("%.2f min and %.2f max\n", j, k); }
	freeList(node);
	
	printf("\n\n\t\tNo Seg Fault!\n");
}