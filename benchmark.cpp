#include<iostream>
#include <string>
#include <array>
#include <fstream>

using namespace std;

class benchmarks{
    public:
        string protocol;
        string host;
        int port;

        int conections;
        int paralelism;
        string result;

        array<string, 10> images;

        void Build(){
            //system("./build-all.sh");
        };

        void Kill(){
            system(("kill $(lsof -t -i:" + to_string(port) + ")").c_str());
            cout << endl << "Killed port:" << port << endl << endl;
        }

        void Run(){
            Build();

            for (string i : images)
            {
                if (i != ""){
                    Kill();
                    string teste = ("docker run -it --rm -p " + to_string(port) + ":" + to_string(port) + " " + i + " &").c_str();

                    cout << teste << endl;

                    system(teste.c_str());
                    cout << "continuou" << endl;

                    result = system("ab -n 10 -c 2  http://localhost:8080/");

                    ofstream MyFile("filename.txt");

                    // Write to the file
                    MyFile << "Files can be tricky, but it is fun enough!";

                    // Close the file
                    MyFile.close();

                    Kill();
                    

                }
            }
            
        };
};

int main(){

    benchmarks Script;

    Script.port = 8080;
    Script.conections = 100000;
    Script.paralelism = 1020;
    Script.host = "localhost";


    Script.images = {"node-express", "go-gin"};

    Script.Run();

    return 0;
}