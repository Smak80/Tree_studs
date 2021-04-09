#pragma once
#include "tree_struct.h"

void add_to_tree(tree& tree, int value);

int find_in_tree(tree& tree, int value);

bool remove_from_tree(tree& tree, int value);

void drop_tree(tree& tree);

queue prefix_traverse(tree tree);

queue infix_traverse(tree tree);

queue postfix_traverse(tree tree);