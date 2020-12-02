// ���� 2���� �迭�� �� �ʿ䰡 ����. 
// �� ���̰� 1�̻� ���̳��� ���� ���� �ʿ䰡 ���� �Ӵ���
// ���� ���� ��ġ �տ� ���� ����  ���� ������ ���� �ʾ��� ���� ����
// ���� �� ���� ���� ��ġ ���� �Ǵ� ��츸 ����ϹǷ�
// 1���� �迭�� ����ص� ���� �ε��� ������ ���鸸 ����ϱ� ����. 

#include <iostream>
#include <algorithm>

using namespace std;

int coins[100] = {0,};
int cases[10001] = {0,};
int n,N,K,inp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> K;
	N = 0;
	for(int i=0; i<n; i++)	{
		cin >> inp;
		if(inp <= 10000)
			coins[N++] = inp;
	}
	
	sort(coins, coins+N);
	
	for(auto coinIdx=0; coinIdx < N; coinIdx++){
		for(auto coinSum = coins[coinIdx]; coinSum <= K; coinSum++ )
			cases[coinSum] = (
								 ( (coinIdx > 0) ? cases[coinSum] : 0) 
							   + ( (coinSum - coins[coinIdx] >= 0) 
							 		 ? (cases[coinSum - coins[coinIdx]] )
							 		 :  0 )
							   + ( (coinSum == coins[coinIdx])
							         ? 1
									 : 0 )
							);
	}

	cout << cases[K];
	
	return 0;
}
