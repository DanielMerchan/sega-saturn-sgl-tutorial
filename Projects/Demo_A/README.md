# Example S_4_5
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Excercise: Cube action_

_Example: Demo_A Chapter 2, 3 and 4 concepts all together_

## Learning  

This project encapsulates all the concepts learn from `S_2_2` until `S_4_5` such as placing polygons, applying transformations, light sources etc

This project contains a smaller cube which bounces around inside of a larger cube with the front side removed

Analyisng the code you will find:

`polygon.c` contains the definition of the two cubes:

 - `PD_PLANE1`: Defines a smaller cube of 15 by 15
 - `PD_PLANE2`: Defines a biger cube of 100 by 100

 From the learnt lessons we can observe that there is not `window` definition, and it makes use of lighting `UseLight`

 `main.c` contains the main program loop following the next logic:

 - The **define** constants define contains the incrementals of position and angles which will be applied to the smaller cube. In addition, it contains the `REFLECT_EXTENT` which will be used for collision detection.
 - The program first initialises the system by calling `slInitSystem`
 - Set the initial position and angle of both cubes (however, later is overrided the Z-Axis initial position of both)
 - Set the **vector** direction of the `light`
 - `while(-1)` is the main gaming loop which will:
    - Draw the smaller cube defined by `PD_PLANE1` as following:
        - `slPushMatrix` stack a new matrix for applying coordinates transformations to the small cube
        - `slTranslate` for shifting the cube to the position determined by `pos1` and apply a fixed **270.0** addition to the Z-Axis
        - The code adds a `delta` to the `pos1` for the next iterations to mimic the movement of the small cube
        - There is a collision detector based on the current `pos1` compared to the `REFLECT_EXTENT` (which is 85.0 because 100.0 (large cube) - 15.0 (smaller cube)). If a collision happens, then it corrects the position on the affected axis
        - Set the angle of the cube defined by `ang1`
        - Update the angle `ang1` for future frame rendering to illustrate the rotation of the cube
        - `slPutPolygon` places the defined polygon to which the transformations defined earlier will be applied
        - `slPopMatrix` applies the transformations defined to polygon just placed
    - Draw the bigger cube defined by `PD_PLANE2` as following:
        - It is fixed `slTranslate` to the original `pos2` defined with the Z-Axis increased by **170.0**
        - The cube is in the original rotation defined by `ang2`
    - `slSynch` is used for rendering the frames
