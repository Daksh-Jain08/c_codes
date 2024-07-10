#include<iostream>
#include<cstring>

using namespace std;

string convert_to_digital_time(int minutes){
  string time = "";
  int hours = minutes/60;
  int min = minutes%60;
  time = time + to_string(hours) + ":";
  if(min<10)
    time += "0" + to_string(min);
  else
    time += to_string(min);
  return time;
}

int main(){
  int minutes;
  cin>>minutes;
  string time = convert_to_digital_time(minutes);
  cout<<time<<endl;
}
