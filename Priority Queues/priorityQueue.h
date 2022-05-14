#include <vector>
#include <climits>
using namespace std;

class PriorityQueue{
    vector<int> pq;

    public:

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if(pq.size() == 0)
        {
            return INT_MAX;        
        }
        return pq.at(0);
    }
// 3 200 19 18 27 7 12 5 19

    void insert(int data)
    {
        pq.push_back(data);
        int ci = pq.size() - 1;
        while (pq[0] != pq[ci])
        {
            int pi = (ci - 1)/2;
            if(pq[pi] < pq[ci])
            {
                return;
            }
            int temp = pq[pi];
            pq[pi] = pq[ci];
            pq[ci] = temp;
            ci = pi;
        }
    }
    void remove()
    {
        if(pq.size() <= 1)
        {
            if(pq.size() == 1)
            {
                pq.pop_back();
            }
            return;
        }
        int temp = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq[pq.size() -1] = temp;
        pq.pop_back();
        int pi = 0;
        while (pi != pq.size() - 1)
        {
            int lci = 2*pi + 1;
            int rci = lci + 1;
            int leftChildData, rightChildData,parentData = pq[pi];
            if(lci >= pq.size())
            {
                leftChildData = INT_MAX;
            }
            else{
                leftChildData = pq[lci];
            }
            if(rci >= pq.size())
            {
                rightChildData = INT_MAX;
            }
            else{
                rightChildData = pq[rci];
            }

            if(parentData < leftChildData && parentData < rightChildData)
            {
                return;
            }
            pq[pi] = min(leftChildData, rightChildData);
            if(leftChildData < rightChildData)
            {
                pq[lci] = parentData;
                pi = lci;
            }
            else{
                pq[rci] = parentData;
                pi = rci;
            }
        }
    }
    void print()
    {
        for(auto &i : pq)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};