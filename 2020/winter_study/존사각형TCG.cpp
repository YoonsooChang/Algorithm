#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main(void){
	
	ofstream ofs;
	ofs.open("tc.txt");
	
	int U,N;
	cout << "�ִ� ����(max : 360,000,000) :" ;
	cin >> U;
	ofs << U <<endl;
	cout << "�� ����(1~500,000 U���� �۾ƾ���) : ";
	cin >> N;
	ofs << N <<endl;
	int s = sqrt(N);
    
	srand((unsigned int)time(NULL));

	for(int i=0; i<N; i++){
	   long long x= ((rand() % s + 1) *(rand()%s+1) *(rand()%s+1))%N;
	   long long y=((rand() % s + 1) *(rand()%s+1) *(rand()%s+1))%N;
	   ofs << x << " " << y << endl;
	}
	
	ofs.close();
	return 0;
}
