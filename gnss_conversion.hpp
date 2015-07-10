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

#define _GNU_SOURCE   // to use M_PI

#include <iostream>
#include <cmath>

class Gnss_Coordinate{
public:
  double deg;
  double rad;
  double iso6709;
  int dms[3];
  void Deg_To_Rad(){
    rad = deg * M_PI / 180;
  }
  void Rad_To_Deg(){
    deg = rad / M_PI * 180;
  }
  void Deg_To_DMS(){
    dms[0] = (int) deg;
    dms[1] = (int) ( (deg-dms[0])*60 );
    dms[2] = (int) ( ( (deg-dms[0])*60-dms[1] )*60 );
  }
  void DMS_To_Deg(){
    deg = dms[0]+dms[1]/60.+dms[2]/3600.;
  }
  void Deg_To_Iso6709(){
    iso6709 = dms[0]*100+(deg-dms[0])*60;
  }
  void Iso6709_To_DMS(){
//    dms[0] = (int) ( iso6709 / 1e2 );
    dms[0] = iso6709 / 1e2 ;
    dms[1] = iso6709 - dms[0]*1e2 ;
    dms[2] = ( iso6709 - (int) iso6709 )*60;
  }
  Gnss_Coordinate(){
    deg = 0.0;
    Deg_To_Rad();
    Deg_To_DMS();
    Deg_To_Iso6709();    
  }
  Gnss_Coordinate(int deg_int, int min_int, int sec_int){ 
    dms[0] = deg_int;
    dms[1] = min_int;
    dms[2] = sec_int;
  }
  /* Constructor's flag 
   * 'd' = degree  = dd.dddddd
   * 'r' = radians = rr.rrrrrr
   * 'i' = iso6709 = ddmm.mmmm
   */
  Gnss_Coordinate(double number, char flag = 'd'){ 
    switch(flag){
    case 'd':
      deg = number;
      Deg_To_Rad();
      Deg_To_DMS();
      Deg_To_Iso6709();
      break;
    case 'r':
      rad = number;
      Rad_To_Deg();
      Deg_To_DMS();
      Deg_To_Iso6709();
      break;
    case 'i':
      iso6709 = number;
      Iso6709_To_DMS();
      DMS_To_Deg();      
      Deg_To_Rad();
      break;
    default:
      std::cout << "Encoding not found. Default to zero." << std::endl;
      deg = 0.0;
      Deg_To_Rad();
      Deg_To_DMS();
      Deg_To_Iso6709();      
      break;
    }
  }
};

class Gnss_Point{
public:
  Gnss_Coordinate lat, lon;
  Gnss_Point(){};
  Gnss_Point( double d_lat, double d_lon, char flag = 'd'){
    switch(flag){
    case 'd':
    case 'r':
    case 'i':
      lat = Gnss_Coordinate(d_lat, flag);
      lon = Gnss_Coordinate(d_lon, flag);
      break;
    default:
      std::cout << "Encoding not found. Default to zero." << std::endl;
    }
  }
};
