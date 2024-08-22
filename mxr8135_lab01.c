/** 
 * Name : Mubtasim Ahmed Rakheen
 * UTA ID : 1001848135
 * Lang: C
 * OS Used : Windows, Linux
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

// Function to recursively calculate the total size of all files
long long calculate_total_size(const char *directory) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    long long total_size = 0;

    // Open the directory
    if ((dir = opendir(directory)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Change to the directory
    if (chdir(directory) == -1) {
        perror("chdir");
        exit(EXIT_FAILURE);
    }

    // Read each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the status of the entry
        if (stat(entry->d_name, &statbuf) == -1) {
            perror("stat");
            exit(EXIT_FAILURE);
        }

        // If the entry is a file, add its size to the total size
        if (S_ISREG(statbuf.st_mode)) {
            total_size += statbuf.st_size;
        }

        // If the entry is a directory, recursively calculate its size and add to the total size
        if (S_ISDIR(statbuf.st_mode)) {
            total_size += calculate_total_size(entry->d_name);
        }
    }

    // Change back to the parent directory
    if (chdir("..") == -1) {
        perror("chdir");
        exit(EXIT_FAILURE);
    }

    // Close the directory
    closedir(dir);

    return total_size;
}

int main() {
    // Get the current working directory
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }

    // Calculate the total size of all files in the current directory and subdirectories
    long long total_size = calculate_total_size(cwd);

    // Print the total size in bytes
    printf("%lld\n", total_size);

    return 0;
}




