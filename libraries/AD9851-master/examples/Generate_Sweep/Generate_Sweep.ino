/*
 *  Copyright (C) 2018 - Handiko Gesang - www.github.com/handiko
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <AD9851.h>

#define RST   8
#define DATA  9
#define FQ    10
#define CLK   11

DDS dds;

unsigned long cfreq = 35000000UL;
unsigned long dev = 300000;
long pos_step = 100;
long neg_step = -100;
unsigned int delay_us = 1;

void setup()
{
  Serial.begin(115200);
  
  Serial.println(" ");
  Serial.print("Sketch:   ");   Serial.println(__FILE__);
  Serial.print("Uploaded: ");   Serial.println(__DATE__);
  Serial.println(" ");
  
  Serial.println("Test - Started ! \n");

  dds = dds_init(RST, DATA, FQ, CLK);
  dds_reset(dds);
}

void loop()
{
  sweepTone(dds, cfreq, dev, pos_step, delay_us);
  sweepTone(dds, cfreq, dev, neg_step, delay_us);
}
