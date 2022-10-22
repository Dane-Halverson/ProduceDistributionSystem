#pragma once

#include <string>
#include "FoodDist_DataSource.h"

/**
 *
 */
enum class SchoolType {
  elementary,
    middle,
    high
};

/**
 *
 */
struct SchoolInfo
{
  std::string name;
  SchoolType type;
  float budget;
};

struct ProduceInfo
{
  std::string type;
  float weight;
  float cost;
  std::string farm;
};

/**
 *
 */
class FoodDist_DataTester : public FoodDist_DataSource
{
public:
  FoodDist_DataTester();
  virtual ~FoodDist_DataTester() = default;
  
  virtual int retrieveNumberSchools() const override;

  virtual std::string retrieveSchoolName( int schoolIndex ) const override;
  virtual std::string retrieveSchoolType( int schoolIndex ) const override;
  virtual float retrieveSchoolBudget( int schoolIndex ) const override;
  virtual void changeSchoolBudget( int schoolIndex, float newBudget ) override;

  virtual bool retrieveHightestPriorityProduce( std::string& prType, float &weight, float &cost, std::string &farm ) override;
  virtual void returnMostRecentProduceAndLowerPriority() override;

private:
  std::vector<SchoolInfo> m_schools;

  int m_produceCyclicIdx;
  std::vector<ProduceInfo> m_produce;
};
