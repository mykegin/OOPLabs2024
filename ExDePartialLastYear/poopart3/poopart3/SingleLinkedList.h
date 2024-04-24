#pragma once
template <class T>
class SingleLinkedList
{
	template <typename T>
	struct Nod
	{
		T val;
		Nod <T>* next;
	};
	Nod <T>* root;

public:
	SingleLinkedList()
	{
		root = nullptr;
	}
	~SingleLinkedList()
	{
		if (!(root == nullptr))
		{
			Nod <T>* p = root;
			Nod <T>* aux;
			root = nullptr;
			while (p->next != nullptr)
			{
				aux = p;
				p = p->next;
				delete aux;
			}
			delete p;
		}
	}

	SingleLinkedList& operator+=(T x)
	{
		if (root == nullptr)
		{
			root = new Nod<T>;
			root->val = x;
			root->next=nullptr;
		}
		else
		{
			Nod <T>* p = root;
			while (p->next != nullptr)
			{
				p = p->next;
			}
			p->next = new Nod<T>;
			p->next->val = x;
			p = p->next;
			p->next = nullptr;
		}

		return(*this);
	}

	bool operator&& (T x)
	{
		if (root == nullptr)
		{
			return false;
		}
		else
		{
			Nod <T>* p = root;
			if (p->val != x)
			{
				while (p->next != nullptr)
				{
					if (p->val == x)
						return true;
					p = p->next;
				}
				if (p->val != x)
					return false;
				else
					return true;
			}
			return true;
		}
	}

	operator bool()
	{
		if (root == nullptr)
			return false;
		else
			return true;
	}

	void print(void (*function) (const T&))
	{
		if (root != nullptr)
		{
			Nod <T>* p = root;
			while (p != nullptr && p->next != nullptr)
			{

				function(p->val);
				p = p->next;
			}
			function(p->val);
		}
	}

	T pop_first()
	{
		Nod <T>* aux = root;
		T p = root->val;
		root = root->next;
		delete aux;
		return p;
	}
};
