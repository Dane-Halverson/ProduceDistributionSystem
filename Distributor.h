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
#include <memory>
#include <vector>
#include <string>
using ProPtr = std::shared_ptr<Produce>;
using HeapPtr = std::shared_ptr<BinaryHeap<ProPtr, CompareProduce>>;

/**
 * @brief class for distributing produce to schools
 */
class Distributor
{
private:
    HeapPtr produceHeap;
    HeapPtr rejectedProduceHeap;
    std::vector<School> schools;
    std::shared_ptr<JSONP> parser;
    ProPtr next;
    void makeLog();
    void swapHeaps();
    void addProduce();
    void addSchools();
    

public:
    Distributor(std::string producefile, std::string schoolfile);
    ~Distributor() = default;

    bool stageNext();
    void pass();
    void buyNext(School s);

    bool produceStaged();
    int getNextWeight();
    std::string getNextType();
    std::string getNextEperation();
    double getNextPrice();
    std::string getNextFarm();


};

struct CompareProduce
{
    bool operator()(const ProPtr &lhs, const ProPtr &rhs) const
    {
        return (lhs->getExperInt() < rhs->getExperInt());
    }
};
