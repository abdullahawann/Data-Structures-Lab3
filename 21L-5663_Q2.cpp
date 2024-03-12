#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class linklist
{
	node* head;
public:
	
	linklist()
	{
		head = NULL;
	}

	void inatst(int const ele)
	{
		node* temp = new node;
		temp-> data = ele;
		temp->next = head;
		head = temp;
	}
	
	linklist intersection(linklist &obj, linklist &obj1)
	{			
		linklist c;
		node* cur=obj.head;
		while(cur != NULL)
		{
			node* cur1 = obj1.head;
			while(cur1 != NULL)
			{ 
				if(cur->data == cur1->data)
				{
					c.inatst(cur->data);
				}
					cur1=cur1->next;
			}
			cur=cur->next;
		}
			return c;
	}

	void sort(linklist &obj)
	{		
		node* cur,*prev;
		int temp;
		for(cur=obj.head;cur->next != NULL;cur=cur->next)
		{
			for(prev=cur->next;prev != NULL;prev=prev->next)
			{
				if(cur->data > prev->data)
				{
					temp=cur->data;
					cur->data=prev->data;
					prev->data=temp;
				}
			}
		}
	}

	linklist un(linklist &obj, linklist &obj1)
	{
		linklist uni;
		node* cur=obj.head;
		node* cur1=obj1.head;
		while(cur != NULL)
		{
			uni.inatst(cur->data);
			cur=cur->next;
		}
		while(cur1 != NULL)
		{
			uni.inatst(cur1->data);
			cur1=cur1->next;
		}
		uni.sort(uni);
		return uni;
	}

	void display()
	{
		node* cur1 = head;
		while (cur1 != NULL)
		{
			cout << cur1->data << " ";
			cur1 = cur1->next;
		}
		cout << endl;
	}
};

int main()
{
	linklist l;
	linklist l1;
	linklist inter;
	linklist uni;
	linklist srt;
	l.inatst(4);
	l.inatst(7);
	l.inatst(1);
	l.inatst(1);
	l.inatst(5);
	l1.inatst(4);
	l1.inatst(3);
	l1.inatst(9);
	inter=l.intersection(l,l1);
	uni=l.un(l,l1);
	l.sort(l);
	l1.sort(l1);
	cout << "Elements of linked list 1 are : " ;
	l.display();
	cout << "Elements of linked list 2 are : " ;
	l1.display();
	cout << "Intersection of linked list is : ";
	inter.display();
	cout << "Union of linked list is : ";
	uni.display();
	cout << "Linked list after getting sorted is : " ;
	uni.display();

	system("pause");
	return 0;
}