/*
  cpu_map.h - CPU and pin mapping configuration file
  Part of Grbl

  Copyright (c) 2012-2016 Sungeun K. Jeon for Gnea Research LLC

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

/* The cpu_map.h files serve as a central pin mapping selection file for different
   processor types or alternative pin layouts. This version of Grbl officially supports
   only the Arduino Mega328p. */


#define cpu_map_h


// Define serial port pins and interrupt vectors.
#define SERIAL_RX     USART_RX_vect
#define SERIAL_UDRE   USART_UDRE_vect

// Define step pulse output pins. NOTE: All step bit pins must be on the same port.
#define STEP_DDR        DDRD
#define STEP_PORT       PORTD
#define X_STEP_BIT      2  // Uno Digital Pin 2
#define Y_STEP_BIT      3  // Uno Digital Pin 3
#define Z_STEP_BIT      4  // Uno Digital Pin 4
#define A_STEP_BIT      9  // Uno Digital Pin 9, 4th Axis Step
#define STEP_MASK ((1<<X_STEP_BIT)|(1<<Y_STEP_BIT)|(1<<Z_STEP_BIT)|(1<<A_STEP_BIT)) // All step bits

// Define step direction output pins. NOTE: All direction pins must be on the same port.
#define DIRECTION_DDR     DDRD
#define DIRECTION_PORT    PORTD
#define X_DIRECTION_BIT   5  // Uno Digital Pin 5
#define Y_DIRECTION_BIT   6  // Uno Digital Pin 6
#define A_DIRECTION_BIT  10  // Uno Digital Pin 10, 4th Axis Direction
#define DIRECTION_MASK ((1<<X_DIRECTION_BIT)|(1<<Y_DIRECTION_BIT)|(1<<Z_DIRECTION_BIT)|(1<<A_DIRECTION_BIT)) // All direction bits

// Define stepper driver enable/disable output pin.
#define STEPPERS_DISABLE_DDR    DDRB
#define STEPPERS_DISABLE_PORT   PORTB
#define STEPPERS_DISABLE_BIT    0  // Uno Digital Pin 8
#define STEPPERS_DISABLE_MASK   (1<<STEPPERS_DISABLE_BIT)

// Define homing/hard limit switch input pins and limit interrupt vectors.
// NOTE: All limit bit pins must be on the same port, but not on a port with other input pins (CONTROL).
#define LIMIT_DDR        DDRB
#define LIMIT_PIN        PINB
#define LIMIT_PORT       PORTB
#define X_LIMIT_BIT      3 
#define Y_LIMIT_BIT      3 
#define Z_LIMIT_BIT      3 
#define A_LIMIT_BIT      3 // All limits assigned to Arduino Uno Digital Pin 11
#define LIMIT_MASK ((1<<X_LIMIT_BIT)|(1<<Y_LIMIT_BIT)|(1<<Z_LIMIT_BIT)|(1<<A_LIMIT_BIT)) // All limit bits
#define LIMIT_INT        PCIE0  // Pin change interrupt enable pin
#define LIMIT_INT_vect   PCINT0_vect
#define LIMIT_PCMSK      PCMSK0 // Pin change interrupt register

// Define user-control controls (cycle start, reset, feed hold) input pins.
// NOTE: All CONTROLs pins must be on the same port and not on a port with other input pins (limits).
#define CONTROL_DDR       DDRC
#define CONTROL_PIN       PINC
#define CONTROL_PORT      PORTC
#define CONTROL_RESET_BIT         0  // Uno Analog Pin 0
#define CONTROL_FEED_HOLD_BIT     1  // Uno Analog Pin 1
#define CONTROL_CYCLE_START_BIT   2  // Uno Analog Pin 2
#define CONTROL_SAFETY_DOOR_BIT   1  // Uno Analog Pin 1 NOTE: Safety door is shared with feed hold. Enabled by config define.
#define CONTROL_INT       PCIE1  // Pin change interrupt enable pin
#define CONTROL_INT_vect  PCINT1_vect
#define CONTROL_PCMSK     PCMSK1 // Pin change interrupt register
#define CONTROL_MASK      ((1<<CONTROL_RESET_BIT)|(1<<CONTROL_FEED_HOLD_BIT)|(1<<CONTROL_CYCLE_START_BIT)|(1<<CONTROL_SAFETY_DOOR_BIT))
#define CONTROL_INVERT_MASK   CONTROL_MASK // May be re-defined to only invert certain control pins.

// Define (optional) digital sensors output pins.
#define DIGITAL_SENSOR_DDR    DDRB
#define DIGITAL_SENSOR_PORT   PORTB
#define A_DIGITAL_SENSOR_BIT  4 // Uno Digital Pin 12
#define B_DIGITAL_SENSOR_BIT  5 // Uno Digital Pin 13 (NOTE: D13 can't be pulled-high input due to LED.)
#define DIGITAL_SENSOR_MASK ((1<<A_DIGITAL_SENSOR_BIT)|(1<<B_DIGITAL_SENSOR_BIT))

// Define (optional) analog sensors sensors output pins.
#define ANALOG_SENSOR_DDR    DDRC
#define ANALOG_SENSOR_PIN    PINC
#define ANALOG_SENSOR_PORT   PORTC
#define A_ANALOG_SENSOR_BIT  3 // Uno Analog Pin 3
#define B_ANALOG_SENSOR_BIT  4 // Uno Analog Pin 4
#define C_ANALOG_SENSOR_BIT  5 // Uno Analog Pin 5
#define ANALOG_SENSOR_MASK ((1<<A_ANALOG_SENSOR_BIT)|(1<<B_ANALOG_SENSOR_BIT)|(1<<C_ANALOG_SENSOR_BIT))