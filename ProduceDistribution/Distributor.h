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
    void makeLog();
    void swapHeaps();
    void addProduce();
    void addSchools();
    SchoolPtr findSchool(std::string name);

    

public:
    Distributor(std::string producefile, std::string schoolfile);
    ~Distributor() = default;

    bool stageNext();
    void pass();
    void buyNext(SchoolPtr s);

    bool produceStaged();
    int getNextWeight();
    std::string getNextType();
    std::string getNextEperation();
    double getNextPrice();
    std::string getNextFarm();

    std::string getSchoolName(int index) const;
    double getSchoolBudget(int index) const;
    std::string getSchoolType(int index) const;
    int getSchoolCount() const;
    void setSchoolBudget(int index, float amount);



};

struct CompareProduce
{
    bool operator()(const ProPtr &lhs, const ProPtr &rhs) const
    {
        return (lhs->getExperInt() > rhs->getExperInt());
    }
};
