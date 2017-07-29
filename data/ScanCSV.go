package data

import (
	"encoding/csv"
	"io"
)

// ScanCSV ...
func ScanCSV(rc io.Reader) (channel chan []string) {
	channel = make(chan []string, 10)
	go func() {
		reader := csv.NewReader(rc)
		// Read labels
		reader.Read()
		defer close(channel)
		for {
			record, err := reader.Read()
			if err == io.EOF {
				break
			}
			if err == nil {
				channel <- record
			}
		}
	}()
	return
}
