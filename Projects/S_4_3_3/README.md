# Example S_4_3_3
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 4: Coordinate Transformation_

_Example: S_4_3_3 Parallel shift for a polygon_

## Learning  

This chapter explains the basic concepts of 3D graphics such as the `Coordinate system`, `Projection transformation`, `Modeling transformation`, `Viewing transformation`

- **Coordinate system**: Determines the positioning and orientation of the object and the viewpoint
- **Projection transformation**: Defines how an image will appear when projected onto a surface
- **Modeling transformation**: Defines movement, rotation, and enlargement / reduction within the coordinate system
- **Viewing transformation**: Defines the viewpoint and its movement. (For details, refer to _Chapter 6_, “The Camera.”)

Reminder

- The **Sega Saturn coordinate system is right-handed** having the **Z-Axis** towards the screen.
- The **Projection concepts** are very important to understand how graphics are projected into the **projection surface**. At the end, the projection surface is the *TV / Monitor screen* and the image is mapped onto the screen coordinate system.
- The **Viewing volume** is the space projected onto the **projection surface**. In *Sega Saturn* this is controlled by the **perspective angle** and the **display level** (also known as Front boundary surface which will be explained in 3D clipping concepts during the same chapter) which can be setup using `slPerspective` and `slZdspLevel` functions respectrively.

This example shows already the concepts of the **Modeling transformation** by placing the polygon in the middle of the screen and then translating it along the **X-Axis** between a value specified in a macro

The `main.c` game illustrates the shift / translate of a polygon along the **X-Axis**:

- The `slTranslate` positions in the coordinate system the polygon defined in `polygon.c` 
- The routine in `slPushMatrix` applies a change into the `pos[X]` between a value defined by the macro `POS_Z` and the `sin` of an increasing angle. This means it goes from the range **[`-POS_Z`,`POZ_Z`]**
