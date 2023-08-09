# Project-OOP
The project represents an executable application that tests the implemented C++ concepts.The project theme is the management of a library.

Project Requirements - Phase 1

Define a minimum of 5 classes related to the project's requirements.
Each class must contain at least one dynamically allocated field managed through a pointer and at least one statically defined array. Both character strings (char*) and arrays of numeric values must be addressed.
The solution must include at least one class that defines a static field and at least one class that defines a constant field.
All attributes must be defined in the private section of the class.
Define a public interface (accessor functions) for each attribute that allows reading and writing of values. Modification functions must include at least one value validation rule.
Each class should contain a minimum of 2 generic methods for attribute manipulation/display.
Each class should include a minimum of 2 parameterized constructors, a copy constructor, a destructor, and the overloaded form of the assignment operator.
The >> and << operators must be overloaded for each class.
For each class, the following operators must be overloaded:
The index operator []
At least one mathematical operator (+, -, *, or /)
++ or -- (with both forms)
Explicit or implicit casting operator (to any type)
The negation operator !
At least one conditional operator (<, >, <=, >=)
The equality operator == for comparing two objects
All classes are defined in a single source file.
Testing of classes (main method) will involve calling all implemented methods.

Project Requirements - Phase 2

Implement a module that allows the application to receive input files (in text format) through the arguments of the main function (example: if the application is named projectOOP.exe, it is launched with the command projectOOP.exe invoices.txt expenses.txt; only text files can be used).
Implement a module that allows users to save application data to binary files. Application data is considered to be the data obtained from the text files received as arguments for the main function, or data loaded by users during the working session. If the application does not receive arguments through the main function (launched with projectOOP.exe), it will access binary files located in known locations for the programmer. Binary files enable the storage of all data loaded into the application through various methods.
Entities managing files and file operations are implemented through classes (source code accessing the files should be included in methods belonging to new classes added to the project).
Implement a module that allows users to generate various reports for all data (e.g., user lists, question lists from a specific category, user hierarchies, answers to a question, etc.) to be displayed in both console and text files (minimum of 3 reports).
Implement a module that manages a simple form of a menu, allowing users to navigate through application functions (after starting the application, users can use numeric keys or input text to decide which functions to activate—e.g., view invoices, generate different types of reports, etc.).
The application allows data loading from CSV files (comma-separated values); the chosen symbol for value separation is determined by the programmer and is used for all CSV files.

Project Requirements - Phase 3

Implement a class exemplifying the concept of class composition (if not already implemented in previous phases).
Extend the classes defined in previous phases by adding new attributes (necessary for this phase) only through derivation, NOT by modifying existing classes—minimum of 2 extensions.
Implement at least one abstract class (with or without attributes) containing a minimum of 2 pure virtual methods.
Implement at least 2 virtual methods (other than pure virtual).
Define at least one hierarchy family through an abstract class or a newly defined or existing base class.
Implement a minimum of one array of pointers to the base class (of the hierarchy) for managing concrete elements of a class family.

