// Copyright 2021 Islam Osmanov
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<class T>
class MyStack {
private:
	T* database;
	int top;
	int size;

public:
	~MyStack() {
		delete[] database;
		this->top = 0;
		this->size = 0;
	}

	MyStack(int length) : top(0), size(length), database(new T[length]) {}

	MyStack(const MyStack& OtherStack) {
		database = new T[OtherStack.size];
		for (int n = 0; n < OtherStack.size; n++) {
			database[n] = OtherStack.database[n];
		}
		top = OtherStack.top;
		size = OtherStack.size;
	}

	bool isFull() const {
		if (size == top) {
			return true;
		}
		else {
			return false;
		}
	}

	T get() const {
		return database[top];
	}

	bool isEmpty() const {
		if (top <= 0) {
			return true;
		}
		else {
			return false;
		}
	}

	T pop() {
		top -= 1;
		int index = top + 1;
		return database[index];
	}

	void push(T th) {
		top += 1;
		database[top] = th;
	}
};

#endif  // INCLUDE_MYSTACK_H_