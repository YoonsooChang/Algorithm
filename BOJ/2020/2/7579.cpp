// �� 2���� �迭�� �ϸ� Ʋ����? �ݷʰ� ����..? 
// �޸������̼�, dp �迭�� ä��� �κп��� ������ �־���. 
// (�ݷ�) ���� 484 ��� 488 
// 19 20169
// 240 2560 434 6 31 577 500 2715 2916 952 2490 258 1983 1576 3460 933 1660 2804 2584
// 82 77 81 0 36 6 53 78 49 82 82 33 66 8 60 0 98 91 93 

// 1�������� �ص� �ð��� 0ms�� �������� �޸𸮰� ���� �̻� ���� 

#include <bits/stdc++.h>

using namespace std;

int N, M, maxCost=0, ans;
int mem[101];
int cost[101];
int dp[101][10001]={{0,},};

void print(){
	for(int i=1; i<=N; i++){
		for(int j=0; j<=maxCost; j++)
			cout << dp[i][j] << " ";
		cout <<endl;
	}
	cout << endl;	
}

void f(){
	
	for(int i=2; i<=N; i++){
		// ���� mem�� �յ�� ���ϱ� ���� �ʱ�ȭ �κ� �߰�
		dp[i][cost[i]] = mem[i]; 
		
		for(int j = 0; j <= maxCost; j++){
//			�߸��� �κ� 
//       : '���� �޸𸮸� ���ϴ� ��� (+mem[i]) �� dp[i-1][j-cost[i]]��
//			0�� �ƴ� ��쿡�� �����ؾ� �ش� ������ ���߸���
// 		    ��� ��쿡 ���� �����ϸ� �������� �ʴ� ������
// 			dp �迭�� ä��� �ȴ�. 
//			dp[i][j] = max(dp[i-1][j], dp[i-1][j - cost[i]] + mem[i]);		
				
//		   ������ �κ�, ���� �������� ���ڴ� ���� mem���� ���, ���ڴ� ���� mem ��� 
			dp[i][j] = max (
						((dp[i-1][j-cost[i]] != 0) ? (dp[i-1][j-cost[i]] + mem[i]) : dp[i][j])
						,dp[i-1][j]
						 );

			print();
		}
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for(int i=1; i<=N; i++)
		cin >> mem[i];
	for(int i=1; i<=N; i++){
		cin >> cost[i];
		maxCost += cost[i];
	}
	
	dp[1][cost[1]] = mem[1];
	f();
		
	for(ans=0; ans<=maxCost && dp[N][ans] < M; ans++);
	cout << ans;
	
	return 0;
}
