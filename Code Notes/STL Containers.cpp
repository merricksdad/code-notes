///////////////////////////////////////////////////////////////////////////////////////////////////////
//MULTIPLE TYPED CONTAINERS
///////////////////////////////////////////////////////////////////////////////////////////////////////

//TUPLES
std::tuple<int, double, std::string> myTuple = std::make_tuple(0,2.0,"hello");
auto value = std::get<0>(myTuple); //Get value at index 0, must be const index
std::tie(myInt, myDouble, std::ignore) = myTuple; //copies from tuple into variables 
std::ignore //ignore copying of variable

//PAIRS
std::pair<int, double> myPair = std::make_pair(1,2.0);
myPair.first / myPair.second //access members of pair

///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
///////////////////////////////////////////////////////////////////////////////////////////////////////

string::npos //maximum allowable size for string; maximum value of unsigned int

string str; //initialises to ""
string str("one"); 
string str(n,'a'); //fill n times with 'a'
string str(char_array, n); //fill n times with char_array

str[0]
str.empty() //returns true/false if empty (faster than size)
str.size() //number of elements
str.length() //same as str.size()
str.insert(4, "hello") //inserts substring one before index 4
str.replace(4, 5, "hello") //replace over index 4 for 5 characteres
str.c_str() //returns pointer to cstring with strings contents
str.clear() //removes all from container
str.back() //returns reference to last element
str.front() //returns reference to first element
str.swap(str2) //swaps two of SAME containers around
str.erase(Begin(str),End(str)) //Erases the elements in the range
str.erase(it) //Erases at particular place
str.max_size() //returns maximum possible size
str.resize(x) //resizes container for x units
str.capacity() //returns number of elements vector can contain before more memory needed
str.reserve(100) //reserves 100 spots (but doesn't create any objects) of vector's type (doesn't affect size)
str.insert(str.begin(),t) //Inserts a reference of t before iterator
str.insert(str.begin(),n,t) //Inserts n references of t before iterator
str.insert(str.begin(),str2.begin(),str2.end()) //Insert copies of elements in the range before iterator

//returns index int
str.find(chararray, 2)  //starts at position 2 and searches for the substring (cstring/string)
str.find("hello", 2)  // returning first occurance's index or string::npos
str.rfind() //finds last occurance of substring
str.find_first_of("hello") //returns index of first occurance of ANY character in substring
str.find_last_of("hello") //returns index of last occurance of ANY character in substring
str.find_first_not_of("hello") //returns index of first occurance of ANY character NOT in substring
str.find_last_not_of("hello") //returns index of last occurance of ANY character NOT in substring

//ITERATORS
begin()   end()   cbegin()   cend()
rbegin()  rend()  crbegin()  crend()

///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <array>
///////////////////////////////////////////////////////////////////////////////////////////////////////

std::array<int, 40> myArray; //fixed, continuous array stored on stack, n must be const

myArray[i]
myArray.assign(0) // assigns array with value
myArray.fill(0)   // fills array with value
myArray.empty()   // returns true/false if empty (faster than size)
myArray.size()    // number of elements
myArray.data()    // returns pointer to internal data
myArray.clear()   // clears array
myArray.front()   // get first element
myArray.back()    // get last element

//ITERATORS
begin()   end()   cbegin()   cend()
rbegin()  rend()  crbegin()  crend()

///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <vector> 
///////////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> V;
vector<int> V(number);
vector<int> V(O.begin(), O.end());

V[i]
V.empty()           // returns true/false if empty (faster than size)
V.size()            // number of elements
V.pop_back()        // Deletes the element at the end of a list.
V.push_back(x)      // Adds an element to the end of a list.
V.assign(n, value)  // assigns reference to value over first n elements
V.clear()           // removes all from container
V.back()            // returns reference to last element
V.front()           // returns reference to first element
V.swap(V2)          // swaps two of SAME containers around
V.erase(itr1, itr2) // Erases the elements in the range
V.erase(itr)        // Erases at particular place
V.max_size()        // returns maximum possible size
V.resize(x)         // resizes container for x units
V.capacity()        // returns number of elements vector can contain before more memory needed
V.reserve(100)      // reserves 100 spots (but doesn't create any objects) of vector's type (doesn't affect size)

V.insert(Begin(V),t)                   // Inserts a reference of t before iterator
V.insert(Begin(V),n,t)                 // Inserts n references of t before iterator
V.insert(Begin(V),V2.begin(),V2.end()) // Insert copies of elements in the range before iterator

//ITERATORS
begin()   end()   cbegin()   cend()
rbegin()  rend()  crbegin()  crend()

///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <deque> 
///////////////////////////////////////////////////////////////////////////////////////////////////////

deque<int> D;

D[i]
D.empty()           // returns true/false if empty (faster than size)
D.size()            // number of elements
D.pop_back()        // Deletes the element at the end of a list.
D.pop_front()       // Deletes the element at the beginning of a list.
D.push_back(x)      // Adds an element to the end of a list.
D.push_front(x)     // Adds an element to the beginning of a list.
D.assign(n,value)   // assigns reference to value over first n elements
D.clear()           // removes all from container
D.back()            // returns reference to last element
D.front()           // returns reference to first element
D.swap(D2)          // swaps two of SAME containers around
D.erase(itr1, itr2) // Erases the elements in the range
D.erase(itr)        // Erases at particular place
D.max_size()        // returns maximum possible size
D.resize(x)         // resizes container for x units
D.capacity()        // returns number of elements vector can contain before more memory needed
D.reserve(100)      // reserves 100 spots (but doesn't create any objects) of vector's type (doesn't affect size)

D.insert(D.begin(),t)                   // Inserts a reference of t before iterator
D.insert(D.begin(),n,t)                 // Inserts n references of t before iterator
D.insert(D.begin(),D2.begin(),D2.end()) // Insert copies of elements in the range before iterator

//ITERATORS
begin()   end()   cbegin()   cend()
rbegin()  rend()  crbegin()  crend()

///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <list> / <forward_list>
///////////////////////////////////////////////////////////////////////////////////////////////////////

list<int> L;
forward_list<int> FL; // only links forward, no reverse iteration

L.empty()                // returns true/false if empty (faster than size)
L.pop_front()            // Deletes the element at the beginning of a list.
L.push_front(x)          // Adds an element to the beginning of a list.
L.reverse()              // Reverses the order in which the elements occur in a list.
L.remove(x)              // Removes all elements with value x from list
L.remove_if(boolLambda)  // Removes all elements returning true from lamda
L.sort()                 // sorts using < in ascending order  speed: L(N*logN)  stable sort
L.merge(one)             // merges one into two, leaving one empty  assumes both are sorted
L.splice(L.begin(), L2)  // inserts L2 in front of L.begin(), leaving one empty
L.unique()               // removes duplicate values in list  assumes list is sorted
L.clear()                // removes all from container
L.front()                // returns reference to first element
L.swap(L2)               // swaps two of SAME containers around
L.erase(itr1, itr2)      // Erases the elements in the range  erase_after() for forward list
L.erase(itr)             // Erases at particular place  erase_after() for forward list
L.max_size()             // returns maximum possible size
L.resize(x)              // resizes container for x units

//LIST SPECIFIC METHODS
L.size()  //number of elements
L.pop_back() //Deletes the element at the end of a list.
L.push_back(x) //Adds an element to the end of a list.
L.back()  //returns reference to last element
L.capacity() //returns number of elements vector can contain before more memory needed
L.emplace_back(obj, 0, "arg2") // Creates element at end and calls constructor with given arguments (varadic)
L.emplace_front(obj, 0, "arg2") // Creates element at front and calls constructor with given arguments (varadic)
L.emplace(itr, obj, 0, "arg2") // Creates element before itr and calls constructor with given arguments (varadic)
L.insert(L.begin(),t) // Inserts a reference of t before iterator
L.insert(L.begin(),n,t) // Inserts n references of t before iterator 
L.insert(itr,L2.begin(),L2.end()) // Insert copies of elements in the range before itr

//FORWARD LIST SPECIFIC METHODS
L.emplace_after(itr, obj, 0, "arg2") // Creates element at after itr and calls constructor with given arguments (varadic)
L.insert_after(L.begin(),t) // Inserts a reference of t after iterator 
L.insert_after(L.begin(),n,t) // Inserts n references of t after iterator
L.insert_after(itr,L2.begin(),L2.end()) // Insert copies of elements in the range after itr

//ITERATORS
begin()   end()   cbegin()   cend()  // Both lists
rbegin()  rend()  crbegin()  crend() // List only

///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <map> / <unordered_map>
///////////////////////////////////////////////////////////////////////////////////////////////////////

typedef std::string KeyType;
typedef std::string ObjType;
typedef std::map<KeyType, ObjType> MyMap;
typedef std::multi_map<KeyType, ObjType> MyMultiMap // can have multiple entries for the one key

MyMap M;
MyMap::iterator itr;

M.empty();          // returns true/false if empty (faster than size)
M.size();           // number of element pairs
M.count("MyKey")    // returns number of items that have that key
M.find("MyKey")     // returns MyMap.end() if not found or iterator MyMap::iterator if found
itr->first          // returns key
itr->second         // returns object

// INSERTING ITEMS
// More effecient to use insert; operator[] creates default object then assigns if object doesn't exist 
M.insert(MyMap::value_type("Key","Object")); // value_type is typedef for maps pair
M["MyKey"] = "MyObject"; // Adds entry if key doesn't exist otherwise overwrites

// ITERATING
// value_type is std::pair<const KeyType, ObjType>
std::for_each(M.begin(), M.end(), [&](const MyMap::value_type& item){ item.second->MyMethod(); });

//ITERATORS
begin()   end()   cbegin()   cend() 
rbegin()  rend()  crbegin()  crend()

// UNORDERED MAP (HASH TABLE)
// Organized into buckets depending on hash values to allow for fast access using keys
std::unordered_map<KeyType, ObjType> hashMap;
std::unordered_multimap<KeyType, ObjType> hashMap;

///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <set> / <unordered_set>
///////////////////////////////////////////////////////////////////////////////////////////////////////

set<int> S;

S.empty();   // returns true/false if empty (faster than size)
S.size();    // number of elements
S.clear();   // clear the container
S.insert(x); // insert element
S.find(x);   // return iterator to element position or S.end() if not found
S.erase(x);  // erase element
S.erase(itr) // erase element at iterator 

//ITERATORS
begin()   end()   cbegin()   cend()
rbegin()  rend()  crbegin()  crend()

//UNORDERED SET (HASH TABLE)
//Organized into buckets depending on hash values to allow for fast access using keys
std::unordered_set<int> hashSet;

///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <queue>
///////////////////////////////////////////////////////////////////////////////////////////////////////

queue<int> Q; //FIFO queue
priority_queue<int> pQ; //largest is automatically sorted to front of queue using heap sort

Q.empty()   // returns true/false if empty (faster than size)
Q.size()    // number of elements
Q.front()   // returns reference to element at front of queue
Q.back()    // returns reference to element at back of the queue
Q.push(x)   // inserts x at back
Q.pop()     // removes element at front

///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stack> 
///////////////////////////////////////////////////////////////////////////////////////////////////////

stack<int> S; //LIFO stack

S.empty()   // returns true/false if empty (faster than size)
S.size()    // number of elements
S.top()     // returns reference to element at top of stack
S.push(x)   // inserts type int to top of the stack
S.pop()     // removes the element at top of stack

///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <bitset>
///////////////////////////////////////////////////////////////////////////////////////////////////////

bitset<numberOfbits> mb; //creates array with n bits; initialised to false

mybits[i]           // access bit
mybits.size()       // size of array
mybits.any()        // returns true if any bit is set to true
mybits.none()       // returns true if no bits are set to true
mybits.set()        // sets all to true
mybits.set(1)       // set bit 1 to true
mybits.reset()      // sets all to false
mybits.reset(1)     // set bit 1 to false
mybits.flip()       // flips all bits to opposite value
mybits.flip(1)      // flips bit 1 to opposite
mybits.count()      // returns number of true bits
mybits.to_string()  // converts bitset to string
mybits.to_ulong()   // converts bitset to unsigned long

///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iterator>
///////////////////////////////////////////////////////////////////////////////////////////////////////

std::end(O) //iterator pointing at one past end of container object
std::begin(O) //iterator pointing at beginning of container object
std::advance(itr, n) //advance iterator by n; Random access iterators use +=/-= else ++/-- 
std::distance(itr1, itr2) //returns int distance between 2 iterators, it2 must be after it1

//Iterating over container
for (vector<int>::iterator itr = scores.begin(); itr != scores.end(); ++itr)
    itr->myMethod();

for (auto& item : myVector) //doesn't work with vs2010
    int x = item;

for each(auto& item in myVector)
    int x = item;

for (vector<int>::reverse_iterator rItr = scores.rbegin(); rItr = scores.rend(); ++rItr)
    rItr->myMethod();

//==================================================================================================
//CONTAINER ITERATORS
//==================================================================================================

//ITERATOR
vector<int>::iterator itr;
*itr //dereferencing gives the value of an element pointed to

//REVERSE ITERATOR
vector<int>::reverse_iterator rItr;
rItr.base() //returns normal iterator pointing to element one after rIt
*rItr //dereferencing gives the value of an element one before the pointed to element
O.erase(++rItr).base()); //erase element rIt holds

//CONST ITERATOR
vector<int>::const_iterator cItr;

//converting between given cItr to itr
vector<int>::iterator itr(myVec.begin());
std::advance(itr, std::distance<vector<int>::const_iterator>(itr, cItr)); //move itr to where const itr is

//==================================================================================================
//INSERT ITERATORS
//==================================================================================================

//Algorithms that require a range to copy can insert instead
transform(S, E, back_inserter(myCon), doCopyLam); //insert at end rather than copying
transform(S, E, front_inserter(myCon), doCopyLam); //insert at front rather than copying
transform(S, E, inserter(myCon, myCon.begin()+myCon.size()/2), doCopyLam); //insert in middle

//BACK INSERT ITERATOR
//inserts at back of container
back_insert_iterator<vector<int>> backIter; 
back_inserter(myContainer) //creates back_insert_iterator

//FRONT INSERT ITERATOR
//inserts at front of container
front_insert_iterator<vector<int>> frontIter; 
front_inserter(myContainer) //creates front_insert_iterator

//INSERT ITERATOR
//inserts at given position
insert_iterator<vector<int>> insertIter;
inserter(myContainer, myContainer.begin()) //creates insert_iterator

//==================================================================================================
//STREAM ITERATORS
//==================================================================================================

//OSTREAM ITERATOR
ostream_iterator<T,char> ostreamItr(cout, " "); //stream, seperator between each item
*out_iter++ = 15;  //works like cout << 15 << " ";
std::copy(object.begin(), object.end(), ostreamItr);
std::copy(object.begin(), object.end(), ostream_iterator<T>(cout, " "));

//ISTREAM ITERATOR
ifstream myFile("myFile.txt");
myFile.unset(ios::skipws); //disable skipping of whitespace (uses operator<< which skips by default)
std::string myString((istream_iterator<char>(myFile)), istream_iterator<char>());
