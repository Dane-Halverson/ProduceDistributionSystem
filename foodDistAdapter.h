#include <Distributor.h>
#include "FoodDist_DataSource.h"


class FoodDistributor : FoodDist_DataSource {
public:
	int retrieveNumberSchools() const;
	std::string retrieveSchoolName(int schoolIndex) const;
	std::string retrieveSchoolType(int schoolIndex) const;
	float retrieveSchoolBudget(int schoolIndex) const;
	float retrieveSchoolBudget(int schoolIndex) const;
	bool retrieveHightestPriorityProduce(std::string& prType, float& weight, float& cost, std::string& farm);
	void returnMostRecentProduceAndLowerPriority();
};
