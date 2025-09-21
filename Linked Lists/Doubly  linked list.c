#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* ll;
  struct node* rl;
};

typedef struct node* NODE;
NODE start = NULL, temp, cur;

void insertb(int data) {
  temp = malloc(sizeof(struct node));
  temp->data = data;
  temp->ll = NULL;
  temp->rl = start;
  if (start != NULL) start->ll = temp;
  start = temp;
}

void inserte(int data) {
  cur = start;
  if (cur == NULL) {
    insertb(data);
  } else {
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->rl = NULL;
    while (cur->rl != NULL) {
      cur = cur->rl;
    }
    cur->rl = temp;
    temp->ll = cur;
  }
}

void insertm(int pos, int data) {
  if (pos <= 1 || start == NULL) {
    insertb(data);
    return;
  }
  cur = start;
  int i = 1;
  while (cur->rl != NULL && i < pos - 1) {
    cur = cur->rl;
    i++;
  }
  temp = malloc(sizeof(struct node));
  temp->data = data;
  temp->rl = cur->rl;
  temp->ll = cur;
  if (cur->rl != NULL) cur->rl->ll = temp;
  cur->rl = temp;
}

void deleteb() {
  if (start == NULL) {
    printf("List is empty!\n");
    return;
  }
  temp = start;
  start = start->rl;
  if (start != NULL) start->ll = NULL;
  free(temp);
}

void deletee() {
  if (start == NULL) {
    printf("List is empty!\n");
    return;
  }
  cur = start;
  while (cur->rl != NULL) {
    cur = cur->rl;
  }
  if (cur->ll != NULL)
    cur->ll->rl = NULL;
  else
    start = NULL;
  free(cur);
}

void deletem_pos(int pos) {
  if (start == NULL) {
    printf("List is empty!\n");
    return;
  }
  cur = start;
  int i = 1;
  while (cur != NULL && i < pos) {
    cur = cur->rl;
    i++;
  }
  if (cur == NULL) {
    printf("Invalid position!\n");
    return;
  }
  if (cur->ll != NULL)
    cur->ll->rl = cur->rl;
  else
    start = cur->rl;
  if (cur->rl != NULL) cur->rl->ll = cur->ll;
  free(cur);
}

void deletem_val(int val) {
  cur = start;
  while (cur != NULL && cur->data != val) {
    cur = cur->rl;
  }
  if (cur == NULL) {
    printf("Value not found!\n");
    return;
  }
  if (cur->ll != NULL)
    cur->ll->rl = cur->rl;
  else
    start = cur->rl;
  if (cur->rl != NULL) cur->rl->ll = cur->ll;
  free(cur);
}

void display() {
  cur = start;
  if (cur == NULL) {
    printf("List is empty!\n");
    return;
  }
  printf("List: ");
  while (cur != NULL) {
    printf("%d <-> ", cur->data);
    cur = cur->rl;
  }
  printf("NULL\n");
}

int main() {
  int choice, data, pos;
  while (1) {
    printf("\nDoubly Linked List Operations:\n");
    printf("1. Insert at start\n2. Insert at end\n3. Insert at middle\n");
    printf("4. Delete at start\n5. Delete at end\n6. Delete nth Node\n");
    printf("7. Delete by value\n8. Display\n9. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data: ");
        scanf("%d", &data);
        insertb(data);
        break;
      case 2:
        printf("Enter data: ");
        scanf("%d", &data);
        inserte(data);
        break;
      case 3:
        printf("Enter position: ");
        scanf("%d", &pos);
        printf("Enter data: ");
        scanf("%d", &data);
        insertm(pos, data);
        break;
      case 4:
        deleteb();
        break;
      case 5:
        deletee();
        break;
      case 6:
        printf("Enter position: ");
        scanf("%d", &pos);
        deletem_pos(pos);
        break;
      case 7:
        printf("Enter value: ");
        scanf("%d", &data);
        deletem_val(data);
        break;
      case 8:
        display();
        break;
      case 9:
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }
  return 0;
}
