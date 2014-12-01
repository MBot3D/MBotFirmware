#include "ButtonArray.hh"
#include "Configuration.hh"
#include "Pin.hh"
#include <util/delay.h>

static uint8_t previousJ;
static micros_t ButtonDelay;

void ButtonArray::init() {
        previousJ = 0;

	ButtonDelay = SlowDelay;

        // Set all of the known buttons to inputs (see above note)
        DDRJ = DDRJ & 0xE0;
        PORTJ = PORTJ & 0xE0;
}

void ButtonArray::scan()
{
	uint8_t newJ = PINJ;// & 0xFE;

    buttonTimeout.clear();

	if ( newJ != previousJ ) {
	    uint8_t diff = newJ ^ previousJ;
	    for(uint8_t i = 0; i < 5; i++) {
		if ( diff & ( 1 << i ) ) {
		    if ( !( newJ & ( 1 << i ) ) ) {
			if ( !buttonPressWaiting ) {
			    buttonPress = i;
			    buttonPressWaiting = true;
			    buttonTimeout.start(ButtonDelay);
			}
		    }
		}
	    }
	}

        previousJ = newJ;
}

void ButtonArray::scanButtons() {
        // Don't bother scanning if we already have a button 
        // or if sufficient time has not elapsed between the last button push
        if (buttonPressWaiting || (buttonTimeout.isActive() && !buttonTimeout.hasElapsed()))
	    return;
		static bool upOld,downOld;
		static bool st=false;
//		static bool st1=false;
		
		
		if(isButtonPressed(DOWN)&&isButtonPressed(UP))
			st = true;
		if(st)
		{
			if((isButtonPressed(DOWN) == false)&&(isButtonPressed(UP) == false))
			{
				if(upOld)
				{
					st = false;
					buttonPress = DOWN;
					buttonPressWaiting = true;
				}
				if(downOld)
				{
					st = false;
					buttonPress = UP;
					buttonPressWaiting = true;
				}
			}			
		}
/*	
		if((isButtonPressed(DOWN) == false)&&(isButtonPressed(UP) == false))
			st1 = true;
		if(st1)
		{
			if(isButtonPressed(DOWN)&&isButtonPressed(UP))
			{
				if(upOld)
				{
					st1 = false;
					buttonPress = DOWN;
					buttonPressWaiting = true;
				}
				if(downOld)
				{
					st1 = false;
					buttonPress = UP;
					buttonPressWaiting = true;
				}
			}			
		}
*/		
		upOld = isButtonPressed(UP);
		downOld = isButtonPressed(DOWN);
		
		
		if(isButtonPressed(CENTER))
		{
			buttonPress = CENTER;
			buttonPressWaiting = true;
			buttonTimeout.start(ButtonDelay);
			return;
		}
		if(isButtonPressed(RIGHT))
		{
			buttonPress = RIGHT;
			buttonPressWaiting = true;
			buttonTimeout.start(ButtonDelay);
			return;
		}
		if(isButtonPressed(LEFT))
		{
			buttonPress = LEFT;
			buttonPressWaiting = true;
			buttonTimeout.start(ButtonDelay);
			return;
		}
}



bool ButtonArray::getButton(ButtonName& button) {
        bool buttonValid;
        uint8_t buttonNumber;

        ATOMIC_BLOCK(ATOMIC_FORCEON)
        {
                buttonValid =  buttonPressWaiting;
                buttonNumber = buttonPress;        
                buttonPressWaiting = false;             
        }

        if (buttonValid) {
                button = (ButtonName)(buttonNumber);
        }

        return buttonValid;
}

void ButtonArray::clearButtonPress(){

		previousJ = 0x1F;
}

//Returns true is button is depressed
bool ButtonArray::isButtonPressed(ButtonArray::ButtonName button) {
        uint8_t newJ = PINJ;// & 0xFE;

	//Buttons are active low
	if ( newJ & (1<<button) ) return false;

	return true;
}

void ButtonArray::setButtonDelay(micros_t delay) {
        ButtonDelay = delay;
}
