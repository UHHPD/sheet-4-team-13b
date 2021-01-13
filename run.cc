#include <iostream>
#include <vector>
#include <functional>
#include <string>

#include "Data.hh"

// generic function comparing two values of some type T used later for int and
// double
template <class T>
bool testEqual(const std::string& name, T expected, T real) {
  if (expected != real) {
    std::cout << "(" << name << ": <" << expected << ">"
              << ", " << real << ") ";
    return false;
  }
  return true;
}

bool testReadingSize() {
  std::cout << "testReadingSize...";
  Data datA("testA");
  return testEqual<int>("size", 1, datA.size());
}

bool testReadingMeasurement() {
  std::cout << "testReadingMeasurement...";
  Data datA("testA");
  return testEqual("measurement", 10., datA.measurement(0));
}

bool testReadingBinEdges() {
  std::cout << "testReadingBinEdges...";
  Data datA("testA");
  return testEqual("bin low", 0., datA.binLow(0)) &&
         testEqual("bin high", 1., datA.binHigh(0));
}

bool testReadingErrors() {
  std::cout << "testReadingErrors...";
  Data datA("testA");
  return testEqual("error", 2., datA.error(0));
}

bool testCopyConstructor() {
  std::cout << "testCopyConstructor...";
  Data a("testA");
  Data b(a);
  Data c = a;  // equivalent to Data c(a)
  return testEqual("measurement", 10., b.measurement(0)) &&
         testEqual("measurement", 10., c.measurement(0));
}

void runTests() {
  std::cout << "running tests...\n";
  std::vector<std::function<bool()> > tests(
      {testReadingSize, testReadingMeasurement, testReadingBinEdges,
       testReadingErrors, testCopyConstructor});
  for (auto test : tests)
    std::cout << (test() ? " ok" : " FAILED!") << std::endl;
}

int main() {
  using namespace std;

  cout << "******************************************************" << endl;
  runTests();
  cout << "******************************************************" << endl;
  // create an object which holds data of all 4 experiments
  Data datA("exp_A");
  Data datB("exp_B");
  Data datC("exp_C");
  Data datD("exp_D");
  
  vector<Data> dset;
  
  dset.push_back(datA);
  dset.push_back(datB);
  dset.push_back(datC);
  dset.push_back(datD);
  

  // here is the data from experiment A,B,C,D.
  cout << "bin 27: from " << datA.binLow(27) << " to " << datA.binHigh(27)
       << endl;
  cout << "measurement of experiment A in bin 27: " << datA.measurement(27)
       << endl;
       
  cout << "bin 27: from " << datB.binLow(27) << " to " << datB.binHigh(27)
       << endl;
  cout << "measurement of experiment B in bin 27: " << datB.measurement(27)
       << endl;
       
  cout << "bin 27: from " << datC.binLow(27) << " to " << datC.binHigh(27)
       << endl;
  cout << "measurement of experiment C in bin 27: " << datC.measurement(27)
       << endl;
       
  cout << "bin 27: from " << datD.binLow(27) << " to " << datD.binHigh(27)
       << endl;
  cout << "measurement of experiment D in bin 27: " << datD.measurement(27)
       << endl;
  
  cout<< "bin 27 0f Exp A and Exp B agree within 1*sigma:" << datA.sigma(datB,1,27)<< endl; 
  cout<< "bin 27 0f Exp A and Exp B agree within 2*sigma:" << datA.sigma(datB,2,27)<< endl;
  cout<< "bin 27 0f Exp A and Exp B agree within 3*sigma:" << datA.sigma(datB,3,27)<< endl;
  
  //Exercise 1d
  cout<<"number of bins that differ more than 1*sigma for Exp A and Exp B:" << datA.checkCompatibility(datB,1)<<endl; 
  
  cout<<"number of bins that differ more than 1*sigma for Exp A and Exp C:" << datA.checkCompatibility(datC,1)<<endl; 
  
  cout<<"number of bins that differ more than 1*sigma for Exp A and Exp D:" << datA.checkCompatibility(datD,1)<<endl; 
  
  cout<<"number of bins that differ more than 1*sigma for Exp B and Exp C:" << datB.checkCompatibility(datC,1)<<endl; 
  
  cout<<"number of bins that differ more than 1*sigma for Exp B and Exp D:" << datB.checkCompatibility(datD,1)<<endl; 
  
  cout<<"number of bins that differ more than 1*sigma for Exp C and Exp D:" << datC.checkCompatibility(datD,1)<<endl; 
  
  
  //Exercise 2 a
  
  cout<<"For a Gaussian distribution, 95.4% of the data-points (55 points in given experiemnts) should be within 2 standard deviations" <<endl;
  
  
  
  cout<<"number of bins that differ more than 2*sigma for Exp A and Exp B:" << datA.checkCompatibility(datB,2)<<endl; 
  cout<<"As per the above hypothesis, experiemnts are compatible" <<endl;
  
  
  cout<<"number of bins that differ more than 2*sigma for Exp A and Exp C:" << datA.checkCompatibility(datC,2)<<endl;
  cout<<"As per the above hypothesis, experiemnts are compatible" <<endl;
  
  
  cout<<"number of bins that differ more than 2*sigma for Exp A and Exp D:" << datA.checkCompatibility(datD,2)<<endl; 
  cout<<"As per the above hypothesis, experiemnts are compatible" <<endl;
  
  
  cout<<"number of bins that differ more than 2*sigma for Exp B and Exp C:" << datB.checkCompatibility(datC,2)<<endl; 
  cout<<"As per the above hypothesis, experiemnts are compatible" <<endl;
  
  
  cout<<"number of bins that differ more than 2*sigma for Exp B and Exp D:" << datB.checkCompatibility(datD,2)<<endl;
  cout<<"As per the above hypothesis, experiemnts are not compatible" <<endl;
  
  
  cout<<"number of bins that differ more than 2*sigma for Exp C and Exp D:" << datC.checkCompatibility(datD,2)<<endl;
  cout<<"As per the above hypothesis, experiemnts are compatible" <<endl;
  
  
  
  
  cout<<"For a Gaussian distribution, 99.7% of the data-points (All 56 points in given experiemnts) should be within 3 standard deviations" <<endl;
  
  
  
  cout<<"number of bins that differ more than 3*sigma for Exp A and Exp B:" << datA.checkCompatibility(datB,3)<<endl; 
  cout<<"As per the above hypothesis, experiemnts are compatible" <<endl;
  
  
  cout<<"number of bins that differ more than 3*sigma for Exp A and Exp C:" << datA.checkCompatibility(datC,3)<<endl;
  cout<<"As per the above hypothesis, experiemnts are compatible" <<endl;
  
  
  cout<<"number of bins that differ more than 3*sigma for Exp A and Exp D:" << datA.checkCompatibility(datD,3)<<endl;
  cout<<"As per the above hypothesis, experiemnts are compatible" <<endl;
  
  
  cout<<"number of bins that differ more than 3*sigma for Exp B and Exp C:" << datB.checkCompatibility(datC,3)<<endl;
  cout<<"As per the above hypothesis, experiemnts are compatible" <<endl;
  
  
  cout<<"number of bins that differ more than 3*sigma for Exp B and Exp D:" << datB.checkCompatibility(datD,3)<<endl;
  cout<<"As per the above hypothesis, experiemnts are not compatible" <<endl;
  
  
  cout<<"number of bins that differ more than 3*sigma for Exp C and Exp D:" << datC.checkCompatibility(datD,3)<<endl;
  cout<<"As per the above hypothesis, experiemnts are compatible" <<endl;
  
  
  
  //Exercise 1 e, 2 c
  
  cout<< "The average of Exp A and Exp B is" << endl;
  Data avgAB = datA.average(datB);
  
  cout<< "The average of Exp C and Exp D is" << endl;
  Data avgCD = datC.average(datD);
  
  cout<< " The combined dataset is" << endl;
  Data comDset = avgAB.average(avgCD);
 
 cout << " The X^2/ndf of combined dataset is " << comDset.function_X()[0]/52.0 << endl;  
 
  //Exercise 2 b
  
  cout << "The background function has values" << endl;
  std::vector<double> bf = datD.function();
  for(int i=0; i< bf.size(); i++)
  {
    cout << bf[i] <<"\n";
  }
  
  cout << "The X^2/ndf of Exp A is" <<endl;
  std::vector<double> cs1 = datA.function_X();
  for (int i=0; i<cs1.size(); i++)
  {
    cout << cs1[i]/52 << "\n";
  }
  
  cout << "The X^2/ndf of Exp B is" <<endl;
  std::vector<double> cs2 = datB.function_X();
  for (int i=0; i<cs2.size(); i++)
  {
    cout << cs2[i]/52 << "\n";
  }
  
  cout << "The X^2/ndf of Exp C is" <<endl;
  std::vector<double> cs3 = datC.function_X();
  for (int i=0; i<cs3.size(); i++)
  {
    cout << cs3[i]/52 << "\n";
  }
  
  cout << "The X^2/ndf of Exp D is" <<endl;
  std::vector<double> cs4 = datD.function_X();
  for (int i=0; i<cs4.size(); i++)
  {
    cout << cs4[i]/52 << "\n";
  }
  
 return 0;
 
}
