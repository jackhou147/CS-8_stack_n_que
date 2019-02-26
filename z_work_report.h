#ifndef Z_WORK_REPORT_H
#define Z_WORK_REPORT_H

/*
    Features:
        -Not Implemented: None.

        -Implemented:
            * All the required features have been implemented, including
            (but not limited to) big three sisters, push/pop, low level
            functions performing linked list operations.
            * Stack is implemented using list class, which is built on top
            of low level functions located in node.h header file, as instructed.
            * Queue is implemented directly using low level functions
            located in node.h header file, as instructed.
            * Iterator for list class is implemented.
            * copy_list function is implemented using recursion.

        -Partly implemented: None.

    Bugs: None found.

    Note:
        1. Any attempt to dereference the end of a list will result in
        an assertion fail. This is expected behavior as per implementation,
        NOT a bug. To change this behavior, modify the default constructor
        and dereferencing operator for listIterator class located in file list.h.
        2. default constructor for node class initializes the node with a default
        item, depending on data type(eg. an integer node has a default item of 0).
        This is expected behavior, not a bug. To change this, modify the default
        constructor of node class in node.h line 18.
        3.Commenting should be concise, not redundant.Thus, pre-condition and post-condition
        of certain functions are not added when they are self-explanatory enough.


    Reflections:
        I consider this project to be relatively well done. A couple things
        worth mentioning are as following:
         1. In the future, asserts should be replaced with custom exception classes.
         2.low level functions(those located in file node.h) should not
         be responsible for error handling; high level functions or classes
         should be responsible for avoiding or handling the errors and edge cases when
         calling low level functions.
*/





#endif // Z_WORK_REPORT_H
