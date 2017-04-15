#include <fstream>
#include <iostream>
using namespace std;

template <class T> struct Node
{
	T key;
	Node<T>* left;
	Node<T>* right;
};
template <class T> class tree
{
private:
	Node<T>*root;
	int count;
public:
	tree();
	~tree();
	void delNode(Node<T>* temp);
	void ins_node(const T&);
	int get_count()const;
	void print()const;
	Node<T>* find_node(const T& val, Node<T>* temp)const;
	Node<T>*root_()const;
	void out()const;
	void read(const std::string& filename);
	void disp(Node<T>* temp, unsigned int level)const;
	void writing(const std::string& filename)const;
};

template<class T>
tree<T>::tree()
{
	root = nullptr;
	count = 0;
}
template<class T>
tree<T>::~tree()
{
	delNode(root);
}
template<class T>
void tree<T>::delNode(Node<T>* temp)
{
	if (!temp)
		return;
	if (temp->left)
	{
		delNode(temp->left);
		temp->left = nullptr;
	}

	if (temp->right)
	{
		delNode(temp->right);
		temp->right = nullptr;
	}
	delete temp;
}

template<class T>
Node<T>*tree<T>::root_()const
{
	return root;
}
template<class T>
int tree<T>::get_count()const
{
	return count;
}


template<class T>
void tree<T>::ins_node(const T&x)
{
	Node<T>* duz = new Node<T>;
	duz->key = x;
	duz->left = duz->right = 0;
	Node<T>* puz = root;
	Node<T>* temp = root;
	while (temp)
	{
		puz = temp;
		if (x < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if (!puz)
		root = duz;
	else
	{
		if (x < puz->key)
			puz->left = duz;
		else
			puz->right = duz;
	}
	count++;

}
template<class T>
Node<T>* tree<T>::find_node(const T& val, Node<T>* temp) const
{
	if (temp == 0 || val == temp->key)
		return temp;
	if (val > temp->key)
		return find_node(val, temp->right);
	else
		return find_node(val, temp->left);
}

template<typename T>
void tree<T>::read(const std::string& filename)
{
	ifstream fin(filename);
	if (root != nullptr)
		delNode(root);

	int k;
	fin >> k;
	T temp;
	for (int i = 0; i < k; ++i)
	{
		fin >> temp;
		ins_node(temp);
	}
	fin.close();
}
template<typename T>
void tree<T>::print() const
{
	out(cout, this->root);
}
template<class T>
void tree<T>::disp(Node<T>* temp, unsigned int level)const
{

	if (temp)
	{
		disp(temp->left, level + 1);
		for (unsigned int i = 0; i < level; i++)
			std::cout << "-";
		std::cout << temp->key << std::endl;
		disp(temp->right, level + 1);
	}
}

template<typename T>
void tree<T>::writing(const std::string& filename)const
{
	ofstream fout(filename);
	fout << count << " ";
	out(fout, root);
	fout.close();
}
void tree<T>::out()const
{
	disp(root, 0);
}
