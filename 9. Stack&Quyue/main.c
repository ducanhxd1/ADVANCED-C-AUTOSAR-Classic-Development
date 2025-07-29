// #include "stack.h"
#include "queue.h"

int main()
{
    Queue q;

    initQueue(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    // enqueue(&q, 40);
    // enqueue(&q, 50);

    display(&q);

    freeQueue(&q);
    return 0;

}