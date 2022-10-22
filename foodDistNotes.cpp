#include <iostream>
#include <memory>

// #include "handleGraphicsArgs.h"
#include "GLSceneRenderer.h"


class SchoolList
{
public:
  
};


class DistributionItem
{
public:
  
};


class FoodDistStub {
public:
  
};



int main(int argc, char *argv[])
{
  FarmToSchoolManager f2s;

  // acquire information about schools participating
  // name
  // budget
  // f2s.addSchool();
  
  FoodDistFactory fdFactory;

  while (simulationTime < maxTime) {

    // query next food available for schools
    // get type
    // get weight
    // get cost
    // get farm info

    // add distribution item to simulation
    f2s.nextItemForDistribution();

    bool providedToSchool = attemptToDistribute(currentTime);

    if (!providedToSchool) {
      // how much was left

      // insert back into food distribution system
      
    }
  }

  // close down food system until next run
}


void insertItemForDistribution
{
  take it, place it in system...
}


// maximize the food getting to the schools
// Needs list of schools and their budgets

class FarmToSchoolManager
{
public:
  void addSchool(const std::string, const float budget);

private:
  std::map< const std::string, float > m_schoolBudgetMap;
  
};



class FoodDistItem {
public:
private:
};

 FoodDistFactory {
 public:
   shared_ptr<
 };

class FoodDistSys {
public:
private:
  FoodDistItem currItem;
};
