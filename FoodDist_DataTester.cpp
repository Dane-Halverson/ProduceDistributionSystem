#include <cassert>

#include "FoodDist_DataTester.h"

FoodDist_DataTester::FoodDist_DataTester()
  : m_schools{ { "Ordean East", SchoolType::middle, 232.00 },
	       { "Denfeld", SchoolType::high, 832.00 },
	       { "Myers-Wilkins", SchoolType::elementary, 132.00 },
	       { "Congon", SchoolType::elementary, 302.00 },
	       { "East", SchoolType::high, 732.00 },
	       { "Lakeside", SchoolType::elementary, 132.00 } },
    m_produceCyclicIdx(0),
    m_produce{ { "tomatoes", 28.0f, 1.91f, "Food Farm" },
	       { "lettuce", 12.0f, 3.98f, "Small Acres" },
	       { "carrots", 43.0f, 1.20f, "Food Farm" },
	       { "cucumbers", 32.0f, 0.75f, "Little Small Farm" },
	       { "beets", 20.0f, 3.20f, "Farmer Doug" },
	       { "onions", 12.0f, 1.90f, "East School Garden" } }
{
}

int FoodDist_DataTester::retrieveNumberSchools() const
{
  return (int)m_schools.size();
}

std::string FoodDist_DataTester::retrieveSchoolName( int schoolIndex ) const
{
  assert( schoolIndex >= 0 && schoolIndex < m_schools.size() );
  return m_schools[ schoolIndex ].name;
}

std::string FoodDist_DataTester::retrieveSchoolType( int schoolIndex ) const 
{
  assert( schoolIndex >= 0 && schoolIndex < m_schools.size() );
  if (m_schools[ schoolIndex ].type == SchoolType::elementary)
    return "Elementary School";
  else if (m_schools[ schoolIndex ].type == SchoolType::middle)
    return "Middle School";
  else if (m_schools[ schoolIndex ].type == SchoolType::high)
    return "High School";
  else
    return "Unknown School Type";
}

float FoodDist_DataTester::retrieveSchoolBudget( int schoolIndex ) const
{
  assert( schoolIndex >= 0 && schoolIndex < m_schools.size() );
  return m_schools[ schoolIndex ].budget;
}

void FoodDist_DataTester::changeSchoolBudget( int schoolIndex, float newBudget )
{
  assert( schoolIndex >= 0 && schoolIndex < m_schools.size() );
  m_schools[ schoolIndex ].budget = newBudget;
}


bool FoodDist_DataTester::retrieveHightestPriorityProduce( std::string& prType, float &weight, float &cost, std::string &farm )
{
  prType = m_produce[ m_produceCyclicIdx ].type;
  weight = m_produce[ m_produceCyclicIdx ].weight;
  cost = m_produce[ m_produceCyclicIdx ].cost;
  farm = m_produce[ m_produceCyclicIdx ].farm;

  m_produceCyclicIdx = (m_produceCyclicIdx + 1) % m_produce.size();

  return true;
}

void FoodDist_DataTester::returnMostRecentProduceAndLowerPriority()
{
  // last item from the test was at index
  auto tmpIdx = (m_produceCyclicIdx - 1) % m_produce.size();

  // to mimic lowering the priority, swap with item at end of list
  auto tmpData = m_produce[ tmpIdx ];

  assert( (m_produce.size() - 1) > 0 );
  m_produce[tmpIdx] = m_produce[ m_produce.size() - 1 ];
  m_produce[ m_produce.size() - 1 ] = tmpData;
}
