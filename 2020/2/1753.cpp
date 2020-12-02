// pair�� �켱���� ť�� ������ �� ������ȣ�� first�� ������ �ð��ʰ��� ���� ������ �����ΰ�
// �Ÿ��� ���� �켱������ ������ ���̱� ������ ���� ������ �ϸ� �Ÿ� �� �켱������ �ٲ� ���� �ִ�. 

#include <bits/stdc++.h> 

#define MAX 3000001
#define wgt first
#define num second

using namespace std;

typedef pair<int,int> pii;

int V, E, K, u, v, w;
int curNode, nextNode, curDistSum, stepResult;
int answer;

int dist[20001];
vector<pii> costs[20001];
priority_queue<pii> Q;

void printDist(){
	for(int i=1; i<=V; i++)
		cout <<dist[i] << " ";
	cout <<endl<<endl;
}

void dijk(){
	fill(dist+1, dist+V+1, MAX);
	dist[K] = 0;
	
	Q.push(pii(0, K));
	
	while(!Q.empty()){
		
		curDistSum = -Q.top().wgt;
		curNode = Q.top().num;
		Q.pop();
		
		if(dist[curNode] >= curDistSum){
			vector<pii>& nears = costs[curNode];
			
			for(int i = 0; i< nears.size(); i++) {
				nextNode = nears[i].num;
				stepResult = curDistSum + nears[i].wgt;
				if(stepResult < dist[nextNode] ){
					dist[nextNode] = stepResult;
					Q.push(pii(-stepResult, nextNode));
				}
			}
		} 
	}
}

int main(void){
	scanf("%d%d%d", &V, &E, &K);
		
	for(int e = 0; e < E; e++){
		scanf("%d%d%d", &u, &v, &w);
		costs[u].emplace_back(pii(w,v));
	}
	
		
	dijk();
	
	for(int d = 1; d <= V; d++){
		if(dist[d] == MAX) printf("INF\n");
		else printf("%d\n", dist[d]);
	}
	
	return 0;
}
