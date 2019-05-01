#include <iostream>
 
class Box {
   double width;
   
<<<<<<< HEAD
public:
   friend void printWidth( Box box );
   void setWidth( double wid );
=======
public:
   friend void printWidth (Box box);
   void setWidth (double wid);
>>>>>>> 3393c0345e93e68f396213ec222397fb03240536
};

// Member function definition
void Box::setWidth (double wid) {
   width = wid;
}

// Note: printWidth() is not a member function of any class.
void printWidth (Box box) {
   /* Because printWidth() is a friend of Box, it can
   directly access any member of this class */
   std::cout << "Width of box : " << box.width <<endl;
}
 
// Main function for the program
int main() {
   Box box;
 
   // set box width without member function
   box.setWidth(10.0);
   
   // Use friend function to print the wdith.
   printWidth( box );
 
   return 0;
}
