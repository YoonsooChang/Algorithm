// ���� runtime error �߻� ����. 
// Ʈ���� linked list�� �ƴ� array�� �� �� 
// ���� Ʈ���� ��� index�� 2^10000 ���� �ö� �� �ִ�.
// ����� ���� 10,000 �� ��������, ��� ��ȣ�� 10,000�������
// ��õǾ� ������ �ʴ�. 
 
#include <iostream>

using namespace std;

int inp;
struct node{
	node(int n) : num(n), left(nullptr), right(nullptr) {}
	node* left;
	node* right;
	int num;
}; 
node* root;

void traverse(node* curNode){
	if(curNode->left != nullptr)
		traverse(curNode->left);
	if(curNode->right != nullptr)
		traverse(curNode->right);
	cout << curNode->num << '\n';
	return;
}

node* insert(node* curNode){
	if(curNode == nullptr){
		curNode = new node(inp);
		return curNode;
	}	
	
	if(curNode->num > inp){
		if(curNode->left == nullptr)
			curNode->left = insert(curNode->left);
		else insert(curNode->left);
	}
	else {
		if(curNode->right == nullptr)
			curNode->right = insert(curNode->right);
		else insert(curNode->right);
	}
	return curNode;
}

int main(void){
	
	cin >> inp;
	root = new node(inp);
	
	while(cin >> inp) 
		insert(root);
		
	traverse(root);

	return 0;
}
