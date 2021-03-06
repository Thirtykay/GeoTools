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

#include <iostream>
#include <string>

#include "../headers/func.hpp"

GeoTools *geoTools;

int main(int argc, char const *argv[])
{

    bool firstStart = true;

    if(firstStart == true)
    {
        std::cout << "GeoTools Copyright (C) 2018 Thirtykay" << std::endl;
        std::cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'." << std::endl;
        std::cout << "This is free software, and you are welcome to redistribute it" << std::endl;
        std::cout << "under certain conditions; type `show c' for details. \n" << std::endl;
    }

    //geoTools->utmConvert();
    //geoTools->mgrsConvert();
    //geoTools->dmsConvert();

    return 0;
}
