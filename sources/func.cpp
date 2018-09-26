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

void format(std::string* mgrs, int prec)
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
