#include <iostream>

int main() {
    int zahl_a = 13;
    int zahl_b = 10;
    int holder = zahl_a;
    int result = 0;

    while(holder != 0){
        if(holder < zahl_b){
            std::cout << result << std::endl;
            return 0;
        }
        holder = holder - zahl_b;
        ++result;
    }

    std::cout << result << std::endl;

    return 0;
}