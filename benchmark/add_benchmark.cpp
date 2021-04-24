#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream

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
  long time = 0;
  while (getline(stream, line, ',')){
    const auto time_point_before = chrono::high_resolution_clock::now();
    cb->addFront(stoi(line));
    const auto time_point_after = chrono::high_resolution_clock::now();

    // переводим время в наносекунды
    const auto time_diff = time_point_after - time_point_before;
    time += chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
  }
  delete cb;
  return time;
}

int main() {

  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  auto output_file = ofstream (path + "/result.csv");
  ifstream input_file;
  string message;
  for (int i = 1; i < 5; ++i) {
    for (int j = 0; j < 10; ++j) {
      input_file = ifstream(path + "/TestCase" + to_string(i) + "/TestData" + to_string(j) + ".csv");
      message = "For test case " + to_string(i) + " test data № " + to_string(j) + " average time: "
                + to_string(addFront_test(input_file)) + " number of launches: 10";
      output_file << message << endl;
    }
  }

  return 0;
}