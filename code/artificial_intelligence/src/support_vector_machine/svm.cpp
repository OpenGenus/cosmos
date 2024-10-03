#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <array>
#include <math.h>

//Implementing a Linear SVM in the form of "wx - b = 0"
//I will write the function in string form, and it can 
//be eventually implemented to an actual equation

class SVMClass {

    private:

    int dataPointSize;
    int dataSize;
    std::vector<std::pair<float,float>> dataset;

    float wVal;
    float bVal;

    //int int std::array arrayData [5,5];

    public:

    SVMClass();
    SVMClass(std::vector<std::pair<float,float>> vectData, int dataPointSize);

    void inputSet(std::vector<std::pair<float,float>> dataInput);
    int getDataSetSize();

    void calculateHyperplane();
    std::string getHyperplaneFunction();
};

SVMClass::SVMClass(){
}

SVMClass::SVMClass(std::vector<std::pair<float,float>> inputVec, int dataPointSize){

    this->dataPointSize = dataPointSize;
    this->dataset = inputVec; 
    this->dataSize = inputVec.size();

}

void SVMClass::inputSet(std::vector<std::pair<float,float>> dataInput){

    this->dataset = dataInput;

}

void SVMClass::calculateHyperplane(){

    float sumX = 0;
    float sumY = 0;

    float sumTotal = 0;

    for (int i = 0; i < dataset.size(); i++){
        sumX += dataset.at(i).first; 
        sumY += dataset.at(i).second; 
    }

    sumTotal = pow(sumX,2) + pow(sumY,2);

    wVal = sqrt(sumTotal);

    bVal = wVal/sumTotal;
}

std::string SVMClass::getHyperplaneFunction(){

    std::string function = "";
    function += std::to_string(this->wVal);

    function = function + "*";
    function += "x";

    function = function + "-";
    function += std::to_string(this->bVal);

    function = function + "=0";
    return function;
}

int main(){

    int testVectSize = 2;
    //pairs are separated into their x and y components and act as the "x vectors" from the origin
    std::vector<std::pair<float,float>> testVectData = {{1.1,2}, {2.1,1}, {3,3.2}};

    SVMClass testSVM(testVectData, testVectSize);



}