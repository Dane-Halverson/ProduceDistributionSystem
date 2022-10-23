#include <Distributor.h>
#include "FoodDist_DataSource.h"
#include <memory>

class FoodDistributor : public FoodDist_DataSource
{
private:
std::shared_ptr<Distributor> dist;
public:
	FoodDistributor(std::string projson, std::string schooljson) : dist(std::make_shared<Distributor>(projson, schooljson)){}

	int retrieveNumberSchools() const {return dist->getSchoolCount();}

	std::string retrieveSchoolName(int schoolIndex) const {return dist->getSchoolName(schoolIndex);}

	std::string retrieveSchoolType(int schoolIndex) const {return dist->getSchoolType(schoolIndex);}

	float retrieveSchoolBudget(int schoolIndex) const {return dist->getSchoolBudget(schoolIndex);}

	void changeSchoolBudget(int schoolIndex, float newBudget) {dist->setSchoolBudget(schoolIndex, newBudget);}

	bool retrieveHightestPriorityProduce(std::string &prType, float &weight, float &cost, std::string &farm) {
		prType = dist->getNextType();
		weight = dist->getNextWeight();
		cost = dist->getNextPrice();
		farm = dist->getNextFarm();
		dist->stageNext();
	}

	void returnMostRecentProduceAndLowerPriority() {dist->pass();}
};
