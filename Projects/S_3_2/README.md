# Example S_3_2
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 2: Graphics_

_Chapter 3: Light Sources_  

_Example: S_3_2 render a cube (3D) and add a basic light

## Learning  

This example enriches `S_2_2` by updating the `polygon.c` to define a cube.  

In the code, you will find comments about how to define its vertices and the normal (where the faces of the cube are looking to)  

To calculate the normal you can make the trick of *following, the vertice direction in Sega Saturn coordinate system with your left hand*. Where your thumb points then it is the *normal* direction.  

Another important part of `polygon.c` is the definition of the faces of the cube properties. Make sure you analyse attributes like `UseLight`  

The `main.c` game follows the following logic:

- First there is a definition of the *positions and angles* variables to define where the **cube** and the **light** will be placed. Basically, **ang** and **pos** will be used to determine the orientation and the position of the **cube**.
- The **light** is set for -X direction
- During the principal game loop. The light is positioned and placed in the coordinate system. As you can see `slLight` is used to establish the light source and a variable **tmp** for rotating the *light* over the Y-axis for each iteration
- A second structure of `slPushMatrix` and `slPopMatrix` is placed in order to setup the coordinates and location of the **cube** which will be placed by using `slPutPolygon`
