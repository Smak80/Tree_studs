#include "tree.h"

bool _add_to_tree(node*& root, int value);
int _find_in_tree(node* tree, int value);
bool _remove_from_tree(node*& node, int value);
void _drop_tree(node*& node);
void _move_node(node* rem);
node* _find_prev_nearest(node* rem);

enum _traverse_type{prefix, infix, postfix};

void _traverse(queue& q, node* root, _traverse_type type);

void add_to_tree(tree& tree, int value)
{
	if (_add_to_tree(tree.root, value))
		tree.elem_count++;
}

int find_in_tree(tree& tree, int value)
{
	return _find_in_tree(tree.root, value);
}

bool remove_from_tree(tree& tree, int value)
{
	auto res = _remove_from_tree(tree.root, value);
	if (res)
		tree.elem_count--;
	return res;
}

void drop_tree(tree& tree)
{
	_drop_tree(tree.root);
	tree.elem_count = 0;
}

bool _add_to_tree(node*& root, int value)
{
	if (root)
	{
		if (root->value == value)
		{
			root->count++;
			return false;
		}
		auto& branch = value < root->value ? root->left : root->right;
		bool r = _add_to_tree(branch, value);
		return r;
	}
	node* newnode = new node;
	newnode->value = value;
	root = newnode;
	return true;
}

int _find_in_tree(node* root, int value)
{
	if (!root) return 0;
	if (root->value == value) return root->count;
	if (value < root->value)
		return _find_in_tree(root->left, value);
	return _find_in_tree(root->right, value);
}

inline void _del(node*& root)
{
	//Удаление элементов узла дерева
	//....
	//Удаление узла
	delete root;
	root = nullptr;
}

void _drop_tree(node*& root)
{
	if (root)
	{
		_drop_tree(root->left);
		_drop_tree(root->right);
		_del(root);
	}
}

bool _remove_from_tree(node*& root, int value)
{
	if (root)
	{
		if (root->value == value)
		{
			if (!root->left && !root->right)
				_del(root);
			else
				_move_node(root);
			return true;
		}
		auto& subtree = value < root->value ? root->left : root->right;
		bool r = _remove_from_tree(subtree, value);
		return r;
	}
	return false;
}

inline bool _is_left(const node* rem)
{
	return (bool)rem->left;	
}

inline void _copy_value(node* to, const node* from)
{
	if (to && from)
	{
		to->value = from->value;
		to->count = from->count;
	}
}

void _move_node(node* rem)
{
	auto is_lft = _is_left(rem);
	auto parent = _find_prev_nearest(rem);
	if (parent == rem) is_lft = !is_lft;
	auto& to_remove = is_lft ? parent->right : parent->left;
	node* child = nullptr;
	if (to_remove)
		child = is_lft ? to_remove->right : to_remove->left;
	_copy_value(rem, to_remove);
	_del(to_remove);
	to_remove = child;
}

node* _find_prev_nearest(node* rem)
{
	if (!rem) return rem;
	auto prev = rem;
	if (_is_left(rem))
	{
		auto last = rem->left;
		while (last && last->right)
		{
			prev = last;
			last = last->right;
		}
	} else
	{
		auto last = rem->right;
		while (last && last->left)
		{
			prev = last;
			last = last->left;
		}
	}
	return prev;
}

queue prefix_traverse(tree tree)
{
	queue q;
	_traverse(q, tree.root, prefix);
	return q;
}

queue infix_traverse(tree tree)
{
	queue q;
	_traverse(q, tree.root, infix);
	return q;
}

queue postfix_traverse(tree tree)
{
	queue q;
	_traverse(q, tree.root, postfix);
	return q;
}

void _traverse(queue& q, node* root, _traverse_type type)
{
	
}