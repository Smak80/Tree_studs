#pragma once
#include "tree_struct.h"

void enqueue(queue& queue, node* tree_node);

bool dequeue(queue& queue, node*& tree_node);

void clear(queue& queue);
