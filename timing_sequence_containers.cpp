/*
This is test code for measureing the various differences in timing for using
the defined C++ sequence containers

Author: Sean Cassero
4/19/17

*/

#include <iostream>
#include <chrono>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

using namespace std;
using namespace std::chrono;


// function to time the duration for populating referenced container with 1000000 longs
template <typename T>
long growTime(T & container){
high_resolution_clock::time_point t1 = high_resolution_clock::now(); // log the start time
for (long i = 0; i < 1000000; i++){container.push_back(i);} // push back 1,000,000 longs
high_resolution_clock::time_point t2 = high_resolution_clock::now(); // log the finish time
return duration_cast<microseconds>( t2 - t1 ).count(); // return the elapsed time in microseconds
}

// function to time the duration for traversing each element using iterators on referenced container
template <typename T>
long traverseTime(T & container){
high_resolution_clock::time_point t1 = high_resolution_clock::now(); // log the start time
for(typename T::iterator itr = container.begin();itr != container.end(); ++itr ){} // increment the iterator through the container
high_resolution_clock::time_point t2 = high_resolution_clock::now(); // log the stop time
return duration_cast<microseconds>( t2 - t1 ).count(); // return the elapsed time
}

// function to time the duration for executing a shuffle on referenced container
template <typename T>
long shuffleTime(T & container){
high_resolution_clock::time_point t1 = high_resolution_clock::now(); // log the start time
random_shuffle(container.begin(),container.end()); // call the shuffle alogorithm on the iterators
high_resolution_clock::time_point t2 = high_resolution_clock::now(); // log the end time
return duration_cast<microseconds>(t2-t1).count(); // return the elapsed time
}


// function to time the duration for executing a sort on referenced container
template <typename T>
long sortTime(T & container){
high_resolution_clock::time_point t1 = high_resolution_clock::now(); // log the start time
sort(container.begin(),container.end()); // sort the container
high_resolution_clock::time_point t2 = high_resolution_clock::now();
return duration_cast<microseconds>(t2-t1).count();
}


// function to return the number of digits on int or long
template <typename T>
unsigned numDigits(T  & number){

unsigned numDigits = 1;
while(number /= 10)
{
    ++numDigits;
}
return numDigits;
}

// function to generate the a formatted string of the
// iterator duration for pretty printing
std::string generatePrintString(long & duration){

// initialize the string with the duration
std::string returnString = std::to_string(duration);

// get the number of digits in the duration
unsigned digits = numDigits(duration);

// the print string should be 9 chars long,
// fill in the print string with spaces until its long enough
for(unsigned i =0; i< (9 - digits); ++i){
    returnString.insert(0,1,' ');
}
return returnString;
}


int main()
{

// initialize containers
vector<long> first;
deque<long> second;
list<long> third;


// compute durations
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

// now we have the times for each of the iterators on the STL containers
// print results
cout << "-------|      grow|  traverse|   shuffle|      sort|-----"<< "\n";
cout << "vector | " << generatePrintString(vecGrowDuration) <<  "| "<< generatePrintString(vecTraverseDuration) << "| " << generatePrintString(vecShuffleDuration)<< "| "<<generatePrintString(vecSortDuration) <<  "| (ns)\n";
cout << "deque  | " << generatePrintString(deqGrowDuration) <<"| "<< generatePrintString(deqTraverseDuration) << "| " << generatePrintString(deqShuffleDuration)<< "| "<<generatePrintString(deqSortDuration) <<  "| (ns)\n";
cout << "list   | " << generatePrintString(listGrowDuration) <<"| "<< generatePrintString(listTraverseDuration) << "|       N/A|       N/A| (ns)\n";

return 0;

}
