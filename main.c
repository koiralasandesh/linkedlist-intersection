#include <stdio.h>
#include <stdlib.h>


struct Node
{
  int data;
  struct Node* next;
};


int main()
{
  /*
    Create two linked lists

    1st 3->6->9->15->30
    2nd 10->15->30

    15 is the intersection point
  */

  struct Node* newNode;
  struct Node* head1 =(struct Node*) malloc(sizeof(struct Node));
  head1->data  = 10;

  struct Node* head2 =
            (struct Node*) malloc(sizeof(struct Node));
  head2->data  = 3;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 6;
  head2->next = newNode;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 30;
  head1->next->next= newNode;

  head1->next->next->next = NULL;

  printf("\n The node of intersection is %d \n",
          getIntersectionNode(head1, head2));

  getchar();
}


int getIntersectionNode(struct Node* head1,struct Node* head2){
struct Node* current1=head1;
struct Node* current2= head2;
int count1, count2,nodeDiff,i;
count1=count2=0;

while(current1!=NULL){
    count1++;
    current1=current1->next;
}
while(current2!=NULL){
    count2++;
    current2=current2->next;
}
current1=head1;
current2=head2;
if(count1>count2){
    nodeDiff=count1-count2;
    for(i=0;i<nodeDiff;i++){
        current1=current1->next;
    }
}
else{
    nodeDiff=count2-count1;
    for(i=0;i<nodeDiff;i++){
        current2=current2->next;
    }
}

while(current1!=NULL && current2!=NULL){
    if(current1==current2){
        return (current1->data);
    }
    current1=current1->next;
    current2=current2->next;
}





}
