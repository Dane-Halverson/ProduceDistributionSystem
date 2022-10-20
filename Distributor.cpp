#include "Distributor.h"
#include <ProduceFactory.h>
#include <iostream>

Distributor::Distributor(std::string producefile, std::string schoolfile)
{
    parser = std::make_shared<JSONP>(producefile, schoolfile);
    addProduce();
}

void Distributor::swapHeaps()
{
    HeapPtr temp = produceHeap;
    produceHeap = rejectedProduceHeap;
    rejectedProduceHeap = temp;
}

bool Distributor::grabNext()
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
    for (auto i = 0; i < parser->getProduceCount(); ++i)
    {
        std::string type = parser->getProduceType(i);
        std::cout << parser->getProduceType(i) <<"\n";
        int weight = parser->getProduceWeight(i);
        std::string date = parser->getDate();
        int dayspick;
        /*
        if (parser->produceHasDateOfPick(i))
        {
            Date d1(parser->getDate());
            Date d2(parser->getProduceDateOfPick(i));
            dayspick = d1.getDaysSinceZero() - d2.getDaysSinceZero();
        }
        else
        {
            */
            dayspick = parser->getDaysSincePicked();
        //}
        std::string name = parser->getFarm(i);
        double price = parser->getCPP(i);

        std::cout << parser->getDate();

        ProPtr temp = p.makeProduce(type, weight, date, dayspick, name, price);
        std::cout << "factory worked\n";
        std::cout << temp->getType() << "\n";
        std::cout << temp->getWeight() << "\n";
        std::cout << temp->getFarm() << "\n";
        std::cout << temp->getPricePerPound() << "\n";
        std::cout << temp->getExperString() << "\n";
        produceHeap->insert(temp);
    }
}

bool Distributor::nextGrabbed() {
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