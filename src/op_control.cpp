#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::MotorGroup left_mg({1, 3});    
	pros::MotorGroup right_mg({9, 10});  

	while (true) {
	
		int leftSpeed = master.get_analog(ANALOG_LEFT_Y);
		int rightSpeed = master.get_analog(ANALOG_RIGHT_Y);

		if (abs((abs(leftSpeed) - abs(rightSpeed))) > 5) {
			leftSpeed = rightSpeed;


		if (leftSpeed > 5) {
			left_mg.move(leftSpeed);
		}
				} else {
			left_mg.move(0);
		}

		if (rightSpeed > 5) {
			right_mg.move(rightSpeed);  
		} else {
			right_mg.move(0);  
		}

		               
		pros::delay(20);                              
	}
}
