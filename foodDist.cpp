#include <memory>

#include "FoodDist_GUI.h"
#include "foodDistAdapter.h"

int main(int, char**)
{
  FoodDist_GUI foodDistGUI;
  std::string pf = "C:/Users/USER/source/repos/Food-Distribution-System-new/testJSONP.json";
  std::string sf = "C:/Users/USER/source/repos/Food-Distribution-System-new/testJSONS.json";

  // Create the Data Source and provide to the GUI
  std::shared_ptr<FoodDist_DataSource> fdistSysPtr =
	  std::make_shared<FoodDistributor>(pf,sf);
  foodDistGUI.assignFoodDistSystem( fdistSysPtr );

  foodDistGUI.mainLoop();

  exit(EXIT_SUCCESS);
}
