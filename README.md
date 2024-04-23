# Sega Saturn SGL Graphics Tutorial examples

Repository including the examples of the _SGL Developer's Manual Tutorial.pdf_ with a `README.md` personal explanation of every example.

This is a learning repository, but the idea is to be able someday to make my first homebrew game for `Sega Saturn`

## Setup Development Environment

Clone the repository and open it, for example, with *Visual Studio Code*.

If you are familiar with the C / C++ extension then make sure you add the necessary compiler paths to it so you can get rid of the *include errors* you may in the *.c* files.

> Check https://www.infochunk.com/saturn/vscode.html if needed

The current setup only works in **Windows**, please check the **[Work in Progress](work-in-progress)** section.

## Project Structure

Every project follows the same structure which has been copied from the repository mentioned in the *Credits* section. You can find the following files

-  `clean.bat`: Cleans the C compile objects and the generated **.cue** and executable files for `Sega Saturn`

-  `compile.bat`: Compiles the project and generates the executables such as the **.cue** which can be played in a `Sega Saturn` emulator or burn a CD to be run in the `Sega Saturn` hardware instead.

-  `Mednafen.bat`: Ejecutes the generated **.cue** in the Mednafen emulator.

Also two folders are found:
 
-  `ZTE`: Configures the workarea and setup many variables such as the **maximum vertices** or **maximun polygons**

-  `cd`: Folder which needs to exist by the compiler setup in order to produce the **cue** file

The `main.c` is the game infinite loop.

## Work in Progress

This setup is based in *Jo Engine*. You can find a more modern compilator structure for Windows / Linux at: https://github.com/johannes-fetz/joengine

I will re-factor the project to be easy to compile with *Yaul Docker* which is agnostic to Windows / Linux / MacOS.

# Credits

Compiler setup taken from XL2's Sonic Z-treme code: https://github.com/Maxime-XL2/SONIC-Z-TREME which uses *Jo Engine* compilation structure

Sega Saturn manual's can be found at: https://antime.kapsi.fi/sega/docs.html and also the `sgl302j.rar` with the examples of the tutorial of this repo.

Video tutorials by Emerald Nova about Sega Saturn SGL can be found here: https://www.youtube.com/watch?v=ZaNT7oxlBwI&list=PLlJhkcyS6fn3fYygxnScccr5e4w1C9Xrp