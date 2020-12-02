#include <iostream>
#include <string>

using namespace std;

int N;
char dots[64][64];


string zip(int r, int c, int l){
	if(l==1){
		return string(1,dots[r][c]);
	}	
	
	string lu = zip(r, c, l/2);
	string ru = zip(r, c+l/2, l/2);
	string ld = zip(r+l/2, c, l/2);
	string rd = zip(r+l/2, c+l/2, l/2);
	
	if( ((lu == "0") || (lu == "1")) && (lu == ru) && (lu == ld) && (lu == rd))
		return lu;	
	else
		return ("(" + lu +ru +ld +rd + ")" );
}

int main(void){
	

	cin >> N;
//	for(size_t i=0; i<N; i++){
//		for(size_t j=0; j<N; j++)
//			cin >> dots[i][j];
//	}
	
// string��� ������ �Ʒ�ó�� �ʱ�ȭ�ϸ�
// GCC������ �޸� �ʰ��� �߻��Ѵ�...������? 
// Clang ������ �߻����� ����.
 
	for(size_t i=0; i<N; i++)
		cin >> dots[i];

	cout << zip(0,0,N);
	
	return 0;
}
