#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <vector>

using namespace std;

struct student{
  char fname[20];
  char lname[20];
  int id;
  float gpa;
};
void delt(vector<student*> &data);
void add(vector<student*> &data);
void print(vector<student*> data);
int main(){
  //a while loop thingy variable
  bool kg = true;
  //vector
  vector<student*> list; 
  char input[10];
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
      cout << "bye" << endl;
      kg = false;
    }
  }
}
void add(vector<student*> &data){
  char fname[20];
  char lname[20];
  int id;
  float gpa;
  student *name = new student();
  cout << "input stuff!" << endl;
  cin >> name->fname;
  cin >> name->lname;
  cin >> id;
  cin >> gpa;
  //name->fname = fname;
  //name->lname = lname;
  name->id = id;
  name->gpa = gpa;
  data.push_back(name);
}
void print(vector<student*> data){
  int size = data.size();
  for(int i = 0;i < size;i++){
    cout << data[i]->fname << "," << data[i]->lname << "," << data[i]->id << "," << data[i]->gpa << endl;
  }
  //cout << data[0]->fname << endl;
  
}
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