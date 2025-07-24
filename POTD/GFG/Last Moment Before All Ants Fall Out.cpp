class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // Intuition: if we don't consider ants colliding it will work same 
        // because after colliding one ant will take another aunt pos after collision.
        // https://youtu.be/zv__otbvUEY?si=lUJMWrqcrdpxrOxJ
        int time=0;
        for(int l:left) time=max(time,l);
        for(int r:right) time=max(time,n-r);
        return time;
    }
};
