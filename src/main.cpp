#include <graphics/graphics.hpp>

int main() {
   Graphics graphics;

   for(int i = 0; i < 100; i++)
   {
         graphics.pixel(rand()%640, rand()%480);
   }

   graphics.run();

   return 0;
}