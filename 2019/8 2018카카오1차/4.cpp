/* ��Ʋ �ڵ� - ���� */ 
#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>

using namespace std;
//	N 	 	T			M
int runTime, runInterv, crewMaxNumOnTheShuttle;  
ifstream ifs;

int compare (const void * a, const void * b)
{
	pair<int,int> front = (*(pair<int,int> *)a);
	pair<int,int> back = (*(pair<int,int> *)b);
	if(front.second - back.second)
		return 1;	
    else
   		return front.first - back.first;
   
}

void Leave(queue<int>& waitingCrews, int leavingTime, int& crewRemain){
	int seats = crewMaxNumOnTheShuttle;
	int waitings = waitingCrews.size();	
	
	while(seats!=0 && waitings!=0){
		waitingCrews.pop();
		--seats;
		--crewRemain;
	}
	--runTime;
	return;
}

string toTimeFormat(int number){
	string str =  to_string(number/100) + ":" + to_string(number%100) ;
	return str;	
}

int main(void){
	
	ifs.open("2.txt");
	
	int CornGetOnTheShuttle = 900;
	
	int crewNum = 0;
	
	int* arrival = new int[2000]; // �� ũ���� ���� �ð�  
	
	ifs >> runTime >> runInterv >> crewMaxNumOnTheShuttle;

	int* departure = new int[runTime];  // ��Ʋ�� ��� �ð� 

	while(!ifs.eof()){
		int hour, min;
		char* time = new char[6];
		ifs >> time;
		hour = (time[0]-'0')*10 + (time[1]-'0');
		min = (time[3]-'0')*10 + (time[4]-'0');
		if((hour*100 + min) != 2359)				// 23�� 59���� �Ȱ��ڴٴ°ŷ� ����. 
			arrival[crewNum++] = hour*100 + min;
	}
	
	for(size_t i=0; i<runTime; ++i){
		int hour = 9, min = 0;
		min += (runInterv*i);
		if(min>=60){
			hour+= (min/60); min=(min%60);
		}
		departure[i] = hour*100 + min;
	}
	
	int timeNum = crewNum + runTime; 

	pair<int,int> TIMETABLE[timeNum]; // ��� �ð����� �迭 
	for(size_t i=0; i<crewNum; ++i){
		TIMETABLE[i] = {arrival[i],0};		// ũ���� �ð��� 0
	}
	for(int i=0; i<runTime;  ++i)
		TIMETABLE[crewNum+i] = {departure[i],1};	// ��Ʋ�� �ð��� 1 �� �����Ѵ�. 
	
	delete[] arrival;
	delete[] departure;
		 
	qsort(TIMETABLE, timeNum, sizeof(pair<int,int>), compare);		// �ð� ������ ����	 
	
	for( int i=0; i<runTime+crewNum; ++i)
		cout << TIMETABLE[i].first<<" " << TIMETABLE[i].second <<endl;

	queue<int> waitingCrews;
	for(pair<int,int> elem : TIMETABLE){ 	// �ð� ������ ����	 (ũ�� + ��Ʋ) 

		if(!elem.second){ 		// ũ�簡 ���� ���� 
		
		//------���� ������?-----------//
			
			// ��� �ؾ� �ϴ� ��� 
			if(crewNum >= runTime*crewMaxNumOnTheShuttle){ 
			 // ���� ��Ʋ����  Ÿ�� �ϴ� ũ���� ���� �� ���ų� ���� ��� ���� ��Ÿ�Ƿ� 1�� �� ���� ����. 
				CornGetOnTheShuttle = elem.first - 1;
				if(CornGetOnTheShuttle%100 == 99) 
					CornGetOnTheShuttle -= 40;
				break;
			}
			else if(runTime==1 && elem.first>=900){ // �װ� �ƴѵ�(Ż �ڸ��� �ִµ�)  ������? 
 				CornGetOnTheShuttle = elem.first; // ���� ž�ô�. 
				break;
			} 
			
			// ���� ���� �η��� �ȴٸ� 	
			else 
				waitingCrews.push(elem.first); // ũ�縦 ��⿭�� �߰� 
		}
	
	     //-------------------------------// 
	
	
		else{		// ��Ʋ��  
				if(runTime==1){  // ���� 
 			 		CornGetOnTheShuttle = elem.first;
					break;
				} 
				else{
					if(runInterv==60)
						CornGetOnTheShuttle += 100;
					else CornGetOnTheShuttle += runInterv;
					Leave(waitingCrews, elem.second , crewNum); // ������ ��ŭ ũ����� �¿�����  
				}
			} 
		}
		
		cout << std::setw(5) << std::setfill('0')<< toTimeFormat(CornGetOnTheShuttle);	
}
	
