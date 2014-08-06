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

#ifndef MULTIPLY2FILTER_H_
#define MULTIPLY2FILTER_H_

#include "Filter.h"

class Multiply2Filter: public Filter {
private:
	InputPort<int> * input;
	OutputPort<int> * output;

public:

	Multiply2Filter(const string & name) :
			Filter(name) {
		input = new InputPort<int>("multiply2, input 1, int", this);
		output = new OutputPort<int>("multiply2, output 1, int", this);

		inputPorts.push_back(input);
		outputPorts.push_back(output);
	}

	void init() {
	}

	FilterStatus process() {

		BufferNode<int> * bn;

		bn = input->read();

		int * inputData = bn->getData();

		//int * outputData = new int;
		int outputData = *inputData * 2;

		bn->setData(&outputData);

		output->produce(bn);

		output->process();
		return FILTER_SUCCESS;
	}

	~Multiply2Filter() {
	}

};

#endif /* MULTIPLY2FILTER_H_ */