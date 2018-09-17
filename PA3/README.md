# PA2 - Interaction: Menus, Keyboard, and Mouse

# Dependencies, Building, and Running

## Instructions
```bash
Q/Left Click: self rotation reverses direction
W/Right Click: pauses self rotation
E/XB1: orbital rotation reverses direction
R/XB2: pauses orbital rotation
```

### Ubuntu/Linux
```bash
sudo apt-get install libglew-dev libglm-dev libsdl2-dev
```

### Mac OSX
Installation of brew is suggested to easily install the libs. Ensure that the latest version of the Developer Tools is installed.
```bash
brew install glew glm sdl2
```

### Makefile Instructions 

```bash
mkdir build
cd build
cp ../makefile .
make
cd ..
./build/Tutorial
```

## Ubuntu.cse.unr.edu
OpenGL 3.3 will run on the [ubuntu.cse.unr.edu](https://ubuntu.cse.unr.edu/) website. To do so follow the build instructions, but when running the Tutorial executable use this line to execute.
```bash
/usr/NX/scripts/vgl/vglrun ./Tutorial
```
