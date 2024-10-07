/*
Name: Sean Crosby
KU ID: 3117633
Date: 10/6/24
Class: EECS 348
Purpouse: Gives all possible permutations of scores that could have led to a given football score
*/

#include <stdio.h>

void recursive_scorer(int target_score, int current_score, int combination[], int index, int comb_length, int score_matrix[]) {
    /* Base case: if current_score matches the target_score, print the combination */
    if (current_score == target_score) {
        printf("Combination: ");
        for (int i = 0; i < comb_length; i++) {
            printf("%d ", combination[i]); 
        }
        printf("\n");
        return;
    }

    /* If the current score is more than the target score, terminate this branch */
    if (current_score > target_score) {
        return;
    }

    /* Try adding each type of score recursively */
    for (int i = index; i < 5; i++) {
        combination[comb_length] = score_matrix[i];  /* Add score to current combination */
        recursive_scorer(target_score, current_score + score_matrix[i], combination, i, comb_length + 1, score_matrix);
    }
}

int main(void) {
    /* Declarations */
    int combination[100]; /* Declares a blank list for the recursive function to fill */
    int input_value;
    int score_matrix[5] = {2,3,6,7,8};
    
    printf("Input a valid score or 0 to exit: ");
    scanf("%d", &input_value);

    if (input_value <= 1) {
        printf("Exiting...\n");
        return 0;
    }

    printf("\nPossible combinations of points to reach score %d:\n", input_value);
    recursive_scorer(input_value, 0, combination, 0, 0, score_matrix);
    
    return 0;
}