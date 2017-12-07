#include <iostream>
#include <memory>


using namespace std;


// #1: Must pass reference to unique_ptr, since pass by value would allow
// for multiple instances of the same pointer, which breaks the unique
// definition
void swap_first_last_unique(unique_ptr<int[]>& arr, size_t size) {
  int temp = arr[0];
  arr[0] = arr[size-1];
  arr[size-1] = temp;
}

// #2 Yes, shared pointers can be passed because multiple copies of them
// are intended to exist at once
void swap_first_last_shared(shared_ptr<int> arr, size_t size) {
  int temp = arr.get()[0];
  arr.get()[0] = arr.get()[size-1];
  arr.get()[size-1] = temp;
  cout << "There are " << arr.use_count() << " instances pointing to myInts inside function call" << endl;

}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  shared_ptr<int> myInts(new int[10], default_delete<int[]>());
  for (int i = 0; i < 10; i++) {
    myInts.get()[i] = rand() % 101;
    cout << myInts.get()[i] << " ";
  }
  cout << endl;
  cout << "There are " << myInts.use_count() << " instances pointing to myInts before function call" << endl;
  swap_first_last_shared(myInts, 10);
  cout << "There are " << myInts.use_count() << " instances pointing to myInts after function call" << endl;

  for (int i = 0; i < 10; i++) {
    cout << myInts.get()[i] << " ";
  }
  cout << endl;
  return 0;
}
