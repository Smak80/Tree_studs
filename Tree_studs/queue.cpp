#include "queue.h"

void enqueue(queue& queue, node* tree_node)
{
	elem* newel = new elem;
	newel->node = tree_node;
	if (!queue.tail)
	{
		queue.head = queue.tail = newel;
	} else
	{
		queue.tail->next = newel;
		queue.tail = newel;
	}
	queue.size++;
}

bool dequeue(queue& queue, node*& tree_node)
{
	if (!queue.head)
		return false;
	tree_node = queue.head->node;
	elem* rem = queue.head;
	queue.head = queue.head->next;
	delete rem;
	if (!queue.head) queue.tail = nullptr;
	queue.size--;
	return true;
}

void clear(queue& queue)
{
	while (queue.head)
	{
		elem* rem = queue.head;
		queue.head = queue.head->next;
		delete rem;
	}
	queue.size = 0;
	queue.tail = nullptr;
}
