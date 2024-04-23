# Example S_6_3
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 6: The Camera_

_Example: S_6_3 Camera Movemement_

## Learning  

This chapter explains the basics about the 3D graphics camera.

The camera is configured by the routine `slLookAt`. According to the official documentation *This function multiplies the current matrix and the matrix (line of sight) for viewing the target from the specified camera position at the specified angle.

- FIXED *camera -> Determines the camera position or origin of what is called **line of sight**
- FIXED *target -> Determines the direction of the **line of sight**
- ANGLE angz -> Determines the Camera angle

In this example, the camera will moves its position between -100 and 100 on the X and Z AXIS respectively.

The `main.c` game make sure you have a look into:

- `slLookAt` which initializes the camera
- `CAMERA` which is a struct to handle the camera settings easily
- `cubepos` Contains 4 coordinates to position the same CUBE
