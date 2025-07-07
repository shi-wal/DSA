class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Step 1: Sort events by start day
        sort(events.begin(),events.end());

        // Step 2: Min-heap to track the end days of events available on the current day
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n=events.size(), cnt=0;
        int index=0; // Index to track events added to the heap
        int day=0; // Current day 

        // Step 3: Process until all events are considered and no pending events in heap
        while(!minHeap.empty() || index<n){
            // If no available events, jump to the next event's start day
            if(minHeap.empty()) day=events[index][0];
            // Add all events starting today or earlier to the heap
            while(index<n && events[index][0]<=day){
                minHeap.push(events[index][1]); index++;
            }
            // Attend the event that ends the earliest
            minHeap.pop();
            cnt++;
            day++;
            // Remove all events that have already expired (end day < current day)
            while(!minHeap.empty() && minHeap.top()<day) minHeap.pop();
        }
        return cnt;
    }
};
