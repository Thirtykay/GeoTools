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

#include "../headers/func.hpp"

/*
* Static Member Function - do not call
* Format MGRS string from 38TLPXXXXXXXXX to 38T LP XXXXX XXXXX
* param : *mgrs the non formated mgrs string, prec the required precison 
*/
void GeoTools::format(std::string* mgrs, int prec)
{
    switch (prec)
    {
        case 3:
            mgrs->insert(3, " ");
            mgrs->insert(6, " ");
            mgrs->insert(10, " ");
            std::cout << *mgrs << std::endl;
        break;

        case 4:
            mgrs->insert(3, " ");
            mgrs->insert(6, " ");
            mgrs->insert(11, " ");
            std::cout << *mgrs << std::endl;
        break;

        case 5:
            mgrs->insert(3, " ");
            mgrs->insert(6, " ");
            mgrs->insert(12, " ");
            std::cout << *mgrs << std::endl;
        break;

        default:
            std::cout << "Error prec bad value !" << std::endl;
        break;

    }
}

/*
* Convert any Latitude/Longitude coords type to a MGRS coord 
* param : void
*/
void GeoTools::mgrsConvert(void)
{

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
        //return 1;
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

        if(cont == 'Y')
        {
            system("clear");
        }

    }

    std::cout << "See you later" << std::endl;


}

/* @WIP
* Convert any Latitude/Longitude coords type to a MGRS coord 
* param : void
*/
void GeoTools::utmConvert(void)
{

    float lat = 33.3, lon = 44.4;
    int zone;
    bool northp;
    double x, y;

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

        UTMUPS->Forward(lat, lon, zone, northp, x, y);
    }
    catch(const std::exception &e)
    {
            std::cerr << "Caught exception on UTM/UPS Conversion: " << e.what() << "\n";
            std::cout << "Exiting program" << std::endl;
            exit(0);
    }

    std::string zonestr = UTMUPS->EncodeZone(zone, northp);
    std::cout << std::fixed << std::setprecision(0) << zonestr << " " << x << " " << y << "\n";

    }
}

/*
* Display the main menu
* param : void
*/
void GeoTools::displayMenu(void)
{
    std::cout << "**************MENU**************" << std::endl;
    std::cout << "1 - Latitude/Longitude to MGRS" << std::endl; 
    std::cout << "2 - Latitude/Longitude to UTMUPS" << std::endl;
    std::cout << "3 - Decimal Degrees to DMS" << std::endl;
    std::cout << "4 - Decimal Degrees to DMD" << std::endl;
    std::cout << "5 - DMS to Decimal Degrees" << std::endl;
    std::cout << "6 - DMD to Decimal Degrees" << std::endl;
    std::cout << "7 - Latitude/Longitude to offset" << std::endl;
    std::cout << "***********END OF MENU**********" << std::endl;
}
