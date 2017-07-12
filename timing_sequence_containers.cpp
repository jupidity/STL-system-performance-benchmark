et/*
This is test code for measureing the various differences in timing for using
the defined C++ sequence containers
*/

#include <iostream>
#include <chrono>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

using namespace std;
using namespace std::chrono;


template <typename T>
long growTime(T & container){
high_resolution_clock::time_point t1 = high_resolution_clock::now(); // log the start time
for (long i = 0; i < 1000000; i++){container.push_back(i);} // push back 1,000,000 longs
high_resolution_clock::time_point t2 = high_resolution_clock::now(); // log the finish time
return duration_cast<microseconds>( t2 - t1 ).count(); // return the elapsed time in microseconds
}

template <typename T>
long traverseTime(T & container){
high_resolution_clock::time_point t1 = high_resolution_clock::now(); // log the start time
for(typename T::iterator itr = container.begin();itr != container.end(); ++itr ){} // increment the iterator through the container
high_resolution_clock::time_point t2 = high_resolution_clock::now(); // log the stop time
return duration_cast<microseconds>( t2 - t1 ).count(); // return the elapsed time
}


template <typename T>
long shuffleTime(T & container){
high_resolution_clock::time_point t1 = high_resolution_clock::now(); // log the start time
random_shuffle(container.begin(),container.end()); // call the shuffle alogorithm on the iterators
high_resolution_clock::time_point t2 = high_resolution_clock::now(); // log the end time
return duration_cast<microseconds>(t2-t1).count(); // return the elapsed time
}

template <typename T>
long sortTime(T & container){
high_resolution_clock::time_point t1 = high_resolution_clock::now(); // log the start time
sort(container.begin(),container.end()); // sort the container
high_resolution_clock::time_point t2 = high_resolution_clock::now();
return duration_cast<microseconds>(t2-t1).count();
}



int main()
{
vector<long> first;
deque<long> second;
list<long> third;

/*
growTime(first);
random_shuffle(first.begin(),first.end());
sort(first.begin(),first.end());
*/
long vecGrowDuration = growTime(first);
long vecTraverseDuration = traverseTime(first);
long vecShuffleDuration = shuffleTime(first);
long vecSortDuration = sortTime(first);
long deqGrowDuration = growTime(second);
long deqTraverseDuration = traverseTime(second);
long deqShuffleDuration = shuffleTime(second);
long deqSortDuration = sortTime(second);

long listGrowDuration = growTime(third);
long listTraverseDuration = traverseTime(third);
//long listShuffleDuration = shuffleTime(third);
//long listSortDuration = sortTime(third);

cout << "------    grow    | traverse |  shuffle  |  sort   | -----------------------------"<< "\n";
cout << "vector | " << vecGrowDuration <<"    | "<< vecTraverseDuration << " |" << vecShuffleDuration<< " |"<<vecSortDuration <<  " |\n";
cout << "deque  | " << deqGrowDuration <<"    | "<< deqTraverseDuration << " |" << deqShuffleDuration<< " |"<<deqSortDuration <<  " |\n";
cout << "list   | " << listGrowDuration <<"   | "<< listTraverseDuration << " |\n";

return 0;
}
