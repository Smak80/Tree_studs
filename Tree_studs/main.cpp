#include <iostream>

#include "tree.h"
using namespace std;

void create_tree(tree& t, const int arr[], size_t elem_count)
{
	for (auto i = 0; i < elem_count; i++)
	{
		add_to_tree(t, arr[i]);
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int arr[] = {
		5, 2, 8, 1, 4, 0, 6, 9, 10, 7, 1, 1, 7, 7, 7, 0, 4, 5, 5, 10
	};
	tree tree;
	create_tree(tree, arr, sizeof(arr) / sizeof(arr[0]));
	remove_from_tree(tree, 5);
	remove_from_tree(tree, 9);
	remove_from_tree(tree, 0);
	remove_from_tree(tree, 8);
	remove_from_tree(tree, -1);
	drop_tree(tree);
	system("pause");
}