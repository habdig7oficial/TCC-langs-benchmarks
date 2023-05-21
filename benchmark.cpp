#include <iostream>
#include <string>
#include <array>

#include <thread>
#include <unistd.h>

//g++ -pthread benchmark.cpp -o benchmark && ./benchmark

using namespace std;

class benchmarks{
    public:
        string protocol;
        string host;
        int port;

        int conections;
        int parallelism;
        string result;

        array<string, 10> images;

        void Build(){
            system("./build-all.sh");
        };

        void Kill(){
            system(("kill $(lsof -t -i:" + to_string(port) + ")").c_str());
            system("docker stop $(docker ps -a -q)");
            cout << endl << "Killed port:" << port << endl << endl;
        }

        void Invoke(string str){
            Kill();
            string teste = ("docker run -it --name " + str + "-running --rm --network host " + str).c_str();
            cout << teste << endl;
            system(teste.c_str());
            return;
        };

        void Run(){
            Build();

            for (string i : images)
            {
                if (i != ""){
                    thread t1(&benchmarks::Invoke, this, i);
                    //thread t2(&benchmarks::Bench, this, i);

                    system("until pids=$(lsof -t -i:8080) do sleep 1 done");
                    string mnt = "ab -s 999999 -n " + to_string(conections) + " -c " + to_string(parallelism) + " " + protocol + "://" + host + ":" + to_string(port) + "/ > ./benchmaks/" + i + ".txt";
                    sleep(40);
                    cout << mnt << endl << endl << endl;
                    system(mnt.c_str());
                    Kill();
                    t1.detach();
                    cout << "benchmark done";

                    //t2.join();
                    cout << "th done";
                }
            }
            
        };
};

int main(){

    benchmarks Script;

    Script.port = 8080;
    //Script.conections = 100000;
    //Script.paralelism = 1020;
    Script.conections = 100000;
    Script.parallelism = 1020;
    Script.host = "localhost";
    Script.protocol = "http";


    Script.images = {"node-express", "deno-oak", "go-gin", "cpp-drogon",  "elixir-plug", "v-vweb" };

    Script.Run();

    return 0;
}