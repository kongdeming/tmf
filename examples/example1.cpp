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

#include "tmf.h"


int main(int argc, char** argv) {
  
  TMF tmf;
  
  Pipeline* pipe = tmf.createPipeline("Test App");
  
  Filter* producerFilter = tmf.createFilter(PRODUCER_FILTER,
						   "producerFilter");
  Filter* add2Filter = tmf.createFilter(ADD2_FILTER, "add2Filter");
  Filter* multiply2Filter = tmf.createFilter(MULTIPLY2_FILTER,
					     "multiply2Filter");
  Filter* duplicateFilter = tmf.createFilter(DUPLICATE_FILTER,
					     "duplicateFilter");
  Filter* additionFilter = tmf.createFilter(ADDITION_FILTER,
					    "additionFilter");
  
  pipe->connectFilters(producerFilter, multiply2Filter);
  pipe->connectFilters(producerFilter, add2Filter);
  pipe->connectFilters(producerFilter, duplicateFilter);
  pipe->connectFilters(multiply2Filter, additionFilter);
  pipe->connectFilters(add2Filter, additionFilter);
  
  
  pipe->init();
  
  pipe->run();
  
  tmf.destroyPipeline(pipe);
  
  return 0;
}
