#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    srand(time(0));

    int min_sec = 180;
    int max_sec = 360;

    while (true) {
        int random_sec = min_sec + (rand() % (max_sec - min_sec + 1));
        
        cout << "Next reminder in " << random_sec << " seconds.\n";

        // Sleep first
        this_thread::sleep_for(chrono::seconds(random_sec));
        
        // Then play sound
        PlaySound(TEXT("harikitte-ikou-kitasan-black.mp3"), NULL, SND_FILENAME | SND_ASYNC);
    }

    return 0;
}