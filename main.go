package main

import (
	"fmt"
	"os"

	"./data"
)

func main() {
	datasetCSVFile, _ := os.Open("./sample.csv")
	for record := range data.ScanCSV(datasetCSVFile) {
		fmt.Println(record[0])
		//
		fmt.Println(record[1])
	}
}
