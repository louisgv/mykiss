package data

import (
	"strconv"
	"strings"
	"testing"
)

var expectedData = [3]float64{0.999, 232.424, 14.1515}

const sampleData = `timestamp,value
0,0.999
1,232.424
2,14.1515
`

func TestScanCSV(t *testing.T) {
	for record := range ScanCSV(strings.NewReader(sampleData)) {
		floatValue, err := strconv.ParseFloat(record[1], 64)
		if err != nil {
			t.Fatal(err)
		}
		rIndex, err := strconv.ParseInt(record[0], 10, 32)
		if err != nil {
			t.Fatal(err)
		}

		if expectedData[rIndex] != floatValue {
			t.Fatal("Value is wrong")
		}
	}
}
