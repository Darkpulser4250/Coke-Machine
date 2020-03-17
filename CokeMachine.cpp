// Muhammad Daud 1001439613//
// Coke Machine.cpp
#include <iostream>
#include <string>
#include <vector>
#include "CokeMachine.h"
#include <stdexcept>

	 CokeMachine :: CokeMachine(std::string name,int change,int cost, int inventory)
		{
			CokePrice = cost;
			inventoryLevel = inventory;
			setMachineName(name);
			incrementChangeLevel(change);
		}
	 CokeMachine :: ~CokeMachine()
	 {
	 }
	
	void CokeMachine :: setCokePrice(int newCokePrice)
	{
		CokePrice = newCokePrice;
	}
	  
	bool CokeMachine :: buyACoke(int payment, std::string& change, int& action)
	  {
		  int ChangeLevel;
		bool paymentCheck = true;
		enum actions{insufficientFunds,exactChange,works,noInventory,noChange,outOfOrder};
		if (payment < CokePrice)			
		{
			action = insufficientFunds;
			paymentCheck = false;
		}
		else if (payment == CokePrice)
		{
			action = exactChange;
			ChangeLevel = (CokeMachine:: getChangeLevel())+payment;  // local change value
			CokeMachine :: incrementChangeLevel(ChangeLevel);
			inventoryLevel = (CokeMachine :: getInventoryLevel()-1);
		}
		else if ((payment > CokePrice)&&(payment<(CokeMachine :: getChangeLevel())))
		{
			action = works;
			ChangeLevel = (CokeMachine :: getChangeLevel()) + CokePrice;
			CokeMachine :: incrementChangeLevel(ChangeLevel);
			change = CokeMachine :: displayMoney(payment-CokePrice);
			inventoryLevel = (CokeMachine :: getInventoryLevel()-1);
		}
		else if (inventoryLevel == 0)
		{
			action = noInventory;
			paymentCheck = false;
		}
		else if (payment>(CokeMachine :: getChangeLevel()))
		{
			action = noChange;
			paymentCheck = false;
		}
		else
		{
			action = outOfOrder;
			paymentCheck = false;
		}
		return paymentCheck;
	  }
	  
	  int CokeMachine :: getInventoryLevel()
	  {
		  return inventoryLevel;
	  }
	  
	  int CokeMachine :: getMaxInventoryCapacity()
	  {
		  return maxInventoryCapacity;
	  }
	  
	  bool CokeMachine :: incrementInventory(int amountToAdd)
	  { 
	     bool inventoryCheck = true;
		 if((amountToAdd+inventoryLevel)<=maxInventoryCapacity)
		 {
			 inventoryLevel +=amountToAdd;
		 }
		 else if ((amountToAdd+inventoryLevel)>maxInventoryCapacity)
		 {
			 inventoryCheck = false;
		 }
		 
		return inventoryCheck;
	  }
	  	
	std::string CokeMachine :: getCokePrice(void)
	  {
		  return CokeMachine :: displayMoney(CokePrice);
	  }
	

	  
	void CreateCokeOutputLine(CokeMachine& MyCokeMachine)
	{
	std::cout<<MyCokeMachine.getMachineName();
	std::cout<<"|";
	std::cout<<MyCokeMachine.getCokePrice();
	std::cout<<"|";
	std::cout<<MyCokeMachine.getChangeLevel();
	std::cout<<"|";
	std::cout<<MyCokeMachine.inventoryLevel<<std::endl;
	}
	std::ostream &operator <<(std::ostream &output,CokeMachine &coke)
		{       
			output<<"Machine Name: "<<coke.CokeMachine :: getMachineName()<<std::endl; 
			output<<"inventoryLevel: "<<coke.CokeMachine :: getInventoryLevel()<<std::endl;
			output<<"maxInventoryCapacity: "<<coke.CokeMachine :: getMaxInventoryCapacity()<<std::endl;
			output<<"changeLevel: "<<coke.CokeMachine :: getChangeLevel()<<std::endl;
			output<<"Max Change Level: "<<coke.CokeMachine :: getMaxChangeCapacity()<<std::endl;
			output<<"CokePrice: "<<coke.CokeMachine :: getCokePrice()<<std::endl;
            return output;
		}
	
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  



























