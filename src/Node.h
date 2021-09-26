#pragma once

#include <iostream>

template <class T>
class Node {
protected:
	T data;
	Node* nextNode;
	Node* prevNode;
public:

	Node<T>() : prevNode(nullptr), nextNode(nullptr), data(NULL) {};
	Node<T>(T initData) :prevNode(nullptr), nextNode(nullptr), data(initData) {};
	~Node() {};

	T getData();
	void setData(T newData);

	Node<T>* getNextNode();
	void setNextNode(Node<T>* newNextNode);

	Node<T>* getPrevNode();
	void setPrevNode(Node<T>* newPrevNode);
};

template <class T>
T Node<T>::getData() {
	return data;
}

template <class T>
void Node<T>::setData(T newData) {
	data = newData;
}

template <class T>
Node<T>* Node<T>::getNextNode() {
	return nextNode;
};

template <class T>
void Node<T>::setNextNode(Node<T>* newNextNode) {
	nextNode = newNextNode;
}

template <class T>
Node<T>* Node<T>::getPrevNode() {
	return prevNode;
}


template <class T>
void Node<T>::setPrevNode(Node<T>* newPrevNode) {
	prevNode = newPrevNode;
}