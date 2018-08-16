/*
I, <SUN,Wufan>, am submitting the assignment for
an individual project.
I declare that the assignment here submitted is original except for
source material explicitly acknowledged, the piece of work, or a part
of the piece of work has not been submitted for more than one purpose
(i.e. to satisfy the requirements in two different courses) without
declaration. I also acknowledge that I am aware of University policy
and regulations on honesty in academic work, and of the disciplinary
guidelines and procedures applicable to breaches of such policy and
regulations, as contained in the University website
http://www.cuhk.edu.hk/policy/academichonesty/.
It is also understood that assignments without a properly signed
declaration by the student concerned will not be graded by the
teacher(s).
*/
/***
WARNING:
1. You are not allowed to modify anything outside the 'START EDIT HERE'
and 'END EDIT HERE' area.
2. The implementation must be in O(log n) complexity per operation, as-
suming the total number of operations is n.
***/


#include <stdlib.h>
#include <stdio.h>

int* priority_queue;
int queue_size;

void Init(int length) {
	// init the priority queue
	priority_queue = (int*)malloc((length + 1) * sizeof(int));
	queue_size = 0;
}
int DeleteElement() {
	// delete the element
	/** START EDIT HERE **/
	if (queue_size == 0){ 
		printf("The heap is empty.\n");
		return 0;
	}
	int parent, child, item, temp;
	item = priority_queue[1];
	temp = priority_queue[queue_size--];
	parent = 1;
	child = 2;
	while (child <= queue_size){
		if ((child < queue_size) && (priority_queue[child] < priority_queue[child + 1]))
			child++;
		if (temp >= priority_queue[child])
			break;
		priority_queue[parent] = priority_queue[child];
		parent = child;
		child = child * 2;
	}
	priority_queue[parent] = temp;
	return item;
	/** END EDIT HERE **/
}

void InsertElement(int number) {
	// insert the element
	/** START EDIT HERE **/
	int i;
	i = ++queue_size;
	while ((i != 1) && (number>priority_queue[i / 2])){
		priority_queue[i] = priority_queue[i / 2];
		i = i / 2;
	}
	priority_queue[i] = number;
	/** END EDIT HERE **/
}

int main() {
	int N, i;
	char c;
	scanf_s("%d", &N);
	Init(N);
	while (N--) {
		while (1) {
			c = getchar();
			if (c == 'd' || c == 'i') {
				break;
			}
		}
		if (c == 'd') {
			printf("%d\n", DeleteElement());
		}
		else {
			scanf_s("%d", &i);
			InsertElement(i);
		}
	}
	return 0;
}