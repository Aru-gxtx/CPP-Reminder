#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <vector>
#include <filesystem>
#include <string>

// Link the library automatically
#pragma comment(lib, "winmm.lib")

using namespace std;
namespace fs = std::filesystem;

void PrintMCIError(MCIERROR error) {
    if (error != 0) {
        char buffer[128];
        mciGetErrorString(error, buffer, 128);
        cout << "  [Error]: " << buffer << endl;
    }
}

void PlayAudioFile(string filePath) {
    mciSendString("close myMusic", NULL, 0, NULL);

    string openCommand = "open \"" + filePath + "\" alias myMusic";
    
    MCIERROR err = mciSendString(openCommand.c_str(), NULL, 0, NULL);
    if (err != 0) {
        cout << "  [Failed to Open]: " << filePath << endl;
        PrintMCIError(err);
        return;
    }

    cout << "  [Playing]..." << endl;
    err = mciSendString("play myMusic wait", NULL, 0, NULL);
    
    if (err != 0) PrintMCIError(err);

    mciSendString("close myMusic", NULL, 0, NULL);
}

int main() {
    srand(time(0));

    string folderPath = "sound_assets";
    int min_sec = 22; 
    int max_sec = 360;

    vector<string> playlist;
    
    if (fs::exists(folderPath) && fs::is_directory(folderPath)) {
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            string ext = entry.path().extension().string();
            
            // Basic extension check
            if (ext == ".mp3" || ext == ".wav" || ext == ".MP3" || ext == ".WAV") {
                try {
                    playlist.push_back(fs::absolute(entry.path()).string());
                } catch (const exception& e) {
                    cout << "  [Warning] Skipping file due to path error: " << e.what() << endl;
                }
            }
        }
    } else {
        cout << "Error: Could not find folder '" << folderPath << "'!" << endl;
        return 1;
    }

    if (playlist.empty()) {
        cout << "Error: No .mp3 or .wav files found!" << endl;
        return 1;
    }

    cout << "Loaded " << playlist.size() << " audio files." << endl;
    cout << "Reminder started. Waiting for interval...\n";

    while (true) {
        int random_sec = min_sec + (rand() % (max_sec - min_sec + 1));

        // Timer Loop
        for (int i = random_sec; i > 0; --i) {
            cout << "\rNext reminder in: " << i << " seconds...   " << flush;
            this_thread::sleep_for(chrono::seconds(1));
        }

        // Pick random song
        int randomIndex = rand() % playlist.size();
        string selectedSong = playlist[randomIndex];

        // Get just the filename for display (cleaner console output)
        string filenameOnly = fs::path(selectedSong).filename().string();

        cout << "\rReminder! Selected: " << filenameOnly << "                  " << endl;
        
        PlayAudioFile(selectedSong);
    }

    return 0;
}