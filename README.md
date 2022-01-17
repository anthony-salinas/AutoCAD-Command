# AutoCAD-Command
Written in C++ using the ObjectARX library. Both commands prompt the user for an ID and will display the opening dimensions for the provided ID within the AutoCAD command line. The commands can be used by a CAD designer to get door/window dimensions without having to look them up in architectural plans.
# How to use
** Commands must be written for specific versions of AutoCAD. This command works with AutoCAD 2018.
1. Download the .arx file
2. Open a drawing with AutoCAD
3. Run the APPLOAD command
4. Find the the .arx file and click load
5. Run DOORSCHEDULE command to get dimensions for doors, WINDOWSCHEDULE for windows
