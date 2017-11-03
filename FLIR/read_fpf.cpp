#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <stdlib.h>

#include "oFPF.h"

int main( int argc, char* argv[]) 
{
  //  std::string fname = "img0323.fpf", fitsname="img0323.fits";
  std::string fname, fitsname;
  bool noshow=false;
  int f=0,c=0;
  ifstream file_p;
  oFPF fpf_obj;

  if (argc == 1) {
    std::cout << "Exit..." << endl;
    exit(0);
  }
  
  if (argc == 2) {
    fname=(string) argv[1]+".fpf";
    fitsname=(string) argv[1]+"fits";
  }
  
  fpf_obj.OpenImage(fname, file_p);
  fpf_obj.ReadHeader(file_p);
  fpf_obj.DimensionDataArray(noshow);
  
  fpf_obj.ReadImage(file_p);
  //  fpf_obj.ShowHeader();

  fpf_obj.CloseImage(file_p);
  
  //if (argc == 2) fpf_obj.writeFITS(fitsname);

  if (argc == 4)
    {
      fname = (string) argv[1]+".fpf" ;
      f=atoi(argv[2]);
      c=atoi(argv[3]);
      cout << endl << endl << "File = " << fname << endl ;
      cout << "Element <" << f << "," << c << "> = " << fpf_obj.getElement(f,c) << endl << endl << endl ;
    }
    
}