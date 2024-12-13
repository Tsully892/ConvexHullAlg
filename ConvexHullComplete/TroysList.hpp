#pragma once

#include <string>
#include <vector>

/*
 A list class built on top of the std::vector class. Unlike the STL class
 std::list, this class implements the the basic insert and remove methods
 as they are described in most textbooks.
 */
template <typename T>
class List {
protected:

    /*
     This List class is backed by a std::vector
     */
    std::vector<T>* items;

public:

    /*
     Creates an empty list.
     */
    List();

    /*
     Copy constructor
     */
    List(const List<T>& another);

    /*
     Destructor
     */
    ~List();

    /*
     Returns true if and only if this list is empty.
     */
    bool isEmpty() const;

    /*
     Returns the number of items stored in this list.
     */
    int size() const;

    /*
     Returns the index of the first element in this list that contains the
     specified data, or a negative number (-1) if this list does not contain
     the data.
     */
    int contains(const T data) const;

    /*
     Returns the value stored in the specified index of this list.
     */
    T get(int ndx) const;

    /*
     Creates a new list element with the specified index, and stores the
     specified data in that index. Indices of items after the specified
     index are incremented by 1.
     */
    void insert(const T data, int ndx);

    /*
     Overwrites the data with the specified index with the given data, and
     returns the data that was previously in that position.
     */
    T replace(const T data, int ndx);

    /*
     Removes the item at the specified index from this list, and returns it.
     */
    T remove(int ndx);

    /*
     Appends the specified list to the end of this one.
     */
    void append(const List<T>& suffix);

    /*
     Prepends the specified list to the beginning of this one.
     */
    void prepend(const List<T>& prefix);

    /*
     Two lists are considered equal if they contain the same data in the same
     order.
     */
    bool operator==(const List<T>& another);

    /*
     Returns the negation of operator==(List<T>&).
     */
    bool operator!=(const List<T>& another);

    /*
     Returns a string representation of this list.
     */
    std::string toString() const;

};

//
// Non-member functions
//

/*
 Overload stream insertion. This enables an object of type List<T> to be
 directly given to the stream insertion operator <<.
 */
template <typename T>
std::ostream& operator<<(std::ostream& outStream, const List<T>& lst);

