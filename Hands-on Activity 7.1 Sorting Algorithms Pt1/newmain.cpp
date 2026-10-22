#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

const int maxSize = 100;
void displayArr(int arr[]);

int main() {
    int votes[maxSize];
    int voteCounts[5] = {0};

    srand(time(0));

    for (int i = 0; i < maxSize; i++) {
        votes[i] = (rand() % 5) + 1;
    }

    insertionSort(votes, maxSize);

    std::cout << "Sorted Votes:\n";
    displayArr(votes);

    for (int i = 0; i < maxSize; i++) {
        voteCounts[votes[i] - 1]++;
    }

    int winner = 1;
    int maxVotes = voteCounts[0];

    std::cout << "\nResults:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "Candidate " << (i + 1) << ": " << voteCounts[i] << " votes\n";
        if (voteCounts[i] > maxVotes) {
            maxVotes = voteCounts[i];
            winner = i + 1;
        }
    }
    std::cout << "\nWinner: Candidate " << winner;

    return 0;
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}