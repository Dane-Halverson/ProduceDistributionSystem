#pragma once

#include <vector>

/**
 * @class FoodDist_DataSource
 * @brief This class is an interface used by the FoodDist_GUI frontend.
 *
 * This class acts as an inerface to the FoodDist_GUI frontend. This class can be derived
 * as it is strictly an interface.  Supporting the calls of this interface will allow the
 * FoodDist_GUI to retrieve and return information back to the implementation of the food
 * distribution data source.
 */
class FoodDist_DataSource
{
 public:

  /**
   * Returns the number of schools participating in the farm to school
   * food program. This is the total number of schools the food system
   * knows about after reading in data from the input sources.
   *
   * @return An integer representing the number of schools.
   */
  virtual int retrieveNumberSchools() const = 0;

  /**
   * Retrieves the name of the school given the index of the
   * school. 
   *
   * @param schoolIndex The index of the school is an indentifer
   * that can be used to look up information about the school in the
   * food system.
   * @return A string containing the school's name.
   */
  virtual std::string retrieveSchoolName( int schoolIndex ) const = 0;

  /**
   * Retrieves the type of the school given the index of the
   * school. 
   *
   * @param schoolIndex The index of the school is an indentifer
   * that can be used to look up information about the school in the
   * food system.
   * @return A string containing the type of the school.  For
   * instance, Middle School, or High School, or HS, etc...
   */
  virtual std::string retrieveSchoolType( int schoolIndex ) const = 0;
  
  /**
   * Retrieves the current budget associated with the school given the
   * index of the school. 
   *
   * @param schoolIndex The index of the school is an indentifer
   * that can be used to look up information about the school in the
   * food system.
   * @return A float representing the current budget the school has to
   * purchase food.
   */
  virtual float retrieveSchoolBudget( int schoolIndex ) const = 0;

  /**
   * Allows the FoodDist_GUI program to return new information about a
   * school's budget after produce has been purchased by the farm to
   * school manager using the FoodDist GUI front end. 
   *
   * @param schoolIndex The index of the school is an indentifer
   * that can be used to look up information about the school in the
   * food system.
   * @param newBudget The updated information about how much money a
   * particular school has remaining after purchasing food.
   */  
  virtual void changeSchoolBudget( int schoolIndex, float newBudget ) = 0;

  /**
   * The Food Distribution GUI front end will call this function to
   * retrieve the next highest priority produce to be sold to schools.
   * This function fills in the various parameters passed in by
   * reference about the produce that is ready to be distributed.
   *
   * @param prType A string containing the type of produce.
   * 
   * @param weight A float representing the weight of the
   * produce. Assumed to be in pounds.
   * 
   * @param cost A float representing the cost per pound of the produce.
   *
   * @param farm A string containing the name of the farm where the
   * produce originated.
   *
   * @return A boolean is returned to indicate if the call was
   * successful in getting additional produce.  The function returns
   * true if the call to get the hightest priority produce is
   * successful, meaning there was still produce available.  The
   * function returns false if there was no produce available.
   */
  virtual bool retrieveHightestPriorityProduce( std::string& prType, float &weight, float &cost, std::string &farm ) = 0;

  /**
   * When produce is unable to be matched with a school, the Farm to
   * School Coordiator using the Food Distribution GUI front end will
   * request the produce be returned back into the queue for later
   * processing.  When this happens the produce's priority should be
   * lowered so that other produce items can be provided to the
   * schools.
   *
   * This function requires that the class that implements this will
   * have a record or data about the last item sent into the Food
   * Distribution front end.
   */
  virtual void returnMostRecentProduceAndLowerPriority() = 0;
};
