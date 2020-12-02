/*

8
���� �迭: 1 6 2 5 7 3 5 6
��ģ ����: 1 2 2 3 4 3 4 5 
���� ���� ��ģ ����: 5 

*/

#include <iostream>
#include <vector>

using namespace std;

class maxbox {
   int* box;
   int len_box;
   static void swap(int& a, int& b) {
      int temp;
      temp = a;
      a = b;
      b = temp;
   }
   static int find_max(int* a, int len) {
      for(int i=0; i<len-1; ++i)
         for(int j=i+1; j<len; ++j)
            if(a[i]<a[j])
               swap(a[i],a[j]);
      return a[0];
   }
   static void clear(int* a, int len) {
      for(int i=0; i<len; ++i)
         a[i] = 0;
   }
public:
   maxbox(int len): box(new int[len]), len_box(len) {}
   ~maxbox(void) {
      if(box!=nullptr)
         delete[] box;
   }
   void input_box(void) {
      for(int i=0; i<len_box; ++i)
         cin >> box[i];
   }
   int max_box(void) const {
//      int* overlap = new int[len_box];
//      int* temp = new int[len_box];
      int overlap[len_box];
      int temp[len_box];
      int temp_len=0;
      overlap[0] = 1; // �� ó�� ���� 1��.
      for(int i=1; i<len_box; ++i) {
         for(int j=0; j<i; ++j) {
            if(box[j]<box[i]) {
               temp[temp_len++] = overlap[j];
            }
         } // ������ �� ���� �������� ���� ���� ��ģ �� �߿� 
         int max = 0;
         for(int i=0; i<temp_len; ++i) {
            if(temp[i] > max) {
               max = temp[i];
            } // ���� ū ���� ã�´�. 
         }
         overlap[i] = max+1;
         // �� ���� ū ���� +1�� ���Ѵ�. 
         clear(temp, temp_len);
         temp_len = 0;
      }
      return find_max(overlap, len_box);
   }
};

int main(void)
{
   int N=0;
   do {
      cin >> N;
   } while( !(1<=N || N<=1000) );
   
   maxbox b(N);
   
   b.input_box();
   cout << b.max_box() << endl;

//   if(temp!=nullptr) delete[] temp;
//   if(overlap!=nullptr) delete[] overlap;
   return 0;
}
