#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

//int bit32[3125]; //100,000bits = 3125 x 32bitmask

int main(void){
	int T,N,M,Ans;
	int x,y;
	cin >> T;
	
//	for(int bitmask : bit32)
//		bitmask&=0;
	
	for(int testCase=0; testCase<T; ++testCase){
		cin >> N >> M; // ȸ�� �� �� ���� ���
		//1~32 1
		//33~64 2 
		int bitMask[(N-1)/32 + 1];
		for(int i=0; i<((N-1)/32+1); ++i){
			bitMask[i] &= 0;
			cout << bitset<32> (bitMask[i]) <<endl;
		}
		vector<int> mem[N];	
		vector<int>::iterator it;
		for(int i=0; i<N; ++i)
				mem[i]=vector<int>();
		
		for(int i=0; i<M; ++i){
			cin >> x >> y;
			int xSelectMask = (x-1) / 32; // 3 
			int xIndexInMask = (x-1) % 32; //13
			int ySelectMask = (y-1) / 32; // 3 
			int yIndexInMask = (y-1) % 32; //13
				
			cout << xSelectMask <<" "<< xIndexInMask <<" "<< ySelectMask <<" "<< yIndexInMask <<endl;	
			//x 1 y 4
			if( (bitMask[xSelectMask] & (1 << xIndexInMask) ) // ���������� ó�� x
				|| (bitMask[ySelectMask] & (1 << yIndexInMask) ) )
				continue;
				 
			// 4 vector has 1
			 
			it = find(mem[y-1].begin(), mem[y-1].end(), x);
			if(it != mem[y-1].end()){		 // �ʵ� �� �����ϳ�? �׷� 1�� ������ 
			  bitMask[xSelectMask] |= (1 << xIndexInMask);	
     		  bitMask[ySelectMask] |= (1 << yIndexInMask);
     		  cout << xSelectMask <<"x32 +" <<xIndexInMask << " on"<<endl;
     		  cout << bitset<32>(bitMask[xSelectMask])<<endl;
			  cout << ySelectMask <<"x32 +" <<yIndexInMask << " on"<<endl;
			  cout << bitset<32>(bitMask[ySelectMask])<<endl;	
			}			
			else
				mem[x-1].push_back(y);
		}
	
		int bitsOn = 0;
		for(int i=0; i<((N-1)/32+1); ++i){
	    	int target = bitMask[i];
			for(;target!=0;bitsOn++) 
	   		    target&=(target-1);
		}
				
		cout << "bitMask Array Size : " << (N-1)/32 +1 << " M : " << M <<endl;
		cout << "N : " << N << " bitsOn : " << bitsOn <<endl;			
		Ans = N-bitsOn; 
		cout << "Case#" << testCase+1 <<endl;
		cout << Ans << endl;
	}
	
	return 0;
}
