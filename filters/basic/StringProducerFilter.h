/*
 * 
 *  Tiny Multimedia Framework
 *  Copyright (C) 2014 Arash Shafiei
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
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef STRINGPRODUCERFILTER_H_
#define STRINGPRODUCERFILTER_H_ 

#include "core/tmf.h"
#include "core/Filter.h"
#include "core/Port.h"

#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

class StringProducerFilter: public Filter {
  
private:
  
  int number;
  int limit;
  
  OutputPort<string> * outputString;
  
  static  FilterRegister<StringProducerFilter> reg;
public:
  
  StringProducerFilter(const string& name);
  
  virtual void init();
  
  virtual void run();
  
  virtual void runRT();
  
  virtual ~StringProducerFilter();
  
};

#endif /* STRINGPRODUCERFILTER_H_ */