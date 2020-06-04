#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Threads
{
  public:
    long long int start_time;
    int thread_id;

    Threads()
    {
      this->start_time = 0;
    }
};

int leftchild(int i)
{
  return (2*i) + 1;
}

int rightchild(int i)
{
  return (2*i)+2;
}

void Siftdown(int i, vector <Threads> &mythreads)
{
  int minIndex = i;
  int left = leftchild(i);
  
  if(left < mythreads.size() && mythreads[left].start_time == mythreads[minIndex].start_time)
  {
    int temp_original_id = mythreads[minIndex].thread_id;
    int temp_left_id = mythreads[left].thread_id;

    if(temp_original_id > temp_left_id)
      minIndex = left;
  }

  else if(left < mythreads.size() && mythreads[left].start_time < mythreads[minIndex].start_time)
    minIndex = left;

  int right = rightchild(i);

  if(right < mythreads.size() && mythreads[right].start_time == mythreads[minIndex].start_time)
  {
    int left_id = mythreads[minIndex].thread_id;
    int right_id = mythreads[right].thread_id;

    if(left_id > right_id)
      minIndex = right;
  }

  else if(right < mythreads.size() && mythreads[right].start_time< mythreads[minIndex].start_time)
    minIndex = right;

  if(i!=minIndex)
  {
    swap(mythreads[i], mythreads[minIndex]);
    Siftdown(minIndex,mythreads);
  }
}

void ChangePriority(int i, long long int new_priority, vector <Threads> &mythreads)
{
  mythreads[0].start_time = new_priority;

  Siftdown(0,mythreads);
}

void start(vector <long long int> &jobs_list, vector <Threads> &mythreads)
{
  vector <pair <int ,long long int> > results;
  results.resize(jobs_list.size());

  for(int i=0; i<jobs_list.size(); i++)
  {
    results[i] = make_pair(mythreads[0].thread_id, mythreads[0].start_time);
    if(jobs_list[i] != 0)
      ChangePriority((int)0,mythreads[0].start_time + jobs_list[i], mythreads);
  }

  //writing response
  for(int i=0; i<results.size(); i++)
    cout << results[i].first << " " << results[i].second << std::endl;
}


int main()
{
  int n,m;
  cin >> n >> m;

  vector <long long int> jobs_list;
  jobs_list.resize(m);

  for(int i=0; i<m; i++)
    cin >> jobs_list[i];

  vector <Threads> mythreads;
  mythreads.resize(n);

  for(int i=0; i<n; i++)
    mythreads[i].thread_id = i;

  start(jobs_list,mythreads);
  return 0;
}