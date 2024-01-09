# Password-Manager
This simple C program provides a basic credential manager with functionalities to save and load credentials securely. User credentials, including app/cite name, username, and password, are stored in a file named credentials.txt.

## How to Use
1. Compile the Program:
  - Make sure you have a C compiler installed (e.g., GCC).
  - Compile the program using the following command:

    ```bash
    gcc credentials_manager.c -o credentials_manager
    ```
2. Run the Program:
  - Execute the compiled program:
     ```bash
    ./credentials_manager
     ```
3. Choose Action:
 - The program will prompt you to choose between 'Save', 'Load', or 'Exit'.


### Save Credentials
-  If you choose 'Save', you will be prompted to enter the application/cite name, username, and password.
-  The password is confirmed to ensure accuracy.
-  Credentials will be saved in the 'credentials.txt' file.

### Load Credentials
-  If you choose 'Load', enter the application/cite name for which you want to retrieve credentials.
-  The program will search for and display the corresponding username and password if found.

### Exit 
-  Choosing 'Exit' terminates the program.

## Important Notes
-  Maximum length for application/cite name, username, and password is set to 50 characters.
-  Credentials are stored in the 'credentials.txt' file in a formatted manner.
-  The program validates password confirmation during the saving process.

## File Structure
- `credentials_manager.c`: The main C source code file.
- `credentials.txt`: The file where credentials are stored.
  
## License
This project is licensed under the [MIT License](https://opensource.org/license/mit/).

## Contact
For any questions or suggestions, please feel free to contact the project maintainer:

- Name: Jaani Söderström
- Email: soderstrom.jaani@gmail.com

Please allow some time for a response, as the maintainer's availability may vary.

---
