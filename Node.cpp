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

//Constructor
Node::Node(Student* newStudent) {
  student = newStudent;
  next = NULL;
}
//set the student in the node
Student* Node:: getStudent(){
  return student;
}
//set the next node value
void Node::setNext(Node* newNext){
  next = newNext;
}
//get the next node value
Node* Node::getNext(){
  return next;
}
//the deconstructor
Node::~Node(){
  delete student;
  next = NULL;
}
