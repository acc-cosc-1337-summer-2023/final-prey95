#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Testing Die Roll function") {
	Die die(1);

	die.roll();
	REQUIRE(die.rolled_value() > 0);
	REQUIRE(die.rolled_value() < 7);

	for(int i = 0; i < 10; i++){
		die.roll();
		REQUIRE(die.rolled_value() > 0);
		REQUIRE(die.rolled_value() < 7);
	}
}

TEST_CASE("Testing die rolls value") {
	Roll myRoll;

	myRoll.roll_die();
	REQUIRE(myRoll.roll_value() > 1);
	REQUIRE(myRoll.roll_value() < 13);
	for(int i = 0; i < 10; i++){
		myRoll.roll_die();
		REQUIRE(myRoll.roll_value() > 1);
		REQUIRE(myRoll.roll_value() < 13);
	}
}

TEST_CASE("Testing Shooter return a Roll") {
	Shooter shoot;
	Roll* myRoll;
	Die die1(1), die2(2);

	for(int i = 0; i < 10; i++){

		myRoll = shoot.throw_die(die1, die2);
		REQUIRE(myRoll->roll_value() > 1);
		REQUIRE(myRoll->roll_value() < 13);
	}
}

TEST_CASE("Testing ComeOutPhase get_outcomes") {

	ComeOutPhase d;
	Roll* myRoll = new Roll();

	for(int i = 0; i < 10; i++){

		myRoll->roll_die();

		if(myRoll->roll_value() == 7){
			cout << "myRoll->roll_value() == 7 actual value is: " << myRoll->roll_value();
			REQUIRE(d.get_outcome(myRoll) == RollOutcome::natural);
		}else if(myRoll->roll_value() == 11){
			REQUIRE(d.get_outcome(myRoll) == RollOutcome::natural);
		}else if(myRoll->roll_value() == 2 || myRoll->roll_value() == 3 || myRoll->roll_value() == 12)
		{
			REQUIRE(d.get_outcome(myRoll) == RollOutcome::craps);
		}else{
			REQUIRE(d.get_outcome(myRoll) == RollOutcome::point);
		}
	}
}

TEST_CASE("Testing PointPhase get_outcomes") {

	PointPhase p(2);
	Roll* myRoll = new Roll();

	for(int i = 0; i < 10; i++){
		myRoll->roll_die();

		if(myRoll->roll_value() == 2){
			REQUIRE(p.get_outcome(myRoll) == RollOutcome::point);
		}else if(myRoll->roll_value() == 7){
			REQUIRE(p.get_outcome(myRoll) == RollOutcome::seven_out);
		}else{
			REQUIRE(p.get_outcome(myRoll) == RollOutcome::nopoint);
		}
	}
}
