#pragma once
#include <vector>
#include <cmath>
// template <class T> struct less;

template <typename T, typename comparator = std::less<>>
class binaryHeap
{
private:
    // hold comparator, so we know if > or <
    comparator m_cmpObject;

    std::vector<T> m_heap;

    static constexpr auto m_rootIdx{1};      // sets root index to 1 isntead of 0
    static constexpr auto m_initialSize{64}; // default size for heap
    unsigned int m_nextIdx;
    void swap(unsigned int idx1, unsigned int idx2);
    void floatUp(unsigned int idx);
    void sinkDown(unsigned int idx);

public:
    binaryHeap();
    explicit binaryHeap(const int initSize);
    T remove();
    void insert(const T &t);
    auto getSizeIdx() { return m_heap.size(); }
    int maxSize;
};

template <typename T, typename comparator>
binaryHeap<T, comparator>::binaryHeap() : m_cmpObject(), m_heap(m_initialSize), m_nextIdx(m_rootIdx)
{
    maxSize = m_initialSize;
}

template <typename T, typename comparator>
binaryHeap<T, comparator>::binaryHeap(const int initSize) : m_cmpObject(), m_heap(initSize), m_nextIdx(m_rootIdx)
{
    maxSize = initSize;
}

template <typename T, typename comparator>
void binaryHeap<T, comparator>::insert(const T &t)
{
    if (maxSize <= m_nextIdx)
    {
        m_heap.resize(maxSize * 2);
        maxSize = maxSize * 2;
    }
    else
    {
        // insert next avail index
        m_heap[m_nextIdx] = t;
        floatUp(m_nextIdx);
        m_nextIdx++;
    }
}

template <typename T, typename comparator>
void binaryHeap<T, comparator>::swap(unsigned int idx1, unsigned int idx2)
{
    T temp = m_heap[idx1];
    m_heap[idx1] = m_heap[idx2];
    m_heap[idx2] = temp;
}

template <typename T, typename comparator>
void binaryHeap<T, comparator>::floatUp(unsigned int idx)
{
    // catch the root
    if (idx <= m_rootIdx)
        return;
    auto parentIdx = floor(idx / 2);
    if (m_cmpObject(m_heap[idx], m_heap[parentIdx]))
    {
        swap(parentIdx, idx);
        floatUp(parentIdx);
    }
}

template <typename T, typename comparator>
void binaryHeap<T, comparator>::sinkDown(unsigned int idx)
{
    unsigned int swapIdx = idx;

    auto leftChIdx = idx * 2;
    auto rightChIdx = idx * 2 + 1;

    if ((leftChIdx < m_nextIdx) && (m_cmpObject(m_heap[leftChIdx], m_heap[idx])))
        swapIdx = leftChIdx;
    if ((leftChIdx < m_nextIdx) && (m_cmpObject(m_heap[idx], m_heap[rightChIdx])))
        swapIdx = rightChIdx;
    if (swapIdx != idx)
    {
        swap(swapIdx, idx);
        sinkDown(swapIdx);
    }
}

template <typename T, typename comparator>
T binaryHeap<T, comparator>::remove()
{
    T cpRoot = m_heap[m_rootIdx];

    m_nextIdx = m_nextIdx - 1;

    m_heap[m_rootIdx] = m_heap[m_nextIdx];

    sinkDown(m_rootIdx);
    return cpRoot;
}