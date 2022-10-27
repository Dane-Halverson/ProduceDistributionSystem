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

Distributor::~Distributor() {
    JSONOut ProduceOut;
    
    //setting current date
    if (next != nullptr) {
        produceHeap->insert(next);
    }
    ProduceOut.setDate("9/11/2001");
    while (stageNext()) {
    
    //setting each produce for json format
    ProduceOut.setType(next->getType());
    ProduceOut.setWeight(next->getWeight());
    ProduceOut.setCost(float(next->getPricePerPound()));
    ProduceOut.setFarm(next->getFarm());
    Date d(curdate.getString());
    d.addDays(0 - produceParser->getDaysSincePicked());
    ProduceOut.setDoP(d.getString());
    ProduceOut.vecPush();

    produceHeap->remove();

    }

    for (int i = 0; i < schools.size(); i++)
    {
        ProduceOut.setSchool(schools[i]->getType(), schools[i]->getName(), schools[i]->getBudget());
    }
    

    ProduceOut.OUT();
}

void Distributor::swapHeaps()
{
    HeapPtr temp = produceHeap;
    produceHeap = rejectedProduceHeap;
    rejectedProduceHeap = temp;
}

bool Distributor::stageNext()
{
    next = nullptr;
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
    curdate.setDate(produceParser->getDate());
    ProduceFactory p;
    for (auto i = 0; i < produceParser->getProduceCount(); ++i)
    {
        std::string type = produceParser->getProduceType(i);
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


        ProPtr temp = p.makeProduce(type, weight, date, dayspick, name, price);
        
        produceHeap->insert(temp);
    }
}

void Distributor::addSchools()
{
    for (auto i = 0; i < schoolParser->getSchoolCount(); ++i)
    {
        std::string name = schoolParser->getSchool(i);
        std::string type = schoolParser->getSchoolType(i);
        double budget = schoolParser->getSchoolBudget(i);
        schools.push_back(std::make_shared<School>(name, type, budget));
    }
}

bool Distributor::produceStaged()
{
    if (next == nullptr)
    {
        return false;
    }
    return true;
}

int Distributor::getNextWeight()
{
    return next->getWeight();
}

std::string Distributor::getNextType()
{
    return next->getType();
}

std::string Distributor::getNextEperation()
{
    return next->getExperString();
}

double Distributor::getNextPrice()
{
    return next->getPricePerPound();
}
std::string Distributor::getNextFarm()
{
    return next->getFarm();
}



SchoolPtr Distributor::findSchool(std::string name)
{
    for (auto i = 0; i < schools.size(); ++i)
    {
        if (schools[i]->getName() == name)
        {
            return schools[i];
        }
    }
    return nullptr;
}

std::string Distributor::getSchoolName(int index) const
{
    return schools[index]->getName();
}

double Distributor::getSchoolBudget(int index) const
{
    return schools[index]->getBudget();
}

std::string Distributor::getSchoolType(int index) const
{
    return schools[index]->getType();
}

int Distributor::getSchoolCount() const
{
    return int(schools.size());
}

void Distributor::setSchoolBudget(int index, float amount)
{
    schools[index]->setBudget(amount);
}

void Distributor::pass() {
    rejectedProduceHeap->insert(next);
    next = nullptr;
}
