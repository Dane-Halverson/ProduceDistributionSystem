#pragma once

/**
 * @author Dane Halverson
 * @file Distributor.h
 * @date  10/17/2022
 * @brief contains Distibutor.h class definition
 */
struct CompareProduce;

#include "BinaryHeap.h"
#include "ProduceInterface.h"
#include "School.h"
#include "JSONP.h"
#include "JSONPS.h"
#include "JSONOut.h"
#include <memory>
#include <vector>
#include <string>
using ProPtr = std::shared_ptr<Produce>;
using HeapPtr = std::shared_ptr<BinaryHeap<ProPtr, CompareProduce>>;
using SchoolPtr = std::shared_ptr<School>;

/**
 * @brief class for distributing produce to schools
 */
class Distributor
{
private:
    HeapPtr produceHeap = std::make_shared<BinaryHeap<ProPtr, CompareProduce>>();
    HeapPtr rejectedProduceHeap = std::make_shared<BinaryHeap<ProPtr, CompareProduce>>();
    std::vector<SchoolPtr> schools;
    std::shared_ptr<JSONP> produceParser;
    std::shared_ptr<JSONPS> schoolParser;
    ProPtr next;
    Date curdate;

    void swapHeaps();
    void addProduce();
    void addSchools();
    SchoolPtr findSchool(std::string name);

    

public:
    /**
     * @brief constructor 
     * @param producefile filepath for produce json
     * @param schoolfile filepath for school json
     */
    Distributor(std::string producefile, std::string schoolfile);
    ~Distributor();

    /**
     * @brief stages the next produce of highest priority
     * @return true if there is produce left
     */
    bool stageNext();

    /**
     * @brief reinserts stagged produce into heap with lower priority
     */
    void pass();

    /**
     * @brief checks if produce is staged
     * @return true if next not nulptr
     */
    bool produceStaged();

    /**
     * @brief gets weight of staged produce
     * @return weight of staged produce
     */
    int getNextWeight();

    /** 
     * @return type of staged produce
     */
    std::string getNextType();

    /**
     * @brief will return in the foramt Mon dd yyy
     * @return the experation date of the staged produce
     */
    std::string getNextEperation();

    /**
     * @return price per pound of the staged produce
     */
    double getNextPrice();

    /**
     * @return the farm of the staged produce
     */
    std::string getNextFarm();

    /**
     * @param index index of the school to get from
     * @return the name of the school
     */
    std::string getSchoolName(int index) const;

    /**
     * @param index index of the school to get from
     * @return the schools budget
     */
    double getSchoolBudget(int index) const;

    /**
     * @param index index of the school to get from
     * @return the type of the school
     */
    std::string getSchoolType(int index) const;

    /**
     * @return how many schools there are
     */
    int getSchoolCount() const;

    /**
     * @param index index of the school to get from
     * @param amount the amount to set the schools budget to 
     */
    void setSchoolBudget(int index, float amount);



};

/**
 * @brief struct for comapring the expertation of two produce objects
 */
struct CompareProduce
{
    bool operator()(const ProPtr &lhs, const ProPtr &rhs) const
    {
        return (lhs->getExperInt() < rhs->getExperInt());
    }
};
