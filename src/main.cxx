#include <chrono>

#include <iostream>
#include <iterator>

#include "csvmonkey/csvmonkey.hpp"
using namespace csvmonkey;


int main(int argc, char *argv[])
{
  if (argc < 2) {
    return 1;
  }

  MappedFileCursor cursor;
  cursor.open(argv[1]);

  CsvReader  reader(cursor);
  CsvCursor& row = reader.row();
  int sum        = 0;
	// int index = 1;
  CsvCell *cell_ImageID;
  CsvCell *cell_Subset;
  CsvCell *cell_OriginalURL;
  CsvCell *cell_OriginalSize;

  auto start = std::chrono::high_resolution_clock::now();


  while (reader.read_row()) {
    sum += row.count;

    row.by_value("ImageID",      cell_ImageID);
    row.by_value("Subset",       cell_Subset);
    row.by_value("OriginalURL",  cell_OriginalURL);
    row.by_value("OriginalSize", cell_OriginalSize);

    std::cout.precision(2);
    std::cout
			// << index++
      << " "
      << cell_ImageID->as_str()
      << "\t"
      << std::fixed
      << cell_OriginalSize->as_double()
      << "\t"
      << cell_Subset->as_str()
      << "\t"
      << cell_OriginalURL->as_str()
      << std::endl;
  }

  std::cout << sum << std::endl;
  auto finish = std::chrono::high_resolution_clock::now();

  std::cout <<
  (std::chrono::duration_cast<std::chrono::microseconds>(finish -
                                                         start).count()) <<
  " us\n";

  return 0;
}
