#ifndef SRC_SOLUTION_H_
#define SRC_SOLUTION_H_

#include <string>

#include "GLOBAL.h"

using namespace std;

class Solution{
public:
	int sizeSolution = 0;
	int* cities = 0;
	int* cars = 0;
	int fitness = 0;

	Solution( int sizeSolution );
	void calculeFitness();
	string toString();

};

Solution::Solution( int sizeSolution ){
	this->sizeSolution = sizeSolution;
	cities = new int[ sizeSolution ];
	cars = new int[ sizeSolution ];
	for( int i = 0; i < sizeSolution; i++ ){
		cars[ i ] = -1;
		cities[ i ] = -1;
	}
}

void Solution::calculeFitness(){
	fitness = 0;
	for( int i = 0; i < sizeSolution; i++ ){
		if( i < 0 ){
			break;
		}
		fitness += bonus_satisfaction_GLOBAL[ cities[ i ] ];
	}
}

string Solution::toString(){
	string s = ">";
	string s2 = "*";
	for( int i = 0; i < sizeSolution; i++ ){
		s += to_string( cities[i] ) + "\t";
		s2 += to_string( cars[i] ) + "\t";
	}
	return s + "\n" + s2 + "\n";
}

#endif /* SRC_SOLUTION_H_ */
