#pragma once
#include <iostream>
#include <memory.h>
using namespace std;
class Stack
{
private:

	int size_m;
	int elem_m;
	int index_m;
	int step_m;
	int* pArr_m;

public:

	Stack();
	~Stack();
	Stack(const  Stack& copy_stack);
	Stack& operator = (const  Stack& copy_stack);
	void push(int elem);
	void expandStack(int size);
	int pop();
	bool isEmpty();
	void multiPop(int N);
	void show();

};