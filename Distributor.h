#pragma once

/**
 * @author Dane Halverson
 * @file Distributor.h
 * @date  10/17/2022
 * @brief contains Distibutor.h class definition
 */

#include "BinaryHeap.h"
#include "ProduceInterface.h"
#include "School.h"
#include <memory>
#include <vector>
#include <string>
using ProPtr = std::shared_ptr<Produce>;
using HeapPtr = std::shared_ptr<BinaryHeap<ProPtr>>;

/**
 * @brief class for distributing produce to schools
 */
class Distributor
{
private:
    HeapPtr produceHeap;
    HeapPtr rejectedProduceHeap;
    std::vector<School> schools;
    ProPtr next;
    void addProduce(std::string jsonFilename);
    void makeLog();
    void swapHeaps();

public:
    Distributor();
    ~Distributor();

    bool grabNext();
    void pass();
    void buyNext(School s);
    ProPtr getnext();
};
