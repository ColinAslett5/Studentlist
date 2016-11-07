// Colin Aslett, C++, Period 07
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <vector>

using namespace std;
//the structure
struct student{
  char fname[20];
  char lname[20];
  int id;
  float gpa;
};
//three methods
void delt(vector<student*> &data);
void add(vector<student*> &data);
void print(vector<student*> data);
int main(){
  cout.setf(ios::fixed,ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(2);
  //a while loop thingy variable
  bool kg = true;
  //vector
  vector<student*> list; 
  char input[10];
  //taking the input the user gives
  while(kg == true){
    cout << "Input a command,(add,print,delete,quit)" << endl;
    cin >> input;
    if(strcmp(input,"add") == 0){
      add(list);
    }
    if(strcmp(input,"print") == 0){
      print(list);
    }
    if(strcmp(input,"delete") == 0){
      delt(list);
    }
    if(strcmp(input,"quit") == 0){
      cout << "Goodbye" << endl;
      kg = false;
    }
  }
}
//adds the student's name, id , and gpa
void add(vector<student*> &data){
  char fname[20];
  char lname[20];
  int id;
  float gpa;
  student *name = new student();
  cout << "Input information: first name, last name , id, gpa" << endl;
  cin >> name->fname;
  cin >> name->lname;
  cin >> id;
  cin >> gpa;
  name->id = id;
  name->gpa = gpa;
  data.push_back(name);
}
//prints all of the data in the student vector
void print(vector<student*> data){
  int size = data.size();
  //cout.precision(3);
  for(int i = 0;i < size;i++){
    cout << data[i]->fname << "," << data[i]->lname << "," << data[i]->id << "," << data[i]->gpa << endl;
  }
  if(size == 0){
    cout << "No items!" << endl;
  }
  
}
//deleting the students name,id,gpa based on the id number given
void delt(vector<student*> &data){
  cout << "insert id number" << endl;
  int size = data.size();
  int number;
  cin >> number;
  for(vector<student*>::iterator i = data.begin();i != data.end();i++){
    if((*i)->id == number){
      data.erase(i);
      //exit the for loop
      break;
    }
  }
}
