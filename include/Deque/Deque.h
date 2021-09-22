#pragma once

#include <iostream>
#include "Node.h"

template <class T>
class Deque {
protected:
	Node<T>* front;
	Node<T>* back;
public:
	Deque<T>() :front(nullptr), back(nullptr) {};
	~Deque() {};

	void pushBack(T newValue);
	void pushFront(T newValue);

	T popBack();
	T popFront();

	T getBack();
	T getFront();
};

template<class T>
void Deque<T>::pushBack(T newValue) {
	if ((back == front) && (back == nullptr)) {
		back = new Node<T>(newValue);
		front = back;
	}
	else {
		Node<T>* newBack = new Node<T>(newValue);
		newBack->setPrevNode(back);
		back->setNextNode(newBack);
		back = back->getNextNode();
	}
}


template<class T>
inline void Deque<T>::pushFront(T newValue) {
	if ((back == front) && (back == nullptr)) {
		front = new Node<T>(newValue);
		back = front;
	}
	else
	{
		Node<T>* newFront = new Node<T>(newValue);
		newFront->setNextNode(front);
		front->setPrevNode(newFront);
		front = front->getPrevNode();
	}
}

template<class T>
T Deque<T>::popBack() {

	if (back == nullptr) {
		return NULL;
	}

	T data = back->getData();

	if (front == back) {
		Node<T>* nodeToDelete = back;
		back = front = nullptr;
		delete nodeToDelete;
	}
	else {
		back = back->getPrevNode();
		delete back->getNextNode();
		back->setNextNode(nullptr);
	}

	return data;
}

template<class T>
T Deque<T>::popFront() {

	if (front == nullptr) {
		return NULL;
	}

	T data = front->getData();

	if (back == front) {
		Node<T>* nodeToDelete = front;
		back = front = nullptr;
		delete nodeToDelete;
	}
	else {
		front = front->getNextNode();
		delete front->getPrevNode();
		front->setPrevNode(nullptr);
	}

	return data;
}

template<class T>
T Deque<T>::getBack() {
	if (back == nullptr) {
		return NULL;
	}
	return back->getData();
}

template<class T>
T Deque<T>::getFront() {
	if (front == nullptr) {
		return NULL;
	}
	return front->getData();
}
