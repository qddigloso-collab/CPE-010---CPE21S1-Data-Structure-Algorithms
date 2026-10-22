#include <iostream>
#include "PrinterSimulation.h"

int main() {
    Printer officePrinter;

    std::cout << "==========================================\n";
    std::cout << "    OFFICE SHARED PRINTER SIMULATION      \n";
    std::cout << "==========================================\n\n";

    officePrinter.addJob(101, "Alice", 15);
    officePrinter.addJob(102, "Bob", 5);
    officePrinter.addJob(103, "Charlie", 42);

    officePrinter.displayQueue();

    officePrinter.processNextJob();
    officePrinter.processNextJob();

    officePrinter.displayQueue();

    officePrinter.addJob(104, "Diana", 8);
    officePrinter.addJob(105, "Evan", 12);

    officePrinter.displayQueue();

    officePrinter.processNextJob();
    officePrinter.processNextJob();
    officePrinter.processNextJob();

    officePrinter.displayQueue();

    return 0;
}