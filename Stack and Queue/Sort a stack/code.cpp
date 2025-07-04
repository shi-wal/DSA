/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */

void sortedInsert(stack<int>& s,int num){
    if(s.empty() || s.top()<num){
        s.push(num); return;
    }
    int x=s.top();
    s.pop();
    sortedInsert(s,num);
    s.push(x);
}

void SortedStack ::sort() {
    if(s.empty()) return;
    int x=s.top(); s.pop();
    sort();
    sortedInsert(s,x);
}
