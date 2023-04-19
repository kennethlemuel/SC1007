#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;
typedef ListNode StackNode;

typedef struct _graph{
    int V;
    int E;
    int **matrix;
}Graph;

typedef struct _linkedlist
{
	int size;
	ListNode *head;
} Stack;

// You should not change the prototypes of these functions
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
////GRAPH////////////////////////////////////////////
void printGraphMatrix(Graph );
////////////////////////////////////////////

void DFS_I (Graph , int );

int main()
{
    Graph g;
    int i,j;

    printf("Enter the number of vertices:\n");
    scanf("%d",&g.V);

    g.E = 0;
    g.matrix = (int **)malloc(g.V*sizeof(int *));
    for(i=0;i<g.V;i++)
        g.matrix[i] = (int *)malloc(g.V*sizeof(int));

    for(i=0;i<g.V;i++)
       for(j=0;j<g.V;j++)
           g.matrix[i][j] = 0;

    int V1, V2;
    printf("Enter two vertices which are adjacent to each other:\n");
    while(scanf("%d %d",&V1,&V2)==2)
    {
        if(V1>0 && V1<=g.V && V2>0 && V2<=g.V)
        {
            g.matrix[V1-1][V2-1] = 1;
            g.matrix[V2-1][V1-1] = 1;
            g.E++;
        }
        else
            break;
        printf("Enter two vertices which are adjacent to each other:\n");
    }
    scanf("%*c");
    printf("Enter a start vertex for DFS:\n");
    scanf("%d", &i);
    printGraphMatrix(g);
    DFS_I(g,i);

    return 0;
}

void DFS_I (Graph g, int v)
{
    Stack s; // initiate stack
    s.size = 0;
    s.head = NULL;

    int i;// loop counter
    int temp;// for peeking purposes, can be any variable name

    int *visitV; //initialize variable to keep track of visited vertices in DFS
    visitV = (int *) malloc(sizeof(int)*g.V); //make space
    for(i=0;i<g.V;i++)
        visitV[i] = 0; //all elements set as 0

    push(&s,v); //push the vertex into the stack
    visitV[v-1] = 1; //mark vertex as visited

    int unvisited; // no unvisited vertices flag
    while(isEmptyStack(s)==0){ //while not empty stack...
        temp = peek(s); //set w as whatever is in the top of stack s
        unvisited = 0; //no unvisited so far
        for(i=0;i<g.V;i++) //iterate through the vertices connected to vertex w
        {
            if(g.matrix[temp-1][i] == 1 && visitV[i]==0) //if a connected vertex is found and its not visited
            {
                push(&s,i+1); //push this unvisited vertex into stack
                visitV[i]=1; //mark as visited
                unvisited = 1; //found an unvisited
                break; //break out the loop
            }
        }

        if(unvisited==0){ //if no unvisited vertices are found,
           printf("%d ",w); //print value of w
           pop(&s); //and pop it from the stack
        }
    }

    free(visitV); //once stack empty, free memory of visitV
}

void printGraphMatrix(Graph g)
{
    int i,j;

    for(i=0;i<g.V;i++){
        for(j=0;j<g.V;j++)
            printf("%d\t",g.matrix[i][j]);
        printf("\n");
    }

}

void push(Stack *sPtr, int vertex)
{
	StackNode *newNode;
    newNode= malloc(sizeof(StackNode));
    newNode->vertex = vertex;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if(sPtr==NULL || sPtr->head==NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

int isEmptyStack(Stack s)
{
     if(s.size==0) return 1;
     else return 0;
}

int peek(Stack s){
    return s.head->vertex;
}

void removeAllItemsFromStack(Stack *sPtr)
{
	while(pop(sPtr));
}
