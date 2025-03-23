#include <iostream>     /* std::cout */
#include <cmath>        /* std::abs */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

void print_bobs_friends_floors(unsigned char bobs_friends_floors[], const unsigned char &bobs_friends) {
    for(unsigned char x = bobs_friends - 2; x > 0; x--) {
        std::cout << +bobs_friends_floors[x] << ", "; // print all but the last two, delimited by commas
    }
    std::cout << +bobs_friends_floors[bobs_friends - 1] << " and " << +bobs_friends_floors[bobs_friends] << ".\n"; // print the last two
}

unsigned char find_closest_friend(const unsigned char &alice_floor, const unsigned char &bob_floor, unsigned char bobs_friends_floors[], const unsigned char &bobs_friends) {
    unsigned char closest {255}; // intialize to 255 so that the first evaluation will always overwrite this.
    for(unsigned char x = bobs_friends; x > 0; x--) {
        if((bobs_friends_floors[x] <= bob_floor && bobs_friends_floors[x] >= alice_floor) || (bobs_friends_floors[x] >= bob_floor && bobs_friends_floors[x] <= alice_floor)) // is the floor in between?
            return bobs_friends_floors[x]; // if the floor is inbetween Bob and Alice, there is no quicker floor Bob could stop at
        if((std::abs(bobs_friends_floors[x] - alice_floor)) < std::abs(closest - alice_floor) || (std::abs(bobs_friends_floors[x] - bob_floor)) < std::abs(closest - bob_floor)) // is this floor closer to Bob or Alice's place than the previous 'closest' floor?
            closest = bobs_friends_floors[x];
    }
    return closest;
}

unsigned char calculate_minutes(const unsigned char &alice_floor, const unsigned char &bob_floor, const unsigned char &closest) {
    if((closest <= bob_floor && closest >= alice_floor) || (closest >= bob_floor && closest <= alice_floor)) // if Bob's friend lives between himself and Alice, just return the difference of thier floors and add time_to_change later
        return std::abs(bob_floor - alice_floor);
    return std::abs(bob_floor - closest) + std::abs(closest - alice_floor); // otherwise, return the difference between Bob and his friend, and then his friend and Alice's floor.
}

int main() {
    srand(time(NULL)); // seed rand()
    unsigned char floors = (rand() % 190) + 10;
    /*  For a signed variable that is set = to rand() in a range where the largest bit is subject to change, the result could be negative.
        The same goes for any downstream variable that is set = to rand() % floors. For this reason, unsigned char is used. char takes up the least memory.
    */
    unsigned char alice_floor = (rand() % floors) + 1;
    unsigned char bob_floor = (rand() % floors) + 1;
    unsigned char bobs_friends = (rand() & 8) + 2; // unsigned simply for consistency
    unsigned char bobs_friends_floors[10] {};
    unsigned char time_to_change = (rand() % 5) + 5; // unsigned simply for consistency
    for(unsigned char x = bobs_friends; x > 0; x--) {
        bobs_friends_floors[x] = (rand() % floors) + 1;
    }

    std::cout << "\nBob and Alice's building has " << +floors << " floors.\n"
        << "Alice lives on floor " << +alice_floor << " and Bob lives on floor " << +bob_floor << ".\n"
        << "Bob has " << +bobs_friends << " friends that live in the building on floors ";
    print_bobs_friends_floors(bobs_friends_floors, bobs_friends);
    std::cout << "It takes bob " << +time_to_change << " minutes to stop at a friends place and change and 1 minute to move up or down one floor.\n";

    unsigned char closest = find_closest_friend(alice_floor, bob_floor, bobs_friends_floors, bobs_friends);
    unsigned char quickest_time = calculate_minutes(alice_floor, bob_floor, closest) + time_to_change;

    std::cout << "Bob's friend that lives closest to himself or Alice, or a friend living directly in between Bob and Alice, lives on floor " << +closest << ".\n";
    std::cout << "It will take Bob " << +quickest_time << " minutes to go change at his friends place and then get to Alice's place.\n\n";
    
}