# Example Blank SGL
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

## Learning  

This is the code baseline **Hello World** project which is used as baseline to create the other example projects.

The project has been taken from the `sgl302j.jar` from the Sega Saturn Graphic Library examples and extended with the **Compiler**, **Emulator**, and **bat** files used by other Sega Saturn community developers (see Credits on the main `README.md`)

## How to create a new project based on this one?

- Create a new **folder** in the **Projects** for your new project, give it a name such as `MyAmazingSaturnGame`
- Create a folder **cd** and **ZTE** on them
- Copy the **workarea.c** in the **ZTE** folder
- Copy **aSatlink.bat**, **clean.bat**, **compile.bat**, **Medafen.bat**, **makefile**, **common.h**,  at the root of the main project folder.
- Copy the **main.c** and **polygon.c** from the **SGL** project
- Perform a **clean.bat**, **compile.bat**, **Medafen.bat** to make sure the setup is correct.
- Enjoy coding and making some excercises like the **SGL examples**. Modify the code for understanding the concepts

## How the compilation and runtime works?

- They make use of the **Compiler** folder to compile the source code
- They make use of the **Emulators** to run the code in a particular emulator. In this repository is being used **Medafen**, but also you can use **SSF**, **yabause** or your preferred one for debugging

