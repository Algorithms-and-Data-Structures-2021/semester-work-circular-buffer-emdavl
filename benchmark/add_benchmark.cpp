#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>

// подключаем вашу структуру данных
#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

long addFront_test(ifstream &stream){
  string line;
  Circular_buffer *cb = new Circular_buffer();
  float globalTime = 0;
  long inCycleTime = 0;
  vector<int> vector;

  while (getline(stream, line, ',')){
    vector.push_back(stoi(line));
  }

  int elem;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < vector.size(); ++j) {
      elem = vector[j];
      const auto time_point_before = chrono::high_resolution_clock::now();
      cb->addFront(elem);
      const auto time_point_after = chrono::high_resolution_clock::now();

      // переводим время в наносекунды
      const auto time_diff = time_point_after - time_point_before;
      inCycleTime += chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
    }
    globalTime+=inCycleTime/(1000);
    inCycleTime = 0;
  }

  delete cb;
  return (long) globalTime/10;
}

long addBack_test(ifstream &stream){
  string line;
  Circular_buffer *cb = new Circular_buffer();
  float globalTime = 0;
  long inCycleTime = 0;
  vector<int> vector;

  while (getline(stream, line, ',')){
    vector.push_back(stoi(line));
  }

  int elem;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < vector.size(); ++j) {
      elem = vector[j];
      const auto time_point_before = chrono::high_resolution_clock::now();
      cb->addBack(elem);
      const auto time_point_after = chrono::high_resolution_clock::now();

      // переводим время в наносекунды
      const auto time_diff = time_point_after - time_point_before;
      inCycleTime += chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
    }
    globalTime+=inCycleTime/(1000);
    inCycleTime = 0;
  }

  delete cb;
  return (long) globalTime/10;
}
int main() {

  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  auto output_file = ofstream (path + "/add_result.csv");
  ifstream input_file;
  string message;
  for (int i = 1; i < 11; ++i) {
    for (int j = 0; j < 10; ++j) {
      input_file = ifstream(path + "/TestCase" + to_string(i) + "/TestData" + to_string(j) + ".csv");
      message = "Operation: addFront(),test case " + to_string(i) + "." + to_string(j) + ","
                + to_string(addFront_test(input_file));
      output_file << message << ",     ,";
      message = "Operation: addBack(),test case " + to_string(i) + "." + to_string(j) + ","
      + to_string(addBack_test(input_file));
      output_file << message<<endl;
    }
  }

  return 0;
}