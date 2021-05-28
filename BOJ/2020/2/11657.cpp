// N (1 �� N �� 500) , M (1 �� M �� 6,000)
// ��° �ٺ��� M���� �ٿ���
// A, B, C (1 �� A, B �� N, -10,000 �� C �� 10,000)
// �� �Ÿ� ��(dist[]) Ÿ���� long long ���� ���� ������ ��� �ʰ��� ������
// ������ �� �𸣰ڴ�... �Ʒ� �ڵ�� HardCase(500, 6000, 1,2�� ���� -10000�� weight�� ���� edge��� ����) 
// �� �Է¹޴´�.
  
#include <bits/stdc++.h>

#define MAX 1e9
#define dest first
#define cost second

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int N,M,a,b,t;
bool result;
vector<pii> destAndCost[501];
ll dist[501] = {0,};

bool BellmanFord(){
	for(int i = 1; i <= N; i++){
		for(int n = 1; n <= N; n++){
			if(dist[n] == MAX) continue;
			vector<pii>& edges = destAndCost[n];
			for(int e = 0; e < edges.size(); e++){
				if(dist[edges[e].dest] > dist[n] + edges[e].cost ){
					if( i == N ) return false;
					dist[edges[e].dest] = dist[n] + edges[e].cost;
				}
			}
		}
	}

	return true;
}

int main(void){

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ifstream ifs("11657HardCase.txt");
	ifs >> N >> M;
//	cin >> N >> M;

	fill(dist+2, dist+N+1, MAX);
	for(int m = 0; m < M; m++){
//		cin >> a >> b >> t;
		ifs >> a >> b >> t;
		destAndCost[a].emplace_back(pii(b,t));
	}

	result = BellmanFord();

//	if(!result) cout << -1;
//	else {
//		for(int i = 2; i <= N; i++)	
//			cout << ( (dist[i]==MAX) ? -1 : dist[i]) << "\n";
//	}

	for(int i = 1; i <= 10; i++)	
			cout << dist[i] <<endl;
	ifs.close();
	
	return 0;
}
