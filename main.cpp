#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

struct node_t
{
	int value;
	node_t* next;
};

void quit()
{
	exit(0);
}

void add(node_t*& head, int value)
{
	node_t* node = new node_t;
	node->value = value;
	node->next = nullptr;
	if (head == nullptr)
	{
		head = node;
	}
	else
	{
		node_t* last = head;
		while (last->next)
		{
			last = last->next;
		}
		last->next = node;
	}
}

void subt(node_t*& head)
{
	node_t* x = head;
	head = x->next;
	delete x;
}

void reverse(node_t* head, int p)
{
	node_t* prev = head;
	node_t* next = prev;
	for (int i = 0; i < p / 2; i++)
	{
		int first = prev->value;
		for (int j = i; j < p - 1 - i; j++)
		{
			next = next->next;
		}
		prev->value = next->value;
		next->value = first;
		prev = prev->next;
		next = prev;
	}
}

void print(node_t*& head, int p)
{
	node_t* x = head;
	for (int i = 0; i < p; i++)
	{
		cout << "+---+"
			<< "    ";
	}
	cout << endl;
	int k = 0;
	for (int i = 0; i < p; i++)
	{
		if (i > 0)
			cout << "--->";
		cout << "| " << x->value << " |";
		x = x->next;
	}
	cout << endl;
	for (int i = 0; i < p; i++)
	{
		cout << "+---+"
			<< "    ";
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	int p = 0, ch;
	node_t* head = nullptr;
	print(head, p);
	char op;
	while (cin >> op)
	{
		if (op == '+')
		{
			cin >> ch;
			add(head, ch);
			p++;
			print(head, p);
		}
		else if (op == '-')
		{
			subt(head);
			p--;
			print(head, p);
		}
		else if (op == '=')
		{
			print(head, p);
		}
		else if (op == '/')
		{
			reverse(head, p);
			print(head, p);
		}
		else if (op == 'q')
		{
			quit();
		}
	}
	return 0;
}
