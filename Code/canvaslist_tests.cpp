#include <gtest/gtest.h>

#include "canvaslist.h"
#include "shape.h"

/* Shape Testing */

/* testing to make sure the string function returns correctly */
TEST(Shape, as_string) {
  Shape shape(4,6);

  string result = shape.as_string();
  string expected = "It's a Shape at x: 4, y: 6";
  EXPECT_EQ(expected, result) << "Returned string is not the same." << endl;
}

/* testing to make sure the get and set functions return correctly */
TEST(Shape, getAndSet) {
  Shape shape(4,6);

  EXPECT_EQ(4, shape.getX()) << "Returned x value is not correct." << endl;
  EXPECT_EQ(6, shape.getY()) << "Returned y value is not correct." << endl;

  shape.setX(1);
  shape.setY(2);

  EXPECT_EQ(1, shape.getX()) << "Set x value is not correct." << endl;
  EXPECT_EQ(2, shape.getY()) << "Set y value is not correct." << endl;
}

/* testing to make sure the copy function returns correctly */
TEST(Shape, copy) {
  Shape test(4,6);
  Shape* ptrToTest = test.copy();

  EXPECT_EQ(4, ptrToTest->getX()) << "Copied x value is not correct." << endl;
  EXPECT_EQ(6, ptrToTest->getY()) << "Copied y value is not correct." << endl;
}

/* Circle Testing */

/* testing to make sure the string function returns correctly */
TEST(Circle, as_string) {
  Circle shape(2,4,3);

  string result = shape.as_string();
  string expected = "It's a Circle at x: 2, y: 4, radius: 3";
  EXPECT_EQ(expected, result) << "Returned string is not the same." << endl;
}

/* testing to make sure the get and set functions return correctly */
TEST(Circle, getAndSet) {
  Circle circle(6);

  EXPECT_EQ(6, circle.getRadius()) << "Returned r value is not correct." << endl;

  circle.setRadius(3);

  EXPECT_EQ(3, circle.getRadius()) << "Set r value is not correct." << endl;
}

/* testing to make sure the copy function returns correctly */
TEST(Circle, copy) {
  Circle test(6);
  Circle* ptrToTest = test.copy();

  EXPECT_EQ(6, ptrToTest->getRadius()) << "Copied r value is not correct." << endl;
}

/* Rectangle Testing */

/* testing to make sure the string function returns correctly */
TEST(Rect, as_string) {
  Rect shape(0,0,0,10);

  string result = shape.as_string();
  string expected = "It's a Rectangle at x: 0, y: 0 with width: 0 and height: 10";
  EXPECT_EQ(expected, result) << "Returned string is not the same." << endl;
}

/* testing to make sure the get and set functions return correctly */
TEST(Rect, getAndSet) {
  Rect test(4,6);

  EXPECT_EQ(4, test.getWidth()) << "Returned w value is not correct." << endl;
  EXPECT_EQ(6, test.getHeight()) << "Returned h value is not correct." << endl;

  test.setWidth(1);
  test.setHeight(2);

  EXPECT_EQ(1, test.getWidth()) << "Set w value is not correct." << endl;
  EXPECT_EQ(2, test.getHeight()) << "Set h value is not correct." << endl;
}

/* testing to make sure the copy function returns correctly */
TEST(Rect, copy) {
  Rect test(4,6);
  Rect* ptrToTest = test.copy();

  EXPECT_EQ(4, ptrToTest->getWidth()) << "Copied w value is not correct." << endl;
  EXPECT_EQ(6, ptrToTest->getHeight()) << "Copied h value is not correct." << endl;
}

/* Right Triangle Testing */

/* testing to make sure the string function returns correctly */
TEST(RightTriangle, as_string) {
  RightTriangle shape(1,2,3,4);

  string result = shape.as_string();
  string expected = "It's a Right Triangle at x: 1, y: 2 with base: 3 and height: 4";
  EXPECT_EQ(expected, result) << "Returned string is not the same." << endl;
}

/* testing to make sure the get and set functions return correctly */
TEST(RightTriangle, getAndSet) {
  RightTriangle test(4,6);

  EXPECT_EQ(4, test.getBase()) << "Returned b value is not correct." << endl;
  EXPECT_EQ(6, test.getHeight()) << "Returned h value is not correct." << endl;

  test.setBase(1);
  test.setHeight(2);

  EXPECT_EQ(1, test.getBase()) << "Set b value is not correct." << endl;
  EXPECT_EQ(2, test.getHeight()) << "Set h value is not correct." << endl;
}

/* testing to make sure the copy function returns correctly */
TEST(RightTriangle, copy) {
  RightTriangle test(4,6);
  RightTriangle* ptrToTest = test.copy();

  EXPECT_EQ(4, ptrToTest->getBase()) << "Copied b value is not correct." << endl;
  EXPECT_EQ(6, ptrToTest->getHeight()) << "Copied h value is not correct." << endl;
}

/* Canvas List Testing*/

/* testing to make sure the default constrcutor creates an empty 'Canvas List' */
TEST(CanvasList, DefaultConstructor_PointsToNothing) {
  CanvasList list; // call class object, default constructor thereby called

  ShapeNode* result = list.front(); // pointer of type ShapeNode is initialized with the front of the list
  ShapeNode* expected = nullptr; // pointer of type ShapeNode is initialized with nullptr
  EXPECT_EQ(expected, result) << "List does not point to nullptr.\n";
}

TEST(CanvasList, DefaultConstructor_IsEmpty) {
  CanvasList list; // call class object, default constructor thereby called

  bool result = list.empty();
  bool expected = true;
  EXPECT_EQ(expected, result) << "List is not empty.\n";
}

/* testing to make sure the empty member function returns true when empty and false when not empty */
TEST(CanvasList, empty) {
  CanvasList emptyList;

  bool emptyResult = emptyList.empty();
  bool emptyExpected = true;
  EXPECT_EQ(emptyExpected, emptyResult) << "Empty member function returned " << emptyResult << " instead of " << emptyExpected << "." << endl;

  CanvasList nonEmptyList;
  Shape* Square = new Shape(5,5);
  nonEmptyList.push_front(Square);
  bool nonEmptyResult = nonEmptyList.empty();
  bool nonEmptyExpected = false;
  EXPECT_EQ(nonEmptyExpected, nonEmptyResult) << "Empty member function returned " << nonEmptyResult << " instead of " << nonEmptyExpected << "." << endl;

}

/* testing to make sure the size member function returns the correct number of elements in 'Canvas List' */
TEST(CanvasList, size) {
  CanvasList emptyList;

  int emptyResult = emptyList.size();
  int emptyExpected = 0;
  EXPECT_EQ(emptyExpected, emptyResult) << "Size member function returned " << emptyResult << " instead of " << emptyExpected << "." << endl;

  CanvasList nonEmptyList;
  Shape* Square = new Shape(5,5);
  nonEmptyList.push_front(Square);
  int nonEmptyResult = nonEmptyList.size();
  int nonEmptyExpected = 1;
  EXPECT_EQ(nonEmptyExpected, nonEmptyResult) << "Size member function returned " << nonEmptyResult << " instead of " << nonEmptyExpected << "." << endl;

}

/* testing to make sure the front member function returns a pointer to the node at the front of the `CanvasList` */
TEST(CanvasList, front) {
  CanvasList nonEmptyList;
  Shape* Square = new Shape(5,5);
  nonEmptyList.push_front(Square);

  // obtain the actual result from the CanvasList
  ShapeNode* nonEmptyResult = nonEmptyList.front();

  // create a ShapeNode with the expected Shape* value
  ShapeNode* nonEmptyExpected = new ShapeNode;
  nonEmptyExpected->value = Square;

  // perform the comparison
  EXPECT_EQ(nonEmptyExpected->value, nonEmptyResult->value) << "Front member function returned a different ShapeNode." << endl;

  // clean up the dynamically allocated objects
  delete nonEmptyExpected;
}

/* testing to make sure the push_front member function adds the given shape to the front of the canvas list */
TEST(CanvasList, push_front) {
  CanvasList list;
  Shape* Square = new Shape(5,5);
  list.push_front(Square);

  ShapeNode* result = list.front();
  // create a ShapeNode with the expected Shape* value
  ShapeNode* expected = new ShapeNode;
  expected->value = Square;
  // compare
  EXPECT_EQ(expected->value, result->value) << "Front member function returned a different ShapeNode." << endl;

  delete expected;
}

/* testing to make sure the push_back member function adds the given shape to the front of the canvas list */
TEST(CanvasList, push_back) {
  CanvasList list;
  Shape* Square = new Shape(5,5);
  Shape* Rectangle = new Shape(10,5);
  list.push_back(Square);
  list.push_back(Rectangle);

  ShapeNode* ptrToBack = list.front()->next;
  
  ShapeNode* ptrToRectangle = new ShapeNode;
  ptrToRectangle->value = Rectangle;

  EXPECT_EQ(ptrToRectangle->value, ptrToBack->value) << "Back member function returned a different ShapeNode." << endl;
  
  
  delete ptrToRectangle;
}

/* testing to make sure the draw member function outputs each shape correctly */
TEST(CanvasList, draw) {
  CanvasList list;
  Shape* Square = new Shape(5,5);
  Shape* Rectangle = new Shape(10,5);
  list.push_front(Square);
  list.push_back(Rectangle);

  cout << Square->as_string() << endl << Rectangle->as_string() << endl;
  cout << "Above is expected. Below is result." << endl;
  list.draw();
  cout << "*************INSPECT THE ABOVE LINES!!!*************" << endl;

}

/* testing to make sure the print_addresses member function outputs each address correctly */
TEST(CanvasList, print_addresses) {
  CanvasList list;
  Shape* Square = new Shape(5,5);
  Shape* Rectangle = new Shape(10,5);
  list.push_front(Square);
  list.push_back(Rectangle);

  cout << "Node Address: " << list.front() << "\t" << "Shape Address: " << Square << endl;
  cout << "Node Address: " << list.front()->next << "\t" << "Shape Address: " << Rectangle << endl;
  cout << "Above is expected. Below is result." << endl;
  list.print_addresses();
  cout << "*************INSPECT THE ABOVE LINES!!!*************" << endl;

}

/* testing to make sure the copy constrcutor creates a deep copy of the `CanvasList`, where each `Shape` is copied over */
TEST(CanvasList, copyConstructor) {
  CanvasList list;
  Shape* Square = new Shape(5,5);
  Shape* Rectangle = new Shape(10,5);
  list.push_front(Square);
  list.push_back(Rectangle);

  CanvasList copiedList(list);

  int sizeExpected = list.size();
  int sizeResult = copiedList.size();
  EXPECT_EQ(sizeExpected, sizeResult) << "Sizes are different." << endl;
  
  bool emptyExpected = list.empty();
  bool emptyResult = copiedList.empty();
  EXPECT_EQ(emptyExpected, emptyResult) << "Empty bool return is different." << endl;

}

/* testing to make sure the find member function returns the index of the first matching shape */
TEST(CanvasList, find) {
  CanvasList list;
  Shape* Square = new Shape(5,5);
  Shape* Rectangle = new Shape(10,5);
  Shape* Square2 = new Shape(5,5);
  list.push_front(Square);
  list.push_back(Rectangle);
  list.push_back(Square2);

  int resultIndex = list.find(5,5);
  int expectedIndex = 0;
  EXPECT_EQ(expectedIndex, resultIndex) << "Expected: " << expectedIndex << ". Result is: " << resultIndex << "." << endl;

  resultIndex = list.find(10,5);
  expectedIndex = 1;
  EXPECT_EQ(expectedIndex, resultIndex) << "Expected: " << expectedIndex << ". Result is: " << resultIndex << "." << endl;

  resultIndex = list.find(6,3);
  expectedIndex = -1;
  EXPECT_EQ(expectedIndex, resultIndex) << "Expected: " << expectedIndex << ". Result is: " << resultIndex << "." << endl;

}

/* testing to make sure the shape_at member function returns the correct shape* of the inputted index */
TEST(CanvasList, shape_at) {
  CanvasList list;
  Shape* Square = new Shape(5,5);
  Shape* Rectangle = new Shape(10,5);
  list.push_front(Square);
  list.push_back(Rectangle);

  Shape* resultPtr = list.shape_at(0);
  Shape* expectedPtr = Square;
  EXPECT_EQ(expectedPtr, resultPtr) << "Expected: " << expectedPtr << ". Result is: " << resultPtr << "." << endl;

  resultPtr = list.shape_at(1);
  expectedPtr = Rectangle;
  EXPECT_EQ(expectedPtr, resultPtr) << "Expected: " << expectedPtr << ". Result is: " << resultPtr << "." << endl;

  resultPtr = list.shape_at(7);
  expectedPtr = nullptr;
  EXPECT_EQ(expectedPtr, resultPtr) << "Expected: " << expectedPtr << ". Result is: " << resultPtr << "." << endl;

}

/* testing to make sure the insert_after member function returns the correct shape* of the inputted index */
TEST(CanvasList, insert_after) {
  CanvasList list;
  Shape* shapeToAdd = new Shape(20, 24);

  list.insert_after(0, shapeToAdd);
  EXPECT_EQ(0, list.size()) << "List is empty. Should not be inserting elements." << endl;

  Shape* Square = new Shape(5,5);
  Shape* Rectangle = new Shape(10,5);
  list.push_back(Square);
  list.push_back(Rectangle);

  list.insert_after(0, shapeToAdd);

  int resultSize = list.size();
  int expectedSize = 3;
  EXPECT_EQ(expectedSize, resultSize) << "Expected Size: " << expectedSize << ". Result Size is: " << resultSize << "." << endl;

  Shape* resultIndexShape = list.shape_at(1);
  Shape* expectedShape = shapeToAdd;
  EXPECT_EQ(expectedShape, resultIndexShape) << "Expected Shape: " << expectedShape->as_string() << ". Result Size is: " << resultIndexShape->as_string() << "." << endl;

  Shape* shapeNotToAdd = new Shape(60, 12);
  list.insert_after(5, shapeNotToAdd);
  resultSize = list.size();
  EXPECT_EQ(expectedSize, resultSize) << "Added Shape to Invalid Index." << endl;

  delete shapeNotToAdd;

}

/* testing to make sure the pop_front member function returns the shape* of the removed element */
TEST(CanvasList, pop_front) {
  CanvasList list;
  Shape* Square = new Shape(5,5);
  Shape* Rectangle = new Shape(10,5);
  Shape* Triangle = new Shape(12,3);
  list.push_front(Square);
  list.push_back(Rectangle);
  list.push_back(Triangle);

  Shape* resultFront = list.pop_front();
  Shape* expectedFront = Square;
  EXPECT_EQ(expectedFront, resultFront) << "Front Shape Returned is incorrect. (pop #1)" << endl;

  resultFront = list.pop_front();
  expectedFront = Rectangle;
  EXPECT_EQ(expectedFront, resultFront) << "Front Shape Returned is incorrect. (pop #2)" << endl;

  resultFront = list.pop_front();
  expectedFront = Triangle;
  EXPECT_EQ(expectedFront, resultFront) << "Front Shape Returned is expected to be nullptr. (pop #3)" << endl;

  resultFront = list.pop_front();
  expectedFront = nullptr;
  EXPECT_EQ(expectedFront, resultFront) << "Front Shape Returned is expected to be nullptr. (pop #4)" << endl;

  delete Square;
  delete Rectangle;
  delete Triangle;
}

/* testing to make sure the pop_back member function returns the shape* of the removed element */
TEST(CanvasList, pop_back) {
  CanvasList list;
  Shape* Square = new Shape(5,5);
  Shape* Rectangle = new Shape(10,5);
  Shape* Triangle = new Shape(12,3);
  list.push_front(Square);
  list.push_back(Rectangle);
  list.push_back(Triangle);

  Shape* resultBack = list.pop_back();
  Shape* expectedBack = Triangle;
  EXPECT_EQ(expectedBack, resultBack) << "Back Shape Returned is incorrect. (pop #1)" << endl;

  resultBack = list.pop_back();
  expectedBack = Rectangle;
  EXPECT_EQ(expectedBack, resultBack) << "Back Shape Returned is incorrect. (pop #2)" << endl;

  resultBack = list.pop_back();
  expectedBack = Square;
  EXPECT_EQ(expectedBack, resultBack) << "Back Shape Returned is incorrect. (pop #3)" << endl;

  resultBack = list.pop_back();
  expectedBack = nullptr;
  EXPECT_EQ(expectedBack, resultBack) << "Back Shape Returned is expected to be nullptr. (pop #4)" << endl;

  delete Square;
  delete Rectangle;
  delete Triangle;
  
}

/* testing to make sure the clear member function: 1) releases all allocated memory, 2) resets all member variables */
TEST(CanvasList, clear) {
  CanvasList list;
  Shape* Square = new Shape(5,5);
  Shape* Rectangle = new Shape(10,5);
  Shape* Triangle = new Shape(12,3);
  list.push_front(Square);
  list.push_back(Rectangle);
  list.push_back(Triangle);

  list.clear();

  /* HOW DO WE CHECK IF MEMORY WAS FREED ??????????????????????????????????????????????????????????????????? */

  int resultSize = list.size();
  int expectedSize = 0;
  EXPECT_EQ(expectedSize, resultSize) << "Size function returned different values." << endl;

  bool resultEmpty = list.empty();
  bool expectedEmpty = true;
  EXPECT_EQ(expectedEmpty, resultEmpty) << "Empty function returned different values." << endl;

}

/* testing to make sure the assignment operator sets the current canvas list to a deep copy */
TEST(CanvasList, assignmentOperator) {
  CanvasList list;
  CanvasList other;

  list = list.operator=(other);
  EXPECT_EQ(list.size(), other.size()) << "Both lists were supposed to be empty." << endl;

  Shape* Square = new Shape(5,5);
  Shape* Rectangle = new Shape(10,5);
  Shape* Triangle = new Shape(12,3);
  list.push_back(Square);
  list.push_back(Rectangle);
  list.push_back(Triangle);

  CanvasList copyIntoThisList;
  list.operator=(copyIntoThisList);

  ShapeNode* resultPtrToFront = copyIntoThisList.front();
  ShapeNode* expectedPtrToFront = nullptr;
  EXPECT_EQ(expectedPtrToFront, resultPtrToFront) << "Front ptrs to elements are different." << endl;
}

/* testing to make sure the destructor member function clears all allocated memory */
TEST(CanvasList, destructor) {
  
  /* HOW DO WE CHECK IF MEMORY WAS FREED ??????????????????????????????????????????????????????????????????? */
  cout << "idk how to test destructor. ignore me :D" << endl;

}

/* testing to make sure the remove_at member function removes the element at the specified index */
TEST(CanvasList, remove_at) {
  CanvasList list;
  Shape* Square = new Shape(5,5);
  Shape* Rectangle = new Shape(10,5);
  Shape* Triangle = new Shape(12,3);
  list.push_front(Square);
  list.push_back(Rectangle);
  list.push_back(Triangle);

  int resultSize = list.size();
  int expectedSize = 3;
  list.remove_at(7);
  EXPECT_EQ(expectedSize, resultSize) << "Entering invalid index changed the size." << endl;

  list.remove_at(0);
  if (list.find(5,5) != -1) { // shape was found
    EXPECT_EQ(1,0) << "Element at index " << 0 << " not removed." << endl;
  }

  list.remove_at(0);
  if (list.find(10,5) != -1) { // shape was found
    EXPECT_EQ(1,0) << "Element at index " << 1 << " not removed." << endl;
  }

  list.remove_at(0);
  if (list.find(12,3) != -1) { // shape was found
    EXPECT_EQ(1,0) << "Element at index " << 2 << " not removed." << endl;
  }

}

/* testing to make sure the remove_every_other member function removes every other element */
TEST(CanvasList, remove_every_other) {
  CanvasList list;
  Shape* Square = new Shape(5,5);
  Shape* Rectangle = new Shape(10,5);
  Shape* Triangle = new Shape(12,3);
  Shape* Trapezoid = new Shape(13,3);
  Shape* Circle = new Shape(9,9);
  list.push_front(Square);
  list.push_back(Rectangle);
  list.push_back(Triangle);
  list.push_back(Trapezoid);
  list.push_back(Circle);


  list.remove_every_other();

  if (list.find(10,5) != -1) { // shape found
    EXPECT_EQ(1,0) << "Element at index " << 1 << " not removed." << endl;
  }
  if (list.find(13,3) != -1) { // shape found
    EXPECT_EQ(1,0) << "Element at index " << 3 << " not removed." << endl;
  }

  int resultSize = list.size();
  int expectedSize = 3;
  EXPECT_EQ(expectedSize, resultSize) << "Size function returned different values." << endl;
  
}
