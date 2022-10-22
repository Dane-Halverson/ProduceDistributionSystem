#include <memory>

#include "FoodDist_GUI.h"
#include "FoodDist_DataTester.h"

int main(int, char**)
{
  FoodDist_GUI foodDistGUI;

  // Create the Data Source and provide to the GUI
  std::shared_ptr<FoodDist_DataSource> fdistSysPtr = std::make_shared<FoodDist_DataTester>();
  foodDistGUI.assignFoodDistSystem( fdistSysPtr );

  foodDistGUI.mainLoop();

  exit(EXIT_SUCCESS);
}
