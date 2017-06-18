Install GLUT before running:

Make a folder called c:\glut and download from the following link: http://ivl.calit2.net/wiki/images/0/0a/Glut-3.7.6-bin.zip

Open c:\glut and right click on glut-3.7.6-bin.zip and select Extract Here.

Open the new folder (glut-3.7.6-bin) and verify that you see the following five files: glut.def, glut.h, glut32.dll, glut32.lib, README-win32.txt

Move glut32.dll to c:\Windows\System32 (or SysWOW64 for 64bit) so that all programs can access it. If you don't have write privileges for this directory, you can put the .dll file into the directory your executable (.exe) resides in. This is typically your Debug or Release directory, just below your project directory.

Create a new directory under c:\glut\glut-3.7.6-bin and name it "GL". Move glut.h to this new directory (should be "c:\glut\glut-3.7.6-bin\GL").


NOTE: Play on 60Hz. Have not yet implemented upport for other framrates


How to Play:

Left Arrow: Move left

Right Arrow: Move Right

Spacebar: Shoot

Objective: Shoot stuff for points. If an enemy ship passes, lose one life (5 total).

Shooting red enemies rewards the player with one life. Maximum life count is 5
