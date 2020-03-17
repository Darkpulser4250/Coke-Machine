// Muhammad Daud 1001439613
// Codeing Assignment test


#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "CokeMachine.h"
#include "CokeLib.h"
#include "VendingMachine.h"
#include <stdexcept>
#include <map>
#include <gtkmm.h>

using namespace std;
void get_command_line_params(int argc,char *argv[],string& INPUTFILENAME,string& OUTPUTFILENAME);

int BuyACoke(){
Gtk::Dialog *MyDialog = new Gtk::Dialog();
MyDialog->set_title("Payment");     
MyDialog->add_button("Cancel", 0);
MyDialog->add_button("OK",1);
MyDialog->set_default_response(1);     

		Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
		MyEntry->set_text("Enter payment");
		MyEntry->set_max_length(100);
		MyEntry->show();
		MyDialog->get_content_area()->pack_start(*MyEntry);


int result = MyDialog->run();
MyDialog->close();

		std::string payment = MyEntry->get_text();	
delete MyDialog;	
		
		return stoi(payment);
}
int RestockMachine()
{
Gtk::Dialog *MyDialog = new Gtk::Dialog();
MyDialog->set_title("Restock");     
MyDialog->add_button("Cancel", 0);
MyDialog->add_button("OK",1);
MyDialog->set_default_response(1);     

		Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
		MyEntry->set_text("Enter Amount");
		MyEntry->set_max_length(100);
		MyEntry->show();
		MyDialog->get_content_area()->pack_start(*MyEntry);


int result = MyDialog->run();
MyDialog->close();

		std::string product = MyEntry->get_text();	
delete MyDialog;	
		
		return stoi(product);
		
}
int AddChange()
{
	Gtk::Dialog *MyDialog = new Gtk::Dialog();
MyDialog->set_title("Add Change");     
MyDialog->add_button("Cancel", 0);
MyDialog->add_button("OK",1);
MyDialog->set_default_response(1);     

		Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
		MyEntry->set_text("Enter Amount");
		MyEntry->set_max_length(100);
		MyEntry->show();
		MyDialog->get_content_area()->pack_start(*MyEntry);


int result = MyDialog->run();
MyDialog->close();

		std::string addChange = MyEntry->get_text();	
delete MyDialog;	

		return stoi(addChange);
}
string UpdateMachineName()
{
		Gtk::Dialog *MyDialog = new Gtk::Dialog();
MyDialog->set_title("New Name");     
MyDialog->add_button("Cancel", 0);
MyDialog->add_button("OK",1);
MyDialog->set_default_response(1);     

		Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
		MyEntry->set_text("Enter New machine Name");
		MyEntry->set_max_length(100);
		MyEntry->show();
		MyDialog->get_content_area()->pack_start(*MyEntry);


MyDialog->run();
MyDialog->close();

		std::string machName = MyEntry->get_text();	
delete MyDialog;	

		return machName;
}
int UpdateCokePrice()
{
	Gtk::Dialog *MyDialog = new Gtk::Dialog();
MyDialog->set_title("New Price");     
MyDialog->add_button("Cancel", 0);
MyDialog->add_button("OK",1);
MyDialog->set_default_response(1);     

		Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
		MyEntry->set_text("Enter Amount");
		MyEntry->set_max_length(100);
		MyEntry->show();
		MyDialog->get_content_area()->pack_start(*MyEntry);


int result = MyDialog->run();
MyDialog->close();

		std::string cokePrice = MyEntry->get_text();	
delete MyDialog;	

		return stoi(cokePrice);	
}


void CokeMenu(int machine,int i,vector<CokeMachine>SetOfCokeMachines,int payment,string change,int action,int product,int addChange,int cokePrice,string machName,int x)
{
	if ((machine>0)){
	while(i==1){
Gtk::Dialog *MyDialog = new Gtk::Dialog();
MyDialog->show();
MyDialog->set_title("Coke Machine");
std::vector<std::string> buttons = {"Cancel", "BuyACoke", "Restock Machine", "Add Change", "Display Machine Info", "Update Machine Name","Update Coke Price"};
for (int i = 0; i < buttons.size(); i++)
MyDialog->add_button(buttons[i], i);
MyDialog->set_default_response(1); 
x = MyDialog->run();
MyDialog->close();
delete MyDialog;


	switch (x){
		case 0:
		i = 0;
		cout << "I see how it is, you like PEPSI better huh?!?!?!?" <<endl;
		break;
		case 1:
		{
		payment = BuyACoke();
		if(SetOfCokeMachines[machine-1].buyACoke(payment,change,action)==1)
		{
			if (action == 2) //works
			{
				std::string message1{"Here's your coke and your change of"};
				std::string message = message1 + " " + change;
				Gtk::MessageDialog *MyMessageDialog =
				new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
				MyMessageDialog->run();
				MyMessageDialog->close();
				delete MyMessageDialog;
			}
			else if (action == 1) //Exact Change
			{
				std::string message{"Thank you for exact change"};
				Gtk::MessageDialog *MyMessageDialog =
				new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
				MyMessageDialog->run();
				MyMessageDialog->close();
				delete MyMessageDialog;

			}
		}
		else if (SetOfCokeMachines[machine-1].buyACoke(payment,change,action)==0)
		{
			if (action == 0) //insufficientFunds
			{
				std::string message{"Insufficent Payment...returning your payment"};
				Gtk::MessageDialog *MyMessageDialog =
				new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
				MyMessageDialog->run();
				MyMessageDialog->close();
				delete MyMessageDialog;
			}
			else if (action == 3) //noInventory
			{
				std::string message{"Sorry we are out of coke...Come back again"};
				Gtk::MessageDialog *MyMessageDialog =
				new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
				MyMessageDialog->run();
				MyMessageDialog->close();
				delete MyMessageDialog;
			}
			if (action == 4) //noChange
			{
				std::string message{"Unable to give change at this time...returning your payment"};
				Gtk::MessageDialog *MyMessageDialog =
				new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
				MyMessageDialog->run();
				MyMessageDialog->close();
				delete MyMessageDialog;
			}
			else if (action == 5)//outOfOrder
			{
				std::string message{"Out of Order, Exciting flavors coming soon;)"};
				Gtk::MessageDialog *MyMessageDialog =
				new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
				MyMessageDialog->run();
				MyMessageDialog->close();
				delete MyMessageDialog;
				
			}
		
		}
		}
		break;
		case 2:
		{
		product = RestockMachine();
		if(SetOfCokeMachines[machine-1].incrementInventory(product)==1)
		{			
			std::string message1{"Machine has been restocked!!!"};
			Gtk::MessageDialog *MyMessageDialog =
			new Gtk::MessageDialog{message1, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
			MyMessageDialog->run();
			MyMessageDialog->close();
			delete MyMessageDialog;
		}
		else
		{

			std::string message1{"Exceeding machine's capacity!!!"};
			Gtk::MessageDialog *MyMessageDialog =
			new Gtk::MessageDialog{message1, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
			MyMessageDialog->run();
			MyMessageDialog->close();
			delete MyMessageDialog;
		}
		}
		break;
		case 3:
		{

		addChange = AddChange();
		if(SetOfCokeMachines[machine-1].incrementChangeLevel(addChange)==1)
		{

			std::string message1{"The Change has been updated..."};
			Gtk::MessageDialog *MyMessageDialog =
			new Gtk::MessageDialog{message1, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
			MyMessageDialog->run();
			MyMessageDialog->close();
			delete MyMessageDialog;
		}
		else
		{
			std::string message1{"Exceeding machine's capacity!!!"};
			Gtk::MessageDialog *MyMessageDialog =
			new Gtk::MessageDialog{message1, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
			MyMessageDialog->run();
			MyMessageDialog->close();
			delete MyMessageDialog;
		}
		}
		break;
		case 4:
		{
		ostringstream out;
		out << SetOfCokeMachines[machine-1]<<endl;
		string message = out.str();
			Gtk::MessageDialog *MyMessageDialog =
			new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
			MyMessageDialog->run();
			MyMessageDialog->close();
			delete MyMessageDialog;
		}
		break;
		
		case 5:
		{
		cin.ignore();
		machName = UpdateMachineName();
		SetOfCokeMachines[machine-1].setMachineName(machName);
			std::string message1{"Machine Name has been updated..."};
			Gtk::MessageDialog *MyMessageDialog =
			new Gtk::MessageDialog{message1, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
			MyMessageDialog->run();
			MyMessageDialog->close();
			delete MyMessageDialog;
		}
		break;
		
		case 6:
		{
		cokePrice = UpdateCokePrice();
		SetOfCokeMachines[machine-1].setCokePrice(cokePrice);
		//cout <<"Coke Price has been updated..."<<endl;
			std::string message1{"Coke Price has been updated..."};
			Gtk::MessageDialog *MyMessageDialog =
			new Gtk::MessageDialog{message1, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
			MyMessageDialog->run();
			MyMessageDialog->close();
			delete MyMessageDialog;
		}
		break;
	}
	}
	}
}

int main(int argc, char *argv[]){
	Gtk::Main kit(argc, argv);

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
	for(auto it:SetOfCokeMachines)
	{
		cout<<counter<<". "<<it.getMachineName()<<endl;
		counter++;
	}
	cout<<counter<<". Add a New Machine"<<endl;
	cin>>machine;
	if (machine==6)
	{
		CokeMachine MyCokeMachine;
		SetOfCokeMachines.push_back(MyCokeMachine);
	}
	CokeMenu(machine,i,SetOfCokeMachines,payment,change,action,product,addChange,cokePrice,machName,x);
	
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