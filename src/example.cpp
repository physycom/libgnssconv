/* Copyright 2015 - Alessandro Fabbri, Stefano Sinigardi */

/***************************************************************************
This file is part of gnss_conversion.

gnss_conversion is free software : you can redistribute it and / or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

gnss_conversion is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with gnss_conversion. If not, see <http://www.gnu.org/licenses/>.
***************************************************************************/
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <iostream>
#include <iomanip>
#include "libgnssconv/libgnssconv.hpp"

#define LAT_BO 44.499371
#define LON_BO 11.353849

int main(){
  std::cout << "TEST GNSS_COORDINATE class" << std::endl;

// Gnss_Coordinate DEGREE constructor test
  Gnss_Coordinate lat(LAT_BO), lon(LON_BO);
  std::cout << "TEST degree constructor" << std::endl;
  std::cout << "lat deg: " << std::fixed << std::setprecision(6) << lat.deg << "\t\tlon deg: " << lon.deg << std::endl;
  std::cout << "lat rad: " << lat.rad << "\t\t\tlon rad: " << lon.rad << std::endl;
  std::cout << "lat dms: " << lat.dms[0] << "d" << lat.dms[1] << "m" << lat.dms[2] << "s" 
       << "\t\tlon dms: " << lon.dms[0] << "d" << lon.dms[1] << "m" << lon.dms[2] << "s" << std::endl;
  std::cout << "lat iso: " << std::fixed << std::setprecision(4) << lat.iso6709 << "\t\tlon iso: " << lon.iso6709 << std::endl << std::endl;

// Gnss_Coordinate RADIANS constructor test
  Gnss_Coordinate lat_r(M_PI/2.999, 'r'), lon_r(M_PI/1.999, 'r');
  std::cout << "TEST radians constructor" << std::endl;
  std::cout << "lat deg: " << std::fixed << std::setprecision(6) << lat_r.deg << "\t\tlon deg: " << lon_r.deg << std::endl;
  std::cout << "lat rad: " << lat_r.rad << "\t\t\tlon rad: " << lon_r.rad << std::endl;
  std::cout << "lat dms: " << lat_r.dms[0] << "d" << lat_r.dms[1] << "m" << lat_r.dms[2] << "s" 
       << "\t\t\tlon dms: " << lon_r.dms[0] << "d" << lon_r.dms[1] << "m" << lon_r.dms[2] << "s" << std::endl;
  std::cout << "lat iso: " << std::fixed << std::setprecision(4) << lat_r.iso6709 << "\t\tlon iso: " << lon_r.iso6709 << std::endl << std::endl;

// Gnss_Coordinate ISO6709 constructor test
  Gnss_Coordinate lat_i(4429.9623, 'i'), lon_i(1121.2309, 'i');
  std::cout << "TEST iso6709 constructor" << std::endl;
  std::cout << "lat deg: " << std::fixed << std::setprecision(6) << lat_i.deg << "\t\tlon deg: " << lon_i.deg << std::endl;
  std::cout << "lat rad: " << lat_i.rad << "\t\t\tlon rad: " << lon_i.rad << std::endl;
  std::cout << "lat dms: " << lat_i.dms[0] << "d" << lat_i.dms[1] << "m" << lon_i.dms[2] << "s" 
       << "\t\t\tlon dms: " << lon_i.dms[0] << "d" << lon_i.dms[1] << "m" << lon_i.dms[2] << "s" << std::endl;
  std::cout << "lat iso: " << std::fixed << std::setprecision(4) << lat_i.iso6709 << "\t\tlon iso: " << lon_i.iso6709 << std::endl << std::endl;

// Gnss_Coordinate DEFAULT constructor test
  Gnss_Coordinate lat_def(M_PI/2.999, 'x'), lon_def(M_PI/1.999, 'x');
  std::cout << "TEST default constructor" << std::endl;
  std::cout << "lat deg: " << std::fixed << std::setprecision(6) << lat_def.deg << "\t\t\tlon deg: " << lon_def.deg << std::endl;
  std::cout << "lat rad: " << lat_def.rad << "\t\t\tlon rad: " << lon_def.rad << std::endl;
  std::cout << "lat dms: " << lat_def.dms[0] << "d" << lat_def.dms[1] << "m" << lat_def.dms[2] << "s" 
       << "\t\t\t\tlon dms: " << lon_def.dms[0] << "d" << lon_def.dms[1] << "m" << lon_def.dms[2] << "s" << std::endl;
  std::cout << "lat iso: " << std::fixed << std::setprecision(4) << lat_def.iso6709 << "\t\t\t\tlon iso: " << lon_def.iso6709 << std::endl << std::endl;


  std::cout << "TEST GNSS_POINT class" << std::endl;
// Gnss_Point DEGREE constructor test
  Gnss_Point point( LAT_BO , LON_BO );
  std::cout << "lat deg: " << std::fixed << std::setprecision(6) << point.lat.deg << "\t\tlon deg: " << point.lon.deg << std::endl;
  std::cout << "lat rad: " << point.lat.rad << "\t\t\tlon rad: " << point.lon.rad << std::endl;
  std::cout << "lat dms: " << point.lat.dms[0] << "d" << point.lat.dms[1] << "m" << point.lat.dms[2] << "s" 
       << "\t\tlon dms: " << point.lon.dms[0] << "d" << point.lon.dms[1] << "m" << point.lon.dms[2] << "s" << std::endl;
  std::cout << "lat iso: " << std::fixed << std::setprecision(4) << point.lat.iso6709 << "\t\tlon iso: " << point.lon.iso6709 << std::endl << std::endl;

  return 0;
}

