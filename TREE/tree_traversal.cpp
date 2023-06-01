// input.txt파일에서 읽어들인 정보를 바탕으로 -> 트리구조 생성 /* 트리구조에서 leftchild가 rightchild보다 많은 노드의 수를 반환(출력) */

#include <iostream>
using namespace std;

class node
{
private:
	int data;
	node* leftchild; 
	node* rightchild; 
public: 
	node() { this->data = 0; this->leftchild = 0; this->rightchild = 0; this->num_of_child = 0; } node(int data) { this->data = data; this->leftchild = 0; this->rightchild = 0; this->num_of_child = 0; } int num_of_child; void input_leftchild(int left) { this->leftchild = new node(left); } void input_rightchild(int right) { this->rightchild = new node(right); } void input_data(int data) { this->data = data; } int show_data() { return data; } void set_left(node* left) { this->leftchild = left; } void set_right(node* right) { this->rightchild = right; } node* show_left() { return leftchild; } node* show_right() { return rightchild; }
};

void traversal(node* currentnode, int& child) { if (currentnode->show_left()->show_data() != -1) { child++; traversal(currentnode->show_left(), child); } if (currentnode->show_right()->show_data() != -1) { child++; traversal(currentnode->show_right(), child); } else child++; }

int main() {
	freopen("input.txt", "r", stdin);

	int N;

	cin >> N;

	int* output = new int[N];
	for (int i = 0; i < N; i++)
	{
		output[i] = 0;
		int n;

		cin >> n;

		node* hj = new node[n];
		int a, b, c;

		cin >> a >> b >> c;

		node tmp(a);
		hj[0] = tmp;
		hj[0].input_leftchild(b);
		hj[0].input_rightchild(c);
		for (int j = 1; j < n; j++)
		{
			int a, b, c;

			cin >> a >> b >> c;

			for (int k = 0; k < j; k++)
			{
				if (hj[k].show_left()->show_data() == a)
				{
					hj[j].input_data(a);
					hj[j].input_leftchild(b);
					hj[j].input_rightchild(c);
					hj[k].set_left(&hj[j]);
				}
				else if (hj[k].show_right()->show_data() == a)
				{
					hj[j].input_data(a);
					hj[j].input_leftchild(b);
					hj[j].input_rightchild(c);
					hj[k].set_right(&hj[j]);
				}
				else if (hj[k].show_data() == a)
				{
					hj[j].input_data(a);
					hj[j].input_leftchild(b);
					hj[j].input_rightchild(c);
					hj[k] = hj[j];
				}
				else
				{
					hj[j].input_data(a);
					hj[j].input_leftchild(b);
					hj[j].input_rightchild(c);
				}
			}
		}

		int* result = new int[n];

		for (int j = 0; j < n; j++)
		{
			traversal(&hj[j], hj[j].num_of_child);
		}

		for (int j = 0; j < n; j++)
		{
			if (hj[j].show_left()->num_of_child < hj[j].show_right()->num_of_child)
				output[i]++;
		}
	}
	for (int i = 0; i < N; i++)
		cout << output[i] << endl;
}