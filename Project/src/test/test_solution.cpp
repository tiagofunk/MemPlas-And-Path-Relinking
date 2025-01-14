#include "../model/Solution.h"
#include "gtest.h"


TEST( , SETUP_SOLUTION ) {
	const int SIZE = 4;
	Solution* sol = new Solution( SIZE );

	EXPECT_EQ( sol->getSize(), 0 );
	EXPECT_EQ( sol->getFitness(), 0 );
	EXPECT_EQ( sol->getSatisfaction(), 0 );
}

TEST( , ADD_END) {
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );

	EXPECT_EQ( sol->cars[ 0 ], 1 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );

	EXPECT_EQ( sol->getSize(), 1 );

	sol->addEnd( 2, 2 );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 2 );

	EXPECT_EQ( sol->getSize(), 2 );

	sol->addEnd( 3, 3 );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );
	EXPECT_EQ( sol->cars[ 2 ], 3 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 2 );
	EXPECT_EQ( sol->cities[ 2 ], 3 );

	EXPECT_EQ( sol->getSize(), 3 );
}

TEST( , ADD_END_FAIL ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	ASSERT_THROW( sol->addEnd( 4, 4 ), runtime_error );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );
	EXPECT_EQ( sol->cars[ 2 ], 3 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 2 );
	EXPECT_EQ( sol->cities[ 2 ], 3 );

	EXPECT_EQ( sol->getSize(), 3 );
}

TEST( , REMOVE_INDEX_1 ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	sol->removeIndex( 1 );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 3 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 3 );

	EXPECT_EQ( sol->getSize(), 2 );
}

TEST( , REMOVE_INDEX_2 ){
	const int SIZE = 4;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	sol->removeIndex( 1 );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 3 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 3 );

	EXPECT_EQ( sol->getSize(), 2 );
}

TEST( , REMOVE_INDEX_3 ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	sol->removeIndex( 0 );

	EXPECT_EQ( sol->cars[ 0 ], 2 );
	EXPECT_EQ( sol->cars[ 1 ], 3 );

	EXPECT_EQ( sol->cities[ 0 ], 2 );
	EXPECT_EQ( sol->cities[ 1 ], 3 );

	EXPECT_EQ( sol->getSize(), 2 );
}

TEST( , REMOVE_INDEX_4 ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	sol->removeIndex( 2 );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 2 );

	EXPECT_EQ( sol->getSize(), 2 );
}

TEST( , REMOVE_INDEX_6 ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	sol->removeIndex( 2 );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 2 );

	EXPECT_EQ( sol->getSize(), 2 );

	sol->removeIndex( 0 );

	EXPECT_EQ( sol->cars[ 0 ], 2 );

	EXPECT_EQ( sol->cities[ 0 ], 2 );

	EXPECT_EQ( sol->getSize(), 1 );
}

TEST( , REMOVE_INDEX_FAIL ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	ASSERT_THROW( sol->removeIndex( 3 ), runtime_error );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );
	EXPECT_EQ( sol->cars[ 2 ], 3 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 2 );
	EXPECT_EQ( sol->cities[ 2 ], 3 );
}

TEST( , REMOVE_INDEX_FAIL_2 ){
	const int SIZE = 4;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );

	ASSERT_THROW( sol->removeIndex( 2 ), runtime_error );

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 2 );

	EXPECT_EQ( sol->getSize(), 2 );
}

TEST( , INSERT_CITY_AT ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	sol->insertCityAt(1,4);

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );
	EXPECT_EQ( sol->cars[ 2 ], 3 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 4 );
	EXPECT_EQ( sol->cities[ 2 ], 3 );
}

TEST( , INSERT_CITY_AT_FAIL ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	try{
		sol->insertCityAt(4,4);
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Invalid index to insert city.\n", exc.what() );
	}
}

TEST( , INSERT_CITY_AT_FAIL_2 ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	try{
		sol->insertCityAt(-1,4);
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Invalid index to insert city.\n", exc.what() );
	}
}

TEST( , ADD_CITY_AT ){
	const int SIZE = 5;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	sol->addCityAt(1,4);

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 2 );
	EXPECT_EQ( sol->cars[ 2 ], 2 );
	EXPECT_EQ( sol->cars[ 3 ], 3 );

	EXPECT_EQ( sol->cities[ 0 ], 1 );
	EXPECT_EQ( sol->cities[ 1 ], 4 );
	EXPECT_EQ( sol->cities[ 2 ], 2 );
	EXPECT_EQ( sol->cities[ 3 ], 3 );
}

TEST( , ADD_CITY_AT_2 ){
	const int SIZE = 5;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	sol->addCityAt(0,4);

	EXPECT_EQ( sol->cars[ 0 ], 1 );
	EXPECT_EQ( sol->cars[ 1 ], 1 );
	EXPECT_EQ( sol->cars[ 2 ], 2 );
	EXPECT_EQ( sol->cars[ 3 ], 3 );

	EXPECT_EQ( sol->cities[ 0 ], 4 );
	EXPECT_EQ( sol->cities[ 1 ], 1 );
	EXPECT_EQ( sol->cities[ 2 ], 2 );
	EXPECT_EQ( sol->cities[ 3 ], 3 );
}

TEST( , ADD_CITY_AT_FAIL ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	try{
		sol->addCityAt(4,4);
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Invalid index to add city.\n", exc.what() );
	}
}

TEST( , ADD_CITY_AT_FAIL_2 ){
	const int SIZE = 3;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	try{
		sol->addCityAt(-1,4);
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Invalid index to add city.\n", exc.what() );
	}
}

TEST( , ADD_CITY_AT_FAIL_3 ){
	const int SIZE = 5;
	Solution* sol = new Solution( SIZE );
	sol->addEnd( 1, 1 );
	sol->addEnd( 2, 2 );
	sol->addEnd( 3, 3 );

	try{
		sol->addCityAt(3,4);
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Invalid index to add city.\n", exc.what() );
	}
}
