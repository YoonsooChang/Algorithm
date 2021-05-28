#include <iostream>
#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int N, M, link, start, coRoot;
int parents[201];

int findRoot(int node){
	if(parents[node] == node) return node;
	return parents[node] = findRoot(parents[node]);
}

void uni(int a, int b){
	int aR = findRoot(a);
	int bR = findRoot(b);
	if(aR == bR) return;
	(aR > bR) ? (parents[aR] = bR) : (parents[bR] = aR);
	return;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	FOR(i,1,N) parents[i] = i;
	FOR(i,1,N){
		FOR(j,1,N){
			cin >> link;
			if(link)		
		// i,j�� ���� �ٲ���� �� �����ϸ� �ȵȴ�. 
		// �� �� ���� ��� �ܿ� �Ǵٸ� ���� ��ġ�� ��忡����
		//  findRoot ȣ��� ���� 
		// �� ���� ���� root�� ���ŵ� ���ɼ��� �ִ�. 
				uni(i,j);
			
		}
	}
	
//	FOR(i,1,N) cout << parents[i] << endl;
	
	cin >> start;
	coRoot = parents[start];
	
	int m, path;
	for(path = 2; path <= M; path++){
		cin >> m;
		if(parents[m] != coRoot){
			cout << "NO";
			break;
		}
	} 
	if(path > M) cout << "YES";
	
	return 0;
}
