

#include<iostream>
using namespace std;
#include<stdlib.h>
#include"SerialPort.h"

// change the name of the port with the port name of your computer
// must remember that the backslashes are essential so do not remove them
const string port = "\\\\.\\COM4";

int main(){
	SerialPort arduino(port);
	string data;

	if(arduino.isConnected()){
		cout<<"Connection made"<<endl<<endl;
	}
	else{
		cout<<"Error in port name"<<endl<<endl;
	}
	while(arduino.isConnected())
	{
		data.clear();

		cout<<endl<<"Commands are:"<<endl;
		cout<<"1)M71 T1 (turn on laser 1)"<<endl;
		cout<<"2)M70 T1 (turn off laser 1)"<<endl;
		cout<<"3)M71 T2 (turn on laser 2)"<<endl;
		cout<<"4)M70 T2 (turn off laser 2)"<<endl;
		cout<<"5)M17 (Enable motors)"<<endl;
		cout<<"6)M18 (Disable motors)"<<endl;
		cout<<"7)G1 F20 (Rotational speed 20 degrees per second)"<<endl;
		cout<<"8)G1 X20 (Move motor 20 degrees)"<<endl;
		cout<<"9)~ (Start cycle)"<<endl;
		cout<<"0)M0 (Pause program - restart with ~)"<<endl;
		cout<<"Enter your command: ";
		cin>>data;
		int choice=std::stoi(data);

		switch(choice)
		{
			case 1:
				data="M71 T1\r\n";
			break;
			case 2:
				data="M70 T1\r\n";
			break;
			case 3:
				data="M71 T2\r\n";
			break;
			case 4:
				data="M70 T2\r\n";
			break;
			case 5:
				data="M17\r\n";
			break;
			case 6:
				data="M18\r\n";
			break;
			case 7:
				data="G1 F20\r\n";
			break;
			case 8:
				data="G1 X20\r\n";
			break;
			case 9:
				data="~\r\n";
			break;
			case 0:
				data="M0\r\n";
			break;
			default:
				data.clear();
		}
		if(data.length()>0)
		{
			char *charArray = new char[data.length() + 1];
			
			copy(data.begin(), data.end(), charArray);
			charArray[data.length()]=0;
			arduino.writeSerialPort(charArray, data.length());
			
			cout<<arduino.readSerialPort()<<endl;

			delete [] charArray;

		}
	}

	return 0;
}

