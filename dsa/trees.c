#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *left_child, *right_child;
};
struct node *new_node(int value)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->value = value;
    tmp->left_child = tmp->right_child = NULL;
    return tmp;
}
void print(struct node *root_node)
{
    if (root_node != NULL)
    {
        print(root_node->left_child);
        printf("%d \n", root_node->value);
        print(root_node->right_child);
    }
}
struct node *insert_node(struct node *node, int value)
{
    if (node == NULL)
        return new_node(value);
    if (value < node->value)
    {
        node->left_child = insert_node(node->left_child, value);
    }
    else if (value > node->value)
    {
        node->right_child = insert_node(node->right_child, value);
    }
    return node;
}
int main()
{
    printf("Implementation of a Binary Tree in C!\n\n");
    struct node *root_node = NULL;
    root_node = insert_node(root_node, 50);
    insert_node(root_node, 45);
    insert_node(root_node, 12);
    insert_node(root_node, 64);
    insert_node(root_node, 21);
    insert_node(root_node, 84);
    insert_node(root_node, 97);
    print(root_node);
    return 0;
}
