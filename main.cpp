#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
int main (int argc, char *argv[])
{
    int c;
    bool var_a = false;
    bool var_f = false;
    bool var_h = false;
    bool var_n = false;
    bool var_v = false;
    char * file_name = "Lab3";
    double version = 1.0;
    while (1)
    {
        static struct option long_options[] =
                {{"version",no_argument,0, 'v'},
                 {"help",no_argument,0, 'h'},
                 {"author",no_argument,0, 'a'},
                 {"file",required_argument,0, 'f'},
                 {"name",no_argument,0, 'n'},
                 {0, 0, 0, 0}
                };
        int option_index = 0;
        c = getopt_long (argc, argv, "ahnvf:",long_options, &option_index);
        if (c == -1)
            break;
        switch (c)
        { case '?':
                break;
            case 'v':
                if (!var_v){
                    printf("Version: %.2f\n", version);
                    var_v = true;
                }
                break;
            case 'h':
                if (!var_h){
                    puts ("Avaiable options:" \
                          "\n-a --author" \
                          "\n-f<filename> --file=<filename>" \
                          "\n-n --n" \
                          "\n-h --help" \
                          "\n-v --version");
                    var_h = true;
                }
                break;
            case 'a':
                if (!var_a){
                    puts ("Author: Andrey Soroka");
                    var_a = true;
                }
                break;
            case 'f': {
                if (!var_f) {
                    file_name = optarg;
                    printf("File name changed to '%s' \n", optarg);
                    var_f = true;
                }
                break;
            }
            case 'n':
                if (!var_n){
                    printf("File name: %s\n",file_name);
                    var_n = true;
                }
                break;
            default:
                break;;
        }
    }
    return 0;
}
