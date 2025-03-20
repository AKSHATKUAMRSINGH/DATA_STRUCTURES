#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    float value;  // Expected return
    float cost;   // Investment required
    float roi;    // Return-to-cost ratio
} Stock;

// Comparator function for sorting stocks by ROI in descending order
int compare(const void *a, const void *b) {
    float r1 = ((Stock *)b)->roi;
    float r2 = ((Stock *)a)->roi;
    return (r1 > r2) - (r1 < r2);  // Descending order
}

// Greedy Fractional Knapsack function
void fractionalKnapsack(Stock stocks[], int n, float budget) {
    qsort(stocks, n, sizeof(Stock), compare);  // Sort by ROI

    float totalReturn = 0;
    printf("Selected Portfolio:\n");

    for (int i = 0; i < n; i++) {
        if (budget >= stocks[i].cost) {
            // Take full stock
            printf("%s: 100%%\n", stocks[i].name);
            budget -= stocks[i].cost;
            totalReturn += stocks[i].value;
        } else {
            // Take a fraction of the stock
            float fraction = budget / stocks[i].cost;
            printf("%s: %.2f%%\n", stocks[i].name, fraction * 100);
            totalReturn += stocks[i].value * fraction;
            break;  // Budget exhausted
        }
    }

    printf("Maximum Expected Return: %.2f\n", totalReturn);
}

// Main function
int main() {
    Stock stocks[] = {
        {"Stock A", 100, 20, 0}, 
        {"Stock B", 200, 30, 0}, 
        {"Stock C", 150, 50, 0}, 
        {"Stock D", 50, 10, 0}
    };

    int n = sizeof(stocks) / sizeof(stocks[0]);
    float budget = 50;

    // Calculate ROI (return/cost) for each stock
    for (int i = 0; i < n; i++) {
        stocks[i].roi = stocks[i].value / stocks[i].cost;
    }

    fractionalKnapsack(stocks, n, budget);
    return 0;
}