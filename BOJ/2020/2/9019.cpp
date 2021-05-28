// �Ǽ��� ���̱� ���� �ڵ带 �� �İ��� ����.
// ��Ÿ�� ������ �� �ִ� ���?
// �迭 ���� ��� ���� �ѱ��� (ex. arr[N] => fill(arr, arr+N+1, val) )
// �Լ� ��ȯ Ÿ���� void�� �ƴѵ� return ���� �������� ���� ���,
// �� ȯ��(devc++, TDM-GCC 4.9.2 64bit) ������ ����Ÿ�԰� ��ȯŸ���� ������
// �״�� ��ȯ�ϴ���? ������ �߻����� ������ ������ syntax error�� �߻��Ѵ�.
 
// �������� �������� ���ϴ� ��찡 ���� bfs������  while�� Ż��������
// ���ǹ��� ����� �ʿ䰡 ����. while(true) ���. 

#include <cstdio>
#include <stack>
#include <queue>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

typedef int(*func)(int);

int T, A, B, curRegVal;
char visited[10000];  // 10M
int preRegVal[10000]; // 40M
stack<char> funcStk;

int D(int reg){
	reg = reg* 2 % 10000;
	return reg;
}

int S(int reg){
	reg = ((reg > 0) ? (reg - 1) : 9999); 
	return reg;
}

int L(int reg){
	reg = (reg % 1000 * 10) + (reg / 1000);
	return reg;
}

int R(int reg){
	reg = ( reg / 10) + ( reg % 10 * 1000 );
	return reg;
}

func calc[4] = {D, S, L, R};
char funcName[4] = {'D', 'S', 'L', 'R'};

void bfs(){
	queue<int> regQ;
	
	regQ.push(A);
	visited[A] = 'X';
	
	while(true){
		curRegVal = regQ.front();
		regQ.pop();
		
		FOR(f, 0, 3){
			int nextRegVal = calc[f](curRegVal);
			if(visited[nextRegVal] == '-'){
				regQ.push(nextRegVal);
				preRegVal[nextRegVal] = curRegVal;
				visited[nextRegVal] = funcName[f];
				if(nextRegVal == B) return;
			}
		}
	}
	
	return;
}

int main(void){
	
	scanf("%d", &T);
	FOR(t, 0, T-1){
		fill(visited, visited+10000, '-');
		fill(preRegVal, preRegVal+10000, -1);
		scanf("%d", &A);
		scanf("%d", &B);
		
		bfs();
		
		curRegVal = B;
		while(curRegVal != A){
			funcStk.push(visited[curRegVal]);
			curRegVal = preRegVal[curRegVal];
		}
		
		while(!funcStk.empty()){
			printf("%c", funcStk.top());
			funcStk.pop();
		}
		printf("\n");
	}

	return 0;
}

