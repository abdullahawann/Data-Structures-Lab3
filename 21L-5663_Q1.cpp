#include<iostream>
using namespace std;

class linkedlist
{
	struct node
	{
		int data;
		node* next;
	};

	node*head;
	node*tail;

public:
	linkedlist()
	{
		head = nullptr;
	}

	void insertathead(int s)

	{
		node *temp = new node;
		temp->data = s;
		temp->next = head;
		head = temp;
	}

	void insertattail(int t)
	{
		node *temp = new node;
		temp->data = t;
		temp->next = NULL;
		node*prev = nullptr;
		node*curr;
		curr = head;
		while (curr != NULL)
		{
			prev = curr;
			curr = curr->next;

		}
		if (prev == 0)
		{
			head = temp;
		}
		else {
			prev->next = temp;

		}
	}

	void print()
	{
		node* curr = head;
		while (curr != NULL)
		{
			cout << curr->data << "  \n";
			curr = curr->next;
		}

	}

	void erasehead()
	{
		node*curr = head;
		head = head->next;
		delete curr;
		curr = 0;
		cout << "deleted from head" << endl;
	}

	void deleteattail()
	{
		node*curr = head;
		node*last = 0;
		node* seclast = 0;
		while (curr != NULL)
		{
			seclast = last;
			last = curr;
			curr = curr->next;
		}
		if (seclast == 0)
		{
			head = NULL;
			delete last;
			last = 0;
			cout << "Last block deleted";
		}
		else {
			seclast->next = NULL;
			delete last;
			last = 0;
			cout << "Last block deleted" << endl;
		}
	}

	~linkedlist()
	{
		while (head != NULL)
		{
			node*curr = head;
			head = curr->next;
			delete curr;
			curr = head;
		}
	}
};

int main()
{
	linkedlist l1;
	l1.insertathead(2);
	l1.insertathead(6);
	l1.insertathead(7);
	l1.insertattail(3);
	l1.insertattail(8);
	l1.insertattail(1);
	l1.erasehead();
	l1.deleteattail();
	l1.print();

	system("pause");
	return 0;
}