#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
  int data;
  struct node *next;
};

struct node *creatNode(int data)
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL)
  {
    printf("memory allocation failed\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void Display(struct node *head)
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  struct node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

struct node *insertAtFirst(struct node *head, int data)
{
  struct node *newNode = creatNode(data);
  newNode->next = head;
  return newNode;
}

struct node *insertAtLast(struct node *head, int data)
{
  struct node *newNode = creatNode(data);
  if (head == NULL)
  {
    return newNode;
  }
  printf("The data of the node inserted at last is: \n");
  struct node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}

struct node *insertAtIndex(struct node *head, int data, int index)
{
  if (index < 0)
  {
    printf("Invalid index\n");
    return head;
  }
  if (index == 0)
  {
    return insertAtFirst(head, data);
  }
  struct node *newnode = creatNode(data);
  if (newnode == NULL)
  {
    printf("Memory is not Allocated");
    return head;
  }
  struct node *temp = head;
  int i = 0;
  while (i != index - 1 && temp!=NULL)
  {
    temp = temp->next;
    i++;
  
  }
  if(temp==NULL){
    printf("Index is out of Bound!\n");
    free(newnode);
    return head;
  }
  newnode->next = temp->next;
  temp->next = newnode;
  return head;
}

void countNode(struct node *head)
{
  struct node *temp = head;
  int count = 0;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  printf("The numbers of node in the list is: %d\n", count);
}
struct node *deleteAtFirst(struct node *head)
{
  if (head == NULL)
  {
    printf("list is empty");
    return NULL;
  }
  struct node *temp = head;
  head = head->next;
  free(temp);
  return head;
}

struct node *deleteAtLast(struct node *head)
{
  if (head == NULL)
  {
    printf("List is empty");
    return NULL;
  }
  else if (head->next == NULL)
  {
    free(head);
    head = NULL;
  }
  else
  {
    struct node *prev = NULL;
    struct node *temp = head;
    while (temp->next != NULL)
    {
      prev = temp;
      temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
  }
  return head;
}

struct node *deleteAtIndex(struct node *head, int index)
{
  if (index < 0)
  {
    printf("Invalid index\n");
  }
  if (index == 0)
  {
    return deleteAtFirst(head);
  }
  struct node *temp = head;
  struct node *prev = NULL;
  int i = 0;
  while (i != index && temp != NULL)
  {
    prev = temp;
    temp = temp->next;
    i++;
  }
  if (temp == NULL)
  {
    printf("Index is outof BOUND");
    return head;
  }
  prev->next = temp->next;
  return head;
}
struct node *update(struct node *head, int data, int index)
{
  if (index < 0)
  {
    printf("Invalid index\n");
    return head;
  }

  struct node *temp = head;
  int i = 0;
  while (i != index)
  {
    temp = temp->next;
    i++;
  }
  temp->data = data;
  return head;
}

struct node *search_value(struct node *head, int value)
{
  struct node *temp = head;
  int i = 0;
  while (temp != NULL)
  {
    i++;
    if (temp->data == value)
    {
      printf("Value found at index %d ", i);
      return temp;
    }
    temp = temp->next;
  }
  printf("\nValue not found in the list\n");
  return NULL;
}

struct node *reverse_linkList(struct node *head)
{
  if (head == NULL)
  {
    printf("List is already empty! Nothing to reverse\n");
    return NULL;
  }
  struct node *current = head;
  struct node *next = NULL;
  struct node *prev = NULL;
  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

struct node *middle_Node(struct node *head)
{
  if (head == NULL)
  {
    printf("List is Empty\n");
    return NULL;
  }
  struct node *slow = head;
  struct node *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
bool cycleDetection(struct node *head)
{
  if (head == NULL)
  {
    printf("List is Empty\n");
    return true;
  }
  struct node *slow = head;
  struct node *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
    {
      break;
      return true;
    }
  }
  return false;
}
int main()
{
  int data, choice, index;
  struct node *head = NULL;
  do
  {
    printf("1)Display the data of the node\n");
    printf("2)InsertAtfirst\n");
    printf("3)InsertAt last\n");
    printf("4)InsertAt a specific position\n");
    printf("5)Number of nodes\n");
    printf("6)DeleteAtfirst\n");
    printf("7)DeleteAt a specific Index\n");
    printf("8)deleteAtEnd\n");
    printf("9)Updating the value\n");
    printf("10)Search value\n");
    printf("11)Reverse a LinkList\n");
    printf("12)MiddleNode of the List\n");
    printf("13)Cycle detection\n");
    printf("14)Exit from the programe\n");
    printf("Enter your choice: \n");
    scanf("%d", &choice);
    switch (choice)
    {

    case 1:
      printf("The node of the List are: ");
      Display(head);
      break;

    case 2:
      printf("\nenter your inserting data at First\n");
      scanf("%d", &data);
      head = insertAtFirst(head, data);
      printf("The List after inserting at first: ");
      Display(head);
      printf("\n------------------------------------------------------------\n");
      break;

    case 3:
      printf("enter your inserting data at Last\n");
      scanf("%d", &data);
      head = insertAtLast(head, data);
      printf("The List after inserting at Last: ");
      Display(head);
      printf("\n----------------------------------------\n");
      break;

    case 4:
      printf("enter your inserting data\n");
      scanf("%d", &data);
      printf("Enter your index of inserting\n");
      scanf("%d", &index);
      head = insertAtIndex(head, data, index);
      printf("The List after inserting at index: ");
      Display(head);
      printf("\n----------------------------------------\n");
      break;

    case 5:
      countNode(head);
      break;

    case 6:
      head = deleteAtFirst(head);
      printf("After deleting at first: ");
      Display(head);
      printf("\n=======================================================\n");
      break;
    case 7:
      printf("Enter your index of deleting\n");
      scanf("%d", &index);
      deleteAtIndex(head, index);
      printf("\nAfter deleting a node at index: ");
      Display(head);
      printf("\n=================================================\n");
      break;
    case 8:
      head = deleteAtLast(head);
      printf("After deleting a node at last, the list are: ");
      Display(head);
      printf("\n====================================================\n");
      break;
    case 9:
      printf("enter your inserting data\n");
      scanf("%d", &data);
      printf("Enter your index of inserting\n");
      scanf("%d", &index);
      head = update(head, data, index);
      printf("After updating the value\n");
      Display(head);
      printf("\n----------------------------------------\n");
      break;
    case 10:
      printf("Enter the value to search: ");
      scanf("%d", &data);
      struct node *result = search_value(head, data);
      if (result != NULL)
      {
        printf("\nAnd value %d found at node with address %p ", data, (void *)result);
      }
      /*If you return a pointer to the node, the caller can modify the node's data or traverse the list further using the next pointer.
      struct node* result = search_value(head, data);
      if (result != NULL) {
    result->data = 100; // Modify the data of the found node
       }*/
      printf("\n======================================================\n");
      break;
    case 11:
      head = reverse_linkList(head);
      printf("After reversing the list: ");
      Display(head);
      printf("\n===================================================\n");
      break;
    case 12:
    {
      struct node *middle = middle_Node(head);
      if (middle != NULL)
      {
        printf("The Middle node's data is %d: ", middle->data);
      }
    }
      printf("\n=============================================\n");
      break;
    case 13:
      if (cycleDetection(head))
      {
        printf("Cycle detected\n");
      }
      else
      {
        printf("No Cycle detected\n");
      }
      break;
    case 14:
      printf("exit from the program---------------------\n");
      break;
    default:
      printf("Invalid Choice\n");
    }

  } while (choice >= 1 && choice <= 14);

  return 0;
}
