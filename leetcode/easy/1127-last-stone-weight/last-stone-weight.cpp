class Solution {
public:
priority_queue<int>Heap;
    int lastStoneWeight(vector<int>& stones) {
        for(int i:stones){
            Heap.push(i);
        }
        while(Heap.size()>1){
            int a=Heap.top();
            Heap.pop();
            int b=Heap.top();
            Heap.pop();
            Heap.push(abs(a-b));

        }
        return Heap.top();
        
    }
};