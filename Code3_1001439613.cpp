// Muhammad Daud 1001439613
// Codeing Assignment 3


#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "CokeMachine.h"
#include "CokeLib.h"
#include <stdexcept>

using namespace std;
void get_command_line_params(int argc,char *argv[],string& INPUTFILENAME,string& OUTPUTFILENAME);
//void CreateCokeOutputLine(vector<CokeMachine>SetOfCokeMachines);

int main(int argc, char *argv[]){
	int i=1;
	int x,machine;
	int payment;
	string change;
	int action;
	int product,addChange;
	string machName;
	int cokePrice;
	string INPUTFILENAME,OUTPUTFILENAME;
	
	
	//CokeMachine MyCokeMachine;
	vector<CokeMachine>SetOfCokeMachines;
	
	try
	{
		get_command_line_params(argc,argv, INPUTFILENAME, OUTPUTFILENAME);
	}
	catch(invalid_argument& ex){
		cerr << "An exception occurred: " << ex.what() << endl;
		//i=0;
		exit(0);
	}
	ifstream CokeInputFile{INPUTFILENAME};
	string CokeMachineLine;
	vector<string>ConstructorValues(4);
	bool value = true;
	if (CokeInputFile.is_open())
	{
		while(!CokeInputFile.eof())
		{
			getline(CokeInputFile,CokeMachineLine);
			value = ParseCokeLine(CokeMachineLine,ConstructorValues);
			if (value)
			{
				CokeMachine tempCokeMachine{ConstructorValues[0],stoi(ConstructorValues[1]),stoi(ConstructorValues[2]),stoi(ConstructorValues[1])};
				SetOfCokeMachines.push_back(tempCokeMachine);
			};
			
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
		exit(0);
	}

	CokeInputFile.close();
	
	do{
	cout<<"Pick a Coke Machine"<<endl;
	int counter =1;
	cout<<"0. Exit"<<endl;
	for(int i =0;i<SetOfCokeMachines.size();i++)
	{
		cout<<counter<<". "<<SetOfCokeMachines[i].getMachineName()<<endl;
		counter++;
	}
	cout<<counter<<". Add a New Machine"<<endl;
	cin>>machine;
	if (machine==6)
	{
		CokeMachine MyCokeMachine;
		SetOfCokeMachines.push_back(MyCokeMachine);
	}
	
	if ((machine>0)){
	//i=1;
	while(i==1){
	cout << "What would you like to do?" <<endl;
	cout << "0: Walk Away" <<endl;
	cout << "1: Buy a Coke" << endl;
	cout << "2: Restock Machine" << endl;
	cout << "3: Add Change" << endl;
	cout << "4: Display Machine Info" <<endl;
	cout << "5: Update Machine Name" <<endl;
	cout << "6: Update Coke Price" <<endl;
	cin >> x;
	switch (x){
		case 0:
		i = 0;
		//machine =0;
		cout << "I see how it is, you like PEPSI better huh?!?!?!?" <<endl;
		break;
		case 1:
		cout << "Insert Payment: " << endl;
		cin >> payment;
		if(SetOfCokeMachines[machine-1].buyACoke(payment,change,action)==1)
		{
			if (action == 2) //works
			{
				cout<< "Here's your Coke and your change of "<<change<<endl;
			}
			else if (action == 1) //Exact Change
			{
				cout<<"Thank you for exact change"<<endl;
			}
		}
		else if (SetOfCokeMachines[machine-1].buyACoke(payment,change,action)==0)
		{
			if (action == 0) //insufficientFunds
			{
				cout<<"Insufficent Payment...returning your payment"<<endl;
			}
			else if (action == 3) //noInventory
			{
				cout<<"Sorry we are out of coke...Come back again"<<endl;
			}
			if (action == 4) //noChange
			{
				cout<<"Unable to give change at this time...returning your payment"<<endl;
			}
			else if (action == 5)//outOfOrder
			{
				cout<<"Out of Order, Exciting flavors coming soon;)"<<endl;
			}
		
		}
		break;
		case 2:
		cout << "How much product are you adding to the machine?" << endl;
		cin>>product;
		if(SetOfCokeMachines[machine-1].incrementInventory(product)==1)
		{
			cout<<"Machine has been restocked!!!"<<endl;
			cout<<"Inventory Level: "<<SetOfCokeMachines[machine-1].getInventoryLevel()<<endl;
		}
		else
		{
			cout<<"Exceeding machine's capacity!!!"<<endl;
			cout<<"Inventory Level: " <<SetOfCokeMachines[machine-1].getInventoryLevel()<<endl;
		}
		break;
		case 3:
		cout << "3: Add Change to machine:" << endl;
		cin>>addChange;
		if(SetOfCokeMachines[machine-1].incrementChangeLevel(addChange)==1)
		{
			cout<<"The Change has been updated..."<<endl;
			cout<<"Change Level: "<<SetOfCokeMachines[machine-1].getChangeLevel()<<endl;
		}
		else
		{
			cout<<"Exceeding machine's capacity!!!"<<endl;
			cout<<"Change Level: " <<SetOfCokeMachines[machine-1].getChangeLevel()<<endl;
		}
		break;
		case 4:
		cout<<SetOfCokeMachines[machine-1];
		break;
		
		case 5:
		cin.ignore();
		cout <<"Enter New machine Name"<<endl;
		getline(cin,machName);
		SetOfCokeMachines[machine-1].setMachineName(machName);
		cout <<"Machine Name has been updated..."<<endl;
		break;
		
		case 6:
		cout <<"Enter a new Coke Price"<<endl;
		cin>>cokePrice;
		SetOfCokeMachines[machine-1].setCokePrice(cokePrice);
		cout <<"Coke Price has been updated..."<<endl;
		break;
	}
	}
	}
}
	while(machine>0);
	ofstream MyOutputFileStream{OUTPUTFILENAME, ios::out};

	if (MyOutputFileStream.is_open())
	{
		if ((machine == 0)||(i==0))
		{
			for(int j=0;j<SetOfCokeMachines.size();j++)
			{
				CreateCokeOutputLine(SetOfCokeMachines[j]);
			}
		}
		return 0;
	}
	else
	{
		cout << "The file did not open" << endl;
	}

	MyOutputFileStream.close();
	return 0;

}


void get_command_line_params(int argc,char *argv[],string& INPUTFILENAME,string& OUTPUTFILENAME)
{
		int i;
	//string INPUTFILENAME;
	//string OUTPUTFILENAME;
	string cla;
	if (argc==3){
	for (i = 1; i < argc; i++)
	{
		cla = argv[i];

		if (cla.substr(0, cla.find("=")) == "INPUTFILENAME")
		{
			INPUTFILENAME = (cla.substr(cla.find("=")+1, cla.length()));
		}
		else if (cla.substr(0, cla.find("=")) == "OUTPUTFILENAME")
		{
			OUTPUTFILENAME = cla.substr(cla.find("=")+1, cla.length());
		}
	}

	//cout << "Values set by command line parameters\n" << endl;
	//cout << "\tINPUTFILENAME = " << INPUTFILENAME;
	//cout << "\tOUTPUTFILENAME = " << OUTPUTFILENAME << endl;
	}
	else if ((argc=1)||(argc>3)){
		throw invalid_argument("Missing command line parameters - - Usage: INPUTFILENAME= OUTPUTFILENAME=");
	}
}