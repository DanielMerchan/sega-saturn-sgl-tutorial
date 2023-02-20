# Example S_4_2
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 2: Coordinate Transformation_

_Example: S_4_2 Perspective Control

## Learning  

This chapter explains the basic concepts of 3D graphics such as the `Coordinate system`, `Projection transformation`, `Modeling transformation`, `Viewing transformation`

- The **Sega Saturn coordinate system is right-handed** having the **Z-Axis** towards the screen.
- The **Projection concepts** are very important to understand how graphics are projected into the **projection surface**. At the end, the projection surface is the *TV / Monitor screen* and the image is mapped onto the screen coordinate system.
- The **Viewing volume** is the space projected onto the **projection surface**. In *Sega Saturn* this is controlled by the **perspective angle** and the **display level** (also known as Front boundary surface which will be explained in 3D clipping concepts during the same chapter) which can be setup using `slPerspective` and `slZdspLevel` functions respectrively.

This example focuses on how the 

The `main.c` game follows the following logic:

- The **perspective angle** can be set by using `slPerspective` function which accepts an `ANGLE` as input parameter. 
- The program defines a **tmp** variable which starts at 90 degrees and then gets modified to increase until 160 degrees and then decrease until 20 degrees
