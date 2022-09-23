#include <iostream>
#include <vector>
using namespace std;

class Flower {
public:
    string name = "";
    string color = "";
    string hem = "";
    bool sweet = false;
    Flower(const string &name, const string &hem, const string &color, const bool &sweet){
        this->name = name;
        this->hem=hem;
        this->color=color;
        this->sweet = sweet;
    }
};

int main() {
    //create new class flower with color, hemisphere as x values
    //y is if it has sweet smell or not
    //Marigold: yellow, south, sweet
    //Rose: white, south, not-sweet
    //Lily: white, north, not-sweet
    //Jasmine: white, north, sweet

    float white = 0;
    float yellow = 0;
    float north = 0;
    float south = 0;
    float sweet_white = 0;
    float sweet_yellow = 0;
    float non_sweet_white = 0;
    float non_sweet_yellow = 0;
    float sweet_south = 0;
    float sweet_north = 0;
    float non_sweet_south = 0;
    float non_sweet_north = 0;
    float sweet = 0;
    float non_sweet = 0;

    vector<Flower> flowers;
    Flower flower1("Marigold","south","yellow",true);
    Flower flower2("Rose","south","white",false);
    Flower flower3("Lily","north","white",false);
    Flower flower4("Jasmine","north","white",true);
    flowers.push_back(flower1);
    flowers.push_back(flower2);
    flowers.push_back(flower3);
    flowers.push_back(flower4);

    for(int i = 0; i < flowers.size(); i++){
        if(flowers.at(i).color == "white"){
            white++;
            if(flowers.at(i).sweet) {
                sweet+=1;
                sweet_white += 1;
                if(flowers.at(i).hem == "north"){
                    north+=1;
                    sweet_north+=1;
                }
                else{
                    non_sweet+=1;
                    south+=1;
                    sweet_south+=1;
                }
            }
            else {
                non_sweet_white += 1;
                non_sweet+=1;
                if(flowers.at(i).hem == "north"){
                    north+=1;
                    non_sweet_north+=1;
                }
                else{
                    south+=1;
                    non_sweet_south+=1;
                }
            }
        }
        else{
            yellow++;
            if(flowers.at(i).sweet) {
                sweet+=1;
                sweet_yellow += 1;
                if(flowers.at(i).hem == "north"){
                    north+=1;
                    sweet_north+=1;
                }
                else{
                    south+=1;
                    sweet_south+=1;
                }
            }
            else {
                non_sweet_yellow += 1;
                non_sweet+=1;
                if(flowers.at(i).hem == "north"){
                    north+=1;
                    non_sweet_north+=1;

                }
                else{
                    south+=1;
                    non_sweet_south+=1;
                }
            }
        }
    }

    //posterior probabilities
    float prob_sweet_white = sweet_white/sweet;
    float prob_sweet_yellow = sweet_yellow/sweet;
    float prob_non_sweet_white = non_sweet_white/non_sweet;
    float prob_non_sweet_yellow = non_sweet_yellow/non_sweet;
    float prob_sweet_south = sweet_south/sweet;
    float prob_sweet_north = sweet_north/sweet;
    float prob_non_sweet_south = non_sweet_south/non_sweet;
    float prob_non_sweet_north = non_sweet_north/non_sweet;

    //Naive_Bayes_Algo
    //what scent is a yellow, northern rose?
    //P(Sweet/X) = P(yellow/sweet)*P(northern/sweet)*P(sweet)

    //calculates for sweet
    float isSweet = prob_sweet_yellow*prob_sweet_north*(sweet/(sweet+non_sweet));
    float isNotSweet = prob_non_sweet_yellow*prob_non_sweet_north*(non_sweet/(sweet+non_sweet));

    if(isSweet > isNotSweet)
        cout << "The scent is sweet!";
    else
        cout << "The scent is not sweet!";



}
