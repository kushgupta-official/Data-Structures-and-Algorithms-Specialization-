//working properly, copied from geekforgeeks
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void max_sliding_window_naive(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}
void printKMax(vector <int>const &arr, int n, int k) 
{ 
    std::deque<int> Qi(k); 
  
    /* Process first k (or first window) elements of array */
    int i; 
    for (i = 0; i < k; ++i) { 
        // For every element, the previous smaller elements are useless so 
        // remove them from Qi 
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
            Qi.pop_back(); // Remove from rear 
  
        // Add new element at rear of queue 
        Qi.push_back(i); 
    } 
  
    // Process rest of the elements, i.e., from arr[k] to arr[n-1] 
    for (; i < n; ++i) { 
        // The element at the front of the queue is the largest element of 
        // previous window, so print it 
        cout << arr[Qi.front()] << " "; 
  
        // Remove the elements which are out of this window 
        while ((!Qi.empty()) && Qi.front() <= i - k) 
            Qi.pop_front(); // Remove from front of queue 
  
        // Remove all elements smaller than the currently 
        // being added element (remove useless elements) 
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
            Qi.pop_back(); 
  
        // Add current element at the rear of Qi 
        Qi.push_back(i); 
    } 
  
    // Print the maximum element of last window 
    cout << arr[Qi.front()]; 
} 

int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    //max_sliding_window_naive(A, w);
    printKMax(A,n,w);
    return 0;
}
