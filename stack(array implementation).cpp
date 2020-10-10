#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template<typename T>
class Stack
{
	/*
	Realization of stack using array, also we use resize function for resizing
	the size of our stack when there are not enough space to place pushing element.
	That's only the difference with stack using linked list.
	*/

private:
	T* dataP;
	unsigned int top;
	unsigned int size;
	T* resizestack();
public:
	void push(T sourcetoP);
	bool isEmpty();
	T pop();
	T gettop();

	Stack()
	{
		size = 5;
		dataP = (T*)malloc(sizeof(T) * size);
		top = 0;
	}

	Stack(unsigned int size)
	{
		this->size = size;
		dataP = (T*)malloc(sizeof(T) * this->size);
		top = 0;
	}

	~Stack()
	{
		free(dataP);
		dataP = nullptr;
	}

};

template<typename T>
bool Stack<T>::isEmpty()
{
	if (top <= 0) return true;
	return false;
}

template<typename T>
T Stack<T>::gettop()
{
	if (!isEmpty()) return *(dataP + top - 1);
	else
	{
		cout << "error: stack is empty!\n";
		exit(1);
	}
}

template<typename T>
void Stack<T>::push(T sourcetoP)
{
	if (top == size) { dataP = resizestack(); }
	*(dataP + top++) = sourcetoP;
}

template<typename T>
T Stack<T>::pop()
{
	if(isEmpty()) 
	{
		cout << "error: stack underflow!\n";
		exit(1);
	}
	return *(dataP + -1 + top--);
}

template<typename T>
T* Stack<T>::resizestack()
{
	T* tempP = (T*)malloc(sizeof(T) * size * 2);
	for (int i = 0; i < (int)size; ++i)
		*(tempP + i) = *(dataP + i);
	size *= 2;
	free(dataP);
	return tempP;
}


int main()
{
	Stack<int> test;

	int i = 5;
	while (i)
	{
		test.push(i * 2);
		--i;
	}

	while (!test.isEmpty())
	{
		cout << test.gettop() << " ";
		test.pop();
	}
	cout << endl;


	Stack<char> test_2(15);
	i = 15;
	while (i)
	{
		test_2.push('a' + i);
		--i;
	}

	while (!test_2.isEmpty())
	{
		cout << test_2.gettop() << " ";
		test_2.pop();
	}
	cout << endl;

	Stack<float> test_3(8);
	i = 8;
	while (i)
	{
		test_3.push(i * 0.1);
		--i;
	}

	while (!test_3.isEmpty())
	{
		cout << test_3.pop() << " ";
	}
	cout << endl;

	return 0;
}