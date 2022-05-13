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
	std::cout << '\n';
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
			std::cout << "has found" << std::endl;
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

	int N = 0;
	int a = 0;
	
	std::cout << "press 1 to create the list automatically, press 2 to create the list by yourself: ";
	std::cin >> a;
	if (a > 2)
	{
		while (a > 2)
		{
			std::cout << "press 1 to create the list automatically, press 2 to create the list by yourself: ";
			std::cin >> a;
		}

	}
	else
		if (a == 1)
		{
			std::cout << "the number of values: ";
			std::cin >> N;
			for (int i = 0; i < N; i++)
			{
				ADD(head, rand() % 10000);
				
			}
			PRINT(head);
		}
		else
			if (a == 2)
			{
				std::cout << "the number of values: ";
				std::cin >> N;
				for (int i = 0; i < N; i++)
				{
					int c = 0;
					std::cin >> c;
					ADD(head, c);
				}

			}
	std::cout << "press 1 to add the value, press 2 to delete the value, press 3 to find the value, press 4 to exit: ";
	std::cin >> a;

	while (a != 4)
	{
		if (a > 4)
		{
			while (a > 4)
			{
				std::cout << "press 1 to add the value, press 2 to delete the value, press 3 to find the value, press 4 to exit: ";
				std::cin >> a;
			}

		}
		else
			if (a == 1)
			{
				std::cout << "type the value to add: ";
				int b = 0;
				std::cin >> b;
				ADD(head, b);
				PRINT(head); 
				std::cout << "press 1 to add the value, press 2 to delete the value, press 3 to find the value, press 4 to exit: ";
				std::cin >> a;
			}
			else
				if (a == 2)
				{
					std::cout << "type the value to delete: ";
					int n = 0;
					std::cin >> n;
					DELETE(head, n);
					PRINT(head); 
					std::cout << "press 1 to add the value, press 2 to delete the value, press 3 to find the value, press 4 to exit: ";
					std::cin >> a;
				}
				else
					if (a == 3)
					{
						std::cout << "type the value to find: ";
						int m = 0;
						std::cin >> m;
						FIND(head, m);
						std::cout << "press 1 to add the value, press 2 to delete the value, press 3 to find the value, press 4 to exit: ";
						std::cin >> a;
					}
	}

	PRINT(head);
	//std::cout << std::endl;
	return 0;
}
