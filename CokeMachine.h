//Muhammad Daud 1001439613
// CokeMachine.h

#ifndef COKE_MACHINE_H
#define COKE_MACHINE_H
#include <string>
#include "VendingMachine.h"
class CokeMachine : public VendingMachine
{
	public:
	  CokeMachine(std::string name = "New Machine",int change = 500,int cost = 50, int inventory = 100);
	  ~CokeMachine();
	  	  
	  void setCokePrice(int newCokePrice);
	  
	  bool buyACoke(int payment, std::string& change, int& action);
	  
	  int getInventoryLevel();
	  
	  bool incrementInventory(int amountToAdd);
	  
	  int getMaxInventoryCapacity();

	  std::string getCokePrice(void);
	  
	  friend std::ostream &operator <<(std::ostream &output,CokeMachine &coke);
	  friend void CreateCokeOutputLine(CokeMachine& MyCokeMachine);

	
	private: 
	int CokePrice;
	int inventoryLevel;
	int maxInventoryCapacity{100};
};
#endif
