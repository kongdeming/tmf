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

#ifndef MEDIASAMPLE_H
#define MEDIASAMPLE_H

#include "core/SampleSynchronizer.h"
#include <string>

enum class SampleStatus {
  OK,
  ERROR,
  EOS
};

template <typename T>
class MediaSample : public SampleSynchronizer {
  
private:
  int number;
  T * data;
  SampleStatus status;
  
public:
  MediaSample(): number(0), status(SampleStatus::OK) { data = new T(); } 
  
  T * get() { return data; }
  
  void setStatus(SampleStatus st) {status = st;}
  SampleStatus getStatus() {return status;}
  
  ~MediaSample() {
    delete data;
  }
};

#endif // MEDIASAMPLE_H
