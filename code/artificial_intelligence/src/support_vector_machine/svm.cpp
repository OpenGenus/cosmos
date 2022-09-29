#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <array>

class SVMClass {

    private:

    int dataPointSize;
    std::vector<int,int> dataset;
    //int int std::array arrayData [5,5];

    public:

    SVMClass();
    SVMClass(std::vector<int,int> vectData, int dataPointSize);

    void inputSet();
    int getDataSetSize();

    std::string getHyperplaneFunction();
};

SVMClass::SVMClass(){
}

SVMClass::SVMClass(std::vector<int,int> inputVec, int dataPointSize){

    this->dataPointSize = dataPointSize;
    this->dataset = inputVec; 

}

void SVMClass::inputSet(){

}

std::string SVMClass::getHyperplaneFunction(){

    std::string function = "";

    return function;
}

int main(){

    int testVectSize = 2;
    std::vector<int,int> testVectData = {};

    SVMClass testSVM(testVectData, testVectSize);


}