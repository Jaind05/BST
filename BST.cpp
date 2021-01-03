// Dhruv Jain
// 12/6/20
// Binary tree




#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <stdlib.h>



using namespace std;

struct node{
  int value;
  node *left;
  node *right;
};



void printnodes(node* ,int);
void addnode(node*, int);
node* deleter(node*, int);

int main(){
  node *head = NULL;
  cout << "would you like to read in from a file?" << endl;
  char file[30];
  cin >> file;
  
  if(strcmp(file, "yes") == 0){
    srand (time(NULL));
    cout << "How many nodes would you like?" << endl;
    int numberofstudents = 0;
    cin >> numberofstudents;
    
    streampos size;
    char * memblock;
    char * pch;
    int filereads[100];
    ifstream file ("example.txt", ios::in|ios::binary|ios::ate);
    if (file.is_open())
      {
	size = file.tellg();
	memblock = new char [size];
	file.seekg (0, ios::beg);
	file.read (memblock, size);
	file.close();
	
	//  cout << "the entire file content is in memory" << endl;
      }
    pch = strtok (memblock," ,.-");
    int i = 0;
    while (pch != NULL)
      {
	//cout << pch << endl;
	filereads[i] = atoi(pch);
	pch = strtok (NULL, " ,.-");
	//cout << filereads[i] << endl;
	i++;
      }
    //cout << firstname[numberofstudents] << endl;
    delete[] memblock;
    
    head = new node;
    head->value = filereads[0];
    head->left = NULL;
    head->right = NULL;
    
    for (int i = 1; i < numberofstudents; i++){
      if(filereads[i]!=0){
	cout << filereads[i] << endl;
	addnode(head, filereads[i]);
      }
    }
  }
  
  
  
  
  
  char input[30];
  bool stillrunning = true;
  while (stillrunning){
    if(head == NULL){
      cout << "what value would you like to give to the first node" << endl;
      head = new node;
      cin >> head->value;
      head->left = NULL;
      head->right = NULL;
    }
    cout << "would you like to add, print, delete, or quit" << endl;
    cin >> input;
    if(strcmp(input, "add") == 0){
      int temp = 0;
      cout << "What value would you like to put in your new node?" << endl;
      cin >> temp;
      addnode(head, temp);
    }
    else if(strcmp(input, "print") == 0){
      printnodes(head, 0);
    }
    else if(strcmp(input, "delete") == 0){
      int temp = 0;
      cout << "What is the value of the node you would like to delete" << endl; 
      cin >> temp;
      deleter(head, temp);
    }
    else if(strcmp(input, "quit") == 0){
      stillrunning = false;
    }
  }
}

void printnodes(node *head, int count){
  if(head==NULL){
    return;
  }
  
  count += 7;
  printnodes(head->right, count);
  cout << endl;
  for (int i = 7; i < count; i++){
  cout << "  ";
  }
  cout << head->value << endl;
  printnodes(head->left, count);
}

void addnode(node *head, int value){
  if((head->left!=NULL)&&(head->value > value)){
    addnode(head->left, value);
  }
  else if((head->right!=NULL)&&(head->value <= value)){
    addnode(head->right, value);
  }
  
  if((head->left == NULL)&&(head->value > value)){
    cout << "adding new node on the left"<< endl;
    node *temp = new node;
    head->left = temp;
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL; 
  }
  if((head->right==NULL)&&(head->value <= value)){
    cout << "adding new node on the right"<< endl;
    node *temp = new node;
    head->right = temp;
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
  }
  return;
}

node* deleter(node *head, int value){
  node *temp;
  if((head->left == NULL)&&(head->right == NULL)){
    delete head;
    return NULL;
  }

  
  if(value < head->value){
    head->left = deleter(head->left, value);
  }
  else if(value > head->value){
    head->right = deleter(head->right, value);
  }
  else {
    if(head->left != NULL){
      bool found = false;
      temp = head->left;
      while (found == false){
	if((temp->left == NULL)&&(temp->right == NULL)){
	  found = true;
	}
	else{
	  temp = temp->right;
	}
      }
      head->value = temp->value;
      head->left = deleter(head->left, temp->value); 
    }
    else{
      bool found = false;
      temp = head->right;
      while (found == false){
        if((temp->left == NULL)&&(temp->right == NULL)){
          found = true;
        }
        else{
          temp = temp->left;
        }
      }
      head->value = temp->value;
      head->right = deleter(head->right, temp->value);
    }
  }
  return head;
}



