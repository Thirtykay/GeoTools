/*
    GeoTools is a toolset for converting coords and other...
    Copyright (C) 2018 Thirtykay

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef FUNC_HPP
#define FUNC_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include <cmath>
#include <cstdint>

#include "database.hpp"

#include <GeographicLib/MGRS.hpp>
#include <GeographicLib/UTMUPS.hpp>

//test
class GeoTools
{

    public:
        GeoTools();
        ~GeoTools();

        static void format(std::string* mgrs, int prec);

        void mgrsConvert(void);
        void utmConvert(void);
        void dmsConvert(void);

        void displayMenu(void);

        GeographicLib::MGRS *MGRS;
        GeographicLib::UTMUPS *UTMUPS;

    private:
        const std::string geoToolsVer = "0x01"; 

};

#endif //FUNC_HPP
