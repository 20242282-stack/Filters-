# Filters-


Image Filters Project

1. Project Overview

This project is an image processing application developed using C++ as part of the CS213 – Object-Oriented Programming (OOP) course at the Faculty of Computers and Artificial Intelligence (FCAI), Cairo University, under the supervision of Dr. Mohammad El-Ramly.

2. Student Information

- Student Name: Mohammed Ramadan Abdelgawad
- Student ID: 20242282

3. Course Information

- Course: CS213 – Object-Oriented Programming (OOP)
- Faculty: Faculty of Computers and Artificial Intelligence (FCAI)
- University: Cairo University
- Instructor: Dr. Mohammad El-Ramly
- Academic Year: 2026–2027
- Programming Language: C++

4. Project Description

The application allows users to load images, apply different image filters, flip images horizontally or vertically, and save the processed images.

The project uses the "Image_Class.h" library to handle image loading, pixel manipulation, and saving.

5. Implemented Filters

Filter 1: Grayscale

Converts a colored image into grayscale by calculating the average of the red, green, and blue color channels for each pixel.

Filter 2: Black and White

Converts an image into black and white using a grayscale value and a threshold of 128.

Filter 3: Invert

Inverts the image colors by subtracting each RGB channel value from 255.

Filter 4: Frame

Adds a black frame around the image with a thickness of 20 pixels, adjusted for smaller images.

Filter 5: Flip

Allows users to flip an image in two directions:

- Horizontal Flip: Reverses the image from left to right.
- Vertical Flip: Reverses the image from top to bottom.

6. Program Menu

Option| Description
 0 Load a new image
 1 Apply the Grayscale filter
 2 Apply the Black and White filter
 3 Apply the Invert filter
 4 Apply the Frame filter
 5 Flip the image
 6 Save the current image
 7 Exit the program
 
7. Requirements

To run the project, you need:

- A C++ compiler or compatible IDE.
- The "Image_Class.h" library.
- An image file supported by the library.

8. How to Run

1. Place the C++ source file and "Image_Class.h" in the appropriate project directory.
2. Open the project in your C++ IDE.
3. Compile and run the program.
4. Enter the filename of the image you want to process.
5. Select a filter from the program menu.
6. Follow the on-screen instructions.
7. Select option "6" to save the processed image.
8. Select option "7" to exit the program.

9. Saving Images

After selecting option "6", enter a filename for the processed image, including the appropriate file extension.

Example:

"output.jpg"

Use a supported image format and a valid output path.

10. Project Structure

A suggested project structure is:

ImageFiltersProject/
├── main.cpp
├── Image_Class.h
├── README.md
└── images/
    └── input.jpg

The actual filenames and directory structure may vary depending on the project setup.

11. Object-Oriented Programming Concepts

The project demonstrates basic object-oriented programming concepts through:

- Classes: The "InvertFilter" and "FrameFilter" classes encapsulate filter operations.
- Member Functions: The "apply()" functions perform the corresponding image transformations.
- Encapsulation: Filter operations are organized within their respective classes.

Other filters are implemented directly in the main program.

12. Conclusion

This project applies fundamental image processing techniques using C++. It provides practical experience with pixel manipulation, image handling, and basic object-oriented programming concepts as part of the CS213 OOP Programming course at FCAI, Cairo University.

---

Developed by: Mohammed Ramadan Abdelgawad
Student ID: 20242282
Course: CS213 – Object-Oriented Programming
University: Cairo University
Supervised by: Dr. Mohammad El-Ramly
Academic Year: 2026–2027
