#include<iostream>
#include <string>

using namespace std;

class benchmarks{
    public:
        string protocol;
        string host;
        int port;

        int conections;
        int paralelism;

        void Build(){
            system("echo hello");
        };

        void Run(){
            cout << host.c_str() ; 
            system(("kill $(lsof -t -i:" + to_string(port) + ")").c_str());
            
        };
};

int main(){

    benchmarks Script;

    Script.port = 8080;
    Script.conections = 100000;
    Script.paralelism = 1020;
    Script.host = "localhost";

    Script.Run();

    return 0;
}