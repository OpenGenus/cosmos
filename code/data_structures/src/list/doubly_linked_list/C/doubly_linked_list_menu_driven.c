// Coded by : Gurkirat Singh (tbhaxor)
// Link to Doubly Linked List : https://blog.bigoitsolution.com/learn/data-structures/1000/

#include <stdio.h>
#include <stdlib.h>
int size;

struct Node
{
    int data;
    struct Node *previous; // for holding the address of previous node
    struct Node *next;     // for holding the address of next node
};

int main()
{
    size = 0;
    int opt1, opt2, flag, value, itr;
    struct Node *HEAD, *LAST, *new_node, *tmp;
    HEAD = (struct Node *)malloc(sizeof(struct Node));
    LAST = (struct Node *)malloc(sizeof(struct Node));
    HEAD = NULL;
    LAST = NULL;
    while (1)
    {
        printf("1. INSERTION\n");
        printf("2. DELETION\n");
        printf("3. TRAVERSE\n");
        printf("4. REVERSE\n");
        printf("5. SEARCH\n");
        printf("6. SIZE\n");
        printf("7. QUIT\n");
        printf("> ");
        scanf("%d", &opt1);
        switch (opt1)
        {
        // case to exit the program
        case 7:
            free(HEAD);
            // free(new_node);
            // free(tmp);
            return 0;
        case 1:
            printf("\tENTER NUMBER TO INSERT : ");
            scanf("%d", &value);
            printf("\t1. IN THE BEGINING\n");
            printf("\t2. IN THE MIDDLE\n");
            printf("\t3. IN THE LAST\n");
            printf("\tINSERTION > ");
            scanf("%d", &opt2);
            switch (opt2)
            {
            case 1:
                new_node = (struct Node *)malloc(sizeof(struct Node));
                new_node->data = value;
                new_node->next = new_node->previous = NULL;
                if (HEAD == NULL && LAST == NULL)
                {
                    HEAD = new_node;
                    LAST = new_node;
                }
                else
                {
                    new_node->next = HEAD;
                    HEAD->previous = new_node; // storing the address of new
                                               // node to node at HEAD in order
                                               // to make it second node ;)
                    HEAD = new_node;           // changing node at HEAD
                }
                new_node = NULL;
                free(new_node);
                break;
            case 2:
                new_node = (struct Node *)malloc(sizeof(struct Node));
                new_node->data = value;
                new_node->next = new_node->previous = NULL;
                tmp = (struct Node *)malloc(sizeof(struct Node));
                tmp = HEAD;
                printf("\tENTER NODE INDEX : ");
                scanf("%d", &value);
                --value;
                if (size < value)
                {
                    printf("OVERFLOW");
                }
                else
                {
                    while (value--)
                    {
                        tmp = tmp->next;
                    }
                }
                new_node->next = tmp->next;
                new_node->previous = tmp;
                tmp->next->previous = new_node;
                tmp->next = new_node;
                new_node = NULL;
                tmp = NULL;
                free(new_node);
                free(tmp);
                break;
            case 3:
                new_node = (struct Node *)malloc(sizeof(struct Node));
                new_node->data = value;
                new_node->next = new_node->previous = NULL;
                new_node->previous = LAST;
                LAST->next = new_node;
                LAST = new_node;
                new_node = NULL;
                free(new_node);
                break;
            }
            ++size;
            break;
        case 2:
            printf("\t1. FROM BEGINNING\n");
            printf("\t2. FROM MIDDLE\n");
            printf("\t3. FROM END\n");
            printf("\tDELETION > ");
            scanf("%d", &opt2);
            switch (opt2)
            {
            case 1:
                tmp = (struct Node *)malloc(sizeof(struct Node));
                tmp = HEAD;
                HEAD = HEAD->next;
                printf("DELETED NODE ASSOCIATED TO %d", tmp->data);
                tmp = NULL;
                free(tmp);
                break;
            case 2:
                new_node = (struct Node *)malloc(sizeof(struct Node));
                tmp = (struct Node *)malloc(sizeof(struct Node));
                tmp = HEAD;
                printf("\tENTER NODE INDEX : ");
                scanf("%d", &value);
                while (--value)
                {
                    tmp = tmp->next;
                }
                new_node = tmp;
                tmp->next = tmp->next->next;
                new_node->next->previous = tmp;
                printf("DELETED NODE ASSOCIATED TO %d", new_node->data);
                tmp = NULL;
                new_node = NULL;
                free(tmp);
                free(new_node);
                break;
            case 3:
                tmp = (struct Node *)malloc(sizeof(struct Node));
                tmp = LAST;
                LAST = LAST->next;
                printf("DELETED NODE ASSOCIATED TO %d", tmp->data);
                tmp = NULL;
                free(tmp);
                break;
            }
            --size;
            break;
        case 3:
            if (HEAD == NULL || LAST == NULL)
            {
                printf("UNDERFLOW\n");
            }
            else
            {
                tmp = (struct Node *)malloc(sizeof(struct Node));
                tmp = HEAD;
                while (tmp != NULL)
                {
                    printf("%d ", tmp->data);
                    tmp = tmp->next;
                }
                tmp = NULL;
                free(tmp);
            }
            break;
        case 4:
            tmp = (struct Node *)malloc(sizeof(struct Node));
            new_node = (struct Node *)malloc(sizeof(struct Node));
            tmp = HEAD;
            while (tmp != NULL)
            {
                new_node = tmp->next;
                tmp->next = tmp->previous;
                tmp->previous = new_node;
                tmp = new_node;
            }
            new_node = HEAD;
            HEAD = LAST;
            LAST = new_node;
            new_node = NULL;
            tmp = NULL;
            free(tmp);
            free(new_node);
            break;
        case 5:
            printf("\tENTER NUMBER TO SEARCH : ");
            scanf("%d", &value);
            flag = 0;
            itr = 0;
            tmp = (struct Node *)malloc(sizeof(struct Node));
            ;
            tmp = HEAD;
            while (tmp != NULL)
            {
                if (value == tmp->data)
                {
                    flag = 1;
                    break;
                }
                tmp = tmp->next;
                ++itr;
            }

            if (flag)
            {
                printf(
                    "NUMBER FOUND AT %d NODE",
                    itr + 1); // to print non index value
            }
            else
            {
                printf("NODE NOT FOUND");
            }
            tmp = NULL;
            free(tmp);
            break;
        case 6:
            printf("SIZE OF LINKED LIST : %d", size);
            break;
        default:
            printf("WRONG INPUT");
        }
        printf("\n===============================================\n");
    }
}