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
void op_control() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::MotorGroup left_mg({1, 3});    
	pros::MotorGroup right_mg({9, 10});  
	bool running = true;
	while (running) {
	
		int left_speed = master.get_analog(ANALOG_LEFT_Y);
		int right_speed = master.get_analog(ANALOG_RIGHT_Y);

		if (abs((abs(left_speed) - abs(right_speed))) > 5) {
			left_speed = right_speed;


		if (left_speed > 5) {
			left_mg.move(left_speed);
		}  else {
			left_mg.move(0);
		}

		if (right_speed > 5) {
			right_mg.move(right_speed);  
		} else {
			right_mg.move(0);  
		}

		               
		pros::delay(20);                              
	}
}
