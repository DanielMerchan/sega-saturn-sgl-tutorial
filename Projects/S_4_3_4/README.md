# Example S_4_3_3
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 4: Coordinate Transformation_

_Example: S_4_3_4 Enlargement and reduction of a polygon (scaling objects)_

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

This example shows already the concepts of the **Modeling transformation** by placing the polygon in the middle of the screen and then scaling it by enlarging it or reducing it.

The `main.c` game illustrates the enlargement and reduction of the polygon by sclaing it in the **X-Axis** and **Y-Axis**:

- The `slScale` allows to enlarge / reduce the polygon defined in `polygon.c` 
- The `slPushMatrix` routine goes from `-1.0 <= scale <= 1.0` value to demonstrate how the polygon changes
- `scale = 0.0` means that the polygon dissapear on that axis
- `scale < 0.0` means it mirrors the image
- `0.0 < scale < 1.0` means it is reduced
- `scale = 1.0` means it is unchanged
- `1.0 < scale` means it is enlarged
