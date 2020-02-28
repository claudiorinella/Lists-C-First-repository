#include <stdio.h>
#include <stdlib.h>

#if !defined TRUE && !defined FALSE
#define TRUE 1
#define FALSE 0
#endif

typedef int Boolean;

#ifndef NULL
#define NULL ((void *)0)
#endif

struct list {
  int value;
  struct list *next;
};


/*Definitions and descriptions of the functions at line 200*/

/*Declare Functions*/

void suf_insert(struct list **doubleptr, int val);

void init(struct list **ptrptr);

void pre_add_node(struct list **doubleptr, int valore);

void init_root_node(struct list **head, int value);

struct list **positive_mtr(int *A, int r, int c); 

int *diag_matrix(struct list *point); 

int lenght(struct list *pointer);


/*==================MAIN==========*/

int main() {

  struct list **doppiopunt;
  struct list *punt;
  doppiopunt = &punt;
  init(&punt);
  int i;

  int na;
  int *Ta;
  Boolean exit= FALSE;

  do{

	  printf("\nIt is possible to create a list. How many nodes are required in this list? Enter a number\n");
	  scanf("\n%d", &na);


	  if (na>0 && na<100){
		  Ta=calloc(na, sizeof(int));
		  printf ("\n Enter %d numbers", na);
	  	  	  for (i=0; i<na;i++){
	  	  		  scanf("\n%d", &Ta[i]);
	  	  		  suf_insert (doppiopunt, Ta[i]);

	  	  	  }
	  	  	  free(Ta);
	  	  	  exit=TRUE;
	  }
	  else
		  printf("\n Enter a numeric value (positive and smaller than 100) \n\n");

  }
	  while (exit==FALSE);

  exit=FALSE;

  struct list *temp;
  temp=punt;

  for (i=0;i<na;i++) {
    printf("\n the value of the node number %d of the list is %d\n",i+1, temp->value);
    temp = temp->next;
  }
  free(temp);

  int j;
  char choose;
  int *D;


  do {
    printf("\n\n\n\n It is possible to create a new diagonal matrix with the "
           "values of the list\n\n");
    printf("\n\nDo the user want to do this? Enter 'y' or 'n' \n\n");
    scanf("%s", &choose);

    switch (choose) {

    case 'y':
      D = diag_matrix(punt);
      int leng;
      leng = lenght(punt);
      printf("\n\n The matrix has been created!\n\n");

      for (i = 0; i < leng; i++) {
        for (j = 0; j < leng; j++) {
          printf("\n the element at row |%d| and column |%d| is %d\n",
                 i + 1, j + 1, D[i * leng + j]);
        }
      }
      exit = TRUE;
      choose = 0;
      break;

    case 'n':
      printf("\n\n Let's move on\n\n");
      exit = TRUE;
      choose = 0;
      break;

    default:
      printf("\n\nThe user should had entered 'y' or 'n'\n\n");
      choose = 0;
      break;
    }
  }

  while (exit == FALSE);

  free(D);
  free(punt);

  exit = FALSE;
  int n;

  do {
    printf("\n\n\n\n\n Now the user can create another quadratic matrix\n\n");
    printf("\n\n After that,  a list which contains the values of the matrix "
           "greater than zero will be created\n\n");
    printf("\n\n Does the user want to take this action? Enter 'y' or 'n'");
    scanf("%s", &choose);

    switch (choose) {

    case 'y':
      printf("\n\nenter the number of arrows (or columns)\n\n");
      scanf("%d", &n);

      int *B;
      B = (int *)calloc(n * n, sizeof(int));
      int val;
      printf("\n\n A matrix %d * %d has been created \n\n", n, n);

      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          printf("\n\n which values do you want to put in the position |%d| "
                 "|%d| ? \n\n",
                 i + 1, j + 1);
          scanf("%d", &val);
          B[i * n + j] = val;
        }
      }

      struct list *ptr;
      init(&ptr);
      ptr = *positive_mtr(B, n, n);
      printf("\n\n The list formed by the values of the matrix greater than "
             "zero has been created \n\n");

      while (ptr != NULL) {
        printf("\n\n one of the values of the list is %d\n\n", ptr->value);
        ptr = ptr->next;
      }

      exit = TRUE;
      choose = 0;
      free(ptr);
      free(B);
      break;

    case 'n':
      printf("\n\nLet's move on\n\n");
      exit = TRUE;
      choose = 0;
      break;

    default:
      printf("\n\nThe user should had entered 'y' or 'n'\n\n");
      choose = 0;
      break;
    }
  } while (exit == FALSE);

  printf("All the possible action have been taken! Goodbye");

  return 0;
}

/*==========================Definitions===================*/

/*positive_mtr
 * Let's consider a matrix composed by positive integers
 * This function will create a list containing all the values
 * of the matrix greater than zero*/
 
struct list **positive_mtr(int *A, int r, int c) {
  struct list **doub;
  struct list *point;
  doub = &point;
  init(doub);
  int i, j, value;

  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      if (A[i * c + j] > 0) {
        value = A[i * c + j];
        suf_insert(doub, value);
      }
    }
  }
  return doub;
}

/* diag_matrix
* Let's consider a list of unknown lenght, 
* This function will create a diagonal matrix containing 
* the numbers of the list */

int *diag_matrix(struct list *point) {
  int *A;
  int n;
  n = lenght(point);
  A = (int *)calloc(n * n, sizeof(int));
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        A[i * n + j] = point->value;
        point = point->next;
      } else
        A[i * n + j] = 0;
    }
  }
  return A;
}



int lenght(struct list *pointer) {
  int m = 0;
  while (pointer != NULL) {
    m++;
    pointer = pointer->next;
  }

  return m;
}

void init_root_node(struct list **head, int value) {

  *head = malloc(sizeof(struct list));
  (*head)->value = value;
  (*head)->next = NULL;
}

void init(struct list **ptrptr) { *ptrptr = NULL; }




 /*suf_insert
  Inserting a node at the end of a list */


void suf_insert(struct list **doubleptr, int val) { 
  if (*doubleptr != NULL) {
   
    while ((*doubleptr)->next != NULL) {
     
      doubleptr = &((*doubleptr)->next);

    }
    (*doubleptr)->next = (struct list *)malloc(sizeof(struct list));
    

    ((*doubleptr)->next)->value = val;
    ((*doubleptr)->next)->next = NULL;
  } else {

    init_root_node(doubleptr, val);
  }
}




 /*pre_add_node
  Inserting a node at the top of a list */


void pre_add_node(struct list **doubleptr, int valore) {

  struct list *temporary; 
  temporary = *doubleptr;
 
  *doubleptr = (struct list *)malloc(sizeof(struct list));
  
  (*doubleptr)->value = valore; 
  (*doubleptr)->next = temporary;
  
}




