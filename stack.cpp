#include "stack.h"
Stack& Stack :: operator = (const Stack& copy_stack)
{
	if (this == &copy_stack)
	{
		return *this;
	}
	index_m = copy_stack.index_m;
	size_m = copy_stack.size_m;
	elem_m = copy_stack.elem_m;
	step_m = copy_stack.step_m;
	delete[] pArr_m;
	pArr_m = new int[size_m];
	memcpy(pArr_m, copy_stack.pArr_m, sizeof(int) * size_m);
	return *this;

}
void Stack::expandStack(int size)
{
	int* new_arr = new int[size];
	step_m = (size_m > size) ? (size_m - size) : (size - size_m);
	if (size >= size_m)
	{

		copy(pArr_m, (pArr_m + size_m), new_arr);

	}
	else
	{


		for (int i = 0; i < size; i++)
		{
			new_arr[i] = pArr_m[i];
		}

	}
	delete[] pArr_m;
	pArr_m = new_arr;
	size_m = size;

}
Stack::Stack()
{
	size_m = 0;
	index_m = 0;
	pArr_m = nullptr;
	step_m = 0;
	elem_m = 0;
}
Stack :: ~Stack()
{
	delete[] pArr_m;
}
Stack::Stack(const Stack& copy_stack) : index_m(copy_stack.index_m), size_m(copy_stack.size_m), elem_m(copy_stack.elem_m), step_m(copy_stack.step_m)
{

	if (copy_stack.pArr_m != nullptr)
	{
		pArr_m = new int[size_m];
		memcpy(pArr_m, copy_stack.pArr_m, sizeof(int) * size_m);
	}


}
void Stack::push(int elem)
{
	if (size_m == 0 && pArr_m == nullptr)
	{
		int temp = size_m + 1;
		expandStack(temp);

		index_m += step_m;
		elem_m += step_m;
		pArr_m[index_m - 1] = elem;
	}
	else
	{
		if ((elem_m + 1) > size_m)
		{
			int temp = elem_m + 1;
			expandStack(temp);
			index_m += step_m;
			elem_m += step_m;
			pArr_m[index_m - 1] = elem;

		}

	}
}
int Stack::pop()
{


	int temp = pArr_m[index_m - 1];
	expandStack(size_m - 1);
	index_m--;
	elem_m--;
	return temp;
}
bool Stack::isEmpty()
{

	return (index_m > 0) ? false : true;
}
void Stack::multiPop(int N)
{
	expandStack(size_m - N);
	index_m -= N;
	elem_m -= N;


}
void Stack::show()
{
	for (int i = 0; i < size_m; i++)
	{
		cout << pArr_m[i];
		if ((i + 1) < size_m)
		{
			cout << " ";
		}

	}
	cout << endl;

}