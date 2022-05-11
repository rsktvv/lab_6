#include <iostream>

struct T_List
{
	T_List* next;
	int elements;
};

void ADD(T_List* head, int elements)
{
	T_List* p = new T_List;
	p->elements = elements;

	p->next = head->next;
	head->next = p;
}

void PRINT(T_List* head)
{
	T_List* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->elements << " ";
		p = p->next;
	}
}

void CLEAR(T_List* head)
{
	T_List* tmp;
	T_List* p = head->next;
	while (p != nullptr)
	{
		tmp = p;
		p = p->next;
		delete tmp;
	}
}

bool FIND(T_List* head, int x)
{
	T_List* p = head->next;
	while (p->next != nullptr)
	{
		if (p->elements == x)
		{
			std::cout << "nayden" << std::endl;
			return true;

		}
		else
		{
			p = p->next;
		}
	}
	return false;
}

void DELETE(T_List* head, int key)
{
	T_List* tmp = head;
	T_List* p;
	while (tmp->next != nullptr)
	{
		if (tmp->next->elements == key && tmp != nullptr)
		{
			p = tmp->next;
			tmp->next = tmp->next->next;
			delete p;
		}
		else
			tmp = tmp->next;
	}
}


int main()
{
	T_List* head = new T_List;
	head->next = nullptr;


	PRINT(head);
	//std::cout << std::endl;
	return 0;
}
