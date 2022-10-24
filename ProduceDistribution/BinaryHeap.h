#pragma once
/**
 * @file BinaryHeap.h
 * @date 9/29/2022
 */

#include <vector>
#include <functional> // std::less
#include <cmath>
#include <iostream>

/**
 * @class BinaryHeap
 * @brief a heap based priority queue
 */
template <typename t,
          typename Comparator = std::less<>>
class BinaryHeap
{
private:
    static constexpr auto m_defaultHeapSize{64};
    static constexpr auto m_rootIdx{1};
    std::vector<t> m_heap;
    unsigned int m_nextIdx;
    unsigned int cursize;
    int heapSize = 0;

    Comparator m_compObj;

    void floatUp(const unsigned int idx);
    void sinkDown(const unsigned int idx);
    void swap(unsigned int x, unsigned int y);

public:
    /// @brief default constr. heap max size starts at 64
    BinaryHeap();

    /// @brief constructor to create a heap with a differnt max size
    /// @param size the size to set it too
    BinaryHeap(int size);

    /// @brief inserts a item into the heap
    /// @param T the item to insert
    void insert(const t &T);

    /// @brief removes next item from heap
    /// @return the item that was removed
    t remove();

    /// @brief gets how many items are in the heap
    /// @return amount of items in heap
    int getSize();

    int getMaxSize();
};

template <typename t,
          typename Comparator>
BinaryHeap<t, Comparator>::BinaryHeap() : m_heap(m_defaultHeapSize), m_nextIdx(1), cursize(m_defaultHeapSize)
{
}

template <typename t,
          typename Comparator>
BinaryHeap<t, Comparator>::BinaryHeap(int size) : m_heap(size), m_nextIdx(1), cursize(size)
{
}

template <typename t,
          typename Comparator>
void BinaryHeap<t, Comparator>::insert(const t &T)
{
    if (heapSize == int(cursize - 2))
    {
        cursize = cursize * 2;
        m_heap.resize(cursize);
    }
    m_heap[m_nextIdx] = T;
    floatUp(m_nextIdx);
    m_nextIdx = m_nextIdx + 1;
    ++heapSize;
}

template <typename t,
          typename Comparator>
t BinaryHeap<t, Comparator>::remove()
{
    t copyToReturn = m_heap[m_rootIdx];

    m_nextIdx = m_nextIdx - 1;

    m_heap[m_rootIdx] = m_heap[m_nextIdx];

    sinkDown(m_rootIdx);

    --heapSize;

    return copyToReturn;
}

template <typename t,
          typename Comparator>
void BinaryHeap<t, Comparator>::floatUp(const unsigned int idx)
{
    if (idx <= m_rootIdx)
    {
        return;
        std::cout << "returned correctly\n";
    }

    auto parentIdx = int(floor(idx / 2));

    if (m_compObj(m_heap[parentIdx], m_heap[idx]))
    {
        swap(parentIdx, idx);
        floatUp(parentIdx);
    }
}

template <typename t,
          typename Comparator>
void BinaryHeap<t, Comparator>::swap(unsigned int x, unsigned int y)
{
    t temp = m_heap[x];
    m_heap[x] = m_heap[y];
    m_heap[y] = temp;
}

template <typename t,
          typename Comparator>
void BinaryHeap<t, Comparator>::sinkDown(const unsigned int idx)
{
    auto currentIdxToSwap = idx;
    auto leftIdx = idx * 2;
    auto rightIdx = idx * 2 + 1;

    if ((leftIdx < m_nextIdx) && m_compObj(m_heap[leftIdx], m_heap[currentIdxToSwap]))
        currentIdxToSwap = leftIdx;

    if ((rightIdx < m_nextIdx) && m_compObj(m_heap[rightIdx], m_heap[currentIdxToSwap]))
        currentIdxToSwap = rightIdx;

    if (currentIdxToSwap != idx)
    {
        swap(currentIdxToSwap, idx);
        sinkDown(currentIdxToSwap);
    }
}

template <typename t,
          typename Comparator>
int BinaryHeap<t, Comparator>::getSize()
{
    return heapSize;
}

template <typename t,
          typename Comparator>
int BinaryHeap<t, Comparator>::getMaxSize()
{
    return cursize;
}
