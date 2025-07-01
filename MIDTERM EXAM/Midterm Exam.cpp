#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    const int LARGE_POUND = 5;
    const int MEDIUM_POUND = 3;
    const int SMALL_POUND = 1;

    const double LARGE_PRICE = 27.99;
    const double MEDIUM_PRICE = 21.99;
    const double SMALL_PRICE = 14.99;

    int largeBars = 620;
    int mediumBars = 500;
    int smallBars = 700;

    int orderNumber = 1;
    char continueOrder = 'Y';

    cout << fixed << setprecision(2);

    while (continueOrder == 'Y' || continueOrder == 'y') {
        int requestedPounds;

        cout << "\nOrder #" << orderNumber << endl;
        cout << "Enter pounds of chocolate to order: ";
        cin >> requestedPounds;

        if (requestedPounds <= 0) {
            cout << "Invalid order quantity. Must be greater than 0.\n";
            continue;  
        }

        
        int tempLarge = largeBars;
        int tempMedium = mediumBars;
        int tempSmall = smallBars;

        int poundsLeft = requestedPounds;
        int usedLarge = 0, usedMedium = 0, usedSmall = 0;

        
        int maxLargeUse = poundsLeft / LARGE_POUND;
        if (maxLargeUse > tempLarge) maxLargeUse = tempLarge;
        usedLarge = maxLargeUse;
        poundsLeft -= usedLarge * LARGE_POUND;

        
        int maxMediumUse = poundsLeft / MEDIUM_POUND;
        if (maxMediumUse > tempMedium) maxMediumUse = tempMedium;
        usedMedium = maxMediumUse;
        poundsLeft -= usedMedium * MEDIUM_POUND;

        
        int maxSmallUse = poundsLeft / SMALL_POUND;
        if (maxSmallUse > tempSmall) maxSmallUse = tempSmall;
        usedSmall = maxSmallUse;
        poundsLeft -= usedSmall * SMALL_POUND;

        
        if (poundsLeft > 0) {
            
            cout << "Error: Unable to fill the order with current inventory.\n";
            cout << "Order cancelled.\n";
        }
        else {
           
            largeBars -= usedLarge;
            mediumBars -= usedMedium;
            smallBars -= usedSmall;

            
            double cost = usedLarge * LARGE_PRICE + usedMedium * MEDIUM_PRICE + usedSmall * SMALL_PRICE;

            
            cout << "Order filled successfully!\n";
            cout << "Used bars:\n";
            cout << "  Large bars: " << usedLarge << "\n";
            cout << "  Medium bars: " << usedMedium << "\n";
            cout << "  Small bars: " << usedSmall << "\n";
            cout << "Total cost: $" << cost << endl;

           
            cout << "Remaining inventory:\n";
            cout << "  Large bars: " << largeBars << "\n";
            cout << "  Medium bars: " << mediumBars << "\n";
            cout << "  Small bars: " << smallBars << "\n";

            orderNumber++;
        }

        cout << "Would you like to enter another order? (Y/N): ";
        cin >> continueOrder;
    }

    cout << "Thank you for using the chocolate warehouse ordering system!\n";

    return 0;
}
