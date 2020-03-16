#ifndef DONZ_DATASTRUCT_LIST_H
#define DONZ_DATASTRUCT_LIST_H

#include<stdexcept>

/*
 *  Head node save data.
 */


template <typename Node>
class List
{
public:

    List();
    ~List();

public:

    virtual int Add(const Node &_newNode);

    virtual void Del(const long long iNodeID);

    virtual int Update(const Node &stUpNode);

    Node Get(const long long iNodeID) const;

    // Include Head
    const int GetNodeCount() const;

    Node *AddNewNode(const Node &);

    void DeleteNode(Node *);

    const Node *GetHead() const;

protected:

    Node *m_pHead;

private:

    int m_iNodeCount;

};


template <typename Node>
const Node *List<Node>::GetHead() const
{
    return m_pHead;
}


template <typename Node>
const int List<Node>::GetNodeCount() const
{
    return m_iNodeCount;
    /*
    if (m_pHead == 0)
    {
        return 0;
    }
    else
    {
        int iCount = 1;
        Node *pNode = m_pHead;

        while(pNode->GetNext() != 0)
        {
            pNode = pNode->GetNext();
            ++iCount;
        }

        return iCount;
    }
    */
}


template <typename Node>
List<Node>::List():m_pHead(0), m_iNodeCount(0)
{ 
}


template <typename Node>
List<Node>::~List()
{
    if (m_pHead != 0)
    {
        Node *pNode = m_pHead->GetNext();
        Node *pDel = pNode;

        while(pDel != 0)
        {
            pNode = pNode->GetNext();
            delete pDel;
            pDel = pNode;
        }

        delete m_pHead;
    }

}


template <typename Node>
Node *List<Node>::AddNewNode(const Node &stNode)
{
    Node *pNewNode = new Node(stNode);
    ++ m_iNodeCount;
    return pNewNode;
}


template <typename Node>
void List<Node>::DeleteNode(Node *pNode)
{
    delete pNode;
    -- m_iNodeCount;
}


template <typename Node>
int List<Node>::Add(const Node &stNewNode)
{
    Node * pNode = this->AddNewNode(stNewNode);
    pNode->SetNext(0);

    int iPos = 0;

    if (m_pHead == 0)
    {
        m_pHead = pNode;
        return iPos;
    }
    else
    {
        Node * pPreNode = m_pHead;
    
        while(pPreNode->GetNext() != 0)
        {
            pPreNode = pPreNode->GetNext();
            ++iPos;
        }
    
        pPreNode->SetNext(pNode);
        return iPos + 1;
    }
}

template <typename Node>
void List<Node>::Del(const long long iNodeID)
{
    if (m_pHead == 0)
    {
        throw std::runtime_error("Empty List");
    }
    else
    {
        if (m_pHead->GetID() == iNodeID)
        {
            Node *pDel = m_pHead;
            m_pHead = m_pHead->GetNext();
            this->DeleteNode(pDel);
        }
        else
        {
            Node *pNode = m_pHead;

            while(pNode->GetNext() != 0 && pNode->GetNext()->GetID() != iNodeID)
            {
                pNode = pNode->GetNext();
            }

            if(pNode->GetNext() != 0)
            {
                Node *pDel = pNode->GetNext();
                pNode->SetNext(pNode->GetNext()->GetNext());
                this->DeleteNode(pDel);
            }
            else
            {
                throw std::runtime_error("Aim Object is not exists!");
            }

        }
    }
}

template <typename Node>
int List<Node>::Update(const Node &stUpNode)
{
    if (m_pHead == 0)
    {
        throw std::runtime_error("Empty List");
    }
    else
    {
        if (m_pHead->GetID() == stUpNode.GetID())
        {
            Node *pUpNode = new Node(stUpNode);
            Node *pDel = m_pHead;
            m_pHead = pUpNode;
            delete pDel;
        }
        else
        {
            Node *pNode = m_pHead;
            while (pNode->GetNext() != 0 && pNode->GetNext()->GetID() != stUpNode.GetID())
            {
                pNode = pNode->GetNext();
            }

            if (pNode->GetNext() != 0)
            {
                Node *pUpNode = new Node(stUpNode);
                Node *pDel = pNode->GetNext();

                pUpNode->SetNext(pDel->GetNext());
                pNode->SetNext(pUpNode);

                delete pDel;
            }
            else
            {
                throw std::runtime_error("Aim Node not exist!");
            }

        }
    }
}

template <typename Node>
Node List<Node>::Get(const long long iNodeID) const
{
    if (m_pHead == 0)
    {
        throw std::runtime_error("Empty List");
    }
    else
    {
        if (m_pHead->GetID() == iNodeID)
        {
            return m_pHead;
        }
        else
        {
            Node *pNode = m_pHead;
            while (pNode->GetNext() != 0 && pNode->GetNext()->GetID() != iNodeID)
            {
                pNode = pNode->GetNext();
            }

            if (pNode->GetNext() != 0)
            {
                return pNode->GetNext();
            }
            else
            {
                throw std::runtime_error("Aim Node Not Exist!");
            }
        }
    }
}


#endif
