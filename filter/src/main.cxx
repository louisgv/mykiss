#include <chrono>

#include <iostream>
#include <iterator>
#include <sys/stat.h>

#include "csvmonkey/csvmonkey.hpp"
using namespace csvmonkey;

const double DEFAULT_SIZE_BOUNDARY_MIN = 6000000;

bool isExists (const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
		std::cout << "ERROR: Not enough argument!" << std::endl;
		return 1;
  }

	if (!isExists(argv[1])) {
		std::cout << "ERROR: " << argv[1] << " does not exist!" << std::endl;
		return 1;
	}

	std::cout.precision(2);

  int index = 0;

  double totalSize = 0;

  MappedFileCursor cursor;
  cursor.open(argv[1]);

  double sizeBoundaryMin = argc >= 3
                           ? std::stod(argv[2])
                           : DEFAULT_SIZE_BOUNDARY_MIN;

  CsvReader  reader(cursor);
  CsvCursor& row = reader.row();

  CsvCell *cell_ImageID;
  CsvCell *cell_Subset;
  CsvCell *cell_OriginalURL;
  CsvCell *cell_OriginalSize;

  auto start = std::chrono::high_resolution_clock::now();

  while (reader.read_row()) {
    row.by_value("OriginalSize", cell_OriginalSize);
		row.by_value("ImageID",     cell_ImageID);
		row.by_value("Subset",      cell_Subset);
		row.by_value("OriginalURL", cell_OriginalURL);

		double originalSize = cell_OriginalSize->as_double();

    if (originalSize > sizeBoundaryMin) {
			index++;

			totalSize += originalSize/1000000;
    }
  }

  std::cout << index << " images" << std::endl;
  std::cout << totalSize << " MB " << '\n';

  auto finish = std::chrono::high_resolution_clock::now();

  double timeDelta = std::chrono::duration_cast<std::chrono::microseconds>
                       (finish - start).count();

  std::cout
    << timeDelta / 1000
    << " ms"
    << std::endl;

  return 0;
}
