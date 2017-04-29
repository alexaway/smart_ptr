#include <iostream>
#include "smart_ptr.h"
#include "shared_ptr.h"

struct A
{
  ~A(){
    cout << boost::typeindex::type_id<decltype(*this)>().pretty_name() << endl;
    cout<<"~A(){}"<<endl;
  }
  int i;
  float f;
};
struct B: public A
{
  ~B(){
    cout << boost::typeindex::type_id<decltype(*this)>().pretty_name() << endl;
    cout<<"~B(){}"<<endl;
  }
  double d;
};


int main() {
  A *a=new A();
  a->f =10.2;
  a->i =521;

  B * b = new B();
  b->f=100.0;
  b->i = 50;
  b->d = 123.321;
  B * b1 = new B();
  b->f=100.0;
  b->i = 50;
  b->d = 123.321;

  shared_ptr<B> sp1(b);
  shared_ptr<B> sp2(b1);
  cout<<"before: "<<sp1.get_count()<<" "<<sp2.get_count()<<endl;
  sp1 = sp2;
  cout<<"after: "<<sp1.get_count()<<" "<<sp2.get_count()<<endl;

  return 0;
}