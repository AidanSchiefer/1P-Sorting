/*
 * sorter.h
 *
 * Declares a template function:
 *    
 *   sorter() : k-way merge sort.
 * 
 * 
 * You may add other functions if you wish, but this template function
 * is the only one that need to be exposed for the testing code.
 * 
 * Authors: C. Painter-Wakefield & Tolga Can
 */

#ifndef _SORTER_H
#define _SORTER_H

#include <string>
#include <cstddef>
#include <vector>

/***
 * DO NOT put unscoped 'using namespace std;' in header files!
 * Instead put them at the beginning of class or function definitions
 * (as demonstrated below).
 *
 * For more details, see the commentary at the top of
 *   tests/header-sans-using-namespace.h
 * in this project repo.
 */

template <class T>
void sorter(std::vector<T> &items, std::size_t k) {  
	using namespace std;
	// write your solution for k-way merge sort below	

	//-----Base Case-----
	// If size of input array is 1, it is already sorted. If the size is zero, it is empty and shouldn't be considered
	if (items.size() <= 1) return;
	
	//-----Determine the number of sub-vectors that need to be made-----
	int extraElements = items.size() % k; // Determine how many subarrays need an extra value
	int subvectorSize = items.size() / k; // Determine the subvector's size

	// Create a vector of vectors that holds k empty vectors
	std::vector<std::vector<T>> subvectors(k);
	
	//Create subvectors with extra value if needed
	if (extraElements != 0){
		//Incremental value to track how many vectors have been resized
		int numVectors = 0;
		for (int i = 0; numVectors < extraElements; i++){
			// Resize the vectors
			subvectors[i].resize(subvectorSize+1);
			numVectors++
		}
		//resize the last vector to size k
		subvectors[numVectors].resize(subvectorSize);
	}
	else{ // Else, resize the vectors to have the regular subvector size
		for (int i = 0; i < k; i++){
			subvectors[i].resize(subvectorSize);
		}
	}

	//-----Copy corresponding parts of A into the smaller vectors-----

	//-----For loop that recursively calls the sorter() function-----
	for (int i = 0; i < k; i++){
		// Iterate through the vector of vectors and perform a recursive call for each subvector
		sorter(subvectors[i], k);
	}

	//-----Merge returned vectors back together-----

	//-----Return the sorted array-----
	return; 
}
#endif
