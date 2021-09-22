#include <gtest/gtest.h>
#include<iostream>
#include <Node.h>
#include <Deque/Deque.h>

TEST(NodeData, setGetData) {
	Node<int> firstNode(5);
	EXPECT_EQ(firstNode.getData(), 5);
	EXPECT_EQ(firstNode.getNextNode(), nullptr);
	EXPECT_EQ(firstNode.getPrevNode(), nullptr);
	
	firstNode.setData(9);
	EXPECT_EQ(firstNode.getData(), 9);

	Node<std::string> strNode("Test");

	EXPECT_EQ(strNode.getData(), "Test");

	strNode.setData("New str");
	EXPECT_EQ(strNode.getData(), "New str");
}

TEST(NodeData, getEmptyData) {
	Node<int> firstNode;
	EXPECT_EQ(firstNode.getData(), NULL);
}

TEST(NodePointers, PrevNode) {
	Node<int>* firstNode = new Node<int>();
	Node<int>* secondNode = new Node<int>();

	firstNode->setPrevNode(secondNode);
	EXPECT_EQ(firstNode->getPrevNode(), secondNode);
}

TEST(NodePointers, NextNode) {
	Node<int>* firstNode = new Node<int>();
	Node<int>* secondNode = new Node<int>();

	firstNode->setNextNode(secondNode);
	EXPECT_EQ(firstNode->getNextNode(), secondNode);
}

TEST(EmptyDequeTest, EmptyDeque) {
	Deque<int> testDq;

	EXPECT_EQ(testDq.getBack(), NULL);
	EXPECT_EQ(testDq.getFront(), NULL);
}

TEST(EmptyDequeTest, PushPopBack) {
	Deque<int> testDq;

	testDq.pushBack(5);

	EXPECT_EQ(testDq.getBack(), 5);
	EXPECT_EQ(testDq.getBack(), testDq.getFront());

	EXPECT_EQ(testDq.popBack(), 5);

	EXPECT_EQ(testDq.getFront(), NULL);
	EXPECT_EQ(testDq.getBack(), NULL);
}

TEST(EmptyDequeTest, PushPopFront) {
	Deque<int> testDq;

	testDq.pushFront(8);

	EXPECT_EQ(testDq.getFront(), 8);
	EXPECT_EQ(testDq.getBack(), testDq.getFront());

	EXPECT_EQ(testDq.popFront(), 8);

	EXPECT_EQ(testDq.getFront(), NULL);
	EXPECT_EQ(testDq.getBack(), NULL);
}


TEST(DequeTest, PushBack) {
	Deque<int> testDq;

	testDq.pushBack(2);
	testDq.pushBack(8);
	testDq.pushBack(3);
	testDq.pushBack(7);
	testDq.pushBack(-1);


	EXPECT_EQ(testDq.popBack(), -1);
	EXPECT_EQ(testDq.popFront(), 2);

	EXPECT_EQ(testDq.popBack(), 7);
	EXPECT_EQ(testDq.popFront(), 8);
}

TEST(DequeTest, PushFront) {
	Deque<int> testDq;

	testDq.pushFront(5);
	testDq.pushFront(6);
	testDq.pushFront(-5);
	testDq.pushFront(1);
	testDq.pushFront(10);


	EXPECT_EQ(testDq.popBack(), 5);
	EXPECT_EQ(testDq.popFront(), 10);

	EXPECT_EQ(testDq.popBack(), 6);
	EXPECT_EQ(testDq.popFront(), 1);
}