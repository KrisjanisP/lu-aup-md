#include <iostream>
using namespace std;

int main() {
   int x = 10;
   
   if (x > 5) {
      for (int i = 0; i < x; i++) {
         while (i < 5) {
            cout << "i is less than 5" << endl;
            i++;
         }
         for (int j = 0; j < i; j++) {
            if (j % 2 == 0) {
               cout << "j is even" << endl;
            } else {
               cout << "j is odd" << endl;
            }
         }
         cout << "i is greater than or equal to 5" << endl;
      }
   } else {
      cout << "x is less than or equal to 5" << endl;
   }
   
   while (x > 0) {
      x--;
      if (x == 5) {
         continue;
      }
      cout << "x is now " << x << endl;
      if (x == 3) {
         break;
      }
   }
   
   return 0;
}