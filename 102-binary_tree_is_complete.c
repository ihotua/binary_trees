#include "binary_trees.h"

/**
 * QueueNode - Structure for a node in the queue
 */
typedef struct QueueNode {
    binary_tree_t *node; // Pointer to the binary tree node
    struct QueueNode *next; // Pointer to the next node in the queue
} QueueNode;

/**
 * Queue - Structure representing a queue
 */
typedef struct Queue {
    QueueNode *front; // Pointer to the front of the queue
    QueueNode *rear; // Pointer to the rear of the queue
} Queue;

/**
 * create_queue_node - Creates a new node for the queue
 * @node: Pointer to the binary tree node
 * Return: Pointer to the new node, or NULL on failure
 */
QueueNode *create_queue_node(binary_tree_t *node)
{
    QueueNode *new_node = malloc(sizeof(QueueNode));
    if (new_node == NULL)
        return NULL;
    new_node->node = node;
    new_node->next = NULL;
    return new_node;
}

/**
 * free_queue - Frees a queue
 * @queue: Pointer to the front of the queue
 */
void free_queue(QueueNode *queue)
{
    while (queue != NULL)
    {
        QueueNode *temp = queue;
        queue = queue->next;
        free(temp);
    }
}

/**
 * enqueue - Adds a node to the rear of the queue
 * @queue: Pointer to the front of the queue
 * @node: Pointer to the binary tree node to enqueue
 * Return: Pointer to the rear of the queue
 */
QueueNode *enqueue(QueueNode **queue, binary_tree_t *node)
{
    QueueNode *new_node = create_queue_node(node);
    if (new_node == NULL)
        return NULL;
    if (*queue == NULL)
    {
        *queue = new_node;
    }
    else
    {
        (*queue)->next = new_node;
    }
    return new_node;
}

/**
 * dequeue - Removes the front node from the queue
 * @queue: Pointer to the front of the queue
 */
void dequeue(QueueNode **queue)
{
    if (*queue == NULL)
        return;
    QueueNode *temp = *queue;
    *queue = (*queue)->next;
    free(temp);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    QueueNode *front = NULL, *rear = NULL;
    int flag = 0;

    enqueue(&front, (binary_tree_t *)tree);

    while (front != NULL)
    {
        binary_tree_t *current = front->node;
        dequeue(&front);

        if (current->left)
        {
            if (flag)
            {
                free_queue(front);
                return 0;
            }
            rear = enqueue(&rear, current->left);
        }
        else
        {
            flag = 1;
        }

        if (current->right)
        {
            if (flag)
            {
                free_queue(front);
                return 0;
            }
            rear = enqueue(&rear, current->right);
        }
        else
        {
            flag = 1;
        }
    }
    return 1;
}
