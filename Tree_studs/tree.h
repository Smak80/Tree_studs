#pragma once

struct node
{
	int value;
	int count = 1;
	node* left = nullptr;
	node* right = nullptr;
};

struct tree
{
	node* root = nullptr;
	size_t elem_count = 0;
};

void add_to_tree(tree& tree, int value);

int find_in_tree(tree& tree, int value);

bool remove_from_tree(tree& tree, int value);

void drop_tree(tree& tree);