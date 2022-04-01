#include <iostream>
#include <cmath>
#include <array>
#include "funcs.h"

// add functions here

std::string decryptCaesar(std::string ciphertext, int rshift) {
  std::string plaintext = "";
  rshift = rshift * -1;
  for (int i = 0;i < ciphertext.length();i++) {
    plaintext += shiftChar(ciphertext[i],rshift);
  }
  return plaintext;
}

char shiftChar(char c, int rshift) {
  char caps[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  char lowercase[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  if (int(c) > 96 && int(c) < 123) {
    int charindex = int(c) - 97;
    charindex += rshift;
    if (charindex < 0) {
      return lowercase[26 + charindex];
    }
    else {
      int encodedindex = charindex % 26;
      char encodedchar = lowercase[encodedindex];
      return encodedchar;
    }
  }
  else if (int(c) > 64 && int(c) < 91) {
    int charindex = int(c) - 65;
    charindex += rshift;
    if (charindex < 0) {
      return caps[26 + charindex];
    }
    else {
      int encodedindex = charindex % 26;
      char encodedchar = caps[encodedindex];
      return encodedchar;
    }
  }
  else {
    return c;
    }
}

std::array<double,26> getFrequency(std::string str) {
  //std::cout << "were inside!" << std::endl;
  double totalchars = 0.0;
  std::array<double,26> frequencyChart = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int index;
  //double* ptr = &frequencyChart;
  for (int i = 0;i < str.length();i++) {
    //std::cout << "i: " << i << std::endl;
    if ((int(str[i]) > 96) && (int(str[i]) < 123)) {
      //std::cout << "were inside 1!" << std::endl;
      index = int(str[i]) - 97;
      //index = charIndex(str[i]);
      frequencyChart.at(index) += 1.0;
      //*(frequencyChartptr + i) += 1.0;
      totalchars += 1.0;
    }
    else if ((int(str[i]) > 64) && (int(str[i]) < 91)) {
      //std::cout << "were inside 2!" << std::endl;
      index = int(str[i]) - 65;
      //std::cout << "index: " << index << std::endl;
      //index = charIndex(str[i]);
      frequencyChart.at(index) += 1.0;
      //*(frequencyChartptr + i) += 1.0;
      totalchars += 1.0;
    }
  }
  for (int i = 0; i < 26; i++) {
    frequencyChart.at(i) = frequencyChart.at(i)/totalchars;
    //*(frequencyChartptr + i) = *(frequencyChartptr + i)/totalchars;
  }
  //return ptr;
  return frequencyChart;
}

int findshift(std::array<double,26> arr) {
  double mindistsofar;
  double shiftsofar;
  double avgshift[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  double freqOfLangChar[26] = {0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074};
  for (int i = 0; i < 26;i++) {
    std::cout << "i: " << i << std::endl;
    std::cout << "arr[i] " << arr[i] << std::endl;
    mindistsofar = arr[i]-freqOfLangChar[0];
    std::cout << "mindistsofar: " << mindistsofar << std::endl;
    std::cout << "shiftsofar: " << shiftsofar << std::endl;
    shiftsofar = 0;
    for (int j = i; j < 26;j++)
      if (mindistsofar > abs(arr[i]-freqOfLangChar[j])) {
        mindistsofar = abs(arr[i]-freqOfLangChar[j]);
        //std::cout << "i: " << i << " j: " << j << " arr[i]: " << arr[i] << " freqOfLangChar[j]: " << freqOfLangChar[j] << std::endl;
        shiftsofar += 1;
        std::cout << "mindistsofar: " << mindistsofar << std::endl;
        std::cout << "shiftsofar: " << shiftsofar << std::endl;
      }
      else {
        shiftsofar += 1;
        std::cout << "mindistsofar: " << mindistsofar << std::endl;
        std::cout << "shiftsofar: " << shiftsofar << std::endl;
      }
    for (int j = 0; j < i;j++) {
      if (mindistsofar > abs(arr[i]-freqOfLangChar[j])) {
        mindistsofar = abs(arr[i]-freqOfLangChar[j]);
        shiftsofar += 1;
        std::cout << "mindistsofar: " << mindistsofar << std::endl;
        std::cout << "shiftsofar: " << shiftsofar << std::endl;
      }
      else {
        shiftsofar += 1;
        std::cout << "mindistsofar: " << mindistsofar << std::endl;
        std::cout << "shiftsofar: " << shiftsofar << std::endl;
      }
    }
    avgshift[i] = shiftsofar;
    std::cout << "avgshift[i]: " << avgshift[i] << std::endl;
    std::cout << "shiftsofar: " << shiftsofar << std::endl;
  }
  int estimatedShift;
  double sum = 0;
  for (int i = 0; i < 26;i++) {
    sum += avgshift[i];
  }
  estimatedShift = round(sum/26);
  return estimatedShift;
}


std::string solve(std::string encrypted_string) {
  std::string decrypted_string;
  //std::cout << "step 1" << std::endl;
  std::array<double,26> frequencyChart;
  //std::cout << "step 2" << std::endl;
  frequencyChart = getFrequency(encrypted_string);
  //std::cout << "step 3" << std::endl;
  int shift = findshift(frequencyChart);
  std::cout << "shift: " << shift << std::endl;
  for (int i = 0;i < 26;i++) {
    std::cout << frequencyChart.at(i) << " ";
  }
  std::cout << std::endl;
  //std::cout << "step 4" << std::endl;
  decrypted_string = decryptCaesar(encrypted_string,shift);
  std::cout << decrypted_string << std::endl;
  return decrypted_string;
}
