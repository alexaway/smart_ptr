//
// Created by alexaway on 4/29/17.
//

#ifndef SMART_PTR_SMART_PTR_H
#define SMART_PTR_SMART_PTR_H
#include <iostream>
#include <typeinfo>
#include <boost/type_index.hpp>
using namespace std;

template<class T>
class smart_ptr {
public:
  smart_ptr(T* ptr=0,string name="");
  ~smart_ptr();
  template<class U>
  smart_ptr(smart_ptr<U> &&ptr){
    pointee = ptr.pointee;
    ptr.pointee = 0;
  }

  T &operator *();
  T *operator ->();
  template<class U>
  smart_ptr<T>& operator =(smart_ptr<U> &&sp);

  /*template<class U>
  operator smart_ptr<U>(){
    cout<<"smart_ptr::smart_ptr<U>()"<<endl;
    return smart_ptr<U>(pointee);
  }*/

  template <class U>
  friend class smart_ptr;
private:
  T *pointee;
  string _name;

};

template <class T>
smart_ptr<T>::smart_ptr(T *ptr,string name) :pointee(ptr),_name(name) {
  cout << typeid(*this).name() << endl;
  cout << boost::typeindex::type_id<decltype(*this)>().pretty_name() << endl;
  cout<<_name<<" smart_ptr::smart_ptr()"<<endl;
}
template <class T>
smart_ptr<T>::~smart_ptr() {
  cout<<_name<<" smart_ptr::~smart_ptr()"<<endl;
  delete pointee;
}
template <class T>
T& smart_ptr<T>::operator*() {
  cout<<_name<<" smart_ptr::operator*()"<<endl;
  return *pointee;
}
template <class T>
T* smart_ptr<T>::operator->() {
  cout<<_name<<" smart_ptr::operator->()"<<endl;
  return pointee;
}

template<class T>
template <class U>
smart_ptr<T>& smart_ptr<T>::operator =(smart_ptr<U> &&sp)
{
  cout<<"smart_ptr::operator =(smart_ptr<T> &sp)"<<endl;
  if(pointee == sp.pointee)
    return *this;
  delete pointee;
  pointee = sp.pointee;
  sp.pointee = nullptr;
  return *this;
}


#endif //SMART_PTR_SMART_PTR_H
