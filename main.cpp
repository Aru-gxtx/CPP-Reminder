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

    int min_sec = 22.5;
    int max_sec = 360;

    cout << "Reminder started. Waiting for the first interval...\n";

    while (true) {
        // Calculate random time inside the loop so it changes every time
        int random_sec = min_sec + (rand() % (max_sec - min_sec + 1));

        for (int i = random_sec; i > 0; --i) {
            cout << "\rNext reminder in: " << i << " seconds...   " << flush;
            
            this_thread::sleep_for(chrono::seconds(1));
        }

        // Clear the countdown line and notify
        cout << "\rReminder! Playing sound...                  " << endl;

        // Play sound (SND_ASYNC lets the code continue immediately)
        PlaySound(TEXT("harikitte-ikou-kitasan-black.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }

    return 0;
}