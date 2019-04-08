# Code_Injection_C-
This program injects a harmless payload into .cc and .cpp files.
# IMPORANT 
#### Only run this in a directory that does not have important C++ files ####
* Compiling 
  * run `g++ -o main main.cc`
  * `./main` to run
    * This will inject the harmless payload into all .cc or .cpp files to be ran
## TODO ##
* ~~Find all the .cc and .cpp files in a directory~~
* ~~Read all the contents of those files and write them back as if nothing changes~~
* ~~Inject code into the files~~
* ~~Do not change the execution/output of the infected files~~
* Force a recompile of the .cc and .cpp files that have been injected
* Create the payload in such a way that it will reproudce itsself when ran
* Have the payload be remotely updated by the person that injected the payload
* Make the payload spread to other directorys 
* Encrpyt the payload and main.cc to make it undetectable by modern software (Probability MD5)

## USE ##
Please only use this for testing and learning purposes. Do not inject harmful code into yours or other people's computer.

## Contact ##
Steven Dellamore - dellamoresteven@gmail.com
