"""
 * Name : Mubtasim Ahmed Rakheen
 * UTA ID : 1001848135
 * Lang: Python
 * OS Used : Windows, Linux
"""

import os

def calculate_total_size(directory):
    """
    Recursively calculates the total size of all files in the given directory and its subdirectories.
    
    :param directory: The directory path to calculate the size of
    :return: The total size of all files in the directory and subdirectories in bytes
    """
    total_size = 0  # Initialize the total size to zero
    
    # Get a list of all items in the directory
    for item in os.listdir(directory):
        item_path = os.path.join(directory, item)  # Get the full path of the item
        
        if os.path.isfile(item_path):
            # If the item is a file, add its size to the total size
            total_size += os.path.getsize(item_path)
        elif os.path.isdir(item_path):
            # If the item is a directory, recursively calculate its size and add to the total size
            total_size += calculate_total_size(item_path)
    
    return total_size

if __name__ == "__main__":
    current_directory = os.getcwd()  # Get the current working directory
    total_size = calculate_total_size(current_directory)  # Calculate the total size
    print(total_size)  # Print the total size in bytes

