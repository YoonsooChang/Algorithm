// ���丮���� ���ϴ� ����  

#include <bits/stdc++.h>

using namespace std; 

int f(int i){
	return (i==0) ? 1 : (i*(i==1 ? 1 : f(i-1)));
}

int main(){
	int i;
	cin >> i;
	cout << f(i);
	return 0;
}
