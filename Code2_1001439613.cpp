// Muhammad Daud 1001439613//
// Codeing Assignment 2

#include <iostream>
#include <sstream>
#include "CokeMachine.h"

using namespace std;

int main(void){
	int i=1;
	int x;
	int payment;
	string change;
	int action;
	int product,addChange;
	
	
	CokeMachine MyCokeMachine{"CSE 1325 Coke Machine",50,500,100};
	
	while(i==1){
	cout << "What would you like to do?" <<endl;
	cout << "0: Walk Away" <<endl;
	cout << "1: Buy a Coke" << endl;
	cout << "2: Restock Machine" << endl;
	cout << "3: Add Change" << endl;
	cout << "4: Display Machine Info" <<endl;
	cin >> x;
	switch (x){
		case 0:
		i = 0;
		cout << "I see how it is, you like PEPSI better huh?!?!?!?" <<endl;
		break;
		case 1:
		cout << "Insert Payment: " << endl;
		cin >> payment;
		if(MyCokeMachine.buyACoke(payment,change,action)==1)
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
		else if (MyCokeMachine.buyACoke(payment,change,action)==0)
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
		if(MyCokeMachine.incrementInventory(product)==1)
		{
			cout<<"Machine has been restocked!!!"<<endl;
			cout<<"Inventory Level: "<<MyCokeMachine.getInventoryLevel()<<endl;
		}
		else
		{
			cout<<"Exceeding machine's capacity!!!"<<endl;
			cout<<"Inventory Level: " <<MyCokeMachine.getInventoryLevel()<<endl;
		}
		break;
		case 3:
		cout << "3: Add Change to machine:" << endl;
		cin>>addChange;
		if(MyCokeMachine.incrementChangeLevel(addChange)==1)
		{
			cout<<"The Change has been updated..."<<endl;
			cout<<"Change Level: "<<MyCokeMachine.getChangeLevel()<<endl;
		}
		else
		{
			cout<<"Exceeding machine's capacity!!!"<<endl;
			cout<<"Change Level: " <<MyCokeMachine.getChangeLevel()<<endl;
		}
		break;
		case 4:
		cout << "4: Display Machine Info:" <<endl;
		cout << "- Inventory Level: "<<MyCokeMachine.getInventoryLevel()<<endl;
		cout << "- Max Inventory Capacity: "<<MyCokeMachine.getMaxInventoryCapacity()<<endl;
		cout << "- Change Level: "<<MyCokeMachine.getChangeLevel()<<endl;
		cout << "- Max Change Level: "<<MyCokeMachine.getMaxChangeCapacity()<<endl;
		cout << "- Coke Price: "<<MyCokeMachine.getCokePrice()<<endl;
		break;
	}
	}
	return 0;

}