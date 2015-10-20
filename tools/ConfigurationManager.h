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

#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class ConfigurationManager
{
private:
  std::string fileName;
  std::fstream cfile;
  std::map<std::string, std::string> data;
public:
ConfigurationManager(const std::string& fname);
std::string getValue(const std::string& key);
~ConfigurationManager();
};

#endif // CONFIGURATIONMANAGER_H
