#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n;
    scanf(" %d", &n);

    // Allocate memory for preferences and arrays
    int **company_preferences = (int **)malloc(n * sizeof(int *));
    int **student_preferences = (int **)malloc(n * sizeof(int *));
    int **student_rank = (int **)malloc(n * sizeof(int *));
    int *current_partner = (int *)malloc(n * sizeof(int));
    int *next_proposal = (int *)calloc(n, sizeof(int));
    bool *is_company_free = (bool *)malloc(n * sizeof(bool));

    for (int i = 0; i < n; i++) {
        company_preferences[i] = (int *)malloc(n * sizeof(int));
        student_preferences[i] = (int *)malloc(n * sizeof(int));
        student_rank[i] = (int *)malloc(n * sizeof(int));
        current_partner[i] = -1;   // Initially, no student has a partner
        is_company_free[i] = true; // All companies are free initially
    }

    // Input company preferences
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %d", &company_preferences[i][j]);
        }
    }

    // Input student preferences
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %d", &student_preferences[i][j]);
        }
    }

    // Prepare rank mappings for student preferences
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            student_rank[i][student_preferences[i][j]] = j;
        }
    }

    // Stable Matching Algorithm
    int free_count = n;

    while (free_count > 0) {
        int company = -1;

        // Find the first free company
        for (int i = 0; i < n; i++) {
            if (is_company_free[i]) {
                company = i;
                break;
            }
        }

        // Propose to the next student in the company's preference list
        int student = company_preferences[company][next_proposal[company]];
        next_proposal[company]++;

        if (current_partner[student] == -1) {
            // Student is free, match them with the company
            current_partner[student] = company;
            is_company_free[company] = false;
            free_count--;
        } else {
            // Student already has a partner, check preferences
            int current_company = current_partner[student];
            if (student_rank[student][company] < student_rank[student][current_company]) {
                // Student prefers the new company, replace the current match
                current_partner[student] = company;
                is_company_free[company] = false;
                is_company_free[current_company] = true;
            }
        }
    }

    // Print the results
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i, current_partner[i]);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(company_preferences[i]);
        free(student_preferences[i]);
        free(student_rank[i]);
    }
    free(company_preferences);
    free(student_preferences);
    free(student_rank);
    free(current_partner);
    free(next_proposal);
    free(is_company_free);

    return 0;
}
