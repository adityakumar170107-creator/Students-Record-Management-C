#include<stdio.h>
#include<stdlib.h>

struct student{
  char name[50];
  int roll;
  double CGPA;
  struct student *next;
};
struct student *head=NULL;
void  addStudent(struct student* s1);
void delStudent(int r);
void searStudent(int r);
void dispStudent();

int main(){
  while(1){
    printf("\nEnter 1 to add a student.\n");
    printf("Enter 2 to Delete a student's record.\n");
    printf("Enter 3 to search student's record.\n");
    printf("Enter 4 to display all students.\n");
    printf("Enter 5 to exit.\n");
    printf("Enter: ");
    int c;
    scanf("%d",&c);
    if(c==1){
      struct student* s1 = (struct student*)malloc(sizeof(struct student));
      printf("Enter student's name: ");
      scanf(" %49[^\n]", s1->name);
      printf("Enter the roll no. of the student: ");
      scanf("%d",&s1->roll);
      printf("Enter the CGPA of the student: ");
      scanf("%lf",&s1->CGPA);
      addStudent(s1);
      // free(s1);
      printf("\nStudent added successfully!\n");
    }
    else if(c==2){
      int rol;
      if(head){
        printf("\nEnter the roll no. of the student: ");
        scanf("%d",&rol);
        delStudent(rol);
      }
      else{
        printf("\nNothing to delete, record is empty\n");
      }
    }
    else if(c==3){
      if(head){
        int rol;
        printf("\nEnter the roll no. of the student: ");
        scanf("%d",&rol);
        searStudent(rol);
      }
      else{
        printf("\nNothing to search, record is empty\n");
      }
    }
    else if(c==4){
      if(head){
        dispStudent();
      }
      else{
        printf("\nNothing to display, record is empty\n");
      }
    }
    else{
      break;
    }
  }
  return 0;
}

void  addStudent(struct student* s1){
  if(!head){
    head = s1;
    head->next = NULL;
  }
  else{
    struct student* temp = head;
    while(temp->next){
      temp = temp->next;
    }
    temp->next = s1;
    temp->next->next = NULL;
  }
}


void delStudent(int r){
  struct student* temp = head;
  if(!temp->next){
    if(temp->roll==r){
      head = NULL;
      free(temp);
      printf("\nStudent removed successfully!\n");
    }
    else{
      printf("\nNo student found with this roll No.\n");
    }
  }
  else{
    while(temp->next && (temp->next->roll != r)){
      temp = temp->next;
    }
    if(temp->next && temp->next->roll==r){
      struct student* s2 = temp->next;
      temp->next = s2->next;
      free(s2);
      printf("\nStudent removed successfully!\n");
    }
    else{
      printf("\nNo student found with this roll No.\n");
    }
  }
}


void searStudent(int r){
  struct student* temp = head;
    while(temp && (temp->roll != r)){
      temp = temp->next;
    }
    if(temp && temp->roll==r){
      printf("\nThe name of the student is: %s\n",temp->name);
      printf("The roll no. of the student is: %d\n",temp->roll);
      printf("The CGPA of the student is: %f\n\n",temp->CGPA);
    }
    else{
      printf("\nNo student found with this roll No.\n");
    }
}


void dispStudent(){
  struct student* s2 = head;
  while(s2){
    printf("\nName:\t\t%s\n",s2->name);
    printf("Roll no.:\t%d\n",s2->roll);
    printf("CGPA:\t\t%.2f\n",s2->CGPA);
    s2 = s2->next;
  }
}