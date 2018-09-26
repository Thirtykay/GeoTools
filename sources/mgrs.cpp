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

#include <GeographicLib/MGRS.hpp>
#include <GeographicLib/UTMUPS.hpp>
#include "../headers/func.hpp"

GeographicLib::MGRS *MGRS;
GeographicLib::UTMUPS *UTMUPS;


int main(int argc, char const *argv[])
{

    std::cout << "GeoTools Copyright (C) 2018 Thirtykay" << std::endl;
    std::cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'." << std::endl;
    std::cout << "This is free software, and you are welcome to redistribute it" << std::endl;
    std::cout << "under certain conditions; type `show c' for details. " << std::endl;

    //My coords, Pegomas 43.5985, 6.9303
    float lat, lon;
    //UTM Zone, no init, MGRS Grid precision
    int zone, prec;
    //North or South hemisphere
    bool northp;
    //Easting = x, Northing = y
    double x, y;

    try
    {

        std::cout << "MGRS Start-Up" << std::endl;
        MGRS->Check();

    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught exception on MGRS Start-Up: " << e.what() << "\n";
        return 1;
    }

    char cont = 'Y';

        std::cout << "MGRS Converter ready" << std::endl;
        std::cout << "Enter your Lat & Long coords" << std::endl;

    while(cont == 'Y')
    {
        bool retryLat = true;
        bool retryLon = true;
        bool retryPrec = true;

        while(retryLat == true)
        {
            std::cout << "Latitude : ";
            std::cin >> lat;

            if(lat < -90 || lat > 90)
            {
                std::cout << "Bad value for lat" << std::endl;
                std::cout << "Valid range for lat is -90d to 90d" << std::endl;
            }
            else
            {
                retryLat = false;
            }
        }

        while(retryLon == true)
        {
            std::cout << "Longitude : ";
            std::cin >> lon;

            if(lon < -180 || lon > 180)
            {
                std::cout << "Bad value for lat" << std::endl;
                std::cout << "Valid range for lat is -180d to 180d" << std::endl;
            }
            else
            {
                retryLon = false;
            }
        }

        try
        {
            //Converting Lat/Long to UTMUPS
            UTMUPS->Forward(lat, lon, zone, northp, x, y);
        }
        catch(const std::exception &e)
        {
            std::cerr << "Caught exception on UTM/UPS Conversion: " << e.what() << "\n";
            std::cout << "Exiting program" << std::endl;
            exit(0);
        }

        while(retryPrec == true)
        {
            std::cout << "Enter the required precision : ";
            std::cin >> prec;

            if(prec < 3 || prec > 5)
            {
                std::cout << "Bad value for prec" << std::endl;
                std::cout << "Valid value for prec are 3, 4 and 5" << std::endl;
            }
            else
            {
                retryPrec = false;
            }
        }

        //Init of the new MGRS string
        std::string mgrs;

        try
        {
            //Converting UTMUPS to MGRS
            MGRS->Forward(zone, northp, x, y, lat, prec, mgrs);
        }
        catch(const std::exception &e)
        {
            std::cerr << "Caught exception on MGRS Conversion: " << e.what() << "\n";
            std::cout << "Exiting program" << std::endl;
            exit(0);
        }

        std::cout << "Conversion done !" << std::endl;
        std::cout << "Your MGRS coords: ";
        //Format the mgrs string to a user-readable string
        format(&mgrs, prec);

        //Asking user if he want to launch the program again
        std::cout << "New conversion ? (Y/n): ";
        std::cin >> cont;

    }

    std::cout << "See you later" << std::endl;

    return 0;
}
