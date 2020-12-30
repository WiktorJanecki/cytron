# CYTRON
C++ game made with SFML. It uses entity component system for easy adding new feature. There is infinite flexibility for adding new systems/components.

## Build
#### Requirements:
 - Compiler (Mingw/GNU compiler/anything else)
 - SFML (It is necessary to link it with compiler)
 
 #### Commands:
 First compile to object files:  
  - `g++ -c src/*.cpp src/*/*.cpp -std=c++14 -m64 -g -Wall -I include`    <br/>
  
Then link them all to one executable file (like .exe on windows):      
   - `g++ *.o -o <OUTPUT FILE PATH> -lsfml-graphics -lsfml-window -lsfml-system`  
   
 Finally run the program:   
  - Windows: click the exe icon
  - Linux: `./<OUTPUT FILE PATH`  
