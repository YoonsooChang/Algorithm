#include <iostream>
#include <algorithm>

using namespace std;

int N,M,n;
int A[100000];

void bs(int n){
	int b = 0;
	int e = N-1;
	int m;
	if((n < A[b]) || (A[e] < n)) {
		printf("0\n");
		return;	
	}
	while(b <= e){
//		m = (b+e)/2;
		m = b + (e-b)/2;
		if(A[m] == n){
			printf("1\n");
			return;	
		} 
		else if(A[m] > n) e = m - 1;
		else b = m + 1;   
	}
	printf("0\n");
	return;	
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++) 	scanf("%d", A+i);
	scanf("%d", &M);

	sort(A, A+N);

	for(int i=0; i<M; i++){
		scanf("%d", &n);
//		1742ms, ���	
//		printf("%d\n",(find(A, A+N, n) != A+N)); 
		

//		���� binary Search �� ¥�� �ϴ� �ڲ� 16%���� �ð��ʰ��� �߻� 
//		for�� �������� sort�� ȣ���� �Ǽ� 
//		68ms
		bs(n);
				
	}		
	
	return 0;
}

// algorithm ��� lower / upper bound 
/*
   for (int i = 0; i < M; ++i) {
      // ���� [a, b] ������ �ִ� �������� ���� ���
      if (countByRange(v1, v2[i], v2[i]) != 0)
         cout << "1"<< '\n';
      else
         cout << "0" << '\n';
   }	
   
   // ���� [left_value, right_value]�� �������� ������ ��ȯ�ϴ� �Լ�
	int countByRange(vector<int>& v, int leftValue, int rightValue) {
	   vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
	   vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
	
	   return rightIndex - leftIndex;
	}
*/
