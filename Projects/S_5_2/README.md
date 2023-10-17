# Example S_5_2
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 5: Matrices_

_Example: S_5_2 Hierarchical Matrix Definition_

## Learning  

This chapter explains the matrices which is a fundamental context for building 3D graphics anywhere. It is important that you refresh your Algebra and trigonometry concepts before diving into the matrices world.

The matrices has been used already in the previous project examples in order to apply **transformations** like moving, rotating, enlarging or reducing the planes and cubes we defined in them. If you forgot, read the first projects **README.md** for further explanation.

In this example we will look into the **Stack** of matrices and how to use it for applying transformations all together to a group of objects. This is called **Hierarchical Matrix Definition**. It is important to learn the concept for inherit and applying transformations on cascade to multiple objects.

The `main.c` game follows the following logic:

- `slUnitMatrix` with **CURRENT** as parameter changes the current matrix into a unit matrix. Initialise
- `slPushMatrix` can be in hierarchy nested to provide a parent-child object relationship
- `slPopMatrix` applies the transformations which are inherit in the relationship
