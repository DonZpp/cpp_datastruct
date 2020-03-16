#ifndef DONZ_DATASTRUCT_NODE_H
#define DONZ_DATASTRUCT_NODE_H

#include "../base/Define.h"

template<typename RealNode>
class Node
{
public:

    Node();

    virtual ~Node();

public:

    RealNode * GetLast() const;

    virtual RealNode * GetNext() const;

    void SetLast(RealNode* pLast);

    void SetNext(RealNode* pNext);

    virtual const long long GetID() const = 0;

protected:

    RealNode *m_pLast;

    RealNode *m_pNext;

};


template<typename RealNode>
Node<RealNode>::Node():m_pLast(0), m_pNext(0) 
{
}


template<typename RealNode>
Node<RealNode>::~Node()
{
}


template<typename RealNode>
RealNode *Node<RealNode>::GetLast() const
{
    return m_pLast;
}

template<typename RealNode>
RealNode *Node<RealNode>::GetNext() const
{
    return m_pNext;
}

template<typename RealNode>
void Node<RealNode>::SetLast(RealNode *const pLast)
{
    m_pLast = pLast;
}

template<typename RealNode>
void Node<RealNode>::SetNext(RealNode *const pNext)
{
    m_pNext = pNext;
}

#endif
