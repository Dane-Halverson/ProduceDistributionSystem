#include "Distributor.h"
#include "ProduceFactory.h"

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

ProPtr Distributor::getnext() {
    return next;
}