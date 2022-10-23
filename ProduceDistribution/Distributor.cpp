#include "Distributor.h"
#include <ProduceFactory.h>
#include <iostream>

Distributor::Distributor(std::string producefile, std::string schoolfile)
{
    produceParser = std::make_shared<JSONP>(producefile);
    schoolParser = std::make_shared<JSONPS>(schoolfile);

    addProduce();
    addSchools();
}

void Distributor::swapHeaps()
{
    HeapPtr temp = produceHeap;
    produceHeap = rejectedProduceHeap;
    rejectedProduceHeap = temp;
}

bool Distributor::stageNext()
{
    if (produceHeap->getSize() == 0)
    {
        swapHeaps();
    }
    if (produceHeap->getSize() != 0)
    {
        next = produceHeap->remove();
        return true;
    }
    return false;
}

void Distributor::addProduce()
{
    ProduceFactory p;
    for (auto i = 0; i < produceParser->getProduceCount(); ++i)
    {
        std::string type = produceParser->getProduceType(i);
        std::cout << produceParser->getProduceType(i) <<"\n";
        int weight = produceParser->getProduceWeight(i);
        std::string date = produceParser->getDate();
        int dayspick;
        
        if (produceParser->produceHasDateOfPick(i))
        {
            Date d1(produceParser->getDate());
            Date d2(produceParser->getProduceDateOfPick(i));
            dayspick = d1.getDaysSinceZero() - d2.getDaysSinceZero();
        }
        else
        {
            
            dayspick = produceParser->getDaysSincePicked();
        }
        std::string name = produceParser->getFarm(i);
        double price = produceParser->getCPP(i);

        std::cout << produceParser->getDate() << "\n";

        ProPtr temp = p.makeProduce(type, weight, date, dayspick, name, price);
        std::cout << "factory worked\n";
        std::cout << temp->getType() << "\n";
        std::cout << temp->getExperString() << "\n";
        produceHeap->insert(temp);
    }
}

void Distributor::addSchools() {
    for (auto i = 0; i < schoolParser->getSchoolCount(); ++i) {
        std::string name = schoolParser->getSchool(i);
        std::string type = schoolParser->getSchoolType(i);
        double budget = schoolParser->getSchoolBudget(i);
        schools.push_back(std::make_shared<School>(name, type, budget));
    }
}

bool Distributor::produceStaged() {
    if (next == nullptr) {
        return false;
    }
    return true;
}

int Distributor::getNextWeight() {
    return next->getWeight();
}

std::string Distributor::getNextType() {
    return next->getType();
}

std::string Distributor::getNextEperation() {
    return next->getExperString();
}

double Distributor::getNextPrice() {
    return next->getPricePerPound();
}
std::string Distributor::getNextFarm() {
    return next->getFarm();
}

void Distributor::buyNext(SchoolPtr s) {
    if (s->getBudget() < (next->getGetPrice()*1) {
        std::string message = "error: school doesn't have enough budget to buy this produce\n";
        throw message;
    }
    else if (s->getBudget() < (next->getGetPrice()*next->getWeight()) {
        s->getBudget()
    }
    s->addProduce(next);
    next = nullptr;
    stageNext();
}

SchoolPtr Distributor::findSchool(std::string name) {
    for (auto i = 0; i < schools.size(); ++i) {
        if (schools[i]->getName() == name) {
            return schools[i];
        }
    }
    return nullptr;
}


