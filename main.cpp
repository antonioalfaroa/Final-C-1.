// staken.cpp
// overloading functions in base and derived classes
#include <iostream>
using namespace std;
#include <cstdlib> //for exit()

////////////////////////////////////////////////////////////////

class Stack{
  protected: //NOTE: can’t be private
    enum { MAX = 5 }; //size of stack array
    int st[MAX]; //stack: array of integers
    int top; //index to top of stack
  public:
    Stack() //constructor
    { top = -1; }
    void push(int var) //put number on stack
      { st[++top] = var; }
    int pop() //take number off stack
    { return st[top--]; }
};
////////////////////////////////////////////////////////////////
class Stack2 : public Stack
{
  public:
    void push(int var) //put number on stack
    {
      if(top >= MAX-1) //error if stack full
      { cout << "\nError: stack is full"; exit(1); }
      Stack::push(var); //call push() in Stack class
    }
    int pop() //take number off stack
    {
      if(top < 0) //error if stack empty
      { cout << "\nError: stack is empty\n"; exit(1); }
      return Stack::pop(); //call pop() in Stack class
    }
};



class pairStack : public Stack2{
public:
void push(pair <int,int> var){
  Stack2::push(var.first); Stack2::push(var.second);
}

pair <int,int> pop(){
  pair <int,int> new_val;
  new_val.first=Stack2::pop(); new_val.second =Stack2::pop();
  return new_val;
}


};

////////////////////////////////////////////////////////////////
int main(){
  pairStack pairS1;
  pair <int, int> pair1;

  pairS1.push(make_pair(9,8));
  cout<<"Pushing values"<<endl;
  pairS1.push(make_pair(3,7));
  cout<<"Pushing values"<<endl;
  pair1 = pairS1.pop();
  cout<<"Popping values"<<endl;
  pair1= pairS1.pop();
  cout<<"Popping one more"<<endl;
  cout<<"Everything is popped"<<endl;
  return 0;
}
