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

void fillBuffer(Circular_buffer* buff, vector<int>& vector);

long getBack_test(vector<int> &vector){
  Circular_buffer *cb = new Circular_buffer(vector.size());
  long globalTime = 0;
  long inCycleTime = 0;

  for (int i = 0; i < 10; ++i) {
    fillBuffer(cb, vector);
    for (int j = 0; j < vector.size(); ++j) {
      const auto time_point_before = chrono::high_resolution_clock::now();
      cb->getBack();
      const auto time_point_after = chrono::high_resolution_clock::now();
      const auto time_diff = time_point_after - time_point_before;
      inCycleTime += (long) chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
    }
    globalTime += inCycleTime/1000;
    inCycleTime = 0;
  }

  delete cb;
  return globalTime/10;
}

long getFront_test(vector<int> &vector){
  Circular_buffer *cb = new Circular_buffer(vector.size());
  long globalTime = 0;
  long inCycleTime = 0;

  for (int i = 0; i < 10; ++i) {
    fillBuffer(cb, vector);
    for (int j = 0; j < vector.size(); ++j) {
      const auto time_point_before = chrono::high_resolution_clock::now();
      cb->getFront();
      const auto time_point_after = chrono::high_resolution_clock::now();
      const auto time_diff = time_point_after - time_point_before;
      inCycleTime += (long) chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
    }
    globalTime += inCycleTime/1000;
    inCycleTime = 0;
  }

  delete cb;
  return globalTime/10;
}

void fillBuffer(Circular_buffer *buff, vector<int>& vector) {
  for (int i = 0; i < vector.size(); ++i) {
    buff->addBack(vector[i]);
  }
}

int main() {

  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  auto output_file = ofstream (path + "/get_result.csv");
  ifstream input_file;
  string message;
  vector<int> vector;
  string line;
  for (int i = 1; i < 11; ++i) {
    for (int j = 0; j < 10; ++j) {
      input_file = ifstream(path + "/TestCase" + to_string(i) + "/TestData" + to_string(j) + ".csv");
      while (getline(input_file, line, ',')){
        vector.push_back(stoi(line));
      }

      message = "Method: getBack(),testcase " + to_string(i) + "." + to_string(j) + "," +
                to_string(getBack_test(vector));
      output_file << message << ",    ," ;

      message = "Method: getFront(),testcase " + to_string(i) + "." + to_string(j) + "," +
                to_string(getFront_test(vector));
      output_file << message<<endl;
      vector.clear();
    }
  }

  return 0;
}
