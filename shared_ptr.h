//
// Created by alexaway on 4/29/17.
//

#ifndef SMART_PTR_SHARED_PTR_H
#define SMART_PTR_SHARED_PTR_H
#include <iostream>
#include <typeinfo>
#include <boost/type_index.hpp>
using namespace std;

template<class T>
class shared_ptr {
public:
  shared_ptr(T* ptr):pointee(ptr){
    cout<<" shared_ptr::shared_ptr()"<<endl;
    count = new int(1);
  }
  template <class U>
  shared_ptr(const shared_ptr<U> & ptr)
  {
    if(pointee != 0){
      --*count;
      if(*count == 0){
        delete pointee;
        delete count;
      }
    }
    pointee = ptr.pointee;
    count = ptr.count;
    ++*count;
  }
  ~shared_ptr(){
    cout<<" ~shared_ptr::shared_ptr()"<<endl;
    --(*count);
    if(*count == 0){
      delete pointee;
      delete count;
    }

  }
  int get_count(){return *count;}

  T &operator *();
  T *operator ->();
  template<class U>
  shared_ptr<T>& operator =(shared_ptr<U> &sp);

  template <class U>
  friend class shared_ptr;
private:
  T * pointee;
   int *count;

};

template <class T>
T& shared_ptr<T>::operator*() {
  cout<<" shared_ptr::operator*()"<<endl;
  return *pointee;
}
template <class T>
T* shared_ptr<T>::operator->() {
  cout<<" shared_ptr::operator->()"<<endl;
  return pointee;
}
template<class T>
template <class U>
shared_ptr<T>& shared_ptr<T>::operator =(shared_ptr<U> &sp)
{
  cout<<"shared_ptr::operator =(smart_ptr<T> &sp)"<<endl;
  ++(*sp.count);
  --(*count);
  if(*count ==0){
    delete pointee;
    delete count;
  }
  pointee = sp.pointee;
  count = sp.count;
  return *this;
}


#endif //SMART_PTR_SHARED_PTR_H
