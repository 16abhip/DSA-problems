#include <iostream>
using namespace std;
#include "priorityQueue.h"

int main()
{
    PriorityQueue p1;
    p1.insert(3);
    p1.insert(200);
    p1.insert(19);
    p1.insert(18);
    p1.insert(27);
    p1.insert(7);
    p1.insert(12);
    p1.insert(5);
    p1.insert(0);

    cout << "Our Heap is: " << endl;
    p1.print();

    p1.remove();
    p1.print();

    p1.remove();
    p1.print();p1.remove();
    p1.print();p1.remove();
    p1.print();p1.remove();
    p1.print();p1.remove();
    p1.print();p1.remove();
    p1.print();p1.remove();
    p1.print();
}
// 3 200 19 18 27 7 12 5 19