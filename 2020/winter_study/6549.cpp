//6549 ������׷����� ���� ū ���簢��
 
#include <iostream>
#include <vector>
 
typedef unsigned long long ull;

using namespace std;

int n;
vector<ull> hArr; // ���� �迭 

int find(int p, int len){
	
	if(len == 1){
	
		return;	
	}
	
	
	
}

int main(void){
	
	cin >> n;
	hArr = vector<ull>(n);
	for(size_t i=0; i<n; i++) cin >> hArr[i];
	
	cout << find(0, n);
	
//	for(ull h : hArr)
//		cout << h;	
	
	return 0;
}
