#include <drogon/drogon.h>

using namespace std;
using namespace drogon;

int main() {
    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0",8080);
    drogon::app().setThreadNum(0);
    //Load config file
        //drogon::app().loadConfigFile("../config.json");
        //Run HTTP framework,the method will block in the internal event loop

    cout << "C++ - Drogon";
    drogon::app().run();
    return 0;
}
