#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to generate a random page reference string
vector<int> generatePageReferenceString(int length, int pageRange) {
    vector<int> referenceString;
    for (int i = 0; i < length; ++i) {
        referenceString.push_back(rand() % pageRange);
    }
    return referenceString;
}

// Function to simulate FIFO page replacement algorithm
int simulateFIFO(const vector<int>& referenceString, int numFrames) {
    list<int> frame;
    unordered_set<int> frameSet;
    int pageFaults = 0;

    for (int page : referenceString) {
        if (frameSet.find(page) == frameSet.end()) {
            if (frame.size() == numFrames) {
                int oldest = frame.front();
                frame.pop_front();
                frameSet.erase(oldest);
            }

            frame.push_back(page);
            frameSet.insert(page);
            ++pageFaults;
        }
    }

    return pageFaults;
}

// Function to simulate LRU page replacement algorithm
int simulateLRU(const vector<int>& referenceString, int numFrames) {
    list<int> frame;
    unordered_map<int, list<int>::iterator> frameMap;
    int pageFaults = 0;

    for (int page : referenceString) {
        if (frameMap.find(page) == frameMap.end()) {
            if (frame.size() == numFrames) {
                int leastRecent = frame.front();
                frame.pop_front();
                frameMap.erase(leastRecent);
            }

            frame.push_back(page);
            frameMap[page] = --frame.end();
            ++pageFaults;
        } else {
            // Move the accessed page to the back to mark it as most recently used
            frame.splice(frame.end(), frame, frameMap[page], next(frameMap[page]));
            frameMap[page] = --frame.end();
        }
    }

    return pageFaults;
}

int main() {
    srand(time(nullptr));

    // Generate a random page reference string
    vector<int> referenceString = generatePageReferenceString(12, 10);

    cout << "Page reference string is:\n";
    for (int page : referenceString) {
        cout << page << " ";
    }
    cout << endl;

    // Test the algorithms for varying numbers of page frames (1 to 7)
    for (int numFrames = 1; numFrames <= 7; ++numFrames) {
        cout << "Page frames: " << numFrames << endl;

        // FIFO
        int fifoPageFaults = simulateFIFO(referenceString, numFrames);
        cout << "FIFO page fault = " << fifoPageFaults << endl;

        // LRU
        int lruPageFaults = simulateLRU(referenceString, numFrames);
        cout << "LRU page fault = " << lruPageFaults << endl;

        cout << endl;
    }

    return 0;
}
