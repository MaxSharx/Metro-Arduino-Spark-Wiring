/*
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */



/*  * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 Main code by Thomas O Fredericks (tof@t-o-f.info)
 Contributions by Paul Bouchier and Benjamin.soelberg
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined(SPARK)
  #include "application.h"
#else
  #if ARDUINO >= 100
    #include "Arduino.h"
  #else
    #include "WProgram.h"
  #endif
#endif
#include "Metro-Arduino-Spark-Wiring.h"

Metro::Metro()
{
	
	this->interval_millis = 1000;
	
}


Metro::Metro(unsigned long interval_millis)
{
	
	this->interval_millis = interval_millis;
	
}


void Metro::interval(unsigned long interval_millis)
{
  this->interval_millis = interval_millis;
}

unsigned int Metro::check()
{

  unsigned long now = millis();
  
  if ( interval_millis == 0 ){
    previous_millis = now;
	return 1;
  }
 
  if ( (now - previous_millis) >= interval_millis) {
	#ifdef NOCATCH-UP
	previous_millis = now ; 
	#else
	previous_millis += interval_millis ; 
	 #endif
    return 1;
  }
  
  return 0;

}

void Metro::reset() 
{
 
  this->previous_millis = millis();

}


