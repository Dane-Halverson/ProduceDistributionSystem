#include <memory>

#include "FoodDist_GUI.h"
#include "foodDistAdapter.h"
#include <iostream>
#include <string>



int main(int, char**)
{
  FoodDist_GUI foodDistGUI;


  std::string pf = "produce.json";
  std::string sf = "schools.json";



  // Create the Data Source and provide to the GUI
  std::shared_ptr<FoodDist_DataSource> fdistSysPtr =
	  std::make_shared<FoodDistributor>(pf,sf);
  foodDistGUI.assignFoodDistSystem( fdistSysPtr );

  foodDistGUI.mainLoop();

  exit(EXIT_SUCCESS);
}

