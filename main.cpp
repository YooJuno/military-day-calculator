#include <iostream>
#include <ctime>
#include <cstring>
#include <cmath>
#include "condition.h"

// #ifndef ADD_H
// #define ADD_H

// int condition_army(int year, int month , int day);
// int condition_airforce(int year, int month , int day);
// int condition_navy(int year, int month , int day);


// #endif

using namespace std;
// 2020 5 5 11:20 ~ 싸지방 연등

/*
[문제점]
총 복무일 수가 복무단축 조건표와 같지 않음.
입대 년도 입대 월에 따라 복무 단축 전의 총 복무일수가
일정하지 않고 계속 달라짐. 이 떄문에 혼동이 오고있음.

오늘 이후의 입대 날짜는 오류가 나옴. 결과가 0으로 나오도록 고쳐야함
*/

struct Day{
  int year=0;
  int month=0;
  int day=0;
};

bool yunyear(int); // 윤년이면 true, 아니면 false 반환하는 함수
struct Day Calcul(void);

class Military{
  private:
    // 입대 구분
    int type;
    int term;

    // 입대 날짜
    int in_year;
    int in_month;
    int in_day;

    //해방 날짜
    int out_year;
    int out_month;
    int out_day;

    //오늘 날짜
    int to_year;
    int to_month;
    int to_day;
    int to_done=0;

    int sum; // 총 복무일 수
    int done;// 해온 일 수

    int cut; // 단축일 수
    int Month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int flag = 0;

  public:
    Military(int type, int year, int month, int day) 
    : type(type), in_year(year), in_month(month), in_day(day),
    to_year(Calcul().year),to_month(Calcul().month),to_day(Calcul().day)
    {
      // 육군
      cout<<endl;
      if(type==1){
        cout<<"땅개입니다."<<endl<<endl;
        cut = condition_army(in_year, in_month, in_day);
        term = 638;
      }
      // 공군
      else if(type==2){
        cout<<"개새입니다."<<endl<<endl;
        cut = condition_airforce(in_year, in_month, in_day);
        term = 730;
      }
      // 해군
      else if(type == 3){
        cout<<"물개입니다."<<endl<<endl;
        cut = condition_navy(in_year, in_month, in_day);
        term = 699;
      }
      sum = term-cut;
      done = 0;

      if(yunyear(in_year) == true) Month[1] = 29; // 입대 년도의 날을 계산하기 위해서 초기화

    }     


    void ShwoOutDay(){
      cout<<endl<<"오늘은 "<<to_year<<"년 "<<to_month<<"월 "<<to_day<<"일 입니다."<<endl;

      // 입대 월의 일 수에서 입대 일을 뺀다
      done = Month[in_month-1] - in_day;
      if(to_year == in_year && to_month == in_month) to_done = to_day - in_day;
      else to_done += done;

      // 입대 당 해 년도에 전역하지 않음을 전제로 그 해 싹 다 더함.

      for(int i = in_month ; i<12 ; i++){
        done += Month[i];

        //오늘까지의 날짜 구하기
        if(to_year == in_year){
          // 입대한 년동안 입대 월 이후의 월
          if(to_month == i+1) to_done += to_day;
          // 입대한 년동안 입대 월부터 오늘 월까지의 덧셈.
          else if(to_month>i+1) to_done += Month[i];
        }
        else to_done += Month[i];
      }

    
      
      // 다음 해부터 전역하거나 다다음 해부터 전역함을 전제
      for(int i=in_year+1 ;; i++){   
        //윤년일 경우 당 해 2월 일 수 조정
        if(yunyear(i) == true) Month[1] = 29;  
        else Month[1] = 28;

        int j;//월
        int k;//일

        // 입대 년도 다음 년도 루프
        // 입대 월 발견하면 입대 일 덧셈
        // 발견 못하면 다음 년도로 넘어가서 반복.
        for(j=0 ; j<12 ; j++){
          done += Month[j];

          if(to_year == i){
            if(to_month == j+1) to_done += to_day;
            else if(to_month > j+1) to_done += Month[j];
          }
          else to_done += Month[j];
          
          if(done >= sum){
            done -= Month[j];
            flag++;
            break;
          }
        }
      
        
        //제대 월까지 구함.
        if(flag == 1){
          for(k=1 ;; k++){
            done ++;
            if(done==sum) break;
          }

          out_year = i;
          out_month = j+1;//배열 특성상 +1
          out_day = k;

          break;
        }
      }

      cout<<endl<<"전역날은 "<<out_year<<"년 "<<out_month<<"월 "<<out_day<<"일 입니다."<<endl<<endl;  
      cout<<"총 복무일 : "<<done<<"일"<<endl<<endl;
      cout<<"총 "<<cut<<"일 줄었어요!"<<endl<<endl;
      int percent = (to_done/(float)done)*100;
      cout<<to_done<<"일 했어! [ "<<percent<<"% ]"<<endl<<endl<<done-to_done<<"일 남았어!!"<<endl<<endl;

      if(percent<20) cout<<"니가 셀 때야?";
      else if(percent < 40) cout<<"답이 없...";
      else if(percent < 60) cout<<"짬 좀 찬거같지?";
      else if(percent < 80) cout<<"어우... 좀 했구나!";
      else cout<<"짬 다~~~ 찼네";
      
    }
};  

int main() {
  int type;
  int year;
  int month;
  int day;
  cout<<"[복무 구분을 선택하세요]"<<endl;
  cout<<"  1) 육군,의경,해병대"<<endl<<"  2) 공군"<<endl<<"  3) 해군,의무소방"<<endl;
  cout<<"==>  ";
  cin>>type;

  cout<<endl<<"입대 날짜를 입력 해 주세요 : ";
  cin>>year>>month>>day;

  Military military(type, year, month, day);
  military.ShwoOutDay();
  // 클래스 너무 어렵다...

  return 0;
}


bool yunyear(int year){
  if(year%4==0 && !(year%100==0 && year%400!=0)) return true;
  else return false;
}


struct Day Calcul(void){
  Day DAY;
  time_t now = time(0); //현재 시간을 time_t 타입으로 저장
  struct tm tstruct;
  char buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y %m %d", &tstruct); // YYYY-MM-DD 형태의 스트링
  
  for(int i=0 ; i<4 ; i++) DAY.year += (pow(10,3-i)*(buf[i]-48));
  for(int i=5 ; i<7 ; i++) DAY.month += (pow(10,6-i)*(buf[i]-48));
  for(int i=8 ; i<10 ; i++) DAY.day += (pow(10,9-i)*(buf[i]-48));

  return DAY;
}