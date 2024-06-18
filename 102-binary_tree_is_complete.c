#include "binary_trees.h"

/**
 * struct QueueNode - Structure for a node in the queue
 * @node: Pointer to the binary tree node
 * @next: Pointer to the next node in the queue
 */
typedef struct QueueNode
{
    binary_tree_t *node; /* Pointer to the binary tree node */
    struct QueueNode *next; /* Pointer to the next node in the queue */
} QueueNode;

/**
 * create_queue_node - Creates a new node for the queue
 * @node: Pointer to the binary tree node
 * Return: Pointer to the new node, or NULL on failure
 */
QueueNode *create_queue_node(binary_tree_t *node)
{
    QueueNode *new_node = malloc(sizeof(QueueNode));
    if (new_node == NULL)
        return (NULL);
    new_node->node = node;
    new_node->next = NULL;
    return (new_node);
}

/**
 * free_queue - Frees a queue
 * @queue: Pointer to the front of the queue
 */
void free_queue(QueueNode *queue)
{
    QueueNode *temp_node;

    while (queue != NULL)
    {
        temp_node = queue;
        queue = queue->next;
        free(temp_node);
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
    QueueNode *temp;

    if (new_node == NULL)
        return (NULL);

    if (*queue == NULL)
    {
        *queue = new_node;
    }
    else
    {
        temp = *queue;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return (new_node);
}

/**
 * dequeue - Removes the front node from the queue
 * @queue: Pointer to the front of the queue
 */
void dequeue(QueueNode **queue)
{
    QueueNode *temp_node;

    if (*queue == NULL)
        return;

    temp_node = *queue;
    *queue = (*queue)->next;
    free(temp_node);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    QueueNode *front, *rear;
    binary_tree_t *current;
    int flag;

    if (tree == NULL)
        return (0);

    front = rear = create_queue_node((binary_tree_t *)tree);
    if (front == NULL)
        exit(1);

    flag = 0;

    while (front != NULL)
    {
        current = front->node;
        dequeue(&front);

        if (current->left != NULL)
        {
            if (flag == 1)
            {
                free_queue(front);
                return (0);
            }
            rear = enqueue(&front, current->left);
        }
        else
        {
            flag = 1;
        }

        if (current->right != NULL)
        {
            if (flag == 1)
            {
                free_queue(front);
                return (0);
            }
            rear = enqueue(&front, current->right);
        }
        else
        {
            flag = 1;
        }
    }
    return (1);
}
}
