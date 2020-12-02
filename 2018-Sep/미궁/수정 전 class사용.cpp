
#include <iostream>

using namespace std;
 
class init{
public:
	int* r;
	int n;
	init(int N):n(N){
		r = new int[N];
		r[0]=1;   r[1]=2;
		int d1=5; int d2=5;
		for(size_t i=2; i<N; ++i){
			if(i%2==0){
				r[i]=r[i-2]+d1;
				d1+=4;
			}
			else{
				r[i]=r[i-2]+d2;
				d2+=4;
			}
		}
	}
	
	~init(void) {
		if(r!=0) delete r;
	}
	
	int get(int x, int y) const{
		int gid=x+y-1;
		if(gid<=n){
			if(gid%2==0)
				return r[gid-1]+(y-1);
			else 
				return r[gid-1]-(y-1);	
		}
		else{
			int n_x=n-x+1;
			int n_y=n-y+1;
			int n_gid=n_x+n_y-1;
			if(n_gid%2==0)
				return n*n+1-(r[n_gid-1]+(n_y-1));
			else
				return n*n+1-(r[n_gid-1]-(n_y-1));
		}
	}
	int move(int m){ 
		int x=1,y=1;
		int i;
		int sum = r[0];
		char dir;
		const char up='U';
		const char down='D';
		const char right='R';
		const char left='L';
		do
		{
			//cout << "input direction"<<endl;
			cin >> dir;
			switch(dir){
				case up:
					if(--y<1){
//						cout << "out of range"<<endl;
						++y;
					}		
					sum+=get(x,y);
//					cout << "value : "<<get(x,y) << endl;
//					cout << "point : "<< x << ", " <<y << endl;
					break;
				case down:
					if(++y>n){
//						cout << "out of range"<<endl;
						--y;
					}
					sum+=get(x,y);	
//					cout << "value : "<<get(x,y) << endl;
//					cout << "point : "<< x << ", " <<y << endl;
					break;
				case right:
					if(++x>n){
//						cout << "out of range"<<endl;
						--x;
					}	
					sum+=get(x,y);	
//					cout << "value : "<<get(x,y) << endl;
//					cout << "point : "<< x << ", " <<y << endl;
					break;
				case left:
					if(--x<1){
//						cout << "out of range"<<endl;
						++x;
					}
					sum+=get(x,y);
//					cout << "value : "<<get(x,y) << endl;
//					cout << "point : "<< x << ", " <<y << endl;
					break; 
				default:
//					cout << "wrong direction" << endl;
					break;
				}
		}while(++i!=m);	
		return sum;
	}	
};



/*int main(void){
	int n,m;
	cout << "input size and the number of movements" << endl;
	cin>>n; cin>>m;
	init it(n);
	for(size_t i=0; i<n;++i)
		cout << it.r[i]<< " ";
	cout << it.move(m);
	return 0;
	
}*/

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		int Answer = 0;
		int n,m;
		cin>>n; cin>>m;
		init it(n);
	//	for(size_t i=0; i<n;++i)
	//		cout << it.r[i]<< " ";
		Answer = it.move(m);
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
