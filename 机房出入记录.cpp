#include<iostream>
#include<string>
#include<vector>

using namespace std;

class time{
public:
	int hour;
	int minute;
	int seconds;

	time(int hour,int minute,int seconds):hour(hour),minute(minute),seconds(seconds){}
	time(string str_time);

	bool operator<(time &t){
		if(hour<t.hour) return true;
		else if(hour>t.hour) return false;
		else{
			if(minute<t.minute) return true;
			else if(minute>t.minute) return false;
			else{
				if(seconds<t.seconds) return true;
				else if(seconds>t.seconds) return false;
				else return true;
			}
		}
	}

};

time::time(string str_time){
	int start=0;int time[3];int pos=0;
	for(int i=0;i<str_time.size();i++){
		if(str_time[i]==':'){
			time[pos++]=atoi((str_time.substr(start,i-start)).c_str());
			start=i+1;
		}
	}
	time[pos++]=atoi((str_time.substr(start,str_time.size()-start)).c_str());
	hour=time[0];minute=time[1];seconds=time[2];

}



int main(){
	int N,M;
	cin>>N;
	for (int j = 0; j < N; j++)
	{
		string First_in_ID;
		string Last_out_ID;
		time First_in_time(23,59,59);
		time Last_out_time(0,0,0);
		string ID,hour,minute,seconds;
		string In_time,Out_time;
		cin>>M;
		for(int i=0;i<M;i++){
			cin>>ID>>In_time>>Out_time;
			time in(In_time);
			time out(Out_time);
			if(in<First_in_time){
				First_in_time=in;
				First_in_ID=ID;
			}
			if(Last_out_time<out){
				Last_out_time=out;
				Last_out_ID=ID;
			}
		}
		cout<<First_in_ID<<" "<<Last_out_ID<<endl;
	}

	return 0;
}