#include "../RASLib/inc/common.h"
#include "../RASLib/inc/gpio.h"
#include "../RASLib/inc/time.h"
#include "../RASLib/inc/motor.h"

void goForward(tMotor* Lmotor, tMotor* Rmotor, float speed){
 
	SetMotor(Lmotor, speed);
	SetMotor(Rmotor, -speed);
}

void goBackwards(tMotor* Lmotor, tMotor* Rmotor, float speed){
	SetMotor(Lmotor, -speed);
	SetMotor(Rmotor, speed);
}

void turnLeftStationary(tMotor* Lmotor, tMotor* Rmotor){
	SetMotor(Lmotor, 1);
	SetMotor(Rmotor, 0);
}

void turnRightStationary(tMotor* Lmotor, tMotor* Rmotor){
	SetMotor(Lmotor, 0);
	SetMotor(Rmotor, 1);
}

void turnLeftDrift(tMotor* Lmotor, tMotor* Rmotor){
	SetMotor(Lmotor, 1);
	SetMotor(Rmotor, .5);
}

void turnRightDrift(tMotor* Lmotor, tMotor* Rmotor){
	SetMotor(Lmotor, .5);
	SetMotor(Rmotor, 1);
}
int main(void) {
	tMotor* LMotor = InitializeServoMotor(PIN_D0, true);
	tMotor* RMotor = InitializeServoMotor(PIN_D1, true);
	goForward(LMotor, RMotor, 1);
	goBackwards(LMotor, RMotor, 1);
	turnLeftStationary(LMotor, RMotor);
	turnRightStationary(LMotor, RMotor);
	turnLeftDrift(LMotor, RMotor);
	turnRightDrift(LMotor, RMotor);
	
		

}
 