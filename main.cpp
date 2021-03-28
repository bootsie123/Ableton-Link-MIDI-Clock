#include <iostream>
#include <ableton/Link.hpp>

void tempoCallback(double bpm) {
    std::cout << "BPM: " << bpm << std::endl;
}

void startStopCallback(bool isPlaying) {
    std::cout << "IsPlaying: " << isPlaying << std::endl;
}

void numPeersCallback(std::size_t numPeers) {
    std::cout << "Peers: " << numPeers << std::endl;
}

static bool running = true;

int main() {
    ableton::Link link(120.0);

    link.setTempoCallback(tempoCallback);
    link.setStartStopCallback(startStopCallback);
    link.setNumPeersCallback(numPeersCallback);
    link.enableStartStopSync(true);
    link.enable(true);

    std::cout << link.isEnabled() << std::endl;

    while (running) {
        ableton::Link::SessionState session = link.captureAppSessionState();

        std::cout << session.tempo() << std::endl;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}