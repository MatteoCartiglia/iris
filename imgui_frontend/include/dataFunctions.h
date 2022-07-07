//---------------------------------------------------------------------------------------------------------------------------------------
//
//
// Author: Ciara Giles-Doran <gciara@student.ethz.ch>
// Last updated: 
//---------------------------------------------------------------------------------------------------------------------------------------

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include "../../teensy_backend/include/datatypes.h"
#include "../include/constants.h"

//
std::vector<std::vector<std::string>> parseCSV(const std::string& path);

//
void getDACvalues(DAC_command dac[]);
void getBiasGenValues(BIASGEN_command biasGen[]);

//
int getFileLines(const std::string& path);
int getRelevantFileRows_BiasGen(std::string substring, BIASGEN_command biasGen[], bool relevantFileRows[], int fileRows);

//
void getAERpacket();
int decimalToBinary(int decimalVal);