Required: 
PRU C compiler
Pypruss python bindings for the PRU. (Instructions for installation can be found at https://bitbucket.org/intelligentagent/pypruss)


Instructions for compiling:

After creating your .ino file, copy it into the Energia directory. (Note: the Energia file must be in the PRdUino directory.) The examples can be copied to the PRdUino directory by running the command from the example folder.

cp [example] ..

Make the compile script executable by executing the following command.

chmod +x compile.sh

Compile into a PRU executable by executing the compile script:

./compile.sh

This script will compile and execute a C++ program. The C++ program will prompt you for the name of your .ino file. 
After typing in the name of your .ino file, a text.bin executable will be generated.

The text.bin executable can be used with the Pypruss python bindings for the PRU. An example python script is included with the package to show how to execute the text.bin. 
However, you must first install Pypruss, make a new directory within the examples folder and copy the test.py script into that folder. The commands for this process can be seen below:

cd pypruss/examples

mkdir test

cp test.py pypruss/examples/test

python test.py
