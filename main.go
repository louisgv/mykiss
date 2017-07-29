package main

import (
	"os"

	"./data"
)

func main() {
	datasetCSVFile, _ := os.Open("./sample.csv")
	for record := range data.ScanCSV(datasetCSVFile) {
		// fmt.Println(record)
	}
}
