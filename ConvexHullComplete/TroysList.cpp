#include <iterator>
#include <sstream>

#include "TroysList.hpp"
#include "ConvexHull.hpp"

using namespace std;

/*
 Creates an empty list.
 */
template <typename T>
List<T>::List() {
    this->items = new std::vector<T>();
}

/*
 Copy constructor.
 */
template <typename T>
List<T>::List(const List<T>& another) {
    this->items = new std::vector<T>();
    for (int k = 0; k < another.size(); k++) {
        this->items->push_back(another.items->at(k));
    }
}

/*
 Destructor.
 */
template <typename T>
List<T>::~List() {
    delete this->items;
}

/*
 Returns the number of items stored in this list.
 */
template <typename T>
int List<T>::size() const {
    return (int)this->items->size();
}

/*
 Returns true if and only if this list is empty.
 */
template <typename T>
bool List<T>::isEmpty() const {
    return this->items->empty();
}

/*
 Returns the index of the first element in this list that contains the
 specified data, or a negative number (-1) if this list does not contain
 the data.
 */
template <typename T>
int List<T>::contains(const T data) const {
    int result = -1;
    for (int k = 0; k < this->items->size(); k++) {
        if (this->items->at(k) == data) {
            result = k;
            break;
        }
    }
    return result;
}

/*
 Returns the value stored in the specified index of this list.
 */
template <typename T>
T List<T>::get(int ndx) const {
    return this->items->at(ndx);
}

/*
 Creates a new list element with the specified index, and stores the
 specified data in that index. Indices of items after the specified
 index are incremented by 1.
 */
template <typename T>
void List<T>::insert(const T data, int ndx) {
    auto it = this->items->begin();
    advance(it, ndx);
    this->items->insert(it, data);
}

/*
 Overwrites the data with the specified index with the given data, and
 returns the data that was previously in that position.
 */
template <typename T>
T List<T>::replace(const T data, int ndx) {
    T oldData = this->get(ndx);
    this->remove(ndx);
    this->insert(data, ndx);
    return oldData;
}

/*
 Removes the item at the specified index from this list, and returns it.
 */
template <typename T>
T List<T>::remove(int ndx) {
    T data = this->get(ndx);
    this->items->erase(this->items->begin() + ndx);
    return data;
}

/*
 Appends the specified list to the end of this one.
 */
template <typename T>
void List<T>::append(const List<T>& suffix) {
    int thisSize = this->size();
    int suffixSize = suffix.size();
    int suffixNdx = 0;
    for (int k = thisSize; k < thisSize + suffixSize; k++) {
        this->insert(suffix.get(suffixNdx), k);
        suffixNdx++;
    }
}

/*
 Prepends the specified list to the beginning of this one.
 */
template <typename T>
void List<T>::prepend(const List<T>& prefix) {
    int thisSize = this->size();
    int prefixSize = prefix.size();
    int prefixNdx = 0;
    for (int k = thisSize; k < thisSize + prefixSize; k++) {
        this->insert(prefix.get(prefixNdx), k);
        prefixNdx++;
    }
}

/*
 Two lists are considered equal if they contain the same data in the same
 order.
 */
template <typename T>
bool List<T>::operator==(const List<T>& another) {
    int thisSize = (int)this->items->size();
    bool result = true;
    if (thisSize != another.items->size()) {
        result = false;
    }
    else {
        for (int k = 0; k < thisSize; k++) {
            if (this->items->at(k) != another.items->at(k)) {
                result = false;
                break;
            }
        }
    }
    return result;
}

/*
 Returns the negation of operator==(List<T>&).
 */
template <typename T>
bool List<T>::operator!=(const List<T>& another) {
    return !this->operator==(another);
}

/*
 Returns a string representation of this list.
 */
template <typename T>
std::string List<T>::toString() const {
    std::ostringstream sout;
    int thisSize = (int)this->items->size();
    if (thisSize == 0) {
        sout << "Empty List at " << this << ".";
    }
    else if (thisSize == 1) {
        sout << "List at " << this << ", containing 1 item";
    }
    else {
        sout << "List at " << this << ", containing " << thisSize << " items.";
    }
    return sout.str();
}

//
// Non-member functions
//

/*
 Overload stream insertion. This enables an object of type List<T> to be
 directly given to the stream insertion operator <<.
 */
template <typename T>
std::ostream& operator<<(std::ostream& outStream, const List<T>& lst) {
    outStream << lst.toString();
    return outStream;
}

