#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CREDENTIAL_LENGTH 50

// Structure to store credentials
struct Credentials
{
    char location[MAX_CREDENTIAL_LENGTH];
    char username[MAX_CREDENTIAL_LENGTH];
    char password[MAX_CREDENTIAL_LENGTH];
};

// Function to save credentials to a file
void saveCredentials(struct Credentials *credentials)
{
    char confirm_password[MAX_CREDENTIAL_LENGTH];

    // Get user input for password confirmation
    printf("Please confirm your password: ");
    scanf("%s", confirm_password);

    // Compare the entered password with the original password
    if (strcmp(credentials->password, confirm_password) == 0)
    {
        // Open the file in append mode ("a")
        FILE *file = fopen("credentials.txt", "a");

        // Check if the file is opened successfully
        if (file != NULL)
        {
            // Write credentials to the file
            fprintf(file, "App/cite name: %s\nUsername: %s\nPassword: %s\n---------------------------------------------------\n",
                    credentials->location, credentials->username, credentials->password);
            // Close the file
            fclose(file);

            printf("\nCredentials saved successfully.\n");
        }
        else
        {
            // Print an error message if opening the file fails
            printf("Error opening file for writing.\n");
        }
    }
    else
    {
        // Print an error message if password confirmation fails
        printf("Password confirmation failed. Credentials not saved.\n");
    }
}

// Function to load credentials from the file
void loadCredentials(const char *location, struct Credentials *credentials)
{
    // Open the file in read mode ("r")
    FILE *file = fopen("credentials.txt", "r");

    // Check if the file is opened successfully
    if (file != NULL)
    {
        // Read the file line by line until the end
        while (fscanf(file, "App/cite name: %s\nUsername: %s\nPassword: %s\n",
                      credentials->location, credentials->username, credentials->password) == 3)
        {
            // Check if the loaded credentials match the specified location
            if (strcmp(location, credentials->location) == 0)
            {

                printf("Credentials loaded successfully for app/cite name '%s'.\n", location);
                printf("Username: %s\nPassword: %s\n", credentials->username, credentials->password);
                // Close the file
                fclose(file);
                return;
            }
        }

        fclose(file);
        // Print a message if credentials for the specified app/cite are not found
        printf("Credentials not found for app/cite name '%s'.\n", location);
    }
    else
    {
        // Print an error message if opening the file fails
        printf("Error opening file for reading.\n");
    }
}

int main()
{
    while (1)
    {
        // Declare a variable to store user credentials
        struct Credentials userCredentials;

        // Prompt the user to choose an action (Save or Load)
        printf("Save' or 'Load' credentials: ");
        char action[10];
        scanf("%s", action);

        // Check the chosen action
        if (strcmp(action, "Save") == 0 || strcmp(action, "save") == 0)
        {

            printf("Enter app/cite name: ");
            scanf("%s", userCredentials.location);

            printf("Enter username: ");
            scanf("%s", userCredentials.username);

            printf("Enter password: ");
            scanf("%s", userCredentials.password);

            // Call the saveCredentials function to save the entered credentials
            saveCredentials(&userCredentials);
        }
        else if (strcmp(action, "Load") == 0 || strcmp(action, "load") == 0)
        {

            printf("Enter app/cite name to load credentials: ");
            char locationToLoad[MAX_CREDENTIAL_LENGTH];
            scanf("%s", locationToLoad);

            // Call the loadCredentials function to load and display the credentials for the specified location
            loadCredentials(locationToLoad, &userCredentials);
        }
        else if (strcmp(action, "Exit") == 0 || strcmp(action, "exit") == 0)
        {
            break;
        }
        else
        {
            printf("Type 'Save', 'Load' or 'Exit'.\n");
        }
    }
    printf("Have a nice day!\n");
    return 0;
}