#include<iostream>
#include"shared_ptr.h"
using namespace std;

int main() {
	int a = 1;
	int* ptrA = new int(a);
	sharedPtr<int> ptr1(ptrA);
	sharedPtr<int> ptr2(ptr1);
	sharedPtr<int> ptr3;
	ptr3 = ptr2;
	cout << ptr1.getCount();
}