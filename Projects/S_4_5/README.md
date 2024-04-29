# Example S_4_5
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 4: Coordinate Transformation_

_Example: S_4_5 Clipping and Windows_

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

This example explains the concept of **Clipping** and **Windows**.

As a summary on what you can find in the documentation:

- Sega Saturn works with a maximum of 2 windows on one screen. The default window is setup when using `slInitSystem` and another window can be added by using the function `slWindow`
- Objects projected in a window, which is defined by 
    - `left`, `top`, `right`, `bottom` indicating the coordinates of the window
    - `Zlimit`indicates the projection limit. Default `7FFF`
    -  `CENTER_X` and `CENTER_Y` determine the **vanishing point**. A vanishing point is a point on the image plane of a perspective rendering where the two-dimensional perspective projections of mutually parallel lines in three-dimensional space appear to converge (source, Wikipedia).

**Clipping** is called when a portion of an object or polygon is projected into a Window and part of it out of its boundaries.

The `main.c` game illustrates two objects / polygons placed in different windows:

- In the `polygon.c` there is a **PLANE** and **CUBE** definitions as usual, make sure you notice `Window_Out` and `Window_In`
- `Window_Out` means that the **PLANE** will be rendered out of the current window
- `Window_In` means that the **CUBE** will be only rendered within the current window
- `slWindow` positions the window. In each iteration, we move the window to see when it crosses the cube, then it is displayed.
- The **CUBE** rotates in its **Y-Axis** and only is displayed when the window allows to project it (passes through its coordinates). Not the entire **CUBE** is shown while the window is moving. This is what we call **CLIPPING**.
- The **PLANE** is always rendered on the outer window and **CLIPPING** applies when the new window is on its coordinates.
