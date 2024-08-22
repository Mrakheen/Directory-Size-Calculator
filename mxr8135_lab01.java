/** 
 * Name : Mubtasim Ahmed Rakheen
 * UTA ID : 1001848135
 * Lang: java
 * OS Used : Windows, Linux
 */

import java.io.File;

public class mxr8135_lab01 {

    /**
     * Recursively calculates the total size of all files in the given directory and its subdirectories.
     *
     * @param directory The directory path to calculate the size of
     * @return The total size of all files in the directory and subdirectories in bytes
     */
    public static long calculateTotalSize(File directory) {
        long totalSize = 0;  // Initialize the total size to zero

        // Get a list of all items (files and directories) in the directory
        File[] items = directory.listFiles();

        if (items != null) {  // Ensure the directory is not empty
            for (File item : items) {
                if (item.isFile()) {
                    // If the item is a file, add its size to the total size
                    totalSize += item.length();
                } else if (item.isDirectory()) {
                    // If the item is a directory, recursively calculate its size and add to the total size
                    totalSize += calculateTotalSize(item);
                }
            }
        }

        return totalSize;
    }

    public static void main(String[] args) {
        File currentDirectory = new File(".");  // Get the current working directory
        long totalSize = calculateTotalSize(currentDirectory);  // Calculate the total size
        System.out.println(totalSize);  // Print the total size in bytes
    }
    
}





