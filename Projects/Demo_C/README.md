# Example Demo_C

## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 7: Polygon Face Attributes_

_Example: Demo C - Moving Akira_

## Learning  

This example puts together a lot of the concepts we have learned until **S_7_6**.

Important parts of the example
- Initialization of the system as usual in `slInitSystem`
- Setup of the light settings and apply them via `slLight` (We played with it in **S_3_2**)
- Setup of the camera by loading the unit matrix `slUnitMatrix(CURRENT)` and setting up its position via `slLookAt` (remember the example **S_6_3**)
- Setting up the position of Akira, rotation etc... This is a complex example from `Matrix hierarchies`, but same as we practice in **S_4_2 - S_5_2** about coordinates transformation and hierarchical matrices. The basics are `slRotX`, `slRotY`, `slRotZ` for rotation. `slTranslate` for the translation in the coordinate system and `slPutPolygon` for the actual polygon placement. It is important how the following hierarchy is done (`slPushMatrix` inside of `slPushMatrix` to corresponds movements between connected parts of the body)
    1. Initializes Akira position defined by `aki_pos` and `walk_ang`
    2. Abdomen processing, this will be used as the reference point on where to place the rest of polygons via `root_pos` table positioning and `bone_length` to determine how big they are
        1. Chest processing (Hierarchical from the abdomen)
        2. Head processing (neck, face, head)
        3. Right shoulder processing
            1. Right arm processing
            2. Right hand (hand, fingers, thumb) processeing
        4. Left shoulder processing
            1. Left arm processing
            2. Left hand (hand, fingers, thumb) processeing
        5. Hips / waist processing
        6. Right thigh processing
            1. Right lower leg processing
            2. Right foot - angle processing
        7. Left thigh processing
            1. Left lower leg processing
            2. Left foot - angle processing
        
There are some new routines like `slGetMatrix` which returns the current matrix if we want to make modifications to.
By the other hand, this example is not using any textures. Majority of the polygons in Akira are using the following polygon attributes
- `plane`: `Single_Plane` as Akira is completely 3D, we will never see the other face side of a polygon
- `sort`: `SORT_MIN` makes the closest point of a polygon the most relevant for the camera
- `texture`: `No_Texture` as we are not using textures here
- `color`: `C_RGB` as we are colouring the polygon manually
- `gouraud`: `No_Gouraud` which means that flat shadding is applied making the polygons more **square** and less quality
- `mode` = `MESHoff` normal display (no mesh)
- `dir` = `sprPolygon` Display polygon 
- `option` = `UseLight` as the light has been setup

**Note**: No worries for now about complex definitions of Akira polygons in their respective `.c` source codes. Just make sure you understand all the attributes and polygon attributes we have been learning.

