#include <iostream>
//52ms
using namespace std;

int Max_safe=0;

void next(int* p, int n){   // nC3 ���տ��� ���� ���� ���ϱ�  
	int cnt=1;		 
	for(int i=n-1; i>=0; i--){
		if(p[i]==1){
			if(i==n-1){
				if(p[i-1]==1) {
					for(int j=n-1; j>=0; j--){
						if(p[j]==1){
						 	p[j]=0;
							 cnt++;
						}
						else {
							if(cnt==4) return;
							int k;
							for(k=j; k>=0; k--)
								if(p[k]==1) break;
							p[k]=0; 
							for(int l=1; l<=cnt; l++)		
								p[k+l]=1;
							break;
						}
					}
				}
				else{
					p[i]=0;
					int j;
					for(j=i-1; p[j]!=1 && j>=0; j--);
					p[j++]=0; 				
					p[j++]=1; p[j]=1;
			
				}		
			}
			else{
				p[i]=0;
				p[i+1]=1;
				break;
			}	
		break;
		}
	}
	return;
}

int comb(int n, int k){ // nCk ���� ���ϱ�  { n/1*(n-1)/2*(n-3)/3 ...*(n-k)/k} 
	int c=1;
	for(int i=0; i<k; i++){
		c*=(n-i); 	
		c/=(i+1);
	}
	return c;
}

void dfs(int** lab, int& safe, int i, int j, int max_x, int max_y){
	// ���̷����� ���������� �Լ� , ������ safe ������ �۾����� return  
	lab[i][j]=3; safe--; 

				if( i-1>=0 && lab[i-1][j]==0){
					if(safe < Max_safe) return;
					dfs(lab ,safe, i-1 , j, max_x, max_y);
				}
				if( j-1>=0 && lab[i][j-1]==0){
					if(safe < Max_safe) return;
					dfs(lab, safe, i , j-1, max_x, max_y);
				}
				if( j+1 <= max_y-1 && lab[i][j+1]==0){
					if(safe < Max_safe) return;
					dfs(lab, safe, i , j+1, max_x, max_y);
				}
				if( i+1 <= max_x-1 && lab[i+1][j]==0){
					if(safe < Max_safe) return;
					dfs(lab, safe, i+1 ,j, max_x, max_y);
				}
	return;
}


int gogoVirus(int** lab, int x, int y, int zeronum){
  // ���̷��� ��ŸƮ  
	int safe = zeronum;
	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			if(lab[i][j]==2){
				if( i-1>=0 && lab[i-1][j]==0)	dfs(lab ,safe, i-1 , j, x, y);
				
				if( j-1>=0 && lab[i][j-1]==0)	dfs(lab, safe, i , j-1, x, y);
				
				if( j+1 <= y-1 && lab[i][j+1]==0)	dfs(lab, safe, i , j+1, x, y);

				if( i+1 <= x-1 && lab[i+1][j]==0)	dfs(lab, safe, i+1 ,j, x, y);	
			}						
		}
	}
	// ���� ���̷��� �Ҹ�  
	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++)
			if(lab[i][j]==3) lab[i][j]=0;		
	}
	return safe;
}


int main(void){
	int x,y, numzero=0; 	// x,y�� ��,�� numzero�� ��Ŀ��� 0�� ����  
	int** lab; 				// ������ ��� 
	int* zero; int* pick;   
	// zero�� numzero���̸�ŭ�� 0 �迭
	// pick�� ����������� 1���� �迭�� ������ ��  0�� �κ��� �ε������� ����
	// ���� ���̰� ���� zero �迭���� 0->1�� �Ǿ��� �� pick���� 
	// zero�迭�� ���� �ε����� ��ġ�� ��(����������� �ε�����)�� ����ϵ��� �Ͽ��� 
	cin >> x >> y;
	zero = new int[x*y];
	pick = new int[x*y];
	lab = new int*[x];
	for(int i=0;i<x;i++){
		lab[i]= new int[y]; 
		for(int j=0; j<y; j++){
			cin >> lab[i][j]; 
			if(lab[i][j]==0){
				pick[numzero]=i*y+j;
				zero[numzero++]=0;	
			} 
		}
	}
	zero[0]++; zero[1]++; zero[2]++; // 1 1 1 0 0 0 0... 0 0 0

	int num = comb(numzero,3);  // num : numzero C 3 ( ����� 0���߿��� 3���� ��(1)�� ���� �� �ִ� ����� ��) 
	for(int i=0; i < num; i++){
	
		//���� ����ϴ�	
		for(int i=0;i<numzero;i++){
			int pos;
			if(zero[i]==1) {
				pos = pick[i];
				lab[(pos/y)][(pos%y)]=1;
			}
		}

		int s = gogoVirus(lab, x,y, numzero-3);
		if(s > Max_safe) Max_safe = s;
	
		//���� �ѽʴϴ� 		
		for(int i=0;i<numzero;i++){
			int pos;
			if(zero[i]==1) pos = pick[i];
			lab[(pos/y)][(pos%y)]=0;
		}		 
		next(zero, numzero); // �� ����� ���� �� ��  
	}
	cout << Max_safe;

	return 0;
}

