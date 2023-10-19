# Example Demo_B
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 5: Matrices_

_Example: demo_B_

## Learning  

This chapter puts into place a more complex example than the one in `S_5_2`

In this case we have three polygon defined in `polygon.c`:
- `PD_PLANE1` represents a rectangle in colour "bluish" (I can't see more than 8 colours)
- `PD_PLANE2` represents a rectangle same size as `PD_PLANE2`, but colour "yellowish"
- `PD_PLANE3` represents a rectangle same size as `PD_PLANE3`, but colour "pinkish"

The `main.c` game follows the following logic:

- `slUnitMatrix` with **CURRENT** as parameter changes the current matrix into a unit matrix. Initialise
- **Object 1** represented by `PD_PLANE1` is placed bottom with some depth indicated in by `Z-Axis=170`
- **Object 2** represented by `PD_PLANE2` is placed in the middle and on top of **Object 1** without any depth
- **Object 3** represented by `PD_PLANE3` is placed on the top of **Object 3** like a chopper as it is an horizontal polygon
- The `while (-1)` main game loop modifies the `Z angle` to be applied to **Object 1** and **Object 2**
- First `slPushMatrix()` puts a matrix in the bottom of the stack to place **Object 1** with the calculated position and angle
- Second `slPushMatrix()` puts a matrix in the bottom of the stack to place **Object 2** with the calculate position and angle
- Third `slPushMatrix()` puts a matrix in the bottom of the stack for top polygon **Object 3** which will rotate in its `Y-Axis` like a chopper.
- When performing `slPopMatrix()` first is applied the rotation into the **Object 1** changing its angle
- When performing again `slPopMatrix()` the second **Object 2** gets the position and angle transformation affected by the matrix pop from **Object 1**. That's why it moves more
- When performign again `slPopMatrix()` gets the angle change of **Object 2** and in addition the rotation in `Y-Axis` only applied to **Object 3**
