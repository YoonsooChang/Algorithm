#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

#include <iostream>
using namespace std;

typedef long long ll;

ll A, B;
int as=0, bs=0;
int S;
ll N;
ll Cache[15][10]; // �ִ� 15�ڸ� ��(���� �ڸ�����), �� �ڸ��� 0~9 �� �� ���� ���� �� 


void print_cache(){
	cout << "\t    ";
	for(int i=0; i<10; i++)
		cout << i << " ";
	cout <<endl; 
	for(int i=0; i<15; i++){
		cout << "10^" <<i <<" �ڸ� : ";
		for(int j=0; j<10; j++)
			 cout << Cache[i][j] << " ";
		cout <<endl; 
	}
}


int main(void){
	scanf("%lld%lld%d", &A, &B, &S);
	
	for(size_t i=0; i<15; i++)
		fill(Cache[i], Cache[i]+10, 0);
	

	ll tmpA = A;
	ll tmpB = B;
		
	while(tmpA!=0){
		as++; tmpA/=10;
	}
		
	while(tmpB!=0){
		bs++; tmpB/=10;
	}

	for(size_t i=start; i>=0; i--){
	}
	 	
	
	print_cache();
	cout << N;
	return 0;
}
