#include "Stack.h"
#include <iostream>
//9->10->null
//m_stackTop ->9
void CStack::Push(int number)
{
	StackList* newNode = new StackList();
	newNode->value = number;
	newNode->nextNode = m_stackTop;
	newNode->previousMaxNode = NULL;

	if (m_MaxNode == NULL)
	{
		m_MaxNode = newNode;
	}
	else if (number > m_MaxNode->value)
	{
		newNode->previousMaxNode = m_MaxNode;
		m_MaxNode = newNode;
	}

	m_stackTop = newNode;
}

void CStack::Pop()
{
	if (m_stackTop == NULL) return;

	StackList* tempNextNode = m_stackTop->nextNode;

	if (m_stackTop->previousMaxNode != NULL)
	{
		m_MaxNode = m_stackTop->previousMaxNode;
	}

	delete(m_stackTop);
	m_stackTop = tempNextNode;
}

int CStack::MaxValue()
{
	if (m_stackTop != NULL && m_MaxNode != NULL)
		return m_MaxNode->value;
}

CStack::CStack()
:m_stackTop(NULL),
m_MaxNode(NULL)
{
}

CStack::~CStack()
{
}