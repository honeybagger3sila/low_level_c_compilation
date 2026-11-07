#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");
    
    if (inputFile == NULL) {
        // If input.txt doesn't exist, create a sample one for demonstration
        inputFile = fopen("input.txt", "w");
        fprintf(inputFile, "10\n20\n30\n40\n");
        fclose(inputFile);
        inputFile = fopen("input.txt", "r");
    }
    
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }
    
    int number, sum = 0, count = 0;
    while (fscanf(inputFile, "%d", &number) == 1) {
        sum += number;
        count++;
    }
    
    fprintf(outputFile, "Total numbers: %d\n", count);
    fprintf(outputFile, "Sum: %d\n", sum);
    if (count > 0) {
        fprintf(outputFile, "Average: %.2f\n", (float)sum / count);
    }
    
    fclose(inputFile);
    fclose(outputFile);
    printf("File processing completed successfully. Check output.txt.\n");
    return 0;
}
