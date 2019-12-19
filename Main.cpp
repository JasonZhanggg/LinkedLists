/*
Jason Zhang
12/19/2019
Linked Lists
*/
#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"
using namespace std;
void print(Node*, Node*);
void printStudent(Student*);
void add(Student*, Node**);

int main(){
  //Declaring the head of the list
  Node* head;
  add(new Student("Jason", "Zhang", 12345, 5.5), &head);
  add(new Student("Gregory", "Feng", 23131, 5.5), &head);
  add(new Student("Bob", "Bob", 12312, 22.2), &head);
  print(head, head);
  add(new Student("Joe", "Joe", 12312, 2.2), &head);
  print(head, head);
}

void add(Student* newStudent, Node** head){
  //make a copy of head
  Node** current = head;
  //if the head is null, declare it
  if(*head == NULL){
    *head = new Node(newStudent);
    return;
  }
  //loop through the list until you reach the end
  while((*current)->getNext() != NULL){
    Node* temp = (*current)->getNext();
    current = &temp;
  }
  //add the new student at the end of the list
  (*current)->setNext(new Node(newStudent));
}
void print(Node* next, Node* head){
  //print List if it is the first iteration
  if(head == next){
    cout<<"List: "<<endl;
  }
  //otherwise
  if(next != NULL){
    //print the student
    printStudent(next->getStudent());
    //recall print with next student in list
    print(next->getNext(), head);
  }
}
//print student formating
void printStudent(Student* student){
  cout<<"Student: "<<student->getFirstName()<<" "<<student->getLastName()<< ", Id: "<<student->getId()<<", GPA: "<<student->getGpa()<<endl;
}

