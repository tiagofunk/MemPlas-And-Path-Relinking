#include "RestoringOperations.h"

#include "../utils/Prints.h"
#include "../utils/SortingMethods.h"
#include "../model/Pair.h"

#include <bits/stdc++.h>

vector< Pair > usedCars;
vector< Pair > usedCities;

void printPairs( vector< Pair > values ){
	for( int i = 0; i < (int) values.size(); i++ ){
		myPrint( values[i].key, false );
		myPrint( "-", false );
		myPrint( values[i].value, false );
		myPrint( ", ", false );
	}
	myPrint( "", true );
}

Solution removeErrors( Solution sol ){
	bool isRepeated = false;
	int actualCity = -1;
	int lastCar = -1, actualCar = -1;
	usedCars.clear();
	usedCities.clear();
	usedCars.resize( numberCars_GLOBAL );
	usedCities.resize( numberCities_GLOBAL );
	Solution newSol = sol;

	for( int i = 0; i < numberCities_GLOBAL; i++ ){
		usedCities[i].key = i;
	}
	for( int i = 0; i < numberCars_GLOBAL; i++ ){
		usedCars[i].key = i;
	}
//	printPairs( usedCities );

	for( int i = 0; i < sol.position; i++ ){
		actualCar = sol.cars[ i ];
		actualCity = sol.cities[ i ];
		if( lastCar != actualCar && usedCars[ actualCar ].value == 1 ){
			newSol.insertCarAt( i, -2 );
			isRepeated = true;
		} else if( usedCars[ actualCar ].value == 1 && isRepeated ){
			newSol.insertCarAt( i, -2 );
		}else if( lastCar != actualCar ){
			usedCars[ actualCar ].value += 1;
			isRepeated = false;
		}
		if( actualCity != 0 && usedCities[ actualCity ].value == 1 ){
			newSol.insertCityAt( i, -2 );
		}else{
			usedCities[ actualCity ].value += 1;
		}
		lastCar = actualCar;
	}
//	myPrint( newSol.toString(), true );
//	printPairs( usedCities );
	return newSol;
}

Solution insertCities( Solution sol ){
	int lastPosition = -1, aux = 0, randomNumber = 0;
	Pair pair;
	Solution newSol = sol;
	usedCities = quicksort( usedCities );
//	printPairs( usedCities );
	for( int i = 0; i < numberCities_GLOBAL; i++ ){
		if( usedCities[i].value != 0 ){
			lastPosition = i;
			break;
		}
	}
	for( int i = 0; i < lastPosition; i++ ){
		randomNumber = rand() % lastPosition;
		pair = usedCities[ i ];
		usedCities[ i ] = usedCities[ randomNumber ];
		usedCities[ randomNumber ] = pair;
	}

	aux = 0;
	for( int i = 1; i < sol.position; i++ ){
		if( newSol.cities[i] == -2 ){
			if( aux == lastPosition ){
				newSol.removeIndex( i );
				i--;
			}else{
				newSol.insertCityAt( i, usedCities[aux].key );
				usedCities[aux].value += 1;
				aux++;
			}
		}
	}
//	myPrint( newSol.toString(), true );
//	printPairs( usedCities );
	return newSol;
}

Solution insertCars( Solution sol ){
	int lastCar = -1;
	Solution newSol = sol;
//	printPairs( usedCities );
	for( int i = 0; i < newSol.position; i++ ){
		if( newSol.cars[i] == -2 ){
			newSol.insertCarAt( i, lastCar );
		}else{
			lastCar = newSol.cars[i];
		}
	}
//	myPrint( newSol.toString(), true );
//	printPairs( usedCities );
	return newSol;
}

Solution checkQuota( Solution sol ){
	int selectCity = 0, biggerQuota = INT_MIN, indexBiggerCity = -1, previousCity = 0;
	Solution newSol = sol;
	newSol.calculeSatisfaction();
	if ( newSol.satisfaction < minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL ){
		for( int i = 1; i < numberCities_GLOBAL; i++ ){
			if( usedCities[i].value == 0 && bonus_satisfaction_GLOBAL[ usedCities[i].key ] > biggerQuota ){
				selectCity = usedCities[i].key;
				biggerQuota = bonus_satisfaction_GLOBAL[ usedCities[i].key ];
				indexBiggerCity = i;
			}
		}

		for( int i = 1; i < newSol.position-1; i++ ){
			previousCity = newSol.cities[i];
			newSol.insertCityAt( i, selectCity );
			newSol.calculeSatisfaction();
			if ( newSol.satisfaction >= minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL ){
				usedCities[indexBiggerCity].value += 1;
				usedCities[previousCity].value -= 1;
				break;
			}
			newSol.insertCityAt( i, previousCity );
		}
	}
//	myPrint( ">>>>>>", true );
//	myPrint( newSol.toString(), true );
//	printPairs( usedCities );

	while ( newSol.satisfaction < minimal_satisfaction_GLOBAL*satisfaction_total_GLOBAL ){
		for( int i = 0; i < numberCities_GLOBAL; i++ ){
			if( usedCities[i].value == 0 ){
				selectCity = usedCities[i].key;
				indexBiggerCity = i;
				break;
			}
		}
		newSol.addCityAt( newSol.position-1, selectCity );
		usedCities[indexBiggerCity].value += 1;
		newSol.calculeSatisfaction();

//		myPrint( ">>>>>>", true );
//		myPrint( newSol.toString(), true );
//		printPairs( usedCities );
	}
	return newSol;
}

vector< Solution > restoringOperations( vector< Solution > population ){
	Solution sol;
	vector< Solution > newPopulation( population.size() );
	for( int i = 0; i < (int) population.size(); i++ ){
		sol = population[ i ];
		sol = removeErrors( sol );
		sol = insertCities( sol );
		sol = insertCars( sol );
		sol = checkQuota( sol );
		newPopulation[i] = sol;
	}
	return newPopulation;
}
